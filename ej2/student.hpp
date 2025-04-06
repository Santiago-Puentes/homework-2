#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student {
    private:
        string fullName;
        int legajo;
        vector<pair<string,int>> courses;

    public:
        student(string name, int Legajo) : fullName(name), legajo(Legajo) {}
        
        bool operator<(const student& st) const;
        friend ostream& operator<<(ostream& os, const student& st) {
            os << "Name: " << st.fullName << ", Legajo: " << st.legajo;
            return os;
        }
        string getName();
        int getLegajo();
        float getPromedio();
};