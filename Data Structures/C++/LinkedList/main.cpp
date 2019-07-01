#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList<int> list;
	list.insert(1);
	list.insert(3);
	list.insert(5);
	list.insert(7);
	list.removeWhere([](int data) -> bool { return data == 5; });
	list.clear();
	return 0;
}
