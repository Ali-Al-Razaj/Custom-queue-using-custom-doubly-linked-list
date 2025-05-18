// Custom Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "clsMyQueue.h";

using namespace std;

int main()
{
    clsMyQueue<int> Queue;

    Queue.Push(1);
    Queue.Push(2);
    Queue.Push(3);
    Queue.Push(4);
    
    Queue.Print();

    Queue.Pop();
    Queue.Print();

    Queue.Pop();
    Queue.Print();

    Queue.Clear();
    cout << Queue.Size() << endl;
}


