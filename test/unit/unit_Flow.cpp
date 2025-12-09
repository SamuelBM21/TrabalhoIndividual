/**
 * @file unit_Flow.cpp
 * @brief Implementação dos testes unitários da classe FlowImpl.
 *
 * Cada função aqui valida um aspecto específico do comportamento de FlowImpl,
 * garantindo que construtores, métodos de acesso, modificadores e operadores
 * funcionem corretamente.
 *
 * @author Samuel
 * @date 2025
 */

#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_Flow.h"
#include "../../src/SystemImpl.h"

using namespace std;

class TestFlow : public FlowImpl {
    public:
        TestFlow():
            FlowImpl() {}
            
        TestFlow(System *source, System *target): 
            FlowImpl(source, target){}

        TestFlow(const Flow& flow): FlowImpl(flow){}
            
        double execute(){
            return (getSource()->getValue())/2;
        }
    
};

void unit_Flow :: unit_Flow_constructor_default(){

    TestFlow flow;

    assert(flow.target == NULL);
    assert(flow.source == NULL);
  
}

void unit_Flow :: unit_Flow_constructor_with_source_target(){

    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    TestFlow *flow = new TestFlow(system1, system2);

    assert(flow->source == system1);
    assert(flow->target == system2);

    delete system1;
    delete system2;
    delete flow;

}


void unit_Flow :: unit_Flow_copy_constructor(){
    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    FlowImpl *flow1 = new TestFlow(system1, system2);
    FlowImpl *flow2 = new TestFlow(*flow1);

    assert(flow1->source == flow2->source);
    assert(flow1->target == flow2->target);

    assert(flow1 != flow2);

    delete system1;
    delete system2;
    delete flow1;
    delete flow2;
}


void unit_Flow :: unit_Flow_destructor(){}

void unit_Flow :: unit_Flow_getSource(){

    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    TestFlow flow;
    flow.source = system1;
    assert(flow.getSource() == system1);

    delete system1;
    delete system2;

}


void unit_Flow :: unit_Flow_setSource(){

    System *system1 = new SystemImpl();

    TestFlow flow;
    flow.setSource(system1);

    assert(flow.source == system1);

    delete system1;
}


void unit_Flow :: unit_Flow_getTarget(){
    System *system2 = new SystemImpl();

    TestFlow flow;
    flow.target = system2;
    assert(flow.getTarget() == system2);

    delete system2;
}


void unit_Flow :: unit_Flow_setTarget(){
    System *system1 = new SystemImpl();

    TestFlow flow;
    flow.setTarget(system1);

    assert(flow.target == system1);

    delete system1;
}

void unit_Flow :: unit_Flow_execute(){

    System *system1 = new SystemImpl(100.0);
    System *system2 = new SystemImpl();

    FlowImpl *flow = new TestFlow(system1, system2);

    double result = flow->execute();

    assert(round(fabs(result - 50.0)*10000) < 1);

    delete system1;
    delete system2;
    delete flow;

}

void unit_Flow :: unit_Flow_runUnitTests(){
    unit_Flow_constructor_default();
    unit_Flow_constructor_with_source_target();
    unit_Flow_copy_constructor();
    unit_Flow_destructor();
    unit_Flow_getSource();
    unit_Flow_setSource();
    unit_Flow_getTarget();
    unit_Flow_setTarget();
    unit_Flow_execute();
}