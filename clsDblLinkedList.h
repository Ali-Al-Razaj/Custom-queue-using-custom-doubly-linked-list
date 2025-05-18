#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:
    int _Size = 0;
public:
    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    ////////////////////////////////////// Insert At Begining
    void InsertAtBeginning(T Value)
    {
        Node* NewNode = new Node();
        NewNode->value = Value;
        NewNode->next = head;
        NewNode->prev = NULL;

        if (head != NULL)
        {
            head->prev = NewNode;
        }

        head = NewNode;
        _Size++;
    }

    ////////////////////////////////////// Printing
    static void PrintNodeDetails(Node* N)
    {

        if (N->prev != NULL)
            cout << N->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << N->value << " <--> ";

        if (N->next != NULL)
            cout << N->next->value << "\n";
        else
            cout << "NULL";
    }
    void PrintNodeDetails()
    {

        if (head->prev != NULL)
            cout << head->prev->value;
        else
            cout << "NULL";

        cout << " <--> " << head->value << " <--> ";

        if (head->next != NULL)
            cout << head->next->value << "\n";
        else
            cout << "NULL";
    }
    void PrintListDetails()
    {
        Node* tmp = head;
        cout << "\n\n";
        while (tmp != NULL)
        {
            PrintNodeDetails(tmp);
            tmp = tmp->next;
        }
    }
    void PrintList()
    {
        Node* tmp = head;
        cout << "NULL <--> ";
        while (tmp != NULL)
        {
            cout << tmp->value << " <--> ";
            tmp = tmp->next;
        }
        cout << "NULL";
        cout << endl;
    }
    void Print()
    {
        Node* tmp = head;
        while (tmp != NULL)
        {
            cout << tmp->value << " --> ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    ////////////////////////////////////// Find
    Node* Find(T Value)
    {
        Node* tmp = head;
        while (tmp != NULL)
        {
            if (tmp->value == Value)
            {
                return tmp;
            }

            tmp = tmp->next;
        }

        return NULL;
    }

    ////////////////////////////////////// Insert After (node)
    void InsertAfter(Node* current, T value)
    {
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
        _Size++;
    }

    ////////////////////////////////////// Insert At End
    void InsertAtEnd(T Value)
    {
        Node* newNode = new Node();
        newNode->value = Value;
        newNode->next = NULL;
        if (head == NULL)
        {
            newNode->prev = NULL;
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        _Size++;
    }

    ////////////////////////////////////// Delete Node
    void DeleteNode(Node* NodeToDelete)
    {
        if (head == NULL || NodeToDelete == NULL)
        {
            return;
        }
        if (head == NodeToDelete)
        {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;
        _Size--;
    }

    ////////////////////////////////////// Delete First Node
    void DeleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
        _Size--;
    }

    ////////////////////////////////////// Delete Last Node
    void DeleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _Size--;
    }

    ////////////////////////////////////// Size
    int Size()
    {
        return _Size;
    }

    ////////////////////////////////////// Empty
    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);
    }

    ////////////////////////////////////// Clear
    void Clear()
    {
        while (_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    ////////////////////////////////////// Reverse
    void Reverse()
    {
        Node* current = head;
        Node* tmp = nullptr;
        while (current != nullptr)
        {
            tmp = current->prev;
            current->prev = current->next;
            current->next = tmp;

            current = current->prev;
        }

        if (tmp != nullptr)
        {
            head = tmp->prev;
        }
    }

    ////////////////////////////////////// Get Node
    Node* GetNode(int index)
    {
        int counter = 0;

        if (index > _Size - 1 || index < 0)
            return NULL;

        Node* current = head;
        while (current != NULL && (current->next != NULL))
        {
            if (counter == index)
                break;

            current = current->next;
            counter++;
        }

        return current;
    }

    ////////////////////////////////////// Get Item
    T GetItem(int index)
    {
        Node* ItemNode = GetNode(index);
        if (ItemNode != NULL)
        {
            return ItemNode->value;
        }
        else
        {
            return NULL;
        }
    }

    ////////////////////////////////////// Update Item
    bool UpdateItem(int index, T NewValue)
    {
        Node* ItemNode = GetNode(index);
        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
        {
            return false;
        }
    }

    ////////////////////////////////////// Insert After (index)
    bool InsertAfter(int index, T value)
    {
        Node* ItemNode = GetNode(index);
        if (ItemNode != NULL)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else
        {
            return false;
        }
    }



};

