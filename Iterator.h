#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);

	Iterator<T> operator++(T);
	Iterator<T> operator--(T);
	const bool operator==(const Iterator<T>& iter);
	const bool operator!=(const Iterator<T>& iter);
	T operator*();

private:
	Node<T>* m_current;
};

template<typename T>
inline Iterator<T>::Iterator()
{
	m_current = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	m_current = node;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++(T)
{
	m_current = m_current->next;
	return *this;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--(T)
{
	m_current = m_current->previous;
	return *this;
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	// TODO: Test
	if (iter.m_current == nullptr)
	{
		if (m_current == nullptr)
			return true;
		else
			return false;
	}
	return m_current == iter.m_current;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	// TODO: Test
	if (iter.m_current == nullptr)
	{
		if (m_current == nullptr)
			return false;
		else
			return true;
	}

	return m_current != iter.m_current;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	// TODO: Test
	return m_current->data;
}
