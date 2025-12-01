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

#ifndef MODELIMPL_H_
#define MODELIMPL_H_

#include <iostream>
#include <vector>
#include "Model.h"

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
class ModelImpl : public Model{
protected:
    /**
     * @brief Lista de sistemas pertencentes ao modelo.
     *
     * Cada ponteiro armazena um objeto do tipo System que participa da simulação.
     */
    std::vector<System*> systems;

    /**
     * @brief Lista de fluxos pertencentes ao modelo.
     *
     * Cada objeto Flow define como os valores dos sistemas passam de um para outro.
     */
    std::vector<Flow*> flows;

    /** @brief  */
    int clock = 0;

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa o modelo vazio, sem sistemas e sem fluxos.
     */
    ModelImpl();

    /**
     * @brief Destrutor.
     *
     * Realiza a limpeza das listas de Systems e Flows, quando necessário.
     */
    ~ModelImpl();

    /**
     * @brief Get the clock field on Flow. 
     * @return return a integer with the clock value.
    */
    int getClock();

    /**
     * @brief Gets the iterator pointing to the beginning of the systems in the ModelImp.
     * @return Iterator pointing to the beginning of the systems.
     */
    iteratorSystem systemsBegin() const;

    /**
     * @brief Gets the iterator pointing to the end of the systems in the ModelImp.
     * @return Iterator pointing to the end of the systems.
     */
    iteratorSystem systemsEnd() const;

    /**
     * @brief Gets the iterator pointing to the beginning of the flows in the ModelImp.
     * @return Iterator pointing to the beginning of the flows.
     */
    iteratorFlow flowsBegin() const;

    /**
     * @brief Gets the iterator pointing to the end of the flows in the ModelImp.
     * @return Iterator pointing to the end of the flows.
     */
    iteratorFlow flowsEnd() const;

    /**
     * @brief Adiciona um novo sistema ao modelo.
     *
     * @param s Ponteiro para o System a ser adicionado.
     * @return true se o sistema foi adicionado com sucesso, false caso contrário.
     */
    bool add(System* s);

    /**
     * @brief Adiciona um novo fluxo ao modelo.
     *
     * @param f Ponteiro para o Flow a ser adicionado.
     * @return true se o fluxo foi adicionado com sucesso, false caso contrário.
     */
    bool add(Flow* f);

    /**
     * @brief Remove um sistema existente do modelo.
     *
     * @param s Ponteiro para o System a ser removido.
     * @return true se o sistema foi removido, false caso contrário.
     */
    bool remove(System* s);

    /**
     * @brief Remove um fluxo existente do modelo.
     *
     * @param f Ponteiro para o Flow a ser removido.
     * @return true se o fluxo foi removido, false caso contrário.
     */
    bool remove(Flow* f);

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
    bool run(int startTime, int endTime);

private:
    /**
     * @brief Construtor de cópia.
     *
     * Cria um novo Model copiando listas de sistemas e fluxos do modelo original.
     *
     * @param other Referência para o modelo a ser copiado.
     */
    ModelImpl(const Model& other);

    /**
     * @brief Operador de atribuição.
     *
     * Permite copiar modelos de forma segura, substituindo o conteúdo atual.
     *
     * @param other Modelo a ser atribuído.
     * @return Referência para o objeto atual, após a operação.
     */
    ModelImpl& operator=(const Model& other);
};

#endif