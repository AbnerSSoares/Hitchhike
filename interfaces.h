#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

<<<<<<< HEAD:interfaces.h
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"
||||||| merged common ancestors:Interfaces/Interfaces.h
#include "dominios.h"
#include "entidades.h"
=======
#include "../dominios/dominios.hpp"
#include "../entidades/entidades.hpp"
>>>>>>> aeb4ed1bc71f031aa91d447e75039710793795a6:Interfaces/Interfaces.h
#include <stdexcept>

using namespace std;

// Declaraï¿½ï¿½es adiantadas.

class ISAutenticacao;
class ISUsuario;
class ISCarona;

class IAAutenticacao {
public:

    // Mï¿½todo por meio do qual ï¿½ solicitado o serviï¿½o.

    virtual bool runAprAut() throw(runtime_error) = 0;

    // Mï¿½todo por meio do qual ï¿½ estabelecida ligaï¿½ï¿½o (link) com a controladora na camada de serviï¿½o.

    virtual void setLinkAut(ISAutenticacao *) = 0;

    // Mï¿½todo destrutor virtual.

    virtual ~IAAutenticacao(){}
};

// Declaraï¿½ï¿½o de interface para serviï¿½o de autenticaï¿½ï¿½o na camada de serviï¿½o.

class ISAutenticacao {
public:

    // Mï¿½todo por meio do qual ï¿½ solicitado o serviï¿½o.

    virtual bool autenticar(const Email&, const Senha&) throw(runtime_error)= 0;

    // Mï¿½todo destrutor virtual.

    virtual ~ISAutenticacao(){}
};

class IAUsuario {
public:

    // Mï¿½todo por meio do qual ï¿½ solicitado o serviï¿½o.

    virtual bool runAprUsu() throw(runtime_error) = 0;

    // Mï¿½todo por meio do qual ï¿½ estabelecida ligaï¿½ï¿½o (link) com a controladora na camada de serviï¿½o.

    virtual void setLinkUsu(ISUsuario *) = 0;

private:

    //Mï¿½todos de usuï¿½rios
    //Verificar os retornos - Pode ser necessï¿½rio retornar bool para o mï¿½dulo de inicializaï¿½ï¿½o

    virtual bool aprCadastrar() throw(runtime_error) = 0;
    virtual bool aprExcluir() throw(runtime_error) = 0;


    // Mï¿½todo destrutor virtual.

    virtual ~IAUsuario(){}
};

class ISUsuario{
public:

    // Mï¿½todos por meio do quais sï¿½o solicitados o serviï¿½os.

    virtual bool cadastrar(Usuario&) throw(runtime_error)= 0;       //Cadastra um usuï¿½rio
    virtual void pesquisar(Usuario&) throw(runtime_error)= 0;       //Pesquisa um usuï¿½rio
    virtual bool excluir(Usuario&) throw(runtime_error)= 0;         //Exclui um usuï¿½rio

    // Mï¿½todo destrutor virtual.

    virtual ~ISUsuario(){}
};

class IACarona{
public:

    // Mï¿½todo por meio do qual ï¿½ solicitado o serviï¿½o.

    virtual bool runAprCar() throw(runtime_error) = 0;

    // Mï¿½todo por meio do qual ï¿½ estabelecida ligaï¿½ï¿½o (link) com a controladora na camada de serviï¿½o.

    virtual void setLinkCar(ISCarona *) = 0;

private:

    //Mï¿½todos de carona
    //Verificar os retornos - Pode ser necessï¿½rio retornar bool para o mï¿½dulo de inicializaï¿½ï¿½o

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

    // Mï¿½todos por meio do quais sï¿½o solicitados o serviï¿½os.

    virtual bool cadastrar(Carona, Usuario) throw(runtime_error) = 0;       //Cadastra uma carona
    virtual Carona pesquisar(Carona&) throw(runtime_error) = 0;             //Pesquisa caronas
    virtual bool reservar(Carona, Usuario) throw(runtime_error) = 0;        //Realiza uma reserva de carona
    virtual bool cancelar(Carona, Usuario) throw(runtime_error) = 0;        //Cancela a reserva de carona
    virtual bool excluir(Codigo_de_carona) throw(runtime_error) = 0;        //Exclui uma carona

    //Mï¿½todo destrutor virtual

    virtual ~ISCarona(){}
};

#endif // INTERFACES_H_INCLUDED
