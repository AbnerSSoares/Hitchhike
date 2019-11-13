#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.

class ISAutenticacao;
class ISUsuario;
class ISCarona;

class IAAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual bool runAprAut() throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setLinkAut(ISAutenticacao *) = 0;

    // Método destrutor virtual.

    virtual ~IAAutenticacao(){}
};

// Declaração de interface para serviço de autenticação na camada de serviço.

class ISAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual bool autenticar(const Email&, const Senha&) throw(runtime_error)= 0;

    // Método destrutor virtual.

    virtual ~ISAutenticacao(){}
};

class IAUsuario {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual bool runAprUsu() throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setLinkUsu(ISUsuario *) = 0;

private:

    //Métodos de usuários

    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;


    // Método destrutor virtual.

    virtual ~IAUsuario(){}
};

class ISUsuario{
public:

    // Métodos por meio do quais são solicitados o serviços.

    virtual bool cadastrar(Usuario&) throw(runtime_error)= 0;       //Cadastra um usuário
    virtual void pesquisar(Usuario&) throw(runtime_error)= 0;       //Pesquisa um usuário
    virtual bool excluir(Usuario&) throw(runtime_error)= 0;         //Exclui um usuário

    // Método destrutor virtual.

    virtual ~ISUsuario(){}
};

class IACarona{
public:

    // Método por meio do qual é solicitado o serviço.

    virtual bool runAprCar() throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setLinkCar(ISCarona *) = 0;

private:

    //Métodos de carona

    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual void aprPesquisar() throw(runtime_error) = 0;
    virtual bool aprReservar() throw(runtime_error) = 0;
    virtual bool aprCancelar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;



    // Método destrutor virtual.

    virtual ~IACarona(){}

};

class ISCarona{
public:

    // Métodos por meio do quais são solicitados o serviços.

    virtual bool cadastrar(Carona, Usuario) throw(runtime_error) = 0;       //Cadastra uma carona
    virtual Carona pesquisar(Carona&) throw(runtime_error) = 0;             //Pesquisa caronas
    virtual bool reservar(Carona, Usuario) throw(runtime_error) = 0;        //Realiza uma reserva de carona
    virtual bool cancelar(Carona, Usuario) throw(runtime_error) = 0;        //Cancela a reserva de carona
    virtual bool excluir(Codigo_de_carona) throw(runtime_error) = 0;        //Exclui uma carona

    //Método destrutor virtual

    virtual ~ISCarona(){}
};

#endif // INTERFACES_H_INCLUDED
