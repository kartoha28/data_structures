#include <iostream>

#include "SingleList.h"
#include "DoubleList.h"
#include "StackArray.h"

#include "StackList.h"
#include "StackArray.h"

#include "Student.h"

using namespace std;

int main() {
    /*// Однозв'язний список студентів
    SingleList<Student> singleList;

    Student s1("Андрій", 18, "ІПЗ-143");
    Student s2("Марія", 19, "КН-141");
    Student s3("Олена", 17, "ІПЗ-143");

    singleList.insertAtBeginning(s1);
    singleList.insertAtEnd(s2);
    singleList.insertAtIndex(1, s3);

    cout << "Однозв'язний список:" << std::endl;
    cout << singleList << std::endl;

    cout << "Розмір: " << singleList.getSize() << std::endl;
    cout << "Містить Марію? " << (singleList.contains(s2) ? "Так" : "Ні") << std::endl;
    cout << "Порожній? " << (singleList.isEmpty() ? "Так" : "Ні") << std::endl;

    // Двозв'язний список студентів
    DoubleList<Student> doubleList;

    doubleList.insertAtEnd(s1);
    doubleList.insertAtBeginning(s2);
    doubleList.insertAtIndex(1, s3);

    cout << "\nДвозв'язний список:" << std::endl;
    cout << doubleList << std::endl;

    cout << "Розмір: " << doubleList.getSize() << std::endl;
    cout << "Містить Олену? " << (doubleList.contains(s3) ? "Так" : "Ні") << std::endl;
    cout << doubleList[1];*/

    try {
        StackArray<int> stack(3); // Створюємо стек з максимальною кількістю елементів = 3

        stack.push(10);
        stack.push(20);
        stack.push(30);

        try {
            stack.push(30);
        }catch(const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cout << "Top element: " << stack.pop() << std::endl;  // Виведе 30

        std::cout << "Top element after pop: " << stack.pop() << std::endl;  // Виведе 20

        std::cout << "Top element after push: " << stack.pop() << std::endl;  // Виведе 40

        // Якщо спробуємо перевищити максимальний розмір:
        std::cout << stack.pop();  // Викликає std::overflow_error

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
