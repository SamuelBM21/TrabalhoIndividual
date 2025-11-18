#include "funcional_tests.h"

#include "../../src/Model.h"
#include "../../src/Flow.h"
#include <assert.h>

using namespace std;

int main(void){
    onlyOneSystem();
    onlyOneFlow();
    flowWithSourceWithoutTarget();
    flowWithoutSourceWithTarget();
    flowWithSourceWithTarget();
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
}