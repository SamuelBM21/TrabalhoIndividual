/**
 * @file System.h
 * @brief Interface abstrata que representa um elemento de armazenamento do modelo.
 *
 * A classe System modela um "estoque" (stock) dentro da Teoria Geral de Sistemas.
 * Cada System contém um valor numérico que pode ser modificado ao longo da simulação
 * por meio de objetos Flow.
 *
 * Esta classe define a API básica para manipulação de sistemas e deve ser
 * implementada por classes concretas como SystemImpl.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

/**
 * @class System
 * @brief Interface para um elemento de armazenamento dentro do modelo.
 *
 * Representa uma entidade que possui um único valor numérico, o qual é
 * atualizado conforme os fluxos que incidem sobre ela durante a simulação.
 *
 * Implementações concretas (como SystemImpl) devem fornecer mecanismos
 * para armazenamento e atualização de valores.
 */
class System {
public:
    /**
     * @brief Destrutor virtual padrão.
     *
     * Necessário para permitir destruição correta via ponteiros para System.
     */
    virtual ~System() {}

    /**
     * @brief Define um novo valor para o sistema.
     *
     * @param v Valor numérico a ser usado.
     * @return true se o valor foi atualizado corretamente.
     */
    virtual bool setValue(double v) = 0;

    /**
     * @brief Retorna o valor atual armazenado no sistema.
     *
     * @return Valor numérico atual.
     */
    virtual double getValue() const = 0;
};

#endif // SYSTEM_H_
