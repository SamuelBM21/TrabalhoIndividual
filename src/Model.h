/**
 * @file Model.h
 * @brief Interface abstrata para representação e execução de modelos na simulação.
 *
 * A classe Model define a estrutura básica para implementação de modelos
 * baseados na Teoria Geral de Sistemas (TGS).  
 * 
 * Um Model é responsável por:
 *  - Gerenciar coleções de objetos System (entidades que armazenam valores).
 *  - Gerenciar coleções de objetos Flow (relações que transferem valores entre systems).
 *  - Coordenar o processo de simulação ao longo do tempo.
 * 
 * Esta classe funciona como o núcleo lógico da simulação, servindo de base
 * para implementações concretas como ModelImpl.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <iostream>
#include <vector>
#include "Flow.h"

/**
 * @class Model
 * @brief Interface abstrata para o gerenciamento de sistemas, fluxos e simulação.
 *
 * Esta classe define a API principal utilizada para manipulação de models
 * dentro do simulador. Implementações concretas devem herdar desta classe
 * e fornecer comportamento específico para armazenamento, remoção e execução.
 */
class Model {
public:
    /**
     * @brief Destrutor virtual padrão.
     *
     * Permite a destruição apropriada via ponteiros para Model.
     */
    virtual ~Model() {}

    /**
     * @brief Retorna o valor atual do relógio do modelo.
     *
     * @return Tempo atual da simulação.
     */
    virtual int getClock() const = 0;

    /** @brief Tipo de iterador constante para percorrer Systems. */
    typedef std::vector<System*>::const_iterator iteratorSystem;

    /** @brief Retorna iterador para o início da lista de sistemas. */
    virtual iteratorSystem systemsBegin() const = 0;

    /** @brief Retorna iterador para o fim da lista de sistemas. */
    virtual iteratorSystem systemsEnd() const = 0;

    /** @brief Tipo de iterador constante para percorrer Flows. */
    typedef std::vector<Flow*>::const_iterator iteratorFlow;

    /** @brief Retorna iterador para o início da lista de fluxos. */
    virtual iteratorFlow flowsBegin() const = 0;

    /** @brief Retorna iterador para o fim da lista de fluxos. */
    virtual iteratorFlow flowsEnd() const = 0;

    /**
     * @brief Adiciona um sistema ao modelo.
     *
     * @param s Ponteiro para o sistema a ser inserido.
     * @return true se o sistema foi adicionado; false caso contrário.
     */
    virtual bool add(System* s) = 0;

    /**
     * @brief Adiciona um fluxo ao modelo.
     *
     * @param f Ponteiro para o fluxo a ser inserido.
     * @return true se o fluxo foi adicionado; false caso contrário.
     */
    virtual bool add(Flow* f) = 0;

    /**
     * @brief Remove um sistema do modelo.
     *
     * @param s Ponteiro para o sistema a ser removido.
     * @return true se o sistema foi removido; false caso contrário.
     */
    virtual bool remove(System* s) = 0;

    /**
     * @brief Remove um fluxo do modelo.
     *
     * @param f Ponteiro para o fluxo a ser removido.
     * @return true se o fluxo foi removido; false caso contrário.
     */
    virtual bool remove(Flow* f) = 0;

    /**
     * @brief Executa a simulação entre dois instantes de tempo.
     *
     * Para cada unidade de tempo entre startTime e endTime, todos os fluxos
     * são processados, atualizando seus sistemas correspondentes.
     *
     * @param startTime Tempo inicial.
     * @param endTime Tempo final.
     * @return true se a simulação foi executada com sucesso.
     */
    virtual bool run(int startTime, int endTime) = 0;
};

#endif // MODEL_H_
