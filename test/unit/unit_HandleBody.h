/**
 * @file unit_HandleBody.h
 * @brief Declaração dos testes para verificar o padrão Handle/Body (Bridge).
 * @author Samuel
 * @date 2025
 */

#ifndef UNIT_HANDLEBODY_H
#define UNIT_HANDLEBODY_H

class unit_HandleBody {
public:
    /**
     * @brief Testa se a cópia de SystemHandle compartilha o mesmo Body.
     */
    void unit_System_HandleBody();

    /**
     * @brief Testa se a cópia de FlowHandle compartilha o mesmo Body.
     */
    void unit_Flow_HandleBody();

    /**
     * @brief Testa se a cópia de ModelHandle compartilha o mesmo Body.
     */
    void unit_Model_HandleBody();

    /**
     * @brief Executa todos os testes do conjunto HandleBody.
     */
    void run_HandleBody_Tests();
};

#endif // UNIT_HANDLEBODY_H