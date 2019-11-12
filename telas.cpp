#include "telas.hpp"
#include <string.h>
#include <iostream>
#include "curses.h"

using namespace std;

void TelaAutenticacao::autenticar(Email *email, Senha *senha) {
    char lblEmail[25] = "Digite seu email: ";
    char lblSenha[25] = "Digite sua senha: ";
    char txtEmail[50], txtSenha[20];
    int linha, coluna;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(linha/2, (coluna - strlen(lblEmail))/2, "%s", lblEmail);
    getstr(txtEmail);
    mvprintw(linha/2 + 2, (coluna - strlen(lblSenha))/2, "%s", lblSenha);
    getstr(txtSenha);
    clear();
    endwin();

    email->setValor(txtEmail);
    senha->setValor(txtSenha);
}
