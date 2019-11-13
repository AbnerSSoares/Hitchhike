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
    /* Testes t;
    t.executar();   // Executa testes de dominio e entidade */

    TelaUsuario tu;
    TelaMensagem tm;
    TelaAutenticacao ta;
    TelaInicializacao ti;
    TelaCarona tc;

    Email email;
    Senha senha;
    Codigo_de_carona codCarona;
    Usuario user;
    Conta conta;
    Carona carona;
    Reserva reserva;

    switch(ti.incializacao()) {
        case 1:
            tu.cadastrar(&user, &conta) ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastro do usuario!");
            break;
        case 2:
            if (ta.autenticar(&email, &senha)) {
                tm.show("Autenticacao realizada com sucesso!");
                switch (ti.usuario()) {
                    case 1:
                        tc.pesquisar(&carona) ? tm.show("Dados da pesquisa corretos!") : tm.show("Falha na pesquisa de caronas!");
                        break;
                    case 2:
                        tc.cadastrar(&carona) ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastro de carona!");
                        break;
                    case 5:
                        tc.reservar(&reserva, &codCarona) ? tm.show("Reserva realizada com sucesso!") : tm.show("Falha na reserva de carona!");
                        break;
                    default:
                        break;
                }
            } else {
                tm.show("Falha na autenticacao do usuario!");
            }
            break;
        case 3:
            tc.pesquisar(&carona) ? tm.show("Dados da pesquisa corretos!") : tm.show("Falha na pesquisa de caronas!");
            break;
        default:
            break;
    }

    /*cout << "Usuario:\n";
    cout << user.getNome().getValor() << "\n";
    cout << user.getCpf().getValor() << "\n";
    cout << user.getEmail().getValor() << "\n";
    cout << user.getSenha().getValor() << "\n";
    cout << user.getTelefone().getValor() << "\n\n";

    cout << "email-auth: " << email.getValor() << "\n";
    cout << "senha-auth: " << senha.getValor() << "\n\n";*/
}
