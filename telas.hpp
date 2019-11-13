#ifndef TELAS_HPP
#define TELAS_HPP

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include "curses.h"

class TelaInicializacao {
public:
    int incializacao();

private:
    int startx = 0;
    int starty = 0;

    void print_menu(WINDOW*, int, char *choices[], int n_choices);
    void report_choice(int mouse_x, int mouse_y, int *p_choice, char *choices[], int n_choices);
};

class TelaAutenticacao {
public:
    bool autenticar(Email *, Senha *);
};

class TelaUsuario {
public:
    bool cadastrar(Usuario*, Conta*);
    bool excluir(Email);
};

class TelaCarona {
public:
    void cadastrar(Carona, Usuario);
    void pesquisar(Carona *);
    void reservar(Carona, Usuario);
    void cancelarReserva(Carona, Usuario);
};

class TelaMensagem {
public:
    void show(char*);
};

#endif // TELAS_HPP
