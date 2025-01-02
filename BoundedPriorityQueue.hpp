#pragma once
#include "PriorityQueue.hpp"
#include <algorithm>

namespace kp {

/**
 * \brief A priority queue with a limited size.
 *
 * This class extends the PriorityQueue to change the maximum size. If the
 * queue reaches its maximum size, elements with lower priorities are discarded
 * to make space for elements with higher priority.
 *
 * \tparam T The type of the elements in the queue.
 */
template <typename T>
class BoundedPriorityQueue : public PriorityQueue<T> {
private:
    size_t maxSize;

public:
    /**
     * \brief Default constructor.
     *
     * Creates a BoundedPriorityQueue with a default maximum size of 10.
     */
    constexpr BoundedPriorityQueue() : maxSize(10) {}

    /**
     * \brief Parameterized constructor.
     *
     * Creates a BoundedPriorityQueue with a specified maximum size.
     *
     * \param maxSize The maximum size of the queue.
     */
    constexpr BoundedPriorityQueue(size_t maxSize) : maxSize(maxSize) {}

    /**
     * \brief Inserts a new element into the queue.
     *
     * If the queue is not full, the element is added. If the queue is full
     * and the new element's priority is higher than the lowest priority in the
     * queue, the lowest-priority element is replaced.
     *
     * \param priority - priority of the element.
     * \param value - value of the element.
     */
    void insert(int priority, const T& value) override {
        if (this->queue.size()<maxSize) {
            this->queue.emplace_back(priority, value, this->currentId++);
            std::sort(this->queue.begin(), this->queue.end(), PriorityQueue<T>::compareNodes);
        } else if (priority>this->queue.back().getPriority()) {
            this->queue.back()=Node<T>(priority, value, this->currentId++);
            std::sort(this->queue.begin(), this->queue.end(), PriorityQueue<T>::compareNodes);
        }
    }

    /**
     * \brief Removes and returns the element with the highest priority.
     *
     * If the queue is empty, the default element value is returned and
     * a message is printed to the standard output.
     *
     * \return The element with the highest priority.
     */
    T pop() override {
        if (this->isEmpty()) {
            std::cout<<"Queue is empty"<<std::endl;
            return T();
        }
        T topValue=this->queue.front().getValue();
        this->queue.erase(this->queue.begin());
        return topValue;
    }

    /**
     * \brief Sets the maximum size of the queue.
     *
     * Adjusts the maximum size of the queue and removes unnecessary elements if
     * the new size is smaller than the current number of elements.
     *
     * \param newSize The new maximum size of the queue.
     */
    void setMaxSize(size_t newSize) {
        maxSize=newSize;
        while (this->queue.size()>maxSize) {
            this->queue.pop_back();
        }
    }

    /**
     * \brief Gets the maximum size of the queue.
     * \return The maximum size of the queue.
     */
    size_t getMaxSize() const { 
        return maxSize; 
    }
};

}
