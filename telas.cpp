#include "telas.hpp"
#include <string.h>
#include <iostream>
#include "curses.h"

using namespace std;

void TelaAutenticacao::autenticar(Email *email, Senha *senha) {
    char *lblEmail = "Digite seu email: ";
    char *lblSenha = "Digite sua senha: ";
    char *mensErro = "Dados invalidos!";
    char txtEmailc[20], txtSenhac[15];
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(linha/2, (coluna - strlen(lblEmail))/2, "%s", lblEmail);
    getstr(txtEmailc);
    mvprintw(linha/2 + 2, (coluna - strlen(lblSenha))/2, "%s", lblSenha);
    getstr(txtSenhac);

    string txtEmails = txtEmailc;
    string txtSenhas = txtSenhac;

    try {
        email->setValor(txtEmails);
        senha->setValor(txtSenhas);
    } catch (...) {
        mvprintw(linha/2 + 4, (coluna - strlen(mensErro))/2, "%s", mensErro);
        noecho();
        getch();
        echo();
    }

    clear();
    endwin();
}

void TelaUsuario::cadastrar(Usuario *user, Conta *conta) {
    char *lblNome       = "Nome: ";
    char *lblEmail      = "Email: ";
    char *lblTelefone   = "Telefone: ";
    char *lblSenha      = "Senha: ";
    char *lblCpf        = "Cpf: ";
    char *lblCodBanco   = "Codigo de banco: ";
    char *lblNumAgencia = "Numero da agencia: ";
    char *lblNumConta   = "Numero da conta: ";
    char *mensErro      = "Dados invalidos!";
    char txtNomec[30], txtEmailc[20], txtTelefonec[17], txtSenhac[15], txtCpfc[20];
    char txtCodBancoc[4], txtNumAgenciac[7], txtNumContac[9];
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Campos de cadastro de usuario
    mvprintw(linha/4, (coluna - strlen(lblNome))/2, "%s", lblNome);
    getstr(txtNomec);

    mvprintw(linha/4+2, (coluna - strlen(lblCpf))/2, "%s", lblCpf);
    getstr(txtCpfc);

    mvprintw(linha/4+4, (coluna - strlen(lblTelefone))/2, "%s", lblTelefone);
    getstr(txtTelefonec);

    mvprintw(linha/4+6, (coluna - strlen(lblEmail))/2, "%s", lblEmail);
    getstr(txtEmailc);

    mvprintw(linha/4+8, (coluna - strlen(lblSenha))/2, "%s", lblSenha);
    getstr(txtSenhac);

    //Campos cadastro conta
    mvprintw(linha/4+10, (coluna - strlen(lblCodBanco))/2, "%s", lblCodBanco);
    getstr(txtCodBancoc);

    mvprintw(linha/4+12, (coluna - strlen(lblNumAgencia))/2, "%s", lblNumAgencia);
    getstr(txtNumAgenciac);

    mvprintw(linha/4+14, (coluna - strlen(lblNumConta))/2, "%s", lblNumConta);
    getstr(txtNumContac);

    //Atribuição de valores
    string txtNome = txtNomec;
    string txtEmail = txtEmailc;
    string txtSenha = txtSenhac;
    string txtCpf = txtCpfc;
    string txtTelefone = txtTelefonec;

    string txtCodBanco = txtCodBancoc;
    string txtNumAgencia = txtNumAgenciac;
    string txtNumConta = txtNumContac;

    try {
        user->setNome(txtNome);
        user->setEmail(txtEmail);
        user->setSenha(txtSenha);
        user->setCpf(txtCpf);
        user->setTelefone(txtTelefone);

        conta->setCodigo_de_banco(txtCodBanco);
        conta->setNumero_de_agencia(txtNumAgencia);
        conta->setNumero_de_conta(txtNumConta);
    } catch (char * e) {
        mvprintw(linha/4 + 10, (coluna - strlen(e))/2, "%s", e);
        noecho();
        getch();
        echo();
    }

    clear();
    endwin();
}

void TelaUsuario::pesquisar(Email *email) {
    char * lblEmail = "Email: ";
    char * mensErro = "Email invalido!";
    char txtEmailc[20];
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Campos de cadastro de usuario
    mvprintw(linha/2, (coluna - strlen(lblEmail))/2, "%s", lblEmail);
    getstr(txtEmailc);

    string txtEmail = txtEmailc;

    try {
        email->setValor(txtEmail);
    } catch (...) {
        mvprintw(linha/2 + 10, (coluna - strlen(mensErro))/2, "%s", mensErro);
        noecho();
        getch();
        echo();
    }

    clear();
    endwin();
}
