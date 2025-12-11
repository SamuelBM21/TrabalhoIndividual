/**
 * @file ModelImpl.h
 * @brief Implementação concreta da interface Model.
 *
 * A classe ModelImpl fornece uma implementação padrão do mecanismo de simulação,
 * armazenando listas de Systems e Flows e aplicando os fluxos ao longo do tempo.
 *
 * Esta classe é responsável por:
 *  - Gerenciar a memória e organização interna dos objetos do modelo;
 *  - Fornecer iteradores constantes para acesso às coleções;
 *  - Executar a simulação conforme a lógica definida nos Flows.
 *
 * @author Samuel
 * @date 2025
 */

#ifndef MODELIMPL_H_
#define MODELIMPL_H_

#include "Model.h"
#include "SystemImpl.h"

/**
 * @class ModelImpl
 * @brief Implementação concreta da classe Model.
 *
 * Armazena e manipula conjuntos de Systems e Flows, além de executar o
 * processo de simulação. É a implementação padrão usada na aplicação.
 */
class ModelImpl : public Model {
protected:
    /**
     * @brief Lista de sistemas pertencentes ao modelo.
     */
    std::vector<System*> systems;

    /**
     * @brief Lista de fluxos pertencentes ao modelo.
     */
    std::vector<Flow*> flows;

    /*
    * @brief Lista estática de todos os modelos criados.
    */
    static std::vector<Model*> models;

    /// Relógio interno do modelo, representando o tempo atual da simulação.
    int clock = 0;

    /** @copydoc Model::add(System*) */
    bool add(System* s) override;

    /** @copydoc Model::add(Flow*) */
    bool add(Flow* f) override;

    /**
     * @brief Adiciona um modelo ao conjunto de modelos.
     *
     * @param m Ponteiro para o modelo a ser inserido.
     * @return true se o modelo foi adicionado; false caso contrário.
     */
    static bool add(Model* m);

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
     * Realiza a liberação dos sistemas e fluxos associados ao modelo.
     */
    ~ModelImpl();

    /**
     * @copydoc Model::getClock()
     */
    int getClock() const override;

    /** @copydoc Model::systemsBegin() */
    iteratorSystem systemsBegin() const override;

    /** @copydoc Model::systemsEnd() */
    iteratorSystem systemsEnd() const override;

    /** @copydoc Model::flowsBegin() */
    iteratorFlow flowsBegin() const override;

    /** @copydoc Model::flowsEnd() */
    iteratorFlow flowsEnd() const override;

    /**
     * @copydoc Model::createModel()
     */
    static Model* createModel();

    /**
     * @copydoc Model::createSystem(double)
     */
    System* createSystem(double value = 0.0) override;  

    /** @copydoc Model::remove(System*) */
    bool remove(System* s) override;

    /** @copydoc Model::remove(Flow*) */
    bool remove(Flow* f) override;

    /** @copydoc Model::run(int,int) */
    bool run(int startTime, int endTime) override;

private:
    /**
     * @brief Construtor de cópia privado.
     *
     * Impede cópia direta fora da classe.  
     * Implementações internas podem utilizá-lo para duplicar modelos.
     *
     * @param other Modelo a ser copiado.
     */
    ModelImpl(const Model& other);

    /**
     * @brief Operador de atribuição privado.
     *
     * Utilizado internamente para redefinir o conteúdo do modelo.
     *
     * @param other Modelo a ser copiado.
     * @return Referência para o objeto atual.
     */
    ModelImpl& operator=(const Model& other);

    friend class unit_Model;
};

#endif // MODELIMPL_H_
