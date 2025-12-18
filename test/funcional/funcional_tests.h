/**
 * @file funcional_tests.h
 * @brief Declaração de fluxos de teste e protótipos de testes funcionais.
 *
 * Este arquivo contém implementações simples de subclasses de Flow usadas
 * exclusivamente para testes funcionais do simulador (ExponentialFlow e
 * logisticFlow), bem como os protótipos das funções de teste que verificam
 * cenários comportamentais do sistema/model.
 *
 * As classes aqui definidas são utilitárias para os testes e não fazem parte
 * da API pública do simulador. Elas são usadas para validar a integração entre
 * Model, System e Flow durante execuções de teste automatizadas.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef _FUNCTIONAL_TESTS_H_
#define _FUNCTIONAL_TESTS_H_

#include "../../src/include/Model.h"  
#include "../../src/include/FlowImpl.h"  

/**
 * @class ExponentialFlow
 * @brief Implementação de Flow para teste: fluxo proporcional ao source.
 *
 * Define um fluxo simples cujo valor é proporcional ao valor do sistema de
 * origem (source). Usado em testes funcionais para validar transferência
 * linear entre Systems.
 *
 * Fórmula usada (no método execute):
 * @f$ value = 0.01 \times source->getValue() @f$
 *
 */
class ExponentialFlow : public FlowImpl {
public:
    /** @brief Construtor padrão. */
    ExponentialFlow(): FlowImpl() {}

    /**
     * @brief Construtor parametrizado.
     * @param source Ponteiro para o System de origem.
     * @param target Ponteiro para o System de destino.
     */
    ExponentialFlow(System *source, System *target): FlowImpl(source, target) {}

    /**
     * @brief Calcula o valor do fluxo (proporcional ao source).
     *
     * @return Valor do fluxo calculado.
     */
    double execute() {
        return 0.01 * getSource()->getValue();
    }
};

/**
 * @class LogisticFlow
 * @brief Implementação de Flow para teste: crescimento logístico no target.
 *
 * Classe de teste que implementa uma taxa dependente do valor do sistema de
 * destino (target) seguindo uma forma logística discreta.
 *
 * Fórmula usada (no método execute):
 * @f$ value = 0.01 \times target->getValue() \times \left(1 - \frac{target->getValue()}{70.0}\right) @f$
 *
 */
class LogisticFlow : public FlowImpl {
public:
    /** @brief Construtor padrão. */
    LogisticFlow(): FlowImpl() {}

    /**
     * @brief Construtor parametrizado.
     * @param source Ponteiro para o System de origem.
     * @param target Ponteiro para o System de destino.
     */
    LogisticFlow(System *source, System *target): FlowImpl(source, target) {}

    /**
     * @brief Calcula o valor do fluxo (crescimento logístico baseado no target).
     *
     * @return Valor do fluxo calculado.
     */
    double execute() {
        return 0.01 * getTarget()->getValue() * (1 - (getTarget()->getValue() / 70.0));
    }
};

/**
 * @brief Teste funcional para verificar comportamento do fluxo exponencial.
 */
void exponentialFuncionalTest();

/**
 * @brief Teste funcional para verificar comportamento do fluxo logístico.
 */
void logisticalFuncionalTest();

/**
 * @brief Teste funcional composto (cenário mais complexo).
 *
 * Este teste combina múltiplos Systems e Fluxos para validar interações e efeitos
 * cumulativos dentro do Model (sinergia/competição entre fluxos).
 *
 */
void complexFuncionalTest();

#endif // _FUNCTIONAL_TESTS_H_