#include <iostream>
#include "SingleList.h"
#include "DoubleList.h"
#include "Student.h"

int main() {
    // Однозв'язний список студентів
    SingleList<Student> singleList;

    Student s1("Андрій", 18, "ІПЗ-11");
    Student s2("Марія", 19, "КН-12");
    Student s3("Олена", 17, "ІПЗ-11");

    singleList.insertAtBeginning(s1);
    singleList.insertAtEnd(s2);
    singleList.insertAtIndex(1, s3);

    std::cout << "Однозв'язний список:" << std::endl;
    std::cout << singleList << std::endl;

    std::cout << "Розмір: " << singleList.getSize() << std::endl;
    std::cout << "Містить Марію? " << (singleList.contains(s2) ? "Так" : "Ні") << std::endl;
    std::cout << "Порожній? " << (singleList.isEmpty() ? "Так" : "Ні") << std::endl;

    // Двозв'язний список студентів
    DoubleList<Student> doubleList;

    doubleList.insertAtEnd(s1);
    doubleList.insertAtBeginning(s2);
    doubleList.insertAtIndex(1, s3);

    std::cout << "\nДвозв'язний список:" << std::endl;
    std::cout << doubleList << std::endl;

    std::cout << "Розмір: " << doubleList.getSize() << std::endl;
    std::cout << "Містить Олену? " << (doubleList.contains(s3) ? "Так" : "Ні") << std::endl;

    return 0;
}
