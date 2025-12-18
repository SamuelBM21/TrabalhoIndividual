/**
 * @file funcional_tests.cpp
 * @brief Implementação dos testes funcionais com limpeza de memória adequada.
 * @author Samuel
 * @date 2025
 */

#include "funcional_tests.h"
#include <math.h>
#include <assert.h>
#include <iostream>

using namespace std;

void exponentialFuncionalTest(){
    cout << "ExponentialFuncionalTest: ";

    // 1. Cria o Modelo (ModelHandle é criado internamente)
    Model *model = Model::createModel();
    
    // 2. Cria Sistemas (SystemHandle criado internamente e adicionado ao ModelBody)
    System *pop1 = model->createSystem(100.0);
    System *pop2 = model->createSystem(0.0);
    
    // 3. Cria Fluxo Exponencial
    model->createFlow<ExponentialFlow>(pop1, pop2);

    // 4. Executa
    model->run(0, 100);

    // 5. Verifica
    assert(round(fabs(pop1->getValue() - 36.6032)*10000) < 1);
    assert(round(fabs(pop2->getValue() - 63.3968)*10000) < 1);

    // 6. Limpeza (O destrutor do ModelHandle deletará os handles de pop1, pop2 e flow)
    delete model;

    cout << "Passou!" << endl;
}

void logisticalFuncionalTest(){
    cout << "LogisticalFuncionalTest: ";

    Model *model = Model::createModel();

    System *pop1 = model->createSystem(100.0);
    System *pop2 = model->createSystem(10.0);

    model->createFlow<LogisticFlow>(pop1, pop2);
    
    model->run(0, 100);
    
    assert(round(fabs(pop1->getValue() - 88.2167)*10000) < 1);
    assert(round(fabs(pop2->getValue() - 21.7833)*10000) < 1);

    delete model;

    cout << "Passou!" << endl;
}


void complexFuncionalTest(){
    cout << "ComplexFuncionalTest: ";

    Model *model = Model::createModel();

    System *pop1 = model->createSystem(100.0);
    System *pop2 = model->createSystem(0.0);
    System *pop3 = model->createSystem(100.0);
    System *pop4 = model->createSystem(0.0);
    System *pop5 = model->createSystem(0.0);
    
    model->createFlow<ExponentialFlow>(pop1, pop2);
    model->createFlow<ExponentialFlow>(pop1, pop3);
    model->createFlow<ExponentialFlow>(pop2, pop5);
    model->createFlow<ExponentialFlow>(pop2, pop3);
    model->createFlow<ExponentialFlow>(pop3, pop4);
    model->createFlow<ExponentialFlow>(pop4, pop1);

    model->run(0, 100);

    assert(round(fabs(pop1->getValue() - 31.8513)*10000) < 1);
    assert(round(fabs(pop2->getValue() - 18.4003)*10000) < 1);
    assert(round(fabs(pop3->getValue() - 77.1143)*10000) < 1);
    assert(round(fabs(pop4->getValue() - 56.1728)*10000) < 1);
    assert(round(fabs(pop5->getValue() - 16.4612)*10000) < 1);

    delete model;

    cout << "Passou!" << endl;
}