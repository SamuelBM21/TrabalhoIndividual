#include "unit_Flow.h"
#include "unit_Model.h"
#include "unit_System.h"
#include <iostream>
using namespace std;

int main(void){
    cout << "===== SystemUnitTests =====\n";
    unit_System_constructor_default();

    unit_system_copy_constructor();

    unit_System_destructor();

    unit_System_getValue();
    unit_System_setValue();

    unit_System_assignOverload();

    cout << "OK\n" << endl;
        
    // ------------------------------------------------------------------

    cout << "===== FlowUnitTests =====\n";
    unit_Flow_constructor_default();
    
    unit_Flow_copy_constructor();

    unit_Flow_destructor();

    unit_Flow_getSource();
    unit_Flow_setSource();

    unit_Flow_getTarget();
    unit_Flow_setTarget();

    cout << "OK\n" << endl;

    // ------------------------------------------------------------------
    
    cout << "===== ModelUnitTests =====\n";
    unit_Model_constructor_default();
    
    unit_Model_destructor();

    unit_Model_systemsBegin();
    unit_Model_systemsEnd();


    unit_Model_flowsBegin();
    unit_Model_flowsEnd();
    
    cout << "OK\n" << endl;

    return 0;
}

