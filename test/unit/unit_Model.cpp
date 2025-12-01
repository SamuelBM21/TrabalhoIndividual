#include <iostream>
#include <math.h>
#include <assert.h>

#include "unit_Model.h"
#include "../../src/ModelImpl.h"
#include "../../src/SystemImpl.h"
#include "../../src/FlowImpl.h"

using namespace std;

class FlowTest : public FlowImpl {
    public:
        FlowTest():
            FlowImpl() {}
            
        FlowTest(System *source, System *target): 
            FlowImpl(source, target){}

        FlowTest(const Flow& flow): FlowImpl(flow) {}
            
        double execute(){
            return (getSource()->getValue())/2;
        }
    
};

void unit_Model_constructor_default(){


    Model *model = new ModelImpl();
    assert(sizeof(*model) > 0);

    delete model;
}


void unit_Model_destructor(){}

void unit_Model_removeSystem(){

    Model *model = new ModelImpl();
    System *system = new SystemImpl();
    model->add(system);

    assert(*(model->systemsBegin()) == system); 

    model->remove(system);
    assert(*(model->systemsBegin()) == NULL); 

    delete system;
    delete model;
}

void unit_Model_removeFlow(){

    Model *model = new ModelImpl();

    Flow *flow = new FlowTest();
    model->add(flow);

    assert(*(model->flowsBegin()) == flow);

    model->remove(flow);
    assert(*(model->flowsBegin()) == NULL);

    delete flow;
    delete model;

}
// /*
void unit_Model_run(){

    ModelImpl *model = new ModelImpl();

    int startTime = 0;
    int endTime = 100;

    model->run(startTime, endTime);

    assert(model->getClock() == (endTime - startTime));

    delete model;
}
// */

void unit_Model_systemsBegin(){

    Model *model = new ModelImpl();

    System *system = new SystemImpl();
    System *system2 = new SystemImpl();

    model->add(system);
    model->add(system2);

    assert(*(model->systemsBegin()) != system2); 
    assert(*(model->systemsBegin()) == system); 

    delete system;
    delete system2;
    delete model;
}

void unit_Model_systemsEnd(){

    Model *model = new ModelImpl();

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

void unit_Model_flowsBegin(){

    Model *model = new ModelImpl();

    Flow *flow = new FlowTest();
    Flow *flow2 = new FlowTest();

    model->add(flow);
    model->add(flow2);

    assert(*(model->flowsBegin()) != flow2); 
    assert(*(model->flowsBegin()) == flow); 

    delete flow;
    delete flow2;
    delete model;
}
void unit_Model_flowsEnd(){

    Model *model = new ModelImpl();

    Flow *flow = new FlowTest();
    Flow *flow2 = new FlowTest();

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

void unit_Model_assignOverload();

