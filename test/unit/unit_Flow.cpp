#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_Flow.h"
#include "../../src/SystemImpl.h"

using namespace std;

class FlowTest : public FlowImpl {
    public:
        FlowTest():
            FlowImpl() {}
            
        FlowTest(System *source, System *target): 
            FlowImpl(source, target){}

        FlowTest(const Flow& flow): FlowImpl(flow){}
            
        double execute(){
            return (getSource()->getValue())/2;
        }
    
};

void unit_Flow_constructor_default(){

    Flow *flow = new FlowTest();

    assert(sizeof(*flow) > 0);
    assert(flow->getTarget() == NULL);
    assert(flow->getSource() == NULL);

    delete flow;   
}

void unit_Flow_constructor_with_source_target(){

    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    Flow *flow = new FlowTest(system1, system2);

    assert(flow->getSource() == system1);
    assert(flow->getTarget() == system2);

    delete system1;
    delete system2;
    delete flow;

}


void unit_Flow_copy_constructor(){
    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    Flow *flow1 = new FlowTest(system1, system2);
    Flow *flow2 = new FlowTest(*flow1);

    assert(flow1->getSource() == flow2->getSource());
    assert(flow1->getTarget() == flow2->getTarget());


    delete system1;
    delete system2;
    delete flow1;
    delete flow2;
}


void unit_Flow_destructor(){}

/* void unit_Flow_getValue(){

    Flow *flow = new FlowTest();
    flow->setValue(100.0);

    assert(flow->getValue() == 100.0);

    delete flow;
}


void unit_Flow_setValue(){

    Flow *flow = new FlowTest();
    flow->setValue(100.0);
    
    Flow *flow2 = new FlowTest(*flow);
    flow2->setValue(0.0);

    assert(flow2->getValue() == 0.0);

    delete flow;

} */

void unit_Flow_getSource(){

    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    Flow *flow = new FlowTest(system1, system2);

    assert(flow->getSource() == system1);

    delete system1;
    delete system2;
    delete flow;

}


void unit_Flow_setSource(){

    System *system1 = new SystemImpl();

    Flow *flow = new FlowTest();
    flow->setSource(system1);

    assert(flow->getSource() == system1);

    delete system1;
    delete flow;

}


void unit_Flow_getTarget(){

    System *system1 = new SystemImpl();
    System *system2 = new SystemImpl();

    Flow *flow = new FlowTest(system1, system2);

    assert(flow->getTarget() == system2);

    delete system1;
    delete system2;
    delete flow;
}


void unit_Flow_setTarget(){
    System *system1 = new SystemImpl();

    Flow *flow = new FlowTest();
    flow->setTarget(system1);

    assert(flow->getTarget() == system1);

    delete system1;
    delete flow;

}
