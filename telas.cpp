#include "telas.hpp"
#include <string.h>
#include <iostream>
#include "curses.h"

using namespace std;

void TelaAutenticacao::autenticar(Email *email, Senha *senha) {
    char *titulo   = "Cadastro de Usuario";
    char *lblEmail = "Digite seu email: ";
    char *lblSenha = "Digite sua senha: ";
    char *mensErro = "Dados invalidos!";
    char txtEmailc[20], txtSenhac[15];
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(linha/8, (coluna - strlen(lblEmail))/2, "%s", titulo);
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
    char *titulo        = "Cadastro de usuario";
    char *lblNome       = "Nome: ";
    char *lblEmail      = "Email: ";
    char *lblTelefone   = "Telefone: ";
    char *lblSenha      = "Senha: ";
    char *lblCpf        = "Cpf: ";
    char *lblCodBanco   = "Codigo de banco: ";
    char *lblNumAgencia = "Numero da agencia: ";
    char *lblNumConta   = "Numero da conta: ";
    char *mensErro      = "Dados invalidos!";
    char txtNomec[21], txtEmailc[42], txtTelefonec[17], txtSenhac[6], txtCpfc[16];
    char txtCodBancoc[4], txtNumAgenciac[7], txtNumContac[9];
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de cadastro de usuario
    mvprintw(linha/8, coluna/8, "%s", lblNome);
    getstr(txtNomec);

    mvprintw(linha/8+2, coluna/8, "%s", lblCpf);
    getstr(txtCpfc);

    mvprintw(linha/8+4, coluna/8, "%s", lblTelefone);
    getstr(txtTelefonec);

    mvprintw(linha/8+6, coluna/8, "%s", lblEmail);
    getstr(txtEmailc);

    mvprintw(linha/8+8, coluna/8, "%s", lblSenha);
    getstr(txtSenhac);

    //Campos cadastro conta
    mvprintw(linha/8+10, coluna/8, "%s", lblCodBanco);
    getstr(txtCodBancoc);

    mvprintw(linha/8+12, coluna/8, "%s", lblNumAgencia);
    getstr(txtNumAgenciac);

    mvprintw(linha/8+14, coluna/8, "%s", lblNumConta);
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

    int i = 16;
    try {
        user->setNome(txtNome);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Nome invalido!");
        i++;
    }
    try {
        user->setEmail(txtEmail);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Email invalido!");
        i++;
    }
    try {
        user->setSenha(txtSenha);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Senha invalida!");
        i++;
    }
    try {
        user->setCpf(txtCpf);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "CPF invalido!");
        i++;
    }
    try {
        user->setTelefone(txtTelefone);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Telefone invalido!");
        i++;
    }
    try {
        conta->setCodigo_de_banco(txtCodBanco);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Codigo de Banco invalido!");
        i++;
    }
    try {
        conta->setNumero_de_agencia(txtNumAgencia);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Numero de Agencia invalido!");
        i++;
    }
    try {
        conta->setNumero_de_conta(txtNumConta);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Numero de Conta invalido!");
        i++;
    }

    noecho();
    getch();
    echo();
    clear();
    endwin();
}
