#ifndef TELAS_HPP
#define TELAS_HPP

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include "curses.h"

using namespace std;

class TelaMensagem {
public:
    void show(const char*);
};

class TelaInicializacao {
public:
    int incializacao();
    int usuario();

private:
    int startx = 0;
    int starty = 0;

    int montarTela(char* choices[], int n_choices);   /*Monta tela de menu com evento de click*/
    void print_menu(WINDOW*, int, char *choices[], int n_choices);  /* Mostra menu com as opcoes */
    void report_choice(int mouse_x, int mouse_y, int *p_choice, char *choices[], int n_choices); /*Retorna opcao escolhida*/
};

class TelaAutenticacao {
public:
    bool autenticar(Email *, Senha *);
};

class TelaUsuario {
public:
    bool cadastrar(Usuario*, Conta *);
    bool excluir(Email);                //
};

class TelaCarona {
public:
    bool cadastrar(Carona*);
    bool pesquisar(Carona *);
    void mostrarCaronas(vector<Carona>, vector<Usuario>);
    bool pesquisarCarona(Codigo_de_carona *);
    bool reservar(Reserva *, Codigo_de_carona *);
    void mostrarReserva(Conta, Reserva);
    void mostrarReservas(vector<Reserva>, vector<Usuario>);
    bool cancelarReserva(Codigo_de_reserva *);
};

#endif // TELAS_HPP
