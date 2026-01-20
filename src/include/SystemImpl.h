/*
    @file SystemImpl.h
    @brief Declaração das classes SystemBody e SystemHandle utilizando o padrão Handle/Body.
*/
#ifndef SYSTEMIMPL_H_
#define SYSTEMIMPL_H_

#include "System.h"
#include "HandleBody.h"


/*
    @class SystemBody: Implementação concreta do System (Usa Handle/Body)
    @brief Classe que implementa a lógica interna do sistema, utilizando o padrão Handle/Body.
*/

class SystemBody : public Body {
private:
    double value;

public:
    SystemBody(double v = 0.0);
    virtual ~SystemBody();

    void setValue(double v);
    double getValue() const;
    friend class unit_System; // Para testes unitários
};

/*
    @class SystemHandle: Interface pública do System (Usa Handle/Body)
    @brief Classe que implementa a interface pública do sistema, utilizando o padrão Handle/Body.
*/
class SystemHandle : public System, public Handle<SystemBody> {
public:
    SystemHandle();
    SystemHandle(double value);
    virtual ~SystemHandle();

    bool setValue(double v) override;
    double getValue() const override;
    friend class unit_System; // Para testes unitários
};

#endif // SYSTEMIMPL_H_