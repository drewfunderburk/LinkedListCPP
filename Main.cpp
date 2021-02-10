#include <iostream>
#include <chrono>
#include "List.h"

int main()
{
	List<int> list = List<int>();

	list.pushFront(1);
	list.pushFront(7);
	list.pushFront(4);
	list.pushFront(20);
	list.pushFront(2);

	List<int> list2 = list;

	std::cout << std::endl;
	list2.print();

	list2.remove(4);

	std::cout << std::endl;
	list2.print();


	/*
	using namespace std::chrono;
	auto lastTime = system_clock::now();

	while (true)
	{
		if (system_clock::now() + milliseconds(10) > lastTime)
		{
			for (int i = 0; i < 10; i++)
			{
				list->pushFront(i);
			}
			list->print();
			list->destroy();
			lastTime = system_clock::now();
		}
	}
	*/
	return 0;
}