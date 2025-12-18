/**
 * @file funcional_tests.h
 * @brief Fluxos concretos para testes adaptados ao padrão Handle/Body.
 * @author Samuel
 * @date 2025
 */

#ifndef _FUNCTIONAL_TESTS_H_
#define _FUNCTIONAL_TESTS_H_

#include "../../src/include/ModelImpl.h" // Inclui ModelHandle (via ModelImpl.h)
#include "../../src/include/FlowImpl.h"  // Inclui FlowHandle

/**
 * @class ExponentialFlow
 * @brief Fluxo exponencial adaptado para herdar de FlowHandle.
 */
class ExponentialFlow : public FlowHandle {
public:
    // Construtor padrão chama o construtor padrão do Handle
    ExponentialFlow(): FlowHandle() {}

    // Construtor parametrizado repassa para o FlowHandle
    // O FlowHandle vai criar o Body e associar source/target
    ExponentialFlow(System *source, System *target): FlowHandle(source, target) {}

    // A implementação do execute continua a mesma, acessando os métodos do Handle
    double execute() override {
        // getSource() delega para o Body internamente
        return 0.01 * getSource()->getValue();
    }
};

/**
 * @class LogisticFlow
 * @brief Fluxo logístico adaptado para herdar de FlowHandle.
 */
class LogisticFlow : public FlowHandle {
public:
    LogisticFlow(): FlowHandle() {}

    LogisticFlow(System *source, System *target): FlowHandle(source, target) {}

    double execute() override {
        double targetVal = getTarget()->getValue();
        return 0.01 * targetVal * (1 - (targetVal / 70.0));
    }
};

// Protótipos das funções de teste
void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif // _FUNCTIONAL_TESTS_H_