/**
 * @file Model.h
 * @brief Declaração da classe Model, responsável pelo gerenciamento da simulação.
 *
 * A classe Model é o núcleo do simulador baseado na Teoria Geral de Sistemas.
 * Ela armazena e controla coleções de objetos do tipo System e Flow, executando
 * a evolução temporal do sistema através da aplicação dos fluxos sobre os sistemas.
 *
 * O Model funciona como um "ambiente de execução", coordenando:
 *  - A lista de sistemas presentes no modelo
 *  - A lista de fluxos conectando esses sistemas
 *  - O processo de execução (simulação) no tempo
 *
 * @author Samuel
 * @date 2025
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>
#include "System.h"
#include "Flow.h"

/**
 * @class Model
 * @brief Classe responsável por gerenciar sistemas, fluxos e a simulação completa.
 *
 * O Model armazena dois conjuntos principais:
 *  - Uma lista de objetos System, representando entidades com um valor armazenado.
 *  - Uma lista de objetos Flow, que representem operações de transferência de valor entre Systems.
 *
 * A função principal do Model é executar a simulação entre um tempo inicial e
 * final, aplicando todos os fluxos existentes a cada passo.
 */
class Model {
public:
    /**
     * @brief Destrutor.
     *
     * Realiza a limpeza das listas de Systems e Flows, quando necessário.
     */
    virtual ~Model() {};

        /**
     * @brief Operador de atribuição.
     *
     * Permite copiar modelos de forma segura, substituindo o conteúdo atual.
     *
     * @param other Modelo a ser atribuído.
     * @return Referência para o objeto atual, após a operação.
     */
    virtual Model& operator=(const Model& other) = 0;

    /**
     * @brief Iterator type for iterating over flows in the model.
     */
    typedef std::vector<System*>::const_iterator iteratorSystem;

    /**
     * @brief Gets the iterator pointing to the beginning of the systems in the model.
     * @return Iterator pointing to the beginning of the systems.
     */
    virtual iteratorSystem systemsBegin() const = 0;

    /**
     * @brief Gets the iterator pointing to the end of the systems in the model.
     * @return Iterator pointing to the end of the systems.
     */
    virtual iteratorSystem systemsEnd() const = 0;

    /**
     * @brief Iterator type for iterating over flows in the model.
     */
    typedef std::vector<Flow*>::const_iterator iteratorFlow;

    /**
     * @brief Gets the iterator pointing to the beginning of the flows in the model.
     * @return Iterator pointing to the beginning of the flows.
     */
    virtual iteratorFlow flowsBegin() const = 0;

    /**
     * @brief Gets the iterator pointing to the end of the flows in the model.
     * @return Iterator pointing to the end of the flows.
     */
    virtual iteratorFlow flowsEnd() const = 0;

    /**
     * @brief Adiciona um novo sistema ao modelo.
     *
     * @param s Ponteiro para o System a ser adicionado.
     * @return true se o sistema foi adicionado com sucesso, false caso contrário.
     */
    virtual bool add(System* s) = 0;

    /**
     * @brief Adiciona um novo fluxo ao modelo.
     *
     * @param f Ponteiro para o Flow a ser adicionado.
     * @return true se o fluxo foi adicionado com sucesso, false caso contrário.
     */
    virtual bool add(Flow* f) = 0;

    /**
     * @brief Remove um sistema existente do modelo.
     *
     * @param s Ponteiro para o System a ser removido.
     * @return true se o sistema foi removido, false caso contrário.
     */
    virtual bool remove(System* s) = 0;

    /**
     * @brief Remove um fluxo existente do modelo.
     *
     * @param f Ponteiro para o Flow a ser removido.
     * @return true se o fluxo foi removido, false caso contrário.
     */
    virtual bool remove(Flow* f) = 0;

    /**
     * @brief Executa a simulação completa.
     *
     * A simulação ocorre aplicando todos os fluxos do modelo entre as iterações
     * de tempo fornecidas. O comportamento detalhado depende da implementação
     * de cada tipo concreto de Flow.
     *
     * @param startTime Tempo inicial da simulação.
     * @param endTime Tempo final da simulação.
     * @return true se a simulação ocorreu normalmente, false caso haja falhas.
     */
    virtual bool run(int startTime, int endTime) = 0;
};

#endif // MODEL_H_