#include <iostream>
#include "List.h"

int main()
{
	List<int>* list = new List<int>();
	list->pushFront(1);
	list->pushFront(5);
	list->pushFront(10);
	list->pushFront(2);

	Iterator<int> iter = list->begin();
	for (int i = 0; i < list->getLength(); i++)
	{
		std::cout << iter.getData() << std::endl;
		iter++;
	}
	return 0;
}