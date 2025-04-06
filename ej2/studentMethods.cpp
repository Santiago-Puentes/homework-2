#include "student.hpp"

string student::getName() {
    return fullName;
}
int student::getLegajo() {
    return legajo;
}
float student::getPromedio() {
    float sum = 0.0;
    for (const auto& course : courses) {
        sum += course.second;
    }
    return courses.empty() ? 0.0 : sum / courses.size();
}

bool student::operator<(const student& st) const {
    return this->fullName < st.fullName;
}