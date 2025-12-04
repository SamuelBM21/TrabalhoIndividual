/**
 * @file SystemImpl.cpp
 * @brief Implementação da classe SystemImpl.
 *
 * Este arquivo contém a implementação da classe SystemImpl, responsável por
 * armazenar e manipular o valor interno de um System no simulador.
 *
 * SystemImpl fornece:
 *  - Construtores (padrão, parametrizado e cópia);
 *  - Operador de atribuição;
 *  - Métodos setValue() e getValue();
 *  - Regras básicas de consistência e encapsulamento.
 *
 * Esta classe é utilizada diretamente pelo Model e pelos Flows para compor
 * a dinâmica dos estoques durante a simulação baseada na Teoria Geral de
 * Sistemas.
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







