#include <iostream>
#include "List.h"

int main()
{
	List<int>* list = new List<int>();
	list->pushFront(1);
	list->pushFront(5);
	list->pushFront(10);
	list->pushFront(2);

	list->pushBack(100);

	list->insert(20, 3);

	Iterator<int> iter = list->begin();
	for (int i = 0; i < list->getLength(); i++)
	{
		std::cout << *iter << std::endl;
		iter++;
	}
	return 0;
}