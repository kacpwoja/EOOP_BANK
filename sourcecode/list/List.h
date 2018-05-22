#pragma once

#include <functional>
#include <exception>
#include <stdexcept>
#include <utility>

template<typename T>
class List
{
	struct Node
	{
		T val;
		Node* next;
		Node* previous;
		Node() {};
		Node( const T& v ): val( v ) {};
		Node( T&& v ): val( std::move( v ) ) {};
	};

	Node* head;
	Node* tail;
	std::size_t length;

public:
	class ListError final: std::invalid_argument
	{
	public:
		using std::invalid_argument::invalid_argument;
		using std::invalid_argument::what;
	};

	class iterator
	{
		friend class List<T>;
		mutable Node* current;
	public:
		iterator( const iterator& src ): current( src.current ) {};
		iterator( iterator&& src ) { current = std::move( current ); };
		iterator( Node* src ): current( src ) {};
		~iterator() = default;

		iterator& operator=( const iterator& rhs ) noexcept { current = rhs.current; return *this; };
		iterator& operator=( iterator&& rhs ) noexcept { current = std::move( rhs.current ); rhs.current = nullptr; return *this; };

		bool operator==( const iterator& rhs ) const noexcept { return current == rhs.current; };
		bool operator!=( const iterator& rhs ) const noexcept { return current != rhs.current; };

		const iterator& operator++() const noexcept { current = current->next; return *this; };
		iterator operator++( int ) const noexcept { iterator temp( *this ); current = current->next; return temp; };
		const iterator& operator--() const noexcept { current = current->previous; return *this; };
		iterator operator--( int ) const noexcept { iterator temp( *this ); current = current->previous; return temp; };

		T& operator*() noexcept { return current->val; };
		const T& operator*() const noexcept { return current->val; };

		T* operator ->() noexcept { return &current->val; };
		const T* operator ->() const noexcept { return &current->val; };
	};
	typedef const iterator const_iterator;

	List();
	List( const List& src ): List() { *this = src; };
	List( List&& src );
	~List();

	List& operator=( const List& rhs );
	List& operator=( List&& rhs );

	void push_back( const T& elem );
	void push_back( T&& elem );
	void push_front( const T& elem );
	void push_front( T&& elem );
	void pop_back();
	void pop_front();
	T& front() const noexcept { return head->next->val; };
	T& back() const noexcept { return tail->previous->val; };

	void clear();
	bool empty() const noexcept { return length == 0; };
	std::size_t size() const noexcept { return length; };

	iterator begin() const noexcept { return iterator( head->next ); };
	iterator end() const noexcept { return iterator( tail ); };

	void insert( const_iterator& pos, const T& elem );
	void insert( const_iterator& pos, T&& elem );
	void erase( const_iterator& pos );

	bool operator==( const List& rhs ) const noexcept;
	bool operator!=( const List& rhs ) const noexcept { return !( *this == rhs ); };

	T& operator[]( int x ) const;
};

template<typename T>
List<T>::List()
{
	head = new Node();
	tail = new Node();
	head->next = tail;
	head->previous = nullptr;
	tail->next = nullptr;
	tail->previous = head;
	length = 0;
}

template<typename T>
List<T>::List( List&& src )
{
	head = new Node();
	tail = new Node();
	head->previous = nullptr;
	tail->next = nullptr;

	head->next = std::move( src.head->next );
	src.head->next = src.tail;

	tail->previous = std::move( src.tail->previous );
	src.tail->previous = src.head;

	length = std::move( src.length );
	src.length = 0;
}

template<typename T>
List<T>& List<T>::operator=( const List& rhs )
{
	if( &rhs == this )
		return *this;

	clear();
	for( iterator it = rhs.begin(); it != rhs.end(); it++ )
	{
		push_back( *it );
	}

	return *this;
}

template<typename T>
List<T>& List<T>::operator=( List && rhs )
{
	if( this == &rhs )
		return *this;

	clear();
	head->next = std::move( rhs.head->next );
	rhs.head->next = rhs.tail;

	tail->previous = std::move( rhs.tail->previous );
	rhs.tail->previous = rhs.head;

	length = std::move( rhs.length );
	rhs.length = 0;

	return *this;
}

template<typename T>
List<T>::~List()
{
	clear();

	delete head;
	delete tail;
}

template<typename T>
void List<T>::push_back( const T& elem )
{
	Node* temp = new Node( elem );
	temp->next = tail;
	temp->previous = tail->previous;
	tail->previous->next = temp;
	tail->previous = temp;
	length++;
}

template<typename T>
void List<T>::push_back( T && elem )
{
	Node* temp = new Node( elem );
	temp->next = tail;
	temp->previous = tail->previous;
	tail->previous->next = temp;
	tail->previous = temp;
	length++;
}

template<typename T>
void List<T>::push_front( const T& elem )
{
	Node* temp = new Node( elem );
	temp->next = head->next;
	temp->previous = head;
	head->next->previous = temp;
	head->next = temp;
	length++;
}

template<typename T>
void List<T>::push_front( T && elem )
{
	Node* temp = new Node( elem );
	temp->next = head->next;
	temp->previous = head;
	head->next->previous = temp;
	head->next = temp;
	length++;
}

template<typename T>
void List<T>::pop_back()
{
	if( empty() )
		return;

	Node* temp = tail->previous;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	delete temp;
	length--;
}

template<typename T>
void List<T>::pop_front()
{
	if( empty() )
		return;

	Node* temp = head->next;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	delete temp;
	length--;
}

template<typename T>
void List<T>::clear()
{
	while( head->next != tail )
	{
		pop_front();
	}
	length = 0;
}

template<typename T>
T& List<T>::operator[]( int x ) const
{
	if( x >= length )
		throw ListError( "Index out of range!" );

	iterator it = begin();
	for( int i = 0; i < x; i++ )
		it++;

	return *it;
}

template<typename T>
void List<T>::insert( const_iterator& pos, const T& elem )
{
	if( pos.current == head )
		throw ListError( "Invalid iterator!" );

	Node* temp = new Node( elem );
	temp->next = pos.current;
	temp->previous = pos.current->previous;
	pos.current->previous->next = temp;
	pos.current->previous = temp;

	length++;
}

template<typename T>
void List<T>::insert( const_iterator & pos, T && elem )
{
	if( pos.current == head )
		throw ListError( "Invalid iterator!" );

	Node* temp = new Node( elem );
	temp->next = pos.current;
	temp->previous = pos.current->previous;
	pos.current->previous->next = temp;
	pos.current->previous = temp;

	length++;
}

template<typename T>
void List<T>::erase( const_iterator& pos )
{
	if( pos.current == head || pos.current == tail )
		throw ListError( "Invalid iterator!" );

	Node* temp = pos.current;
	temp->next->previous = temp->previous;
	temp->previous->next = temp->next;

	delete temp;
	length--;
}

template<typename T>
bool List<T>::operator==( const List& rhs ) const noexcept
{
	if( &rhs == this )
		return true;

	if( size() != rhs.size() )
		return false;

	if( rhs.empty() )
		return true;

	for( typename List<T>::const_iterator it = begin(), rhit = rhs.begin(); it != end(), rhit != rhs.end(); it++, rhit++ )
	{
		if( *it != *rhit )
			return false;
	}

	return true;
}
