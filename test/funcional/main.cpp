
/**
 * @file main.cpp
 * @brief Arquivo principal responsável por executar os testes funcionais do simulador.
 *
 * Este arquivo contém apenas a função `main()`, cuja função é chamar
 * os testes funcionais implementados em `functional_tests.cpp`.
 * Ele serve como ponto de entrada para validar o comportamento do simulador
 * completo, verificando a interação entre Model, System e Flow por meio
 * dos cenários definidos nos testes.
 *
 * A execução inclui:
 *  - Teste funcional exponencial.
 *  - Teste funcional logístico.
 *  - Teste funcional complexo envolvendo múltiplos fluxos.
 *
 * Cada teste utiliza asserts para verificar se o simulador está produzindo
 * resultados consistentes e matematicamente corretos.
 *
 * @author Samuel
 * @date 2025
 */

#include "funcional_tests.h"

using namespace std;

int main(void){
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
}