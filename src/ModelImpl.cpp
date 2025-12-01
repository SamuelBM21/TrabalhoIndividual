/**
 * @file Model.cpp
 * @brief Implementação da classe Model.
 *
 * O Model gerencia os sistemas e fluxos que compõem o simulador baseado na
 * Teoria Geral de Sistemas. Ele armazena coleções de Systems e Flows, além
 * de controlar a execução temporal da simulação.
 *
 * Este arquivo contém a implementação das funções que manipulam a estrutura
 * interna do modelo, adicionam/removem elementos e executam o ciclo principal
 * de simulação.
 *
 * @author Samuel
 * @date 2025
 */

#include "ModelImpl.h"
#include <algorithm> 

using namespace std;

ModelImpl::ModelImpl() : systems(), flows() {}

ModelImpl::~ModelImpl() {
}

int ModelImpl::getClock() {
    return clock;
}

ModelImpl::ModelImpl(const Model& other) {
    for(auto it = other.systemsBegin(); it != other.systemsEnd(); ++it){
        this->add(*it);
    }

    for(auto it = other.flowsBegin(); it != other.flowsEnd(); ++it){
        this->add(*it);
    }
}

ModelImpl& ModelImpl::operator=(const Model& other) {
    if (this == &other)
        return *this;

    for(auto it = other.systemsBegin(); it != other.systemsEnd(); ++it){
        this->add(*it);
    }

    for(auto it = other.flowsBegin(); it != other.flowsEnd(); ++it){
        this->add(*it);
    }

    return *this;
}

ModelImpl::iteratorSystem ModelImpl::systemsBegin() const { 
    return systems.begin(); 
}

ModelImpl::iteratorSystem ModelImpl::systemsEnd() const { 
    return systems.end(); 
}

ModelImpl::iteratorFlow ModelImpl::flowsBegin() const { 
    return flows.begin(); 
}

ModelImpl::iteratorFlow ModelImpl::flowsEnd() const { 
    return flows.end(); 
}

bool ModelImpl::add(System* s) {
    systems.push_back(s);
    return true;
}

bool ModelImpl::add(Flow* f) {
    flows.push_back(f);
    return true;
}

bool ModelImpl::remove(System* s) {
    auto it = find(systems.begin(), systems.end(), s);
    if (it != systems.end()) {
        systems.erase(it);
        return true;
    }
    return false;
}

bool ModelImpl::remove(Flow* f) {
    auto it = find(flows.begin(), flows.end(), f);
    if (it != flows.end()) {
        flows.erase(it);
        return true;
    }
    return false;
}

bool ModelImpl::run(int startTime, int endTime) {
    for (int time = startTime; time < endTime; time++) {

        int n = flows.size();
        vector<double> results(n);

        for (int i = 0; i < n; i++)
            results[i] = flows[i]->execute();

        for (int i = 0; i < n; i++) {
            Flow* f = flows[i];

            if (f->getSource())
                f->getSource()->setValue(f->getSource()->getValue() - results[i]);

            if (f->getTarget())
                f->getTarget()->setValue(f->getTarget()->getValue() + results[i]);
        }
    }
    return true;
}