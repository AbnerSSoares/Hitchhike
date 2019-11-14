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
    virtual bool aprAutenticar() throw(runtime_error) = 0;

    // Metodo por meio do qual e estabelecida ligacao (link) com a controladora na camada de servioo.
    virtual void setLinkAut(ISAutenticacao *) = 0;

    // Metodo destrutor virtual.
    virtual ~IAAutenticacao(){}
};

// Declaracao de interface para servioo de autenticacao na camada de servioo.

class ISAutenticacao {
public:
    // Metodo por meio do qual e solicitado o servioo.
    virtual bool autenticar(const Email&, const Senha&) throw(runtime_error) = 0;

    // Metodo destrutor virtual.
    virtual ~ISAutenticacao(){}
};

class IAUsuario {
public:
    //Metodos de usuarios
    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;

    // Metodo por meio do qual e estabelecida ligacao (link) com a controladora na camada de servioo.
    virtual void setLinkUsu(ISUsuario *) = 0;

    // Metodo destrutor virtual.
    virtual ~IAUsuario(){}
};

class ISUsuario{
public:
    // Metodos por meio do quais sao solicitados o servioos.
    virtual bool cadastrar(Usuario&, Conta&) throw(runtime_error)= 0;   // Cadastra um usuario
    virtual void pesquisar(Usuario&) throw(runtime_error)= 0;           // Pesquisa um usuario
    virtual bool excluir(Usuario&) throw(runtime_error)= 0;             // Exclui um usuario

    // Metodo destrutor virtual.
    virtual ~ISUsuario(){}
};

class IACarona{
public:
    //Metodos de carona
    // virtual bool aprCadastrar(Usuario) throw(runtime_error) = 0;
    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual void aprPesquisar() throw(runtime_error) = 0;
    virtual bool aprReservar() throw(runtime_error) = 0;
    virtual bool aprCancelar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;

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
    // virtual bool cancelar(Carona&, Usuario&) throw(runtime_error) = 0;          //Cancela a reserva de carona
    virtual bool cancelar(Codigo_de_reserva&) throw(runtime_error) = 0;          //Cancela a reserva de carona
    virtual bool excluir(Codigo_de_carona&) throw(runtime_error) = 0;           //Exclui uma carona

    //Metodo destrutor virtual
    virtual ~ISCarona(){}
};

#endif // INTERFACES_HPP
