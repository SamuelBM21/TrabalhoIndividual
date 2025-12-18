#ifndef SYSTEMIMPL_H_
#define SYSTEMIMPL_H_

#include "System.h"
#include "HandleBody.h"

// Classe de Implementação (Body)
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

// Classe Handle (Bridge)
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