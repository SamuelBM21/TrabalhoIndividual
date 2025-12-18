/**
 * @file unit_Model.cpp
 * @brief Testes unitários do Model (White-Box) com Handle-Body.
 */

#include <math.h>
#include <assert.h>
#include <algorithm>

#include "../../src/include/ModelImpl.h"
#include "../../src/include/SystemImpl.h"
#include "../../src/include/FlowImpl.h"
#include "unit_Model.h"

using namespace std;

// Mock para teste de Flow dentro do modelo
class FlowMock : public FlowHandle {
public:
    FlowMock(System* s, System* t) : FlowHandle(s,t) {}
    double execute() override { return 1.0; }
};

void unit_Model::unit_Model_constructor_default() {
    ModelHandle *model = new ModelHandle();

    // Acessa Body para verificar containers vazios e relógio
    assert(model->pImpl_->systems.empty());
    assert(model->pImpl_->flows.empty());
    assert(model->pImpl_->clock == 0);

    delete model; 
}

void unit_Model::unit_Model_getClock() {
    ModelHandle *model = new ModelHandle();
    model->pImpl_->clock = 42; // Seta diretamente no Body
    
    assert(model->getClock() == 42); // Verifica getter

    delete model; 
}

void unit_Model::unit_Model_destructor() {
    ModelHandle *model = new ModelHandle();
    delete model;
}

void unit_Model::unit_Model_createSystem() {
    ModelHandle *model = new ModelHandle();

    model->createSystem(10.0);

    // Verifica tamanho do vetor no Body
    assert(model->pImpl_->systems.size() == 1);
    // Verifica valor do sistema criado
    assert(model->pImpl_->systems[0]->getValue() == 10.0);

    delete model;
}

void unit_Model::unit_Model_createFlow() {
    ModelHandle *model = new ModelHandle();
    System *s1 = model->createSystem(100.0);
    System *s2 = model->createSystem(0.0);

    // Adiciona fluxo manualmente ou via create se houver template method suportado
    Flow *f = new FlowMock(s1, s2);
    model->add(f);

    assert(model->pImpl_->flows.size() == 1);
    assert(model->pImpl_->flows[0] == f);

    delete model;
}

void unit_Model::unit_Model_removeSystem() {
    ModelHandle *model = new ModelHandle();
    System *s1 = model->createSystem(10.0);
    
    assert(model->pImpl_->systems.size() == 1);

    model->remove(s1);

    assert(model->pImpl_->systems.size() == 0);

    delete s1; 
    delete model;
}

void unit_Model::unit_Model_removeFlow() {
    ModelHandle *model = new ModelHandle();
    System *s1 = model->createSystem();
    System *s2 = model->createSystem();
    Flow *f = new FlowMock(s1, s2);
    
    model->add(f);
    assert(model->pImpl_->flows.size() == 1);

    model->remove(f);
    assert(model->pImpl_->flows.size() == 0);

    delete f;
    delete model;
}

void unit_Model::unit_Model_systemsBegin() {
    ModelHandle *model = new ModelHandle();
    model->createSystem();

    // Compara iterator retornado com iterator do vetor interno
    assert(model->systemsBegin() == model->pImpl_->systems.begin());

    delete model;
}

void unit_Model::unit_Model_systemsEnd() {
    ModelHandle *model = new ModelHandle();
    model->createSystem();

    assert(model->systemsEnd() == model->pImpl_->systems.end());

    delete model;
}

void unit_Model::unit_Model_flowsBegin() {
    ModelHandle *model = new ModelHandle();
    // Flow *f = ... (adicionar fluxo)
    assert(model->flowsBegin() == model->pImpl_->flows.begin());
    delete model;
}

void unit_Model::unit_Model_flowsEnd() {
    ModelHandle *model = new ModelHandle();
    assert(model->flowsEnd() == model->pImpl_->flows.end());
    delete model;
}

void unit_Model::unit_Model_run() {
    ModelHandle *model = new ModelHandle();
    System *s1 = model->createSystem(100.0);
    System *s2 = model->createSystem(0.0);
    Flow *f = new FlowMock(s1, s2);
    model->add(f);

    // Executa por 1 passo
    model->run(0, 1);

    // Verifica relógio interno
    assert(model->pImpl_->clock == 1);
    
    // Verifica resultado da execução nos sistemas (depende da lógica do FlowMock)
    // FlowMock retorna 1.0, então s1=99, s2=1
    assert(fabs(s1->getValue() - 99.0) < 0.0001);

    delete model;
}

void unit_Model::unit_Model_runUnitTests() {
    unit_Model_constructor_default();
    unit_Model_destructor(); 
    unit_Model_getClock();
    unit_Model_createSystem();
    unit_Model_createFlow();
    unit_Model_removeSystem();
    unit_Model_removeFlow();
    unit_Model_systemsBegin();
    unit_Model_systemsEnd();
    unit_Model_flowsBegin();
    unit_Model_flowsEnd();
    unit_Model_run();
}