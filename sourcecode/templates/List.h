#pragma once

#include <functional>
#include <exception>
#include <stdexcept>

template<typename T>
class List
{
	struct Node
	{
		T val;
		Node* next;
		Node* previous;
		Node() {};
		Node( T v ): val( v ) {};
	};

	Node* head;
	Node* tail;
	std::size_t length;

public:
	class iterator
	{
		friend class List<T>;
		mutable Node* current;
	public:
		iterator(): current( nullptr ) {};
		iterator( const iterator& src ) { current = src.current; };
		iterator( Node* src ) { current = src; };
		~iterator() = default;
		iterator& operator=( const iterator& rhs ) { current = rhs.current; return *this; };

		bool operator==( const iterator& rhs ) const noexcept { return current == rhs.current; };
		bool operator!=( const iterator& rhs ) const noexcept { return current != rhs.current; };

		iterator& operator++() const noexcept { current = current->next; return *this; };
		iterator operator++( int ) const noexcept { auto temp = *this; current = current->next; return temp; };
		iterator& operator--() const noexcept { current = current->previous; return *this; };;
		iterator operator--( int ) const noexcept { auto temp = *this; current = current->previous; return temp; };

		T& operator*() noexcept { return current->val; };
		const T& operator*() const noexcept { return current->val; };

		T* operator ->() noexcept { return &current->val; };
		const T* operator ->() const noexcept { return &current->val; };
	};
	typedef const iterator const_iterator;

	List();
	List( const List& src ) { *this = src; };
	~List();
	List& operator=( const List& rhs );

	void push_back( const T& elem );
	void push_front( const T& elem );
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
		throw std::invalid_argument( "Index out of range!" );

	iterator it = begin();
	for( int i = 0; i < x; i++ )
		it++;

	return *it;
}

template<typename T>
void List<T>::insert( const_iterator& pos, const T& elem )
{
	if( pos.current == head )
		throw std::invalid_argument( "Invalid iterator!" );

	Node* temp = new Node( val = elem );
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
		throw std::invalid_argument( "Invalid iterator!" );

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

	for( iterator it = begin(), iterator rhit = rhs.begin(); it != end(), rhit != rhs.end(); it++, rhs++ )
	{
		if( *it != *rhit )
			return false;
	}

	return true;
}
