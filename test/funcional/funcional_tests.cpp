/**
 * @file funcional_tests.cpp
 * @brief Implementação dos testes funcionais do simulador de sistemas.
 *
 * Este arquivo contém três testes principais utilizados para verificar
 * a integridade e o comportamento dinâmico do simulador:
 *
 * - **ExponentialFuncionalTest:**  
 *   Valida a transferência proporcional baseada no valor do sistema de origem.
 *
 * - **LogisticalFuncionalTest:**  
 *   Avalia a dinâmica logística (crescimento limitado) sobre o sistema de destino.
 *
 * - **ComplexFuncionalTest:**  
 *   Teste mais robusto que envolve múltiplos sistemas e múltiplos fluxos,
 *   validando interação em larga escala e comportamento combinado.
 *
 * Cada teste:
 *  - Instancia um Model.
 *  - Cria Systems e Flows.
 *  - Executa a simulação usando Model::run().
 *  - Aplica asserts garantindo que os valores finais sejam os esperados.
 *
 * Esses testes são essenciais para verificar a corretude da simulação,
 * especialmente após mudanças estruturais, refatorações ou otimizações.
 *
 * @author Samuel
 * @date 2025
 */

#include "funcional_tests.h"

#include <math.h>
#include <assert.h>

using namespace std;

void exponentialFuncionalTest(){
    cout << "ExponentialFuncionalTest:\n";

    Model *model = Model::createModel();
    
    System *pop1 = model->createSystem(100.0);
    System *pop2 = model->createSystem(0.0);
    
    model->createFlow<ExponentialFlow>(pop1, pop2);

    model->run(0, 100);

    assert(round(fabs(pop1->getValue() - 36.6032) < 0.0001));
    assert(round(fabs(pop2->getValue() - 63.3968) < 0.0001));

    cout << "Passou!\n" << endl;
}

void logisticalFuncionalTest(){
    cout << "LogisticalFuncionalTest:\n";

    Model *model = Model::createModel();

    System *pop1 = model->createSystem(100.0);
    System *pop2 = model->createSystem(10.0);

    model->createFlow<LogisticFlow>(pop1, pop2);
    
    model->run(0, 100);
    
    assert(round(fabs(pop1->getValue() - 88.2167) < 0.0001));
    assert(round(fabs(pop2->getValue() - 21.7833) < 0.0001));

    cout << "Passou!\n" << endl;
}


void complexFuncionalTest(){
    cout << "ComplexFuncionalTest:\n";

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

    assert(round(fabs(pop1->getValue() - 31.8513) < 0.0001));
    assert(round(fabs(pop2->getValue() - 18.4003) < 0.0001));
    assert(round(fabs(pop3->getValue() - 77.1143) < 0.0001));
    assert(round(fabs(pop4->getValue() - 56.1728) < 0.0001));
    assert(round(fabs(pop5->getValue() - 16.4612) < 0.0001));

    cout << "Passou!\n" << endl;
}
