#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class List
{
public:
	List();
	List(List<T>&);
	~List();
	void destroy();
	Iterator<T> begin();
	Iterator<T> end();
	bool contains(const T& object);
	void pushFront(const T& value);
	void pushBack(const T& value);
	bool insert(const T& value, int index);
	bool remove(const T& value);
	void print() const;
	void initialize();
	bool isEmpty() const;
	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	void sort();

	const List<T>& operator=(const List<T>& other);

private:
	Node<T> m_head;
	Node<T> m_tail;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline List<T>::List(List<T>&)
{
	// TODO: Implement
}

template<typename T>
inline List<T>::~List()
{
	// TODO: Implement
}

template<typename T>
inline void List<T>::destroy()
{
	// TODO: Test
	Iterator<T> iter = Iterator<T>(m_head);
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (iter.m_current->previous)
			delete iter.m_current->previous;
		if (!iter.m_current->next)
			delete iter.m_current;
		if (iter.m_current != m_tail)
			iter++;
	}
	// TODO: Test if m_head and m_tail are deallocated
	m_head = nullptr;
	m_tail = nullptr;
	m_nodeCount = 0;
}

template<typename T>
inline Iterator<T> List<T>::begin()
{
	// TODO: Test
	return Iterator<T>(m_head);
}

template<typename T>
inline Iterator<T> List<T>::end()
{
	// TODO: Test
	return Iterator<T>(m_tail);
}

template<typename T>
inline bool List<T>::contains(const T& object)
{
	// TODO: Test
	Iterator<T> iter = Iterator<T>(m_head);
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (&iter.m_current == object)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	// TODO: Test
	Node<T>* node = new Node<T>(value);
	node->next = m_head;
	m_head.previous = node;
	m_head = node;
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	// TODO: Test
	Node<T>* node = new Node<T>(value);
	node->previous = m_tail;
	m_tail->next = node;
	m_tail = node;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	// TODO: Implement
	if (index >= m_nodeCount)
		return false;

	Iterator<T> iter = Iterator<T>(m_head);
	for (int i = 0; i < index; i++)
		iter++;

	if (!iter.m_current)
		return false;

	if (iter.m_current->next)
		iter.m_current->next->previous = value;
	iter.m_current->next = value;
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	// TODO: Implement
	return false;
}

template<typename T>
inline void List<T>::print() const
{
	// TODO: Implement
	return void();
}

template<typename T>
inline void List<T>::initialize()
{
	// TODO: Implement
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	// TODO: Test
	if (m_nodeCount == 0)
		return true;
	else
		return false;
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	// TODO: Implement
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	// TODO: Test
	return m_nodeCount;
}

template<typename T>
inline void List<T>::sort()
{
	// TODO: Implement
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& other)
{
	// TODO: insert return statement here
}
