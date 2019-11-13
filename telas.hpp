#ifndef TELAS_HPP
#define TELAS_HPP

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

class TelaInicializacao {
public:
    int incializacao();
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
