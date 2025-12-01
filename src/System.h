/**
 * @file System.h
 * @brief Declaração da classe System, que representa um elemento básico do modelo.
 *
 * A classe System é uma das estruturas fundamentais do simulador baseado na
 * Teoria Geral de Sistemas. Um System representa um "estoque" (stock), isto é,
 * uma entidade que possui um valor armazenado e que pode ser alterado ao longo
 * da simulação por meio dos fluxos (Flows).
 * 
 * @author Samuel
 * @date 2025
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

/**
 * @class System
 * @brief Representa um elemento de armazenamento dentro do modelo.
 *
 * Um System contém um único valor numérico, que representa a quantidade atual
 * de um recurso, população, nível, concentração etc., dependendo do contexto
 * do modelo sendo simulado.
 *
 * Essa classe é manipulada pela classe Model e pelos objetos Flow, que
 * alteram seu valor ao longo da execução da simulação.
 */
class System {
public:
    /**
     * @brief Destrutor virtual.
     *
     * Mantido virtual para permitir herança segura caso a classe seja estendida.
     */
    virtual ~System() {};

    /**
     * @brief Operador de atribuição.
     *
     * Substitui o valor atual pelo valor do outro System.
     *
     * @param other Objeto System a ser atribuído.
     * @return Referência para o próprio objeto.
     */
    virtual System& operator=(const System& other) = 0;

    /**
     * @brief Define um novo valor para o sistema.
     *
     * @param v Novo valor.
     * @return true se o valor foi definido com sucesso.
     */
    virtual bool setValue(double v) = 0;

    /**
     * @brief Obtém o valor atual armazenado.
     *
     * @return O valor atual do System.
     */
    virtual double getValue() const = 0;
};

#endif // SYSTEM_H_
