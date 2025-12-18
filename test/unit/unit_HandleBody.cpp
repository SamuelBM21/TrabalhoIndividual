/**
 * @file unit_HandleBody.cpp
 * @brief Testes unitários focados no comportamento do padrão Handle/Body.
 * @author Samuel
 * @date 2025
 */

#include "unit_HandleBody.h"
#include "../../src/include/SystemImpl.h"
#include "../../src/include/FlowImpl.h"
#include "../../src/include/ModelImpl.h"
#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;

// Mock necessário pois FlowHandle é abstrato (execute = 0)
class FlowHandleMock : public FlowHandle {
public:
    FlowHandleMock(System* s, System* t) : FlowHandle(s, t) {}
    double execute() override { return 0.0; }
};

void unit_HandleBody::unit_System_HandleBody() {
    cout << "Teste 1 - System Handle/Body: ";

    // 1. Cria o Handle s1
    SystemHandle *s1 = new SystemHandle(10.0);

    // 2. Cria s2 como cópia de s1
    // Pelo padrão, s2 deve apontar para o MESMO body de s1
    SystemHandle *s2 = new SystemHandle(*s1);

    // 3. Modifica s1
    s1->setValue(20.0);

    // 4. Verifica se s2 foi alterado (Prova de vida do Handle/Body)
    // Se falhar aqui, s2 tem sua própria cópia independente (o que estaria errado para este padrão)
    assert(fabs(s2->getValue() - 20.0) < 0.0001);

    delete s1;
    delete s2;

    cout << "Passou!" << endl;
}

void unit_HandleBody::unit_Flow_HandleBody() {
    cout << "Teste 2 - Flow Handle/Body: ";

    System *sys1 = new SystemHandle(100.0);
    System *sys2 = new SystemHandle(0.0);
    System *sys3 = new SystemHandle(50.0);

    // 1. Instancia um FlowHandle (usando o Mock)
    FlowHandleMock *f1 = new FlowHandleMock(sys1, sys2);

    // 2. Cria f2 copiando f1 (devem compartilhar o body)
    FlowHandleMock *f2 = new FlowHandleMock(*f1);

    // 3. Altera a origem de f1
    f1->setSource(sys3);

    // 4. Verifica se f2 enxergou a mudança
    assert(f2->getSource() == sys3);

    delete sys1; delete sys2; delete sys3;
    delete f1; delete f2;

    cout << "Passou!" << endl;
}

void unit_HandleBody::unit_Model_HandleBody() {
    cout << "Teste 3 - Model Handle/Body: ";

    // 1. Cria Modelo m1
    ModelHandle *m1 = new ModelHandle();
    
    // 2. Adiciona um sistema ao m1
    m1->createSystem(10.0);

    // 3. Cria m2 como cópia de m1
    // No C++, se não fosse Handle/Body, m2 seria uma cópia rasa ou profunda independente.
    // Como é Handle/Body, m2 aponta para a mesma estrutura interna.
    ModelHandle *m2 = new ModelHandle(*m1);

    // 4. Adiciona sistema ao m2
    m2->createSystem(20.0);

    // 5. Verifica se m1 possui 2 sistemas (provando que compartilham o container)
    int count = 0;
    for(auto it = m1->systemsBegin(); it != m1->systemsEnd(); it++){
        count++;
    }
    
    assert(count == 2);

    // Cleanup (O Body será deletado quando o último Handle morrer)
    delete m1; 
    delete m2;

    cout << "Passou!" << endl;
}

void unit_HandleBody::run_HandleBody_Tests() {
    unit_System_HandleBody();
    unit_Flow_HandleBody();
    unit_Model_HandleBody();
}