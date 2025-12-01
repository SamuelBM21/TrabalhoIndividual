/**
 * @file System.cpp
 * @brief Implementação da classe System.
 *
 * Define os métodos responsáveis por armazenar e manipular o valor interno
 * de um sistema no simulador baseado na Teoria Geral de Sistemas. Esta classe
 * é utilizada pelo Model e pelos Flow para compor a dinâmica do sistema.
 *
 * @author Samuel
 * @date 2025
 */

#include "SystemImpl.h"

using namespace std;

SystemImpl::SystemImpl() : value(0.0) {}

SystemImpl::SystemImpl(double value) : value(value) {}

SystemImpl::SystemImpl(const System& other) : value(other.getValue()) {}

SystemImpl& SystemImpl::operator=(const System& other) {
    if (this == &other) 
        return *this;
    value = other.getValue();
    return *this;
}

SystemImpl::~SystemImpl() {}

double SystemImpl::getValue() const {
    return value;
}

bool SystemImpl::setValue(double value){
    this->value = value;
    return true;
}







