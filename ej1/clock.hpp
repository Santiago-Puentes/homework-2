#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    string period;

public:

    Time() : hours(0), minutes(0), seconds(0), period("a.m.") {}

    Time(int h) : hours(h % 12), minutes(0), seconds(0), period(h >= 12 ? "p.m." : "a.m.") {
        if (hours < 0) hours = 0;
    }

    Time(int h, int m) : hours(h % 12), minutes(m), seconds(0), period(h >= 12 ? "p.m." : "a.m.") {
        if (hours < 0) hours = 0;
        if (minutes < 0 || minutes >= 60) minutes = (minutes % 60 + 60) % 60; // Asegura que esté en [0, 59]
    }

    Time(int h, int m, int s) : hours(h % 12), minutes(m), seconds(s), period(h >= 12 ? "p.m." : "a.m.") {
        if (hours < 0) hours = 0;
        if (minutes < 0 || minutes >= 60) minutes = (minutes % 60 + 60) % 60;
        if (seconds < 0 || seconds >= 60) seconds = (seconds % 60 + 60) % 60;
    }

    Time(int h, int m, int s, const std::string& p) : hours(h % 12), minutes(m), seconds(s), period((p == "a.m." || p == "p.m.") ? p : "a.m.") {
        if (hours < 0) hours = 0;
        if (minutes < 0 || minutes >= 60) minutes = (minutes % 60 + 60) % 60;
        if (seconds < 0 || seconds >= 60) seconds = (seconds % 60 + 60) % 60;
    }

    // Imprimir formato normal y 24 horas
    void print() const;
    void print24HourFormat() const;

    // Cambiar hora/minutos/segundos/período por separado
    void setHours(int h);
    void setMinutes(int m);
    void setSeconds(int s);
    void setPeriod(const std::string& p);

    // Obtener hora/minutos/segundos/período por separado y en formato a.m./p.m. como strings   
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    string getPeriod() const;
    string getTime() const;
};