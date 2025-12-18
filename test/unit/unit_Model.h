/**
 * @file unit_Model.h
 * @brief Declaração dos testes unitários para a classe Model e ModelImpl.
 *
 * Este arquivo contém as assinaturas das funções responsáveis por testar
 * o funcionamento interno da classe ModelImpl, incluindo:
 *  - Construtor e destrutor;
 *  - Métodos de gerenciamento de Systems e Flows (add/remove);
 *  - Métodos de iteração (begin, end, size);
 *  - Execução da simulação (run);
 *  - Validação do operador de atribuição (=).
 *
 * Cada função implementa um teste isolado, garantindo que ModelImpl
 * mantenha o controle correto de seus componentes e funcione de forma
 * consistente ao longo da execução da simulação.
 *
 * Os testes são implementados no arquivo unit_Model.cpp.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef _UNIT_MODEL_H_
#define _UNIT_MODEL_H_

#include "../../src/include/FlowImpl.h"

/**
 * @class unit_Model
 * @brief Classe que encapsula os testes unitários para ModelImpl.
 *
 * Cada método desta classe implementa um teste específico para validar
 * o comportamento da classe ModelImpl, garantindo que seus construtores,
 * métodos de acesso, modificadores e destrutor funcionem conforme esperado.
 */
class unit_Model{
public:
    /**
     * @brief Testa o construtor padrão de ModelImpl.
     */
    void unit_Model_constructor_default();

    /**
     * @brief Testa o destrutor de ModelImpl.
     *
     * Apenas verifica se a destruição ocorre sem erros.
     */
    void unit_Model_destructor();

    /**
     * @brief Testa o método getClock().
     */
    void unit_Model_getClock(); 

    /**
     * @brief Testa o método createSystem().
     */
    void unit_Model_createSystem();

    /**
     * @brief Testa o método createFlow().
     */
    void unit_Model_createFlow();

    /**
     * @brief Testa o método removeSystem().
     */
    void unit_Model_removeSystem();

    /**
     * @brief Testa o método removeFlow().
     */
    void unit_Model_removeFlow();

    /**
     * @brief Testa o iterador systemsBegin().
     */
    void unit_Model_systemsBegin();

    /**
     * @brief Testa o iterador systemsEnd().
     */
    void unit_Model_systemsEnd();

    /**
     * @brief Testa o iterador flowsBegin().
     */
    void unit_Model_flowsBegin();

    /**
     * @brief Testa o iterador flowsEnd().
     */
    void unit_Model_flowsEnd();

    /**
     * @brief Testa o método run().
     */
    void unit_Model_run();

    /**
     * @brief Executa todos os testes unitários da classe ModelImpl.
     */
    void unit_Model_runUnitTests();
};
#endif // _UNIT_MODEL_H_
