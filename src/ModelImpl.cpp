/**
 * @file ModelImpl.cpp
 * @brief Implementação da classe ModelImpl.
 *
 * Este arquivo contém a implementação da estrutura principal do simulador:
 * a classe ModelImpl. Ela gerencia coleções de Systems e Flows, controla
 * a evolução temporal da simulação e coordena a execução dos fluxos.
 *
 * Entre as responsabilidades implementadas aqui estão:
 *  - Armazenar e organizar Systems e Flows;
 *  - Realizar o loop de simulação passo a passo;
 *  - Garantir que os fluxos sejam aplicados corretamente;
 *  - Manter consistência e gerenciamento de memória.
 *
 * ModelImpl constitui o núcleo coordenador da Teoria Geral de Sistemas
 * dentro deste software, realizando a integração entre suas entidades.
 *
 * @author Samuel
 * @date 2025
 */


#include "ModelImpl.h"
#include "SystemImpl.h"
#include <algorithm> 

using namespace std;

vector<Model*> ModelImpl::models;

ModelImpl::ModelImpl() : systems(), flows() {}

ModelImpl::~ModelImpl() {
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

int ModelImpl :: getClock() const {
    return clock;
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

Model* ModelImpl::createModel(){
    Model* model = new ModelImpl();
    add(model); 
    return model;
}

Model* Model::createModel(){
    return ModelImpl::createModel();
}


System* ModelImpl::createSystem(double value){
    System* system = new SystemImpl(value);
    add(system);
    return system;
}


bool ModelImpl::add(System* s) {
    systems.push_back(s);
    return true;
}

bool ModelImpl::add(Flow* f) {
    flows.push_back(f);
    return true;
}

bool ModelImpl::add(Model* m) {
    models.push_back(m);
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
        clock = time;
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
    clock++;
    return true;
}