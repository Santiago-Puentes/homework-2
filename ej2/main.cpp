#include "course.hpp"
#include "student.hpp"
#include <iostream>
#include <memory>

int main() {
    // Crear estudiantes
    auto student1 = make_shared<student>("Juan Perez", 123);
    auto student2 = make_shared<student>("Maria Lopez", 456);
    auto student3 = make_shared<student>("Carlos Gomez", 789);

    // Crear un curso con estudiantes
    course curso1({student1, student2});

    // Inscribir un estudiante nuevo
    curso1.inscribir(student3);

    // Intentar inscribir un estudiante ya inscrito
    curso1.inscribir(student1);

    // Verificar si un estudiante está en el curso
    if (curso1.studentInCourse(123)) {
        cout << "El estudiante con legajo 123 está inscrito.\n";
    } else {
        cout << "El estudiante con legajo 123 no está inscrito.\n";
    }

    // Desinscribir un estudiante
    curso1.desinscribir(student2);

    // Intentar desinscribir un estudiante que no está en el curso
    curso1.desinscribir(student2);

    // Imprimir estudiantes en orden alfabético
    cout << "Estudiantes en orden alfabético:\n";
    curso1.printOrdenAlfabético({student1, student3});

    // Crear una copia del curso
    course curso2 = curso1;

    // Verificar que la copia comparte los mismos estudiantes
    cout << "Estudiantes en el curso copiado:\n";
    curso2.printOrdenAlfabético({student1, student3});

    // Verificar si el curso está completo
    if (curso1.completeCourse({student1, student3})) {
        cout << "El curso está completo.\n";
    } else {
        cout << "El curso no está completo.\n";
    }

    return 0;
}

// ¿Qué tipo de relación existe entre los objetos curso y estudiante?
// La relación entre los objetos course y student en este ejercicio es
// de una asociación compartida. Esto se debe a que el objeto course utiliza
// un vector de shared pointers a objetos de clase student para almacenar
// a los estudiantes.