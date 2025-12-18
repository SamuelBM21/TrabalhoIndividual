/**
 * @file SystemImpl.h
 * @brief Implementação concreta da interface System.
 *
 * A classe SystemImpl representa a implementação padrão de um "estoque" dentro
 * do simulador baseado na Teoria Geral de Sistemas. Ela armazena internamente
 * um valor numérico que pode ser modificado por Flows e consultado pelo Model.
 *
 * Esta implementação fornece:
 *  - Armazenamento seguro do valor;
 *  - Operações básicas de leitura e escrita;
 *  - Mecanismos de cópia e atribuição seguros.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef SYSTEMIMPL_H_
#define SYSTEMIMPL_H_

#include "System.h"

/**
 * @class SystemImpl
 * @brief Implementação concreta da classe System.
 *
 * Armazena um único valor numérico, representando o estado atual de um
 * elemento do modelo. A classe oferece métodos para definição, obtenção
 * e cópia desse valor.
 */
class SystemImpl : public System {
private:
    /**
     * @brief Valor numérico armazenado pelo sistema.
     *
     * Representa o estado atual de um estoque. Pode ser modificado diretamente
     * pelo Model ou indiretamente pelos Flows.
     */
    double value;

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa o sistema com valor zero.
     */
    SystemImpl();

    /**
     * @brief Construtor com valor inicial.
     *
     * @param value Valor inicial a ser atribuído ao sistema.
     */
    SystemImpl(double value);

    /**
     * @brief Construtor de cópia.
     *
     * Copia o valor armazenado em outro System.
     *
     * @param other Referência para o objeto System a ser copiado.
     */
    SystemImpl(const System& other);

    /**
     * @brief Destrutor.
     */
    virtual ~SystemImpl();

    /**
     * @brief Define um novo valor para o sistema.
     * @copydoc System::setValue()
     */
    bool setValue(double v) override;

    /**
     * @brief Obtém o valor atual.
     * @copydoc System::getValue()
     */
    double getValue() const override;

private:
    /**
     * @brief Operador de atribuição.
     * @copydoc System::operator=()
     */
    SystemImpl& operator=(const System& other);
    
    friend class unit_System;
};

#endif // SYSTEMIMPL_H_
