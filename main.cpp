#include <iostream>

#include "MinHeap.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(2);
    minHeap.print();

    minHeap.extractMinimum();
    minHeap.print();

    std::cout << minHeap.peek() << std::endl;
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.