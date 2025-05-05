//
// Created by vladi on 05.05.2025.
//

#include "Student.h"

Student::Student() : name(""), age(0), group("") {}

Student::Student(const std::string& name, int age, const std::string& group)
    : name(name), age(age), group(group) {}

std::string Student::getName() const {
    return name;
}

int Student::getAge() const {
    return age;
}

std::string Student::getGroup() const {
    return group;
}

bool Student::operator==(const Student& other) const {
    return name == other.name && age == other.age && group == other.group;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "[Name: " << student.name << ", Age: " << student.age << ", Group: " << student.group << "]";
    return os;
}

