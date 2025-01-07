#include "BoundedPriorityQueue.hpp"
#include <iostream>
#include <string>

int main() {
    // 1: Adding elements to the queue
    std::cout<<"1. Creating a queue of strings"<<std::endl;
    kp::BoundedPriorityQueue<std::string> queue(5);

    queue.insert(10, "chlebak10");
    queue.insert(20, "chlebak20");

    std::cout<<"Current state of queue"<<std::endl;
    queue.printQueue();

    // 2: Adding low priority element to the queue
    std::cout<<"\n2. Adding low priority element to the queue"<<std::endl;
    queue.insert(1, "chlebak1");
    queue.printQueue();

    // 3: Adding an element with high priority
    std::cout<<"\nTest 3: Adding an element with high priority"<<std::endl;
    queue.insert(30, "chlebak30");
    queue.printQueue();

    // 4: Checking for an element
    std::cout<<"\nChecking for element (priority: 10, value: 'chlebak10'):"<<std::endl;
    queue.contains(10, "chlebak10");

    std::cout<<"\nChecking for element (priority: 30, value: 'chlebak20'):"<<std::endl;
    queue.contains(30, "chlebak20");

    // 5: Removing elements from the queue
    std::cout<<"\n4: Removing elements from the queue"<<std::endl;
    while (!queue.isEmpty()) {
        std::cout<<"Removed: "<<queue.pop()<<std::endl;
    }

    // 6: Empty queue case
    std::cout<<"\n5: Trying to remove an element from an empty queue"<<std::endl;
    queue.pop();

    // 7: Changing the queue size
    std::cout<<"\n6: Changing the queue size"<<std::endl;
    queue.insert(10, "chlebak1");
    queue.insert(20, "chlebak2");
    queue.insert(15, "chlebak1.5");
    queue.printQueue();

    std::cout<<"\nChanging the maximum size to 2"<<std::endl;
    queue.setMaxSize(2);
    queue.printQueue();

    // 8: Different data types (int)
    std::cout<<"\n7: Handling different data types (int)"<<std::endl;
    kp::BoundedPriorityQueue<int> intQueue(3);

    intQueue.insert(10, 100);
    intQueue.insert(5, 50);
    intQueue.insert(20, 200);
    intQueue.insert(15, 150);

    intQueue.printQueue();

    std::cout<<"\nRemoving elements from the queue (int):"<<std::endl;
    while (!intQueue.isEmpty()) {
        std::cout<<"Removed: "<<intQueue.pop()<<std::endl;
    }

    //9: Default constructor
    std::cout<<"\n9: Default constructor"<<std::endl;
    kp::BoundedPriorityQueue<std::string> defaultQueue;

    defaultQueue.insert(1, "default1");
    defaultQueue.insert(2, "default2");
    defaultQueue.insert(3, "default3");

    defaultQueue.printQueue();
    std::cout<<"Default queue size: "<<defaultQueue.getMaxSize()<<std::endl;

    return 0;
}