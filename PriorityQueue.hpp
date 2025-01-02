#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

namespace kp {

/**
 * \brief Represents a single node in the priority queue.
 *
 * This class is stores an element along
 * with its priority and a unique identifier.
 *
 * \tparam T The type of the value stored in the node.
 */
template <typename T>
class Node {
private:
    int priority;      
    T value;           
    size_t id;         

public:
    /**
     * \brief Default constructor.
     *
     * Creates a Node with default values.
     */
    Node()=default;

    /**
     * \brief Parametric constructor.
     *
     * Creates a Node with specified priority, value, and ID.
     *
     * \param priority - priority of the node.
     * \param value - value to be stored in the node.
     * \param id - unique identifier of the node.
     */
    Node(int priority, const T& value, size_t id) : priority(priority), value(value), id(id) {}

    /**
     * \brief Gets the priority of the node.
     * \return Priority of the node.
     */
    int getPriority() const { 
        return priority; 
    }

    /**
     * \brief Gets the value of the node.
     * \return Value stored in the node.
     */
    const T& getValue() const { 
        return value; 
    }

    /**
     * \brief Gets the unique identifier of the node.
     * \return Unique identifier of the node.
     */
    size_t getId() const { 
        return id; 
    }

    /**
     * \brief Sets the priority of the node.
     * \param newPriority - new priority value.
     */
    void setPriority(int newPriority) { 
        priority=newPriority; 
    }

    /**
     * \brief Sets the value of the node.
     * \param newValue - new value to store in the node.
     */
    void setValue(const T& newValue) { 
        value=newValue; 
    }

    /**
     * \brief Compares two nodes for equality.
     *
     * Checks if two nodes have the same priority, value, and ID.
     *
     * \param other Another node to compare with.
     * \return True if the nodes are equal, false if they are not.
     */
    bool operator==(const Node& other) const {
        return priority==other.priority && value==other.value && id==other.id;
    }

    /**
     * \brief Less-than operator for comparing nodes.
     *
     * Determines the ordering of nodes based on priority and ID.
     *
     * \param other Another node to compare with.
     * \return True if this node has lower priority, false otherwise.
     */
    bool operator<(const Node& other) const {
        return priority<other.priority || (priority==other.priority && id>other.id);
    }

    /**
     * \brief Stream output operator for a node.
     *
     * Output stream in a clear format.
     *
     * \param os - output stream.
     * \param node - node to output.
     * \return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const Node& node){
        os<<"Priority: "<<node.priority<<", Value: "<<node.value<<", ID: "<<node.id;
        return os;
    }
};

/**
 * \brief Abstract base class for priority queue implementations.
 *
 * The PriorityQueue class defines the interface for managing elements
 * in a priority queue structure. Derived classes must implement the methods.
 *
 * \tparam T The type of the elements in the queue.
 */
template <typename T>
class PriorityQueue {
protected:
    std::vector<Node<T>> queue; 
    size_t currentId=1;       

public:
    /**
     * \brief Virtual destructor.
     *
     * Provides proper cleaning of derived classes.
     */
    virtual ~PriorityQueue()=default;

    /**
     * \brief Inserts a new element into the queue.
     *
     * Derived classes must define the behavior for adding elements.
     *
     * \param priority Priority of the element.
     * \param value Value of the element.
     */
    virtual void insert(int priority, const T& value)=0;

    /**
     * \brief Removes and returns the highest-priority element.
     *
     * Derived classes must define the behavior for removing elements.
     *
     * \return The highest-priority element.
     */
    virtual T pop()=0;

    /**
     * \brief Checks if the queue is empty.
     * \return True if the queue is empty, false otherwise.
     */
    bool isEmpty() const { 
        return queue.empty(); 
    }

    /**
     * \brief Gets the size of the queue.
     * \return Number of elements in the queue.
     */
    size_t size() const { 
        return queue.size(); 
    }

    /**
     * \brief Prints the current state of the queue.
     *
     * Displays the contents of the queue to the standard output.
     */
    void printQueue() const {
        if (queue.empty()) {
            std::cout<<"Queue is empty"<<std::endl;
        } else{
            for (const auto& node : queue) {
                std::cout<<node<<std::endl;
            }
        }
    }

protected:
    /**
     * \brief Compares two nodes.
     *
     * Determines the order of nodes based on priority and ID.
     *
     * \param a - first node.
     * \param b - second node.
     * \return True if the first node has a higher priority, false if not.
     */
    static bool compareNodes(const Node<T>& a, const Node<T>& b) {
        if (a.getPriority()==b.getPriority()) {
            return a.getId()<b.getId();
        }
        return a.getPriority()>b.getPriority();
    }
};

}