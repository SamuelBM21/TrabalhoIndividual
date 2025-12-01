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
    cout << "===== ExponentialFuncionalTest =====\n";

    ModelImpl *model = new ModelImpl;
    
    /**
     * @brief Ponteiro de System iniciado como 100.
    */
    System *pop1 = new SystemImpl(100.0);
    pop1->getValue();
    /**
     * @brief Ponteiro de System iniciado como 0.
    */
    System *pop2 = new SystemImpl(0.0);

    /**
     * @brief Ponteiro de Flow.
    */
    ExponentialFlow *flow = new ExponentialFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);

    pop1->setValue(100.0);
    pop2->setValue(0.0);

    /**
     * @brief Execução do programa realizando operacoes de 0 a 100.
    */
    model->run(0, 100);
    
    /**
     * @brief Conferindo o resultado final do primeiro sistema com o valor 36.6032.
    */
    assert(round(fabs(pop1->getValue() - 36.6032) < 0.0001));
    /**
     * @brief Conferindo o resultado final do segundo sistema com o valor 63.3968.
    */
    assert(round(fabs(pop2->getValue() - 63.3968) < 0.0001));

    cout << "OK\n" << endl;
}


void logisticalFuncionalTest(){
    cout << "===== LogisticalFuncionalTest =====\n";

    Model *model = new ModelImpl;

    /**
     * @brief Ponteiro de System iniciado como 100.
    */
    System *pop1 = new SystemImpl(100.0);
    /**
     * @brief Ponteiro de System iniciado como 10.
    */
    System *pop2 = new SystemImpl(10.0);

    /**
     * @brief Ponteiro de Flow.
    */
    LogisticFlow *flow = new LogisticFlow();
    flow->setSource(pop1);
    flow->setTarget(pop2);

    model->add(pop1);
    model->add(pop2);
    model->add(flow);

    /**
     * @brief Execução do programa realizando operacoes de 0 a 100.
    */
    model->run(0, 100);
    
    /**
     * @brief Conferindo o resultado final do primeiro sistema com o valor 88.2167.
    */
    assert(round(fabs(pop1->getValue() - 88.2167) < 0.0001));
    /**
     * @brief Conferindo o resultado final do segundo sistema com o valor 21.7833.
    */
    assert(round(fabs(pop2->getValue() - 21.7833) < 0.0001));

    cout << "OK\n" << endl;
}


void complexFuncionalTest(){
    cout << "===== ComplexFuncionalTest =====\n";

    ModelImpl *model = new ModelImpl;

    /**
     * @brief Ponteiro de System iniciado como 100.
    */
    SystemImpl *pop1 = new SystemImpl(100.0);
    /**
     * @brief Ponteiro de System iniciado como 0.
    */
    SystemImpl *pop2 = new SystemImpl(0.0);
    /**
     * @brief Ponteiro de System iniciado como 100.
    */
    SystemImpl *pop3 = new SystemImpl(100.0);
    /**
     * @brief Ponteiro de System iniciado como 0.
    */
    SystemImpl *pop4 = new SystemImpl(0.0);
    /**
     * @brief Ponteiro de System iniciado como 0.
    */
    SystemImpl *pop5 = new SystemImpl(0.0);
    
    /**
     * @brief Ponteiro de Flow.
    */
    ExponentialFlow *flow1 = new ExponentialFlow();
    flow1->setSource(pop1);
    flow1->setTarget(pop2);

    /**
     * @brief Ponteiro de Flow.
    */
    ExponentialFlow *flow2 = new ExponentialFlow();
    flow2->setSource(pop1);
    flow2->setTarget(pop3);
    
    /**
     * @brief Ponteiro de Flow.
    */
    ExponentialFlow *flow3 = new ExponentialFlow();
    flow3->setSource(pop2);
    flow3->setTarget(pop5);

    /**
     * @brief Ponteiro de Flow.
    */
    ExponentialFlow *flow4 = new ExponentialFlow();
    flow4->setSource(pop2);
    flow4->setTarget(pop3);
    
    /**
     * @brief Ponteiro de Flow.
    */
    ExponentialFlow *flow5 = new ExponentialFlow();
    flow5->setSource(pop3);
    flow5->setTarget(pop4);

    /**
     * @brief Ponteiro de Flow.
    */
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

    /**
     * @brief Execução do programa realizando operacoes de 0 a 100.
    */
    model->run(0, 100);

    /**
     * @brief Conferindo o resultado final do primeiro sistema com o valor 31.8513.
    */
    assert(round(fabs(pop1->getValue() - 31.8513) < 0.0001));
    /**
     * @brief Conferindo o resultado final do segundo sistema com o valor 18.4003.
    */
    assert(round(fabs(pop2->getValue() - 18.4003) < 0.0001));
    /**
     * @brief Conferindo o resultado final do terceiro sistema com o valor 77.1143.
    */
    assert(round(fabs(pop3->getValue() - 77.1143) < 0.0001));
    /**
     * @brief Conferindo o resultado final do quarto sistema com o valor 56.1728.
    */
    assert(round(fabs(pop4->getValue() - 56.1728) < 0.0001));
    /**
     * @brief Conferindo o resultado final do quinto sistema com o valor 16.4612.
    */
    assert(round(fabs(pop5->getValue() - 16.4612) < 0.0001));

    cout << "OK\n" << endl;
}
