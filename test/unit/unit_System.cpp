/**
 * @file unit_System.cpp
 * @brief Implementação dos testes unitários da classe SystemImpl.
 *
 * Cada função aqui valida um aspecto específico do comportamento de SystemImpl,
 * garantindo que construtores, métodos de acesso, modificadores e operadores
 * funcionem corretamente.
 *
 * @author Samuel
 * @date 2025
 */

 
#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_System.h"

using namespace std;

void unit_System :: unit_System_constructor_default(){

    SystemImpl *system = new SystemImpl();
    assert(sizeof(*system) > 0);

    delete system;
}

void unit_System :: unit_System_constructor_with_value(){
    SystemImpl *system = new SystemImpl(30.0);
    assert(round(fabs(system->value - 30.0)* 10000) < 1);

    delete system;
}

void unit_System :: unit_system_copy_constructor(){
    SystemImpl *system1 = new SystemImpl(30.0);
    SystemImpl *system2 = new SystemImpl(*system1);

    assert(round(fabs(system1->value - 30.0)* 10000) == round(fabs(system1->value - 30.0)* 10000));

    delete system1;
    delete system2;
    
}

void unit_System :: unit_System_destructor(){}

void unit_System :: unit_System_getValue(){

    SystemImpl *system = new SystemImpl(30.0);
    assert(round(fabs(system->getValue() - 30.0)* 10000) < 1);

    delete system;
}

void unit_System :: unit_System_setValue(){

    SystemImpl *system = new SystemImpl(30.0);

    system->setValue(100.);
    assert(round(fabs(system->value - 30.0)* 10000) > 1); 
    assert(round(fabs(system->value - 100.0)* 10000) < 1);

}

void unit_System :: unit_System_runUnitTests(){
    unit_System_constructor_default();
    unit_System_constructor_with_value();
    unit_system_copy_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
}   

