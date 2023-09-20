#include <iostream>
#include <string>
#include "Node.h"

class LinkedLint
{
private:
    Node *head = NULL;
    int size = 0;

public:
    LinkedLint()
    {
    }

    LinkedLint(int value)
    {

        Node *node = new Node();
        node->value = value;

        this->head = node;

        size++;
    }

    void showLinkedList()
    {

        for (auto el = this->head; el != NULL; el = el->node)
        {
            cout << el->value << "\n";
        }
    }

    /**
     * Return size
     * @return int
     */
    int getSize()
    {
        return this->size;
    }

    /**
     * Test whether container is empty
     * @return bool
     */
    int empty()
    {
        return (this->size == 0) ? true : false;
    }

    /**
     * Returns a reference to the first Node in the list container.
     * @return Node *
     */
    Node *front()
    {
        return this->head;
    }

    /**
     * Adds a new element at the end of the LinkedList, after its current last element.
     * @param value int
     */
    void push_back(int value)
    {

        auto el = this->head;

        while (el->node != NULL)
        {
            el = el->node;
        }

        Node *node = new Node();
        node->value = value;

        el->node = node;

        size++;
    }
};
