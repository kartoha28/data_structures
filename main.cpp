#include <iostream>
#include "SingleList.h"

int main() {
    SingleList<std::string> list;
    list.insertAtEnd("abc");
    list.insertAtBeginning("def");
    std::cout << list;
    return 0;
}
