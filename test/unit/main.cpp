/**
 * @file main.cpp
 * @brief Arquivo principal responsável por executar os testes funcionais do simulador.
 *
 * Este arquivo contém apenas a função `main()`, cuja função é chamar
 * os testes funcionais implementados em `unit_Classe.cpp`.
 * Ele serve como ponto de entrada para validar o comportamento de cada
 * método das classes Model, System e Flow.
 *
 * @author Samuel
 * @date 2025
 */

#include "unit_Flow.h"
#include "unit_Model.h"
#include "unit_System.h"
#include "unit_HandleBody.h"
#include <iostream>
using namespace std;

int main(void){
    cout << "SystemUnitTests:\n";

    unit_System test_unit_system;
    test_unit_system.unit_System_runUnitTests();
    
    cout << "Passou! \n" << endl;
        
    // ------------------------------------------------------------------

    cout << "FlowUnitTests:\n";

    unit_Flow test_unit_flow;
    test_unit_flow.unit_Flow_runUnitTests();

    cout << "Passou! \n" << endl;

    // ------------------------------------------------------------------
    
    cout << "ModelUnitTests:\n";

    unit_Model test_unit_model;
    test_unit_model.unit_Model_runUnitTests();
    
    cout << "Passou! \n" << endl;

    // ------------------------------------------------------------------

    cout << "HandleBodyUnitTests:\n";

    unit_HandleBody test_handle_body;
    test_handle_body.run_HandleBody_Tests();
    
    cout << "Passou! \n" << endl;

    return 0;
}

