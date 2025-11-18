#include "funcional_tests.h"
#include "../../src/Model.h"

#include <math.h>
#include <assert.h>

using namespace std;

class testFlow : public Flow {
    public:
        testFlow(): Flow() {}
            
        testFlow(string& name, System *source, System *target): Flow(name, source, target) {}
            
        double execute(){
            return 0;
        }
};

void onlyOneSystem() {
    cout << "\n===== OnlyOneSystem =====\n";
    
    Model *model = new Model;
    System *pop1 = new System(0.0);
    model->add(pop1);

    assert(model->getSystems().size() == 1);
    assert(model->getSystems()[0] == pop1);

    cout << "OK\n" << endl;
    delete model;
}

void onlyOneFlow() {
    cout << "\n===== OnlyOneFlow =====\n";
    
    Model *model = new Model;
    testFlow *flow = new testFlow();
    model->add(flow);

    assert(model->getFlows().size() == 1);
    assert(model->getFlows()[0] == flow);

    cout << "OK\n" << endl;
    delete model;
}

void flowWithSourceWithoutTarget() {
    cout << "\n===== FlowWithSourceWithoutTarget =====\n";
    
    Model *model = new Model;
    System *pop1 = new System(0.0);
    
    testFlow *flow = new testFlow();
    flow->setSource(pop1);

    model->add(pop1);
    model->add(flow);
    
    assert(model->getFlows()[0]->getSource() == pop1);
    assert(flow->getSource() == pop1);

    cout << "OK\n" << endl;
}

void flowWithoutSourceWithTarget() {
    cout << "\n===== FlowWithoutSourceWithTarget =====\n";
    
    Model *model = new Model;
    System *pop1 = new System(0.0);
    
    testFlow *flow = new testFlow();
    flow->setTarget(pop1);

    model->add(pop1);
    model->add(flow);
    
    assert(model->getFlows()[0]->getTarget() == pop1);
    assert(flow->getTarget() == pop1);

    cout << "OK\n" << endl;
    delete model;
}

void flowWithSourceWithTarget() {
    cout << "\n===== FlowWithSourceWithTarget =====\n";
    
    Model *model = new Model;
    System *pop1 = new System(0.0);
    System *pop2 = new System(0.0);
    
    testFlow *flow = new testFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);
    
    assert(model->getFlows()[0]->getSource() == pop1);
    assert(model->getFlows()[0]->getTarget() == pop2);
    assert(flow->getSource() == pop1);
    assert(flow->getTarget() == pop2);

    cout << "OK\n" << endl;
    delete model;
}

class ExponentialFlow : public Flow {
    public:
        ExponentialFlow(): Flow() {}
            
        ExponentialFlow(string& name, System *source, System *target): Flow(name,source, target) {}
            
        double execute(){
            return 0.01 * getSource()->getValue();
        }
};


void exponentialFuncionalTest(){
    cout << "===== ExponentialFuncionalTest =====\n";

    Model *model = new Model;

    System *pop1 = new System(100.0);
    System *pop2 = new System(0.0);

    ExponentialFlow *flow = new ExponentialFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);

    model->run(0, 10);

    assert(fabs(pop1->getValue() - 90.4382) < 0.0001);
    assert(fabs(pop2->getValue() - 9.5617) < 0.0001);

    pop1->setValue(100.0);
    pop2->setValue(0.0);

    model->run(0, 100);
    
    assert(fabs(pop1->getValue() - 36.6032) < 0.0001);
    assert(fabs(pop2->getValue() - 63.3968) < 0.0001);

    cout << "OK\n" << endl;
    delete model;
}

class logisticFlow : public Flow {
    public:
        logisticFlow(): Flow() {}
            
        logisticFlow(string& name, System *source, System *target): Flow(name ,source, target) {}
            
        double execute(){
            return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue()/70.0));
        }
};

void logisticalFuncionalTest(){
    cout << "===== LogisticalFuncionalTest =====\n";

    Model *model = new Model;

    System *pop1 = new System(100.0);
    System *pop2 = new System(10.0);

    logisticFlow *flow = new logisticFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);

    model->run(0, 100);
    assert(fabs(pop1->getValue() - 88.2167) < 0.0001);
    assert(fabs(pop2->getValue() - 21.7833) < 0.0001);

    cout << "OK\n" << endl;
    delete model;
}


void complexFuncionalTest(){
    cout << "===== ComplexFuncionalTest =====\n";

    Model *model = new Model;

    System *pop1 = new System(100.0);
    System *pop2 = new System(0.0);
    System *pop3 = new System(100.0);
    System *pop4 = new System(0.0);
    System *pop5 = new System(0.0);
    
    ExponentialFlow *flow1 = new ExponentialFlow();
    flow1->setSource(pop1);
    flow1->setTarget(pop2);

    ExponentialFlow *flow2 = new ExponentialFlow();
    flow2->setSource(pop1);
    flow2->setTarget(pop3);
    
    ExponentialFlow *flow3 = new ExponentialFlow();
    flow3->setSource(pop2);
    flow3->setTarget(pop5);

    ExponentialFlow *flow4 = new ExponentialFlow();
    flow4->setSource(pop2);
    flow4->setTarget(pop3);
    
    ExponentialFlow *flow5 = new ExponentialFlow();
    flow5->setSource(pop3);
    flow5->setTarget(pop4);

    ExponentialFlow *flow6 = new ExponentialFlow();
    flow6->setSource(pop4);
    flow6->setTarget(pop1);

    model->add(pop1);
    model->add(pop2);
    model->add(pop3);
    model->add(pop4);
    model->add(pop5);
    model->add(flow1);
    model->add(flow2);
    model->add(flow3);
    model->add(flow4);
    model->add(flow5);
    model->add(flow6);

    model->run(0, 100);
    assert(fabs(pop1->getValue() - 31.8513) < 0.0001);
    assert(fabs(pop2->getValue() - 18.4003) < 0.0001);
    assert(fabs(pop3->getValue() - 77.1143) < 0.0001);
    assert(fabs(pop4->getValue() - 56.1728) < 0.0001);
    assert(fabs(pop5->getValue() - 16.4612) < 0.0001);

    cout << "OK\n" << endl;
    delete model;
}

