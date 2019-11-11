/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <iostream>
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include "testes.hpp"
#include "telas.hpp"
#include "tu_dominios/tu_dominios.hpp"
#include "tu_entidades/tu_entidades.hpp"

int main() {
    Testes t;
    t.executar();   // Executa testes de dominio e entidade

    Email email;
    Senha senha;

    TelaAutenticacao ta;
    ta.autenticar(&email, &senha);

    return 0;
}
