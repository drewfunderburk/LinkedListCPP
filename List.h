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

	/// <summary>
	/// Destroy all nodes and reinitialize the list
	/// </summary>
	void destroy();

	/// <summary>
	/// Return an Iterator pointing to the first node in the list
	/// </summary>
	Iterator<T> begin() const;

	/// <summary>
	/// Return an Iterator pointing to the last node in the list
	/// </summary>
	Iterator<T> end() const;

	/// <summary>
	/// Checks if a value exists in the list
	/// </summary>
	bool contains(const T& object);

	/// <summary>
	/// Pushes a value to the front of the list
	/// </summary>
	void pushFront(const T& value);

	/// <summary>
	/// Pushes a value to the back of the list
	/// </summary>
	void pushBack(const T& value);

	/// <summary>
	/// Insert a value at the given index
	/// </summary>
	bool insert(const T& value, int index);

	/// <summary>
	/// Remove a value from the list
	/// </summary>
	bool remove(const T& value);

	/// <summary>
	/// Print the list to the console
	/// </summary>
	void print() const;

	/// <summary>
	/// Initialize the list as new without destroying nodes
	/// </summary>
	void initialize();

	/// <summary>
	/// Checks if the list is empty
	/// </summary>
	bool isEmpty() const;

	/// <summary>
	/// Gives an iterator pointing to a specific index
	/// </summary>
	bool getData(Iterator<T>& iter, int index);

	/// <summary>
	/// Get the length of the list
	/// </summary>
	int getLength() const;

	/// <summary>
	/// Sort the list using bubble sort
	/// </summary>
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
	// Destroy all nodes currently in the list if it is not empty
	if (!m_head || !m_tail)
		initialize();
	else
		destroy();
	// Push all node values from the other list into this one
	for (Iterator<T> iter = other.begin(); iter != other.end(); iter++)
	{
		// Deep copy
		pushBack(*iter);
	}
}

template<typename T>
inline List<T>::~List()
{
	// Destroy all nodes
	destroy();
	// Delete head and tail
	delete m_head;
	delete m_tail;
}

template<typename T>
inline void List<T>::destroy()
{
	// Iterate through list and destroy all nodes
	for ( Node<T>*iter = m_head; iter != nullptr;)
	{
		Node<T>* temp = iter;
		iter = iter->next;
		delete temp;
	}

	// Initialize the list as new
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
	// Check each node for the given value
	for (Iterator<T> iter = begin(); iter != end(); iter++)
	{
		if (*iter == object)
			return true;
	}
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{	
	// If there are no nodes, set the tail to this node
	if (isEmpty())
	{
		m_tail->data = value;
		m_nodeCount++;
		return;
	}

	// If there is only one node (meaning only m_tail has a value) set m_head to be the given value
	if (m_nodeCount == 1)
	{
		m_head->data = value;
		m_nodeCount++;
		return;
	}

	// Create new node with given data
	Node<T>* node = new Node<T>(value);

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
	// If there are no nodes, set the tail to this node
	if (isEmpty())
	{
		m_tail->data = value;
		m_nodeCount++;
		return;
	}

	// If there is only one node (meaning only m_tail has a value)
	// move m_tail's value to m_head and add value to m_tail
	if (m_nodeCount == 1)
	{
		m_head->data = m_tail->data;
		m_tail->data = value;
		m_nodeCount++;
		return;
	}

	// Create new node with given data
	Node<T>* node = new Node<T>(value);

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
	// Create head and tail and link them together
	m_head = new Node<T>();
	m_tail = new Node<T>();
	// Link them up
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
	// Set the iterator to the beginning of the list
	iter = begin();
	for (int i = 0; i < index; i++)
	{
		// Increment the iterator up to index
		iter++;
	}

	// Return false if iter is null
	if (iter != nullptr)
		return true;
	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline void List<T>::sort()
{
	for (int i = 0; i < getLength(); i++)
	{
		// Store pointer to m_head
		Node<T>* node = m_head;

		for (int j = 0; j < getLength(); j++)
		{
			// Check if this node is greater than the last node
			if (node->data > node->next->data)
			{
				// Swap data in node with node->next
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
	// Destroy the current list if it is not empty
	if (!m_head || !m_tail)
		initialize();
	else
		destroy();
	// Push the values from the other list into this one
	for (Iterator<T> iter = other.begin(); iter != other.end(); iter++)
	{
		// Deep copy
		pushBack(*iter);
	}

	return *this;
}
