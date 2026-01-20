#ifndef FLOWIMPL_H_
#define FLOWIMPL_H_

#include "Flow.h"
#include "HandleBody.h"

/*  
    @class FlowBody: Implementação concreta do Flow (Usa Handle/Body)
    @brief Classe que implementa a lógica interna do fluxo, utilizando o padrão Handle/Body.
*/
class FlowBody : public Body {
private:
    System* source;
    System* target;

public:
    FlowBody();
    virtual ~FlowBody();

    void setSource(System* s);
    System* getSource() const;
    void setTarget(System* t);
    System* getTarget() const;

    friend class unit_Flow; // Para testes unitários
};

/*
    @class FlowHandle: Interface pública do Flow (Usa Handle/Body)
    @brief Classe que implementa a interface pública do fluxo, utilizando o padrão Handle/Body.
*/
class FlowHandle : public Flow, public Handle<FlowBody> {
public:
    FlowHandle();
    FlowHandle(System* source, System* target);
    virtual ~FlowHandle();

    bool setSource(System* s) override;
    System* getSource() const override;
    bool setTarget(System* t) override;
    System* getTarget() const override;

    // execute() continua abstrato
    virtual double execute() = 0;
    friend class unit_Flow; // Para testes unitários
};

#endif // FLOWIMPL_H_