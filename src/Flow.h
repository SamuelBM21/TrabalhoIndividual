/**
 * @file Flow.h
 * @brief Declaração da classe abstrata Flow, que modela um fluxo entre dois Systems.
 *
 * Um Flow representa a transferência de valor entre um System de origem (source)
 * e um System de destino (target). O comportamento do fluxo é definido pela
 * implementação concreta do método execute(), que calcula quanto valor deve
 * ser transferido em um passo da simulação.
 *
 * Esta classe funciona como interface base para fluxos específicos, como
 * fluxos exponenciais, logísticos, lineares etc.
 *
 * A classe não possui responsabilidade sobre o ciclo de vida dos Systems:
 * ela apenas mantém ponteiros (non-owning pointers).
 *
 * @author Samuel
 * @date 2025
 */

#ifndef FLOW_H_
#define FLOW_H_

#include "System.h"

/**
 * @class Flow
 * @brief Interface abstrata que define um fluxo entre dois Systems.
 *
 * Cada Flow conecta dois Systems por meio de ponteiros — source (origem)
 * e target (destino). O Model executa todos os fluxos a cada iteração
 * para calcular como os valores dos Systems devem evoluir.
 *
 * Subclasses concretas devem implementar o método execute(), que define
 * a regra do fluxo.
 */
class Flow {
public:
    /// Destrutor virtual necessário para herança segura.
    virtual ~Flow() {}
/* 
    /// @brief Operador de atribuição abstrato.
    virtual Flow& operator=(const Flow& other) = 0; */

    /// @brief Define o sistema de origem do fluxo.
    virtual bool setSource(System* s) = 0;

    /// @brief Retorna o sistema de origem.
    virtual System* getSource() const = 0;

    /// @brief Define o sistema de destino do fluxo.
    virtual bool setTarget(System* t) = 0;

    /// @brief Retorna o sistema de destino.
    virtual System* getTarget() const = 0;

    /**
     * @brief Calcula o valor do fluxo no estado atual.
     *
     * Subclasses implementam a equação matemática específica do fluxo.
     *
     * @return Valor numérico do fluxo.
     */
    virtual double execute() = 0;
};

#endif // FLOW_H_
