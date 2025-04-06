#include "course.hpp"
#include <algorithm>
#include <memory>

void course::inscribir(shared_ptr<student> s) {
    if (studentInCourse(s->getLegajo())) return;
    students.push_back(s);
}

void course::desinscribir(shared_ptr<student> s) {
    auto it = find_if(students.begin(), students.end(), [&s](shared_ptr<student> st) {
        return st->getLegajo() == s->getLegajo();
    });
    if (it != students.end()) {
        iter_swap(it, students.end() - 1);
        students.pop_back();
    }
}

bool course::studentInCourse(int legajo) {
    for (const auto& st : students) {
        if (st->getLegajo() == legajo) return true;
    }
    return false;
}

bool course::completeCourse(vector<shared_ptr<student>> students) {
    return students.size() >= 20;
}

void course::printOrdenAlfabético(vector<shared_ptr<student>> students) {
    sort(students.begin(), students.end(), [](const shared_ptr<student>& a, const shared_ptr<student>& b) {
        return a < b;
    });

    // Print the sorted list of students
    for (const auto& st : students) {
        cout << *st << endl;
    }
}