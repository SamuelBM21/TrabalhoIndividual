/*
    @file SystemImpl.cpp
    @brief Implementação das classes SystemBody e SystemHandle utilizando o padrão Handle/Body.
*/

#include "../include/SystemImpl.h"

SystemBody::SystemBody(double v) : value(v) {}

SystemBody::~SystemBody() {}

void SystemBody::setValue(double v) {
    value = v;
}

double SystemBody::getValue() const {
    return value;
}

// --- Implementação do SystemHandle ---

SystemHandle::SystemHandle() {
    // O template Handle<T> cria automaticamente o Body padrão
}

SystemHandle::SystemHandle(double value) {
    // Como o construtor do Handle<T> cria um Body padrão, 
    // precisamos descartá-lo para criar um com o valor desejado.
    pImpl_->detach();
    pImpl_ = new SystemBody(value);
    pImpl_->attach();
}

SystemHandle::~SystemHandle() {}

bool SystemHandle::setValue(double v) {
    pImpl_->setValue(v);
    return true;
}

double SystemHandle::getValue() const {
    return pImpl_->getValue();
}