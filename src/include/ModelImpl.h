/**
 * @file ModelImpl.h
 * @brief Implementação do padrão Handle/Body para Model.
 * @author Samuel
 */

#ifndef MODELIMPL_H_
#define MODELIMPL_H_

#include "Model.h"
#include "HandleBody.h"
#include "SystemImpl.h" 
#include "FlowImpl.h"
#include <vector>

/*
    @class ModelBody: Implementação concreta do Model (Usa Handle/Body)
    @brief Classe que implementa a lógica interna do modelo, utilizando o padrão Handle/Body.
*/
class ModelBody : public Body {
public:
    std::vector<System*> systems;
    std::vector<Flow*> flows;
    int clock;

    ModelBody();
    virtual ~ModelBody();

    void add(System* s);
    void add(Flow* f);
    
    // Iteradores e Run
    typedef std::vector<System*>::iterator iteratorSystem;
    typedef std::vector<Flow*>::iterator iteratorFlow;

    iteratorSystem systemsBegin();
    iteratorSystem systemsEnd();
    iteratorFlow flowsBegin();
    iteratorFlow flowsEnd();

    void run(int start, int end);
};

/*
    @class ModelHandle: Interface pública do Model (Usa Handle/Body)
    @brief Classe que implementa a interface pública do modelo, utilizando o padrão Handle/Body.
    
*/
class ModelHandle : public Model, public Handle<ModelBody> {
public:
    ModelHandle();
    virtual ~ModelHandle();

    // Factories (Única forma pública de adicionar elementos)
    static Model* createModel();
    System* createSystem(double value = 0.0) override;

    // Métodos de execução e acesso
    int getClock() const override;
    bool run(int startTime, int endTime) override;

    // Iteradores
    iteratorSystem systemsBegin() const override;
    iteratorSystem systemsEnd() const override;
    iteratorFlow flowsBegin() const override;
    iteratorFlow flowsEnd() const override;

    // Remoção
    bool remove(System* s) override;
    bool remove(Flow* f) override;

protected:
    // MÉTODOS RESTRITOS: 
    bool add(System* s) override;
    bool add(Flow* f) override;

private:
    // Permite que os testes unitários acessem os métodos protegidos
    friend class unit_Model; 
};

#endif // MODELIMPL_H_