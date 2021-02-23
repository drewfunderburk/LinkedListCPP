#include <iostream>
#include <chrono>
#include "List.h"

int main()
{
	List<int> list = List<int>();

	// Demonstrate push
	list.pushFront(1);
	list.pushFront(7);
	list.pushFront(4);
	list.pushFront(20);
	list.pushBack(2);
	list.print();

	List<int> list2 = list;

	std::cout << std::endl;
	list2.print();

	list2.remove(4);

	std::cout << std::endl;
	list.print();

	Iterator<int> iter = list.begin();
	std::cout << std::endl;
	std::cout << *iter << std::endl;
	list.getData(iter, 2);
	std::cout << *iter << std::endl;

	return 0;
}