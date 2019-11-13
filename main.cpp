/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <iostream>
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include "testes.hpp"
#include "telas.hpp"
#include "tu_dominios/tu_dominios.hpp"
#include "tu_entidades/tu_entidades.hpp"

using namespace std;

int main() {
    Testes t;
    t.executar();   // Executa testes de dominio e entidade

    Email email;
    Senha senha;
    Usuario user;
    Conta conta;

    TelaUsuario tu;
    tu.cadastrar(&user, &conta);

    TelaAutenticacao ta;
    ta.autenticar(&email, &senha);

    cout << "Usuario:\n";
    cout << user.getNome().getValor() << "\n";
    cout << user.getCpf().getValor() << "\n";
    cout << user.getEmail().getValor() << "\n";
    cout << user.getSenha().getValor() << "\n";
    cout << user.getTelefone().getValor() << "\n\n";

    cout << "email-auth: " << email.getValor() << "\n";
    cout << "senha-auth: " << senha.getValor() << "\n\n";
}
