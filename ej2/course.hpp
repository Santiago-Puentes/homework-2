#pragma once
#include <vector>
#include "student.hpp"
#include <memory>
using namespace std;

class course {
    private:
        vector<shared_ptr<student>> students;
    public:
        course(vector<shared_ptr<student>> studentsVec) : students(studentsVec) {}
        // Constructor de copia
        course(const course& other) : students(other.students) {
        // Este constructor realiza una copia superficial del vector `students`.
        // Dado que `students` utiliza shared pointers, los punteros a los objetos
        // `student` son compartidos entre el curso original y la copia. Esto es eficiente
        // en términos de memoria, ya que no se duplican los objetos `student`.
        }

        // Operador de asignación
        course& operator=(const course& other) {
            if (this != &other) {
                students = other.students;
                // Similar al constructor de copia, el operador de asignación realiza
                // una copia superficial del vector `students`. Los shared pointers
                // aseguran que los objetos `student` sean compartidos entre las instancias.
            }
        return *this;
    }

        void inscribir(shared_ptr<student> s);
        void desinscribir(shared_ptr<student> s);
        bool studentInCourse(int legajo);
        bool completeCourse(vector<shared_ptr<student>> students);
        void printOrdenAlfabético(vector<shared_ptr<student>> students);
};