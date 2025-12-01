/**
 * @file Flow.h
 * @brief Declaração da classe abstrata Flow, que modela um fluxo entre dois Systems.
 *
 * A classe Flow representa uma transferência de valor entre um sistema de origem
 * (source) e um sistema de destino (target). Ela é a classe base para todas as
 * implementações concretas de fluxos do simulador (por exemplo: fluxo linear,
 * fluxo logístico, etc.). Subclasses devem implementar o método virtual puro
 * execute(), que calcula o valor do fluxo em um determinado passo de simulação.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef FLOWIMPL_H_
#define FLOWIMPL_H_

#include "Flow.h"

/**
 * @class Flow
 * @brief Classe base abstrata que define um fluxo entre dois Systems.
 *
 * Cada Flow contém ponteiros para um System de origem e um System de destino.
 * O Model utiliza objetos Flow para computar e aplicar transferências entre
 * Systems em cada iteração da simulação.
 *
 */
class FlowImpl : public Flow {
protected:
    /** @brief Ponteiro para o sistema de origem. */
    System* source;

    /** @brief Ponteiro para o sistema de destino. */
    System* target;

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa os ponteiros source e target como nullptr.
     */
    FlowImpl();

    /**
     * @brief Construtor com parâmetros.
     *
     * @param source Ponteiro para o System de origem (pode ser nullptr).
     * @param target Ponteiro para o System de destino (pode ser nullptr).
     */
    FlowImpl(System* source, System* target);

    /**
     * @brief Construtor de cópia.
     *
     * Copia os ponteiros source/target (shallow copy). Se for necessário um
     * comportamento de cópia profunda, implemente explicitamente na subclasse
     * ou ajuste a política de propriedade.
     *
     * @param flow Objeto Flow a ser copiado.
     */
    FlowImpl(const Flow& flow);

    /**
     * @brief Operador de atribuição.
     *
     * Realiza cópia segura dos ponteiros source e target.
     *
     * @param other Objeto a ser atribuído.
     * @return Referência para *this.
     */
    Flow& operator=(const Flow& other);

    /**
     * @brief Destrutor virtual.
     *
     * Declarado virtual para permitir herança segura. Flow não assume
     * propriedade (exclusive ownership) dos Systems apontados.
     */
    virtual ~FlowImpl();

    /**
     * @brief Define o sistema de origem do fluxo.
     *
     * @param s Ponteiro para o System de origem. Pode ser nullptr para indicar
     *          que ainda não foi conectado.
     * @return true se a operação ocorreu com sucesso.
     */
    bool setSource(System* s);

    /**
     * @brief Retorna o sistema de origem.
     *
     * @return Ponteiro para o System de origem (pode ser nullptr).
     */
    System* getSource() const;

    /**
     * @brief Define o sistema de destino do fluxo.
     *
     * @param t Ponteiro para o System de destino. Pode ser nullptr.
     * @return true se a operação ocorreu com sucesso.
     */
    bool setTarget(System* t);

    /**
     * @brief Retorna o sistema de destino.
     *
     * @return Ponteiro para o System de destino (pode ser nullptr).
     */
    System* getTarget() const;

    /**
     * @brief Calcula o valor do fluxo neste passo de simulação.
     *
     * Método abstrato que deve ser implementado por classes derivadas para
     * definir a regra de transferência entre source e target.
     *
     * @return Valor do fluxo calculado (double). A interpretação do valor
     *         depende da semântica do modelo (por ex.: taxa por unidade de tempo).
     */
    virtual double execute() = 0;


};

#endif // FLOWIMPL_H_
