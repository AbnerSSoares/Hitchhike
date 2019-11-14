#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <stdexcept>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

// Declaracoes adiantadas.

class ISAutenticacao;
class ISUsuario;
class ISCarona;

class IAAutenticacao {
public:
    // Metodo por meio do qual e solicitado o servioo.
    virtual bool aprAutenticar(Usuario *) = 0;

    // Metodo por meio do qual e estabelecida ligacao (link) com a controladora na camada de servioo.
    virtual void setLinkAut(ISAutenticacao *) = 0;

    // Metodo destrutor virtual.
    virtual ~IAAutenticacao(){}
};

// Declaracao de interface para servioo de autenticacao na camada de servioo.

class ISAutenticacao {
public:
    // Metodo por meio do qual e solicitado o servioo.
    virtual bool autenticar(const Email&, const Senha&, Usuario *) throw(runtime_error) = 0;

    // Metodo destrutor virtual.
    virtual ~ISAutenticacao(){}
};

class IAUsuario {
public:
    //Metodos de usuarios
    virtual bool aprCadastrar() = 0;
    virtual bool aprExcluir(Usuario *) = 0;

    // Metodo por meio do qual e estabelecida ligacao (link) com a controladora na camada de servioo.
    virtual void setLinkUsu(ISUsuario *) = 0;

    // Metodo destrutor virtual.
    virtual ~IAUsuario(){}
};

class ISUsuario{
public:
    // Metodos por meio do quais sao solicitados o servioos.
    virtual bool cadastrar(Usuario&, Conta&) throw(runtime_error) = 0;   // Cadastra um usuario
    virtual bool excluir(Usuario&) throw(runtime_error) = 0;             // Exclui um usuario

    // Metodo destrutor virtual.
    virtual ~ISUsuario(){}
};

class IACarona{
public:
    //Metodos de carona
    virtual bool aprCadastrar(Usuario *) = 0;
    virtual void aprPesquisar() = 0;
    virtual bool aprReservar(Usuario *) = 0;
    virtual void aprListarReservas(Usuario *) = 0;
    virtual bool aprCancelar(Usuario *) = 0;
    virtual bool aprExcluir(Usuario *) = 0;

    // Metodo por meio do qual e estabelecida ligacao (link) com a controladora na camada de servioo.
    virtual void setLinkCar(ISCarona *) = 0;

    // Metodo destrutor virtual.
    virtual ~IACarona(){}
};

class ISCarona{
public:
    // Metodos por meio do quais sao solicitados o servioos.
    virtual bool cadastrar(Carona&, Usuario&) throw(runtime_error) = 0;         //Cadastra uma carona
    virtual bool pesquisar(Carona&, vector<Carona>*, vector<Usuario>*) throw(runtime_error) = 0;    //Pesquisa caronas
    virtual bool reservar(Reserva*, Codigo_de_carona&, Usuario&, Conta*) throw(runtime_error) = 0;  //Realiza uma reserva de carona
    virtual bool pesquisarReservas(Codigo_de_carona&, vector<Reserva>*, vector<Usuario>*) throw(runtime_error) = 0; // Lista reservas
    virtual bool cancelar(Codigo_de_reserva&, Usuario&) throw(runtime_error) = 0;          //Cancela a reserva de carona
    virtual bool excluir(Codigo_de_carona&, Usuario&) throw(runtime_error) = 0;           //Exclui uma carona

    //Metodo destrutor virtual
    virtual ~ISCarona(){}
};

#endif // INTERFACES_HPP
