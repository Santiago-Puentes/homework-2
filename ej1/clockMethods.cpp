#include "clock.hpp"

void Time::print() const {
    cout << setfill('0') << setw(2) << hours << "h, "
         << setfill('0') << setw(2) << minutes << "m, "
         << setfill('0') << setw(2) << seconds << "s " 
         << period << "." << endl;
}

void Time::print24HourFormat() const {
    int hour24 = (period == "p.m.") ? hours + 12 : hours;
    cout << setfill('0') << setw(2) << hour24 << ":"
         << setfill('0') << setw(2) << minutes << ":"
         << setfill('0') << setw(2) << seconds << endl;
}

void Time::setHours(int h) {
    hours = (h % 12);
    if (hours < 0) hours = 0;
}

void Time::setMinutes(int m) {
    minutes = (m % 60 + 60) % 60;
}

void Time::setSeconds(int s) {
    seconds = (s % 60 + 60) % 60;
}

void Time::setPeriod(const std::string& p) {
    if (p == "a.m." || p == "p.m.") {
        period = p;
    }
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

string Time::getPeriod() const {
    return period;
}

string Time::getTime() const {
    ostringstream oss; // Para armar el formato string
    // setfill() y setw() sirven para que los números se escriban con 2 dígitos,
    // por ejemplo, 5 se escribe como 05 y se unen con el separador ":"
    oss << setfill('0') << setw(2) << hours << ":"
        << setfill('0') << setw(2) << minutes << ":"
        << setfill('0') << setw(2) << seconds << " "
        << period;
    return oss.str();
}

