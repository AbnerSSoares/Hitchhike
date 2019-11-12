#include "telas.hpp"
#include <string.h>
#include <iostream>
#include "curses.h"

using namespace std;

void TelaAutenticacao::autenticar(Email *email, Senha *senha) {
    char *lblEmail = "Digite seu email: ";
    char *lblSenha = "Digite sua senha: ";
    char *txtEmailc, *txtSenhac;
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(linha/2, (coluna - strlen(lblEmail))/2, "%s", lblEmail);
    getstr(txtEmailc);
    mvprintw(linha/2 + 2, (coluna - strlen(lblSenha))/2, "%s", lblSenha);
    getstr(txtSenhac);
    clear();
    endwin();

    string txtEmails(txtEmailc);
    string txtSenhas(txtSenhac);

    email->setValor(txtEmails);
    senha->setValor(txtSenhas);
}
