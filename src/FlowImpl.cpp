/**
 * @file Flow.cpp
 * @brief Implementação da classe Flow.
 *
 * Implementa a infraestrutura básica para representar um fluxo entre dois
 * sistemas no simulador. Classes derivadas devem sobrescrever execute() para
 * definir o comportamento específico do fluxo.
 *
 * O Flow é utilizado pelo Model para simular o comportamento dinâmico de um
 * sistema de acordo com a Teoria Geral de Sistemas.
 *
 * @author Samuel
 * @date 2025
 */

#include "FlowImpl.h"

using namespace std;

FlowImpl::FlowImpl() : source(nullptr), target(nullptr) {}

FlowImpl::FlowImpl( System* source, System* target)
    :source(source), target(target) {}

FlowImpl::~FlowImpl(){};

FlowImpl::FlowImpl(const Flow &flow){
    if(this == &flow) return;
    source = flow.getSource();
    target = flow.getTarget();
}

// Source / Target
bool FlowImpl::setSource(System* s) {
    source = s;
    return true;
}

System* FlowImpl::getSource() const {
    return source;
}

bool FlowImpl::setTarget(System* t) {
    target = t;
    return true;
}

System* FlowImpl::getTarget() const {
    return target;
}

Flow& FlowImpl::operator= (const Flow &flow){

    if(this == &flow)
        return *this;

    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
