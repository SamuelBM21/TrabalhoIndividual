/**
 * @file unit_System.h
 * @brief Declaração dos testes unitários para a classe System e SystemImpl.
 *
 * Este arquivo contém as assinaturas das funções responsáveis por testar
 * o comportamento da classe SystemImpl, incluindo:
 *  - Construtores (padrão, com valor e cópia);
 *  - Métodos de acesso e modificação de valores (getValue/setValue);
 *  - Operador de atribuição (=).
 *
 * Os testes garantem que a classe SystemImpl mantenha corretamente seu
 * estado interno e opere conforme esperado dentro do simulador.
 *
 * As implementações estão em unit_System.cpp.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef _UNIT_SYSTEM_H_
#define _UNIT_SYSTEM_H_

#include "../../src/include/SystemImpl.h"

/**
 * @class unit_System
 * @brief Classe que encapsula os testes unitários para SystemImpl.
 *
 * Cada método desta classe implementa um teste específico para validar
 * o comportamento da classe SystemImpl, garantindo que seus construtores,
 * métodos de acesso, modificadores e operador de atribuição funcionem
 * conforme esperado.
 */
class unit_System{
public:
    /**
     * @brief Testa o construtor padrão.
     */
    void unit_System_constructor_default();

    /**
     * @brief Testa o construtor que recebe um valor inicial.
     */
    void unit_System_constructor_with_value();

    /**
     * @brief Testa o construtor por cópia.
     */
    void unit_system_copy_constructor();

    /**
     * @brief Testa o destrutor de SystemImpl.
     *
     * Apenas verifica que a destruição ocorre sem erros.
     */
    void unit_System_destructor();

    /**
     * @brief Testa o método getValue().
     */
    void unit_System_getValue();

    /**
     * @brief Testa o método setValue().
     */
    void unit_System_setValue();

    /**
     * @brief Testa o operador de atribuição (=).
     */
    void unit_System_runUnitTests();
};


#endif // _UNIT_SYSTEM_H_
