#ifndef TELAS_HPP
#define TELAS_HPP

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

class TelaInicializacao {
public:
    void incializacao();
};

class TelaAutenticacao {
public:
    void autenticar(Email *, Senha *);
};

class TelaUsuario {
public:
    void cadastrar(Usuario *, Conta*);
    void pesquisar(Email *);
    void editar(Usuario);
    void excluir(Email);
};

class TelaCarona {
public:
    void cadastrar(Carona, Usuario);
    void pesquisar(Carona *);
    void reservar(Carona, Usuario);
    void cancelarReserva(Carona, Usuario);
};

#endif // TELAS_HPP
