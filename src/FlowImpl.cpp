/**
 * @file FlowImpl.cpp
 * @brief Implementação parcial da classe Flow.
 *
 * Este arquivo contém a implementação da classe FlowImpl, que fornece a
 * infraestrutura básica para representar um fluxo entre dois Systems.
 * 
 * FlowImpl implementa:
 *  - Construtores (padrão, parametrizado e cópia);
 *  - Operador de atribuição;
 *  - Métodos de acesso e modificação de source e target.
 *
 * O método execute() permanece abstrato, pois cada fluxo concreto deve
 * definir sua própria equação matemática.
 *
 * FlowImpl é usada como classe base para fluxos específicos utilizados pelo
 * Model durante a simulação.
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

FlowImpl& FlowImpl::operator= (const Flow &flow){

    if(this == &flow)
        return *this;

    source = flow.getSource();
    target = flow.getTarget();

    return *this;
}
