/*
    @file ModelImpl.cpp
    @brief Implementação das classes ModelBody e ModelHandle utilizando o padrão Handle/Body.
*/
#include "../include/ModelImpl.h"
#include "../include/SystemImpl.h" 
#include "../include/FlowImpl.h"
#include <algorithm>

using namespace std;


ModelBody::ModelBody() : clock(0) {}

ModelBody::~ModelBody() {
    // Limpa a memória dos componentes se o Model for o dono deles
    for (System* s : systems) delete s;
    for (Flow* f : flows) delete f;
    systems.clear();
    flows.clear();
}

void ModelBody::add(System* s) {
    systems.push_back(s);
}

void ModelBody::add(Flow* f) {
    flows.push_back(f);
}

ModelBody::iteratorSystem ModelBody::systemsBegin() { return systems.begin(); }
ModelBody::iteratorSystem ModelBody::systemsEnd() { return systems.end(); }
ModelBody::iteratorFlow ModelBody::flowsBegin() { return flows.begin(); }
ModelBody::iteratorFlow ModelBody::flowsEnd() { return flows.end(); }

void ModelBody::run(int start, int end) {
    for (int time = start; time < end; time++) {
        clock = time;
        vector<double> results;

        // Fase 1: Execução (cálculo)
        for (Flow* f : flows) {
            results.push_back(f->execute());
        }

        // Fase 2: Atualização
        int i = 0;
        for (Flow* f : flows) {
            double val = results[i];
            if (f->getSource()) {
                f->getSource()->setValue(f->getSource()->getValue() - val);
            }
            if (f->getTarget()) {
                f->getTarget()->setValue(f->getTarget()->getValue() + val);
            }
            i++;
        }
    }
    clock = end; // Ajusta relógio final
}

// --- Implementação do ModelHandle ---

ModelHandle::ModelHandle() {
    // Body criado automaticamente
}

ModelHandle::~ModelHandle() {}

Model* ModelHandle::createModel() {
    return new ModelHandle();
}

System* ModelHandle::createSystem(double value) {
    // IMPORTANTE: Criamos um SystemHandle aqui para manter o padrão
    System* s = new SystemHandle(value);
    add(s);
    return s;
}

bool ModelHandle::add(System* s) {
    pImpl_->add(s);
    return true;
}

bool ModelHandle::add(Flow* f) {
    pImpl_->add(f);
    return true;
}

int ModelHandle::getClock() const {
    return pImpl_->clock;
}

bool ModelHandle::run(int startTime, int endTime) {
    pImpl_->run(startTime, endTime);
    return true;
}

bool ModelHandle::remove(System* s) {
    auto& sysVec = pImpl_->systems;
    auto it = std::find(sysVec.begin(), sysVec.end(), s);
    if (it != sysVec.end()) {
        sysVec.erase(it);
        return true;
    }
    return false;
}

bool ModelHandle::remove(Flow* f) {
    auto& flowVec = pImpl_->flows;
    auto it = std::find(flowVec.begin(), flowVec.end(), f);
    if (it != flowVec.end()) {
        flowVec.erase(it);
        return true;
    }
    return false;
}

Model::iteratorSystem ModelHandle::systemsBegin() const {
    return pImpl_->systemsBegin();
}

Model::iteratorSystem ModelHandle::systemsEnd() const {
    return pImpl_->systemsEnd();
}

Model::iteratorFlow ModelHandle::flowsBegin() const {
    return pImpl_->flowsBegin();
}

Model::iteratorFlow ModelHandle::flowsEnd() const {
    return pImpl_->flowsEnd();
}

Model* Model::createModel() {
    return ModelHandle::createModel();
}