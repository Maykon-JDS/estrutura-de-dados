#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    
    LinkedLint * list = new LinkedLint();
    list->push_front(288);
    list->push_back(30);
    list->push_back(4);
    list->push_back(3);
    list->push_back(2);
    list->push_back(54);
    list->push_back(33);
    list->push_back(29);
    list->push_front(1);
    list->push_front(23);
    list->showLinkedList();
    
    return 0;
}
