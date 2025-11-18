#include "System.h"

using namespace std;

System::System() : value(0.0) {}

System::System(double value) : value(value) {}

System::System(const System& other) : value(other.value) {}

System& System::operator=(const System& other) {
    if (this == &other) 
        return *this;
    name = other.name;
    value = other.value;
    return *this;
}

System::~System() {}

double System::getValue() const {
    return value;
}

bool System::setValue(double value){
    this->value = value;
    return true;
}
const string& System::getName() const {
    return name;
}

void System::setName(const string& n) {
    name = n;
}






