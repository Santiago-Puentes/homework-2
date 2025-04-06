#include "clock.hpp"

int main() {
    Time t;
    int option;

    do {
        cout << "\nMenú de opciones:\n";
        cout << "1. Establecer horas\n";
        cout << "2. Establecer minutos\n";
        cout << "3. Establecer segundos\n";
        cout << "4. Establecer período (a.m./p.m.)\n";
        cout << "5. Mostrar hora en formato estándar\n";
        cout << "6. Obtener hora completa como string\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
            case 1: {
                int h;
                cout << "Ingrese las horas (0-11): ";
                cin >> h;
                if (h < 0 || h > 11) {
                    cout << "Valor inválido. Intente nuevamente.\n";
                } else {
                    t.setHours(h);
                    cout << "Horas actualizadas.\n";
                }
                break;
            }
            case 2: {
                int m;
                cout << "Ingrese los minutos (0-59): ";
                cin >> m;
                if (m < 0 || m >= 60) {
                    cout << "Valor inválido. Intente nuevamente.\n";
                } else {
                    t.setMinutes(m);
                    cout << "Minutos actualizados.\n";
                }
                break;
            }
            case 3: {
                int s;
                cout << "Ingrese los segundos (0-59): ";
                cin >> s;
                if (s < 0 || s >= 60) {
                    cout << "Valor inválido. Intente nuevamente.\n";
                } else {
                    t.setSeconds(s);
                    cout << "Segundos actualizados.\n";
                }
                break;
            }
            case 4: {
                string p;
                cout << "Ingrese el período (a.m. o p.m.): ";
                cin >> p;
                if (p != "a.m." && p != "p.m.") {
                    cout << "Período inválido. Intente nuevamente.\n";
                } else {
                    t.setPeriod(p);
                    cout << "Período actualizado.\n";
                }
                break;
            }
            case 5:
                cout << "Hora actual: ";
                t.print();
                break;
            case 6:
                cout << "Hora completa como string: " << t.getTime() << endl;
                break;
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (option != 7);
    return 0;
}