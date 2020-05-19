#ifndef LIST_HEADER_INCLUDED
#define LIST_HEADER_INCLUDED

class List
{
public:

    Iterator begin()
    {
        return Iterator(first);
    }

    Iterator end()
    {
        return Iterator(NULL);
    }

    class Iterator
    {
    public:
        Iterator(const Node* node)
        {
            currentNode = node;
        }

        Iterator& operator++()
        {
            if (currentNode)
                currentNode = currentNode->next;

            return *this;
        }

        bool operator!=(const Iterator& iterator)
        {
            return currentNode != iterator.currentNode;
        }

        int operator*()
        {
            return currentNode->data;
        }

    private:
        const Node* currentNode;
    };

private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* first;
};

#endif