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

    Email email, email2;
    Senha senha;
    Usuario user;
    Conta conta;

    TelaUsuario tu;
    tu.cadastrar(&user, &conta);
    tu.pesquisar(&email);

    TelaAutenticacao ta;
    ta.autenticar(&email2, &senha);

    cout << "Usuario:\n";
    cout << user.getNome().getValor() << "\n";
    cout << user.getCpf().getValor() << "\n";
    cout << user.getEmail().getValor() << "\n";
    cout << user.getSenha().getValor() << "\n";
    cout << user.getCpf().getValor() << "\n\n";

    cout << "email-pesquisa: " << email.getValor() << "\n\n";
    cout << "email-auth: " << email2.getValor() << "\n";
    cout << "senha-auth: " << senha.getValor() << "\n\n";
}
