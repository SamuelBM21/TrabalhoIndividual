/**
 * @file System.h
 * @brief Declaração da classe System, que representa um elemento básico do modelo.
 *
 * A classe System é uma das estruturas fundamentais do simulador baseado na
 * Teoria Geral de Sistemas. Um System representa um "estoque" (stock), isto é,
 * uma entidade que possui um valor armazenado e que pode ser alterado ao longo
 * da simulação por meio dos fluxos (Flows).
 * 
 * @author Samuel
 * @date 2025
 */

#ifndef SYSTEMIMPL_H_
#define SYSTEMIMPL_H_

#include "System.h"
/**
 * @class System
 * @brief Representa um elemento de armazenamento dentro do modelo.
 *
 * Um System contém um único valor numérico, que representa a quantidade atual
 * de um recurso, população, nível, concentração etc., dependendo do contexto
 * do modelo sendo simulado.
 *
 * Essa classe é manipulada pela classe Model e pelos objetos Flow, que
 * alteram seu valor ao longo da execução da simulação.
 */
class SystemImpl : public System {
private:
    /**
     * @brief Valor atual armazenado pelo sistema.
     *
     * Este valor pode ser modificado diretamente pelo Model ou indiretamente
     * pelos Flows durante a simulação.
     */
    double value;

public:
    /**
     * @brief Construtor padrão.
     *
     * Inicializa o sistema com valor igual a 0.
     */
    SystemImpl();

    /**
     * @brief Construtor com valor inicial.
     *
     * Permite criar um System já com um valor definido.
     *
     * @param value Valor inicial do sistema.
     */
    SystemImpl(double value);

    /**
     * @brief Construtor de cópia.
     *
     * Copia o valor de outro System.
     *
     * @param other Objeto System a ser copiado.
     */
    SystemImpl(const System& other);


    /**
     * @brief Destrutor virtual.
     *
     * Mantido virtual para permitir herança segura caso a classe seja estendida.
     */
    virtual ~SystemImpl();

    /**
     * @brief Define um novo valor para o sistema.
     *
     * @param v Novo valor.
     * @return true se o valor foi definido com sucesso.
     */
    bool setValue(double v);

    /**
     * @brief Obtém o valor atual armazenado.
     *
     * @return O valor atual do System.
     */
    double getValue() const;

private:
    /**
     * @brief Operador de atribuição.
     *
     * Substitui o valor atual pelo valor do outro System.
     *
     * @param other Objeto System a ser atribuído.
     * @return Referência para o próprio objeto.
     */
    SystemImpl& operator=(const System& other);

};

#endif // SYSTEM_H_
