#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_System.h"

using namespace std;

void unit_System_constructor_default(){

    System *system = new SystemImpl();
    assert(sizeof(*system) > 0);

    delete system;
}

void unit_System_constructor_with_value(){
    System *system = new SystemImpl(30.0);
    assert(round(fabs(system->getValue() - 30.0)* 10000) < 1);

    delete system;
}

void unit_system_copy_constructor(){
    System *system1 = new SystemImpl(30.0);
    System *system2 = new SystemImpl(*system1);

    assert(round(fabs(system1->getValue() - 30.0)* 10000) == round(fabs(system1->getValue() - 30.0)* 10000));

    delete system1;
    delete system2;
    
}

void unit_System_destructor(){}

void unit_System_getValue(){

    System *system = new SystemImpl(30.0);
    assert(round(fabs(system->getValue() - 30.0)* 10000) < 1);

    delete system;
}

void unit_System_setValue(){

    System *system = new SystemImpl(30.0);

    system->setValue(100.);
    assert(round(fabs(system->getValue() - 30.0)* 10000) > 1); 
    assert(round(fabs(system->getValue() - 100.0)* 10000) < 1);

}


void unit_System_assignOverload(){

    System *system1 = new SystemImpl(50.0);
    System *system2 = new SystemImpl();

    *system2 = *system1;

    assert(round(fabs(system1->getValue() - 50.0)* 10000) == round(fabs(system1->getValue() - 50.0)* 10000));

    delete system1;
    delete system2;
    
}

