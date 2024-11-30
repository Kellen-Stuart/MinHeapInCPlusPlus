//
// Created by kobld on 11/27/2024.
//

#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>


class MinHeap {
private:
    // Root is index 0
    // Left  child is located at 2i + 1
    // Right child is located at 2i + 2
    // Example: {1, 2, 3, 4, 5, 6}
    //       1
    //     /  \
    //    2    3
    //  /  \  /
    // 4   5 6
    std::vector<int> heapArray;

    int getParent(const int index) {
        return (index - 1) / 2;
    }

    int getLeftChild(const int index) {
        return 2 * index + 1;
    }

    int getRightChild(const int index) {
        return 2 * index + 2;
    }

    void heapifyUp(int index) {
        if (index == 0) return;

        const int parentIndex = getParent(index);
        if (heapArray[index] < heapArray[parentIndex]) {
            swap(index, parentIndex);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(const int index) {
        int leftChildIndex = getLeftChild(index);

        // Base case: If no left child exists, stop (no children)
        if (leftChildIndex >= heapArray.size()) return;

        // Start by assuming the left child is the smallest
        int smallestChildIndex = leftChildIndex;

        // Check if right child is smaller
        int rightChildIndex = getRightChild(index);
        if (rightChildIndex < heapArray.size() && heapArray[rightChildIndex] < heapArray[leftChildIndex]) {
            smallestChildIndex = rightChildIndex;
        }

        if (heapArray[index] > heapArray[smallestChildIndex]) {
            swap(index, smallestChildIndex);
            heapifyDown(smallestChildIndex);
        }
    }

    void swap(int index1, int index2) {
        int temp = heapArray[index1];
        heapArray[index1] = heapArray[index2];
        heapArray[index2] = temp;
    }
public:
    MinHeap() = default;

    void insert(int value) {
        heapArray.push_back(value);
        if (heapArray.size() > 1) {
            heapifyUp(heapArray.size() - 1);
        }
    }

    void extractMinimum() {
        if (heapArray.size() == 0) return;
        if (heapArray.size() == 1) {
            heapArray.erase(heapArray.begin());
            return;
        }

        heapArray[0] = heapArray[heapArray.size() - 1];
        heapArray.pop_back();

        heapifyDown(0);
    }

    int peek() {
        if (heapArray.empty()) {
            throw std::runtime_error("Heap is empty");
        }

        return heapArray[0];
    }

    void print() {
        if (heapArray.empty()) {
            std::cout << "Empty Heap" << std::endl;
        }
        std::cout << "{";
        for (int i = 0; i < heapArray.size(); i++) {
            std::cout << heapArray[i];
            if (i != heapArray.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "}" << std::endl;
    }
};



#endif //MINHEAP_H
