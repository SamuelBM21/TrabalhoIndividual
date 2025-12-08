/**
 * @file unit_Model.cpp
 * @brief Implementação dos testes unitários da classe ModelImpl.
 * @author Samuel
 * @date 2025
 */

#include <math.h>
#include <assert.h>
#include <iostream>

#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h" // Necessário para herdar FlowImpl
#include "unit_Model.h"

using namespace std;

// Classe auxiliar para teste de fluxo (Mock)
class ComplexTest : public FlowImpl {
public:
    ComplexTest() : FlowImpl() {}
    ComplexTest(System *source, System *target) : FlowImpl(source, target) {}

    double execute() {
        if (getSource())
            return (getSource()->getValue()) / 2;
        return 0.0;
    }
};

void unit_Model::unit_Model_constructor_default() {
    Model *model = Model::createModel();

    assert(model != nullptr); 
    assert(model->getClock() == 0);

    delete model;
}

void unit_Model::unit_Model_getClock() {
    Model *model = Model::createModel();
    assert(model->getClock() == 0);
    
    model->run(0, 1);
    assert(model->getClock() == 1);

    delete model;
}

void unit_Model::unit_Model_destructor() {
    Model *model = Model::createModel();
    delete model;
}

void unit_Model::unit_Model_removeSystem() {
    Model *model = Model::createModel();

    System *s1 = model->createSystem(10.0);
    
    assert(model->systemsBegin() != model->systemsEnd());

    bool result = model->remove(s1);
    assert(result == true);

    assert(model->systemsBegin() == model->systemsEnd());

    delete s1;
    delete model;
}

void unit_Model::unit_Model_removeFlow() {
    Model *model = Model::createModel();

    Flow *flow = model->createFlow<ComplexTest>();

    assert(model->flowsBegin() != model->flowsEnd());

    bool result = model->remove(flow);
    assert(result == true);

    assert(model->flowsBegin() == model->flowsEnd());

    delete flow;
    delete model;
}

void unit_Model::unit_Model_systemsBegin() {
    Model *model = Model::createModel();
    System *s1 = model->createSystem();
    System *s2 = model->createSystem();

    assert(*(model->systemsBegin()) == s1);
    assert(*(model->systemsBegin()) != s2);

    delete s1;
    delete s2;
    delete model;
}

void unit_Model::unit_Model_systemsEnd() {
    Model *model = Model::createModel();
    System *s1 = model->createSystem();
    System *s2 = model->createSystem();

    Model::iteratorSystem it = model->systemsEnd();
    it--;

    assert(*it == s2);
    assert(*it != s1);

    delete s1;
    delete s2;
    delete model;
}

void unit_Model::unit_Model_flowsBegin() {
    Model *model = Model::createModel();
    Flow *f1 = model->createFlow<ComplexTest>();
    Flow *f2 = model->createFlow<ComplexTest>();

    assert(*(model->flowsBegin()) == f1);
    assert(*(model->flowsBegin()) != f2);

    delete f1;
    delete f2;
    delete model;
}

void unit_Model::unit_Model_flowsEnd() {
    Model *model = Model::createModel();
    Flow *f1 = model->createFlow<ComplexTest>();
    Flow *f2 = model->createFlow<ComplexTest>();

    Model::iteratorFlow it = model->flowsEnd();
    it--;

    assert(*it == f2);
    assert(*it != f1);

    delete f1;
    delete f2;
    delete model;
}

void unit_Model::unit_Model_run() {
    
    Model *model = Model::createModel();

    System *system1 = model->createSystem(100.0);
    System *system2 = model->createSystem(0.0);

    Flow *flow = model->createFlow<ComplexTest>(system1, system2);

    model->run(0, 1);

    assert(model->getClock() == 1);
    assert(round(fabs(system1->getValue() - 50.0) < 0.0001));
    assert(round(fabs(system2->getValue() - 50.0) < 0.0001));

    delete flow;
    delete system1;
    delete system2;
    delete model;
}

void unit_Model::unit_Model_runUnitTests() {
    unit_Model_constructor_default();
    unit_Model_destructor(); 
    unit_Model_getClock();
    unit_Model_removeSystem();
    unit_Model_removeFlow();
    unit_Model_systemsBegin();
    unit_Model_systemsEnd();
    unit_Model_flowsBegin();
    unit_Model_flowsEnd();
    unit_Model_run();
}