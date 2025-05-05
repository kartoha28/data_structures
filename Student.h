//
// Created by vladi on 05.05.2025.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <ostream>

class Student {
private:
    std::string name;
    int age;
    std::string group;

public:
    Student();
    Student(const std::string& name, int age, const std::string& group);

    std::string getName() const;
    int getAge() const;
    std::string getGroup() const;

    bool operator==(const Student& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};



#endif //STUDENT_H
