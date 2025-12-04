/**
 * @file unit_Model.cpp
 * @brief Implementação dos testes unitários da classe ModelImpl.
 *
 * Cada função aqui valida um aspecto específico do comportamento de ModelImpl,
 * garantindo que construtores, métodos de acesso, modificadores e operadores
 * funcionem corretamente.
 *
 * @author Samuel
 * @date 2025
 */

#include <math.h>
#include <assert.h>

#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "unit_Model.h"

using namespace std;

class ComplexTest : public FlowImpl {
    public:
        ComplexTest():
            FlowImpl() {}
            
        ComplexTest(System *source, System *target): 
            FlowImpl(source, target){}

        ComplexTest(const Flow& flow): FlowImpl(flow) {}
            
        double execute(){
            return (getSource()->getValue())/2;
        }
    
};

void unit_Model :: unit_Model_constructor_default(){

    ModelImpl *model = new ModelImpl();
    assert(sizeof(*model) > 0);
    assert(model->clock == 0);
    assert(model->flows.size() == 0);
    assert(model->systems.size() == 0);
    delete model;
}

void unit_Model :: unit_Model_getClock(){
    ModelImpl *model = new ModelImpl();

    assert(model->getClock() == 0);

    delete model;
}

void unit_Model :: unit_Model_destructor(){}

void unit_Model :: unit_Model_removeSystem(){

    ModelImpl *model = new ModelImpl();
    System *system = new SystemImpl();
    model->add(system);

    assert(model->systems.size() == 1); 

    model->remove(system);
    assert(model->systems.size() == 0); 

    delete system;
    delete model;
}

void unit_Model :: unit_Model_removeFlow(){

    ModelImpl *model = new ModelImpl();
    Flow *flow = new ComplexTest();
    model->add(flow);

    assert(model->flows.size() == 1);

    model->remove(flow);
    assert(model->flows.size() == 0);

    delete flow;
    delete model;
}

void unit_Model :: unit_Model_systemsBegin(){

    ModelImpl *model = new ModelImpl();

    System *system = new SystemImpl();
    System *system2 = new SystemImpl();

    model->add(system);
    model->add(system2);

    assert(*(model->systemsBegin()) == system);
    assert(*(model->systemsBegin()) != system2);

    delete system;
    delete system2;
    delete model;
}

void unit_Model :: unit_Model_systemsEnd(){

    ModelImpl *model = new ModelImpl();

    System *system = new SystemImpl();
    System *system2 = new SystemImpl();

    model->add(system);
    model->add(system2);

    Model::iteratorSystem it = model->systemsEnd();

    it--;

    assert(*it == system2); 
    assert(*it != system); 

    delete system;
    delete system2;
    delete model;
}

void unit_Model :: unit_Model_flowsBegin(){

    Model *model = new ModelImpl();

    Flow *flow = new ComplexTest();
    Flow *flow2 = new ComplexTest();

    model->add(flow);
    model->add(flow2);

    assert(*(model->flowsBegin()) != flow2); 
    assert(*(model->flowsBegin()) == flow); 

    delete flow;
    delete flow2;
    delete model;
}
void unit_Model :: unit_Model_flowsEnd(){

    Model *model = new ModelImpl();

    Flow *flow = new ComplexTest();
    Flow *flow2 = new ComplexTest();

    model->add(flow);
    model->add(flow2);

    Model::iteratorFlow it = model->flowsEnd();

    it--;
    assert(*it == flow2); 
    assert(*it != flow);

    delete flow;
    delete flow2;
    delete model;
}

void unit_Model :: unit_Model_run(){

    ModelImpl *model = new ModelImpl();

    System *system1 = new SystemImpl(100.0);
    System *system2 = new SystemImpl(0.0);

    Flow *flow = new ComplexTest(system1, system2);

    model->add(system1);
    model->add(system2);
    model->add(flow);

    model->run(0,1);

    assert(model->clock == 1);
    assert(fabs(system1->getValue() - 50.0) < 0.0001);
    assert(fabs(system2->getValue() - 50.0) < 0.0001);

    delete flow;
    delete system1;
    delete system2;
    delete model;
}
void unit_Model :: unit_Model_runUnitTests(){
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
