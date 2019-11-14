#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <stdexcept>
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

using namespace std;

// Declara��es adiantadas.

class ISAutenticacao;
class ISUsuario;
class ISCarona;

class IAAutenticacao {
public:
    // M�todo por meio do qual � solicitado o servi�o.
    virtual bool autenticar() throw(runtime_error) = 0;

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    virtual void setLinkAut(ISAutenticacao *) = 0;

    // M�todo destrutor virtual.
    virtual ~IAAutenticacao(){}
};

// Declara��o de interface para servi�o de autentica��o na camada de servi�o.

class ISAutenticacao {
public:
    // M�todo por meio do qual � solicitado o servi�o.
    virtual bool autenticar(const Email&, const Senha&) throw(runtime_error) = 0;

    // M�todo destrutor virtual.
    virtual ~ISAutenticacao(){}
};

class IAUsuario {
public:
    //M�todos de usu�rios
    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    virtual void setLinkUsu(ISUsuario *) = 0;

    // M�todo destrutor virtual.
    virtual ~IAUsuario(){}
};

class ISUsuario{
public:
    // M�todos por meio do quais s�o solicitados o servi�os.
    virtual bool cadastrar(Usuario&, Conta&) throw(runtime_error)= 0;   // Cadastra um usu�rio
    virtual void pesquisar(Usuario&) throw(runtime_error)= 0;           // Pesquisa um usu�rio
    virtual bool excluir(Usuario&) throw(runtime_error)= 0;             // Exclui um usu�rio

    // M�todo destrutor virtual.
    virtual ~ISUsuario(){}
};

class IACarona{
public:
    //M�todos de carona
    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual void aprPesquisar() throw(runtime_error) = 0;
    virtual bool aprReservar() throw(runtime_error) = 0;
    virtual bool aprCancelar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    virtual void setLinkCar(ISCarona *) = 0;

    // M�todo destrutor virtual.
    virtual ~IACarona(){}
};

class ISCarona{
public:
    // M�todos por meio do quais s�o solicitados o servi�os.
    virtual bool cadastrar(Carona&, Usuario&) throw(runtime_error) = 0;       //Cadastra uma carona
    virtual Carona pesquisar(Carona&) throw(runtime_error) = 0;             //Pesquisa caronas
    virtual bool reservar(Carona&, Usuario&) throw(runtime_error) = 0;        //Realiza uma reserva de carona
    virtual bool cancelar(Carona&, Usuario&) throw(runtime_error) = 0;        //Cancela a reserva de carona
    virtual bool excluir(Codigo_de_carona&) throw(runtime_error) = 0;        //Exclui uma carona

    //M�todo destrutor virtual
    virtual ~ISCarona(){}
};

#endif // INTERFACES_HPP
