/**
 * @file unit_Flow.cpp
 * @brief Testes unitários do Flow (White-Box) com Handle-Body.
 */

#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_Flow.h"
#include "../../src/include/SystemImpl.h"
#include "../../src/include/FlowImpl.h"

using namespace std;

// Classe Mock para poder instanciar o FlowHandle abstrato
class FlowHandleMock : public FlowHandle {
public:
    FlowHandleMock() : FlowHandle() {}
    FlowHandleMock(System* s, System* t) : FlowHandle(s, t) {}
    double execute() override { return 0.0; }
};

void unit_Flow::unit_Flow_constructor_default(){
    FlowHandleMock flow;
    
    // Verifica se o Body foi criado e ponteiros estão nulos
    assert(flow.pImpl_->source == nullptr);
    assert(flow.pImpl_->target == nullptr);
}

void unit_Flow::unit_Flow_constructor_with_source_target(){
    SystemHandle *system1 = new SystemHandle();
    SystemHandle *system2 = new SystemHandle();

    FlowHandleMock *flow = new FlowHandleMock(system1, system2);

    // Verifica acessando diretamente o Body
    assert(flow->pImpl_->source == system1);
    assert(flow->pImpl_->target == system2);

    delete system1;
    delete system2;
    delete flow;
}

void unit_Flow::unit_Flow_copy_constructor(){
    SystemHandle *system1 = new SystemHandle();
    SystemHandle *system2 = new SystemHandle();

    FlowHandleMock *flow1 = new FlowHandleMock(system1, system2);
    FlowHandleMock *flow2 = new FlowHandleMock(*flow1);

    // Verifica se compartilham o mesmo Body (Handle Copy Semantics)
    assert(flow1->pImpl_ == flow2->pImpl_);
    assert(flow2->pImpl_->source == system1);

    delete system1;
    delete system2;
    delete flow1;
    delete flow2;
}

void unit_Flow::unit_Flow_destructor(){}

void unit_Flow::unit_Flow_getSource(){
    SystemHandle *system1 = new SystemHandle();
    FlowHandleMock flow;
    
    flow.setSource(system1);
    
    // Compara o retorno do get com o atributo interno do Body
    assert(flow.getSource() == flow.pImpl_->source);
    
    delete system1;
}

void unit_Flow::unit_Flow_setSource(){
    SystemHandle *system1 = new SystemHandle();
    FlowHandleMock flow;
    
    flow.setSource(system1);
    
    // Verifica atributo interno
    assert(flow.pImpl_->source == system1);

    delete system1;
}

void unit_Flow::unit_Flow_getTarget(){
    SystemHandle *system2 = new SystemHandle();
    FlowHandleMock flow;
    
    flow.setTarget(system2);
    assert(flow.getTarget() == flow.pImpl_->target);

    delete system2;
}

void unit_Flow::unit_Flow_setTarget(){
    SystemHandle *system1 = new SystemHandle();
    FlowHandleMock flow;
    
    flow.setTarget(system1);
    assert(flow.pImpl_->target == system1);

    delete system1;
}

void unit_Flow::unit_Flow_execute(){
    SystemHandle *s1 = new SystemHandle(100);
    SystemHandle *s2 = new SystemHandle(0);
    FlowHandleMock flow(s1, s2);
    
    assert(flow.pImpl_->source->getValue() == 100);
    
    delete s1; delete s2;
}

void unit_Flow::unit_Flow_runUnitTests(){
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