/**
 * @file unit_System.cpp
 * @brief Testes unitários do System seguindo padrão White-Box (acesso direto à memória).
 */

#include <iostream>
#include <assert.h>
#include <math.h>

#include "unit_System.h"
#include "../../src/include/SystemImpl.h" 

using namespace std;

void unit_System::unit_System_constructor_default(){
    // Cria o Handle, que instancia o Body automaticamente
    SystemHandle *system = new SystemHandle(); 
    
    // Acessa o pImpl_ (ponteiro para Body) e verifica o valor interno
    assert(system->pImpl_->getValue() == 0.0); 

    delete system;
}

void unit_System::unit_System_constructor_with_value(){
    SystemHandle *system = new SystemHandle(30.0);
    
    // Verifica diretamente no Body se o valor foi setado
    assert(fabs(system->pImpl_->getValue() - 30.0) < 0.0001);

    delete system;
}

void unit_System::unit_system_copy_constructor(){
    SystemHandle *system1 = new SystemHandle(30.0);
    SystemHandle *system2 = new SystemHandle(*system1);

    // No padrão Handle/Body, a cópia do Handle aponta para o MESMO Body.
    // Verificamos se os ponteiros pImpl_ são iguais.
    assert(system1->pImpl_ == system2->pImpl_);
    assert(fabs(system2->pImpl_->getValue() - 30.0) < 0.0001);

    delete system1;
    delete system2;   
}

void unit_System::unit_System_destructor(){
    // Teste de vazamento de memória seria feito externamente ou com contadores estáticos
}

void unit_System::unit_System_getValue(){
    SystemHandle *system = new SystemHandle(30.0);
    
    // Verifica se o método público retorna o mesmo que o atributo interno
    assert(fabs(system->getValue() - system->pImpl_->getValue()) < 0.0001);

    delete system;
}

void unit_System::unit_System_setValue(){
    SystemHandle *system = new SystemHandle(30.0);
    system->setValue(100.0);

    // Valida se a alteração via método público refletiu no atributo privado do Body
    assert(fabs(system->pImpl_->getValue() - 100.0) < 0.0001);

    delete system;
}

void unit_System::unit_System_runUnitTests(){
    unit_System_constructor_default();
    unit_System_constructor_with_value();
    unit_system_copy_constructor();
    unit_System_destructor();
    unit_System_getValue();
    unit_System_setValue();
}