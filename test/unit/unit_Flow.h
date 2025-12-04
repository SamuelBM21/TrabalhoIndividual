/**
 * @file unit_Flow.h
 * @brief Declaração dos testes unitários para a classe Flow e FlowImpl.
 *
 * Este arquivo contém as assinaturas das funções responsáveis por testar
 * o comportamento da classe FlowImpl e suas funcionalidades básicas, tais como:
 *  - Construtores (default, parametrizado e cópia);
 *  - Métodos de acesso e modificação (get/set de source e target);
 *  - Destrutor;
 *  - Validação de integridade da cópia superficial.
 *
 * Cada função implementa um teste isolado que verifica uma funcionalidade
 * específica da classe, permitindo detectar regressões e garantir que FlowImpl
 * se comporte corretamente durante sua integração com a classe Model.
 *
 * Os testes são executados no arquivo unit_Flow.cpp.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef _UNIT_FLOW_H_
#define _UNIT_FLOW_H_

#include "../../src/FlowImpl.h"

class unit_Flow{

public:
    /**
     * @brief Testa o construtor padrão de FlowImpl.
     *
     * Verifica se:
     *  - O objeto é criado corretamente;
     *  - source == nullptr;
     *  - target == nullptr.
     */
    void unit_Flow_constructor_default();

    /**
     * @brief Testa o construtor parametrizado de FlowImpl.
     *
     * Verifica se source e target são atribuídos corretamente.
     */
    void unit_Flow_constructor_with_source_target();

    /**
     * @brief Testa o construtor de cópia de FlowImpl.
     *
     * Garante que o novo fluxo copie corretamente:
     *  - Ponteiro do source (shallow copy);
     *  - Ponteiro do target (shallow copy).
     */
    void unit_Flow_copy_constructor();

    /**
     * @brief Testa o destrutor de FlowImpl.
     *
     * Este teste apenas confirma que a destruição ocorre sem crash.
     */
    void unit_Flow_destructor();

    /**
     * @brief Testa o método getSource().
     */
    void unit_Flow_getSource();

    /**
     * @brief Testa o método setSource().
     */
    void unit_Flow_setSource();

    /**
     * @brief Testa o método getTarget().
     */
    void unit_Flow_getTarget();

    /**
     * @brief Testa o método setTarget().
     */
    void unit_Flow_setTarget();

    /**
     * @brief Testa o método execute().
     *
     * Verifica se a execução do fluxo retorna o valor esperado.
     */
    void unit_Flow_execute();

    /**
     * @brief Executa todos os testes unitários da classe FlowImpl.
     */
    void unit_Flow_runUnitTests();
};


#endif // _UNIT_FLOW_H_
