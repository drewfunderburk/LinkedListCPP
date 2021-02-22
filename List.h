#pragma once
#include "Node.h"
#include "Iterator.h"

template<typename T>
class List
{
public:
	List();
	List(const List<T>& other);
	~List();
	void destroy();
	Iterator<T> begin() const;
	Iterator<T> end() const;
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
	Node<T>* m_head;
	Node<T>* m_tail;
	int m_nodeCount;
};

template<typename T>
inline List<T>::List()
{
	initialize();
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	destroy();
	initialize();
	for (Iterator<T> iter = other.begin(); iter != other.end(); iter++)
	{
		pushFront(*iter);
	}
}

template<typename T>
inline List<T>::~List()
{
	// TODO: Test
	destroy();
	delete m_head;
	delete m_tail;
}

template<typename T>
inline void List<T>::destroy()
{
	// Iterate through list and destroy all nodes
	for ( Node<T>*iter = m_head; iter != m_tail->next;)
	{
		Node<T>* temp = iter;
		iter = iter->next;
		delete temp;
	}

	// TODO: Test if m_head and m_tail are deallocated
	initialize();
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_head);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_tail->next);
}

template<typename T>
inline bool List<T>::contains(const T& object)
{
	// TODO: Test
	Iterator<T> iter = Iterator<T>(m_head);
	for (int i = 0; i < m_nodeCount; i++)
	{
		if (*iter == object)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	// TODO: Test

	// Create new node with given data
	Node<T>* node = new Node<T>(value);
	
	// If there are no nodes, set the tail to this node
	if (isEmpty())
	{
		m_tail->data = value;
		m_nodeCount++;
		return;
	}

	// Attach this node before m_head
	node->next = m_head;
	m_head->previous = node;

	// Make this node the new head
	m_head = node;

	// Increment m_nodeCount
	m_nodeCount++;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	// TODO: Test

	// Create new node with given data
	Node<T>* node = new Node<T>(value);

	// If there are no nodes, set the tail to this node
	if (isEmpty())
	{
		m_tail->data = value;
		m_nodeCount++;
		return;
	}

	// Attach this node after m_tail
	node->previous = m_tail;
	m_tail->next = node;

	// If m_head has no data, push m_tail into it
	if (m_tail->data == NULL)
		m_head = m_tail;

	// Make this node the new tail
	m_tail = node;

	// Increment m_nodeCount
	m_nodeCount++;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	// TODO: Test

	// Ensure valid index
	if (index >= m_nodeCount || index < 0)
		return false;

	// Create node pointer to hold new value
	Node<T>* node = new Node<T>(value);

	// Declare a placeholder node pointer
	Node<T>* indexNode = m_head;
	// Get the node at the given index
	for (int i = 0; i < index; i++)
	{
		indexNode = indexNode->next;
	}
	
	// Insert node before
	indexNode->previous->next = node;
	node->previous = indexNode->previous;
	node->next = indexNode;
	indexNode->previous = node;

	m_nodeCount++;
	return true;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	// Create placeholder node pointer and point it at m_head
	Node<T>* placeholder = m_head;

	// Go through nodes without an Iterator since we need access to the nodes themselves
	for (int i = 0; i < getLength(); i++)
	{
		// If the current node has the given value
		if (placeholder->data == value)
		{
			// Unlink node
			placeholder->previous->next = placeholder->next;
			placeholder->next->previous = placeholder->previous;

			// Delete node
			delete placeholder;
			m_nodeCount--;
			return true;
		}
		
		// Go to next node
		placeholder = placeholder->next;
	}
	return false;
}

template<typename T>
inline void List<T>::print() const
{
	for (Iterator<T> iter = begin(); iter != end(); iter++)
		std::cout << *iter << std::endl;
}

template<typename T>
inline void List<T>::initialize()
{
	// TODO: Test
	m_head = new Node<T>();
	m_tail = new Node<T>();
	m_head->next = m_tail;
	m_tail->previous = m_head;
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return m_nodeCount == 0;
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

	for (int i = 0; i < getLength(); i++)
	{
		// Store pointer to m_head
		Node<T>* node = m_head;

		for (int j = 0; j < getLength(); j++)
		{
			// Check if this node is greater than the last node
			if (node->data > node->next->data)
			{
				// Swap node with node->next
				T temp = node->data;
				node->data = node->next->data;
				node->next->data = temp;
			}

			// Go to the next node
			node = node->next;
		}
	}
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& other)
{
	destroy();
	initialize();
	for (Iterator<T> iter = other.begin(); iter != other.end(); iter++)
	{
		pushFront(*iter);
	}

	return *this;
}
