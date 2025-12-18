/**
 * @file FlowImpl.h
 * @brief Implementação base concreta da interface Flow.
 *
 * FlowImpl fornece uma implementação padrão para o armazenamento e
 * manipulação dos ponteiros `source` e `target`, deixando apenas o método
 * execute() como abstrato, pois sua definição depende do tipo de fluxo.
 *
 * Essa classe pode ser usada diretamente como superclasse para fluxos
 * customizados, evitando repetição de código.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef FLOWIMPL_H_
#define FLOWIMPL_H_

#include "Flow.h"

/**
 * @class FlowImpl
 * @brief Implementação parcial da classe Flow.
 *
 * Esta classe implementa a maior parte da interface Flow, incluindo:
 *  - Armazenamento dos ponteiros source e target;
 *  - Construtores;
 *  - Operador de atribuição;
 *  - Métodos de acesso set/get.
 *
 * O método execute() permanece abstrato, pois cada fluxo concreto define
 * sua própria equação.
 */
class FlowImpl : public Flow {
protected:
    /// Ponteiro para o sistema de origem (pode ser nullptr).
    System* source;

    /// Ponteiro para o sistema de destino (pode ser nullptr).
    System* target;

public:
    /// @brief Construtor padrão: inicializa source e target como nullptr.
    FlowImpl();

    /**
     * @brief Construtor com parâmetros.
     *
     * @param source System de origem.
     * @param target System de destino.
     */
    FlowImpl(System* source, System* target);

    /**
     * @brief Construtor de cópia.
     *
     * Faz shallow copy dos ponteiros — o comportamento esperado,
     * já que Flow não possui Systems.
     *
     * @param flow Objeto Flow de origem.
     */
    FlowImpl(const Flow& flow);

    /**
     * @brief Operador de atribuição.
     * @copydoc Flow::operator=()
     */
    FlowImpl& operator=(const Flow& other);

    /// Destrutor virtual.
    virtual ~FlowImpl();

    /**
     * @copydoc Flow::setSource()
     */
    bool setSource(System* s) override;

    /**
     * @copydoc Flow::getSource()
     */
    System* getSource() const override;

    /**
     * @copydoc Flow::setTarget()
     */
    bool setTarget(System* t) override;

    /**
     * @copydoc Flow::getTarget()
     */
    System* getTarget() const override;

    /**
     * @brief Método ainda abstrato.
     * @copydoc Flow::execute()
     */
    virtual double execute() = 0;

    friend class unit_Flow;
};

#endif // FLOWIMPL_H_
