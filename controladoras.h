#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

//CONTROLADORAS DE APRESENTA��O

#include "interfaces.h"
#include <stdexcept>
#include <iostream>

using namespace std;

class CntrAUntenticacao : public IAAutenticacao{
public:
    // M�todo por meio do qual � solicitado o servi�o.

    bool runAprAut() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    void setLinkAut(ISAutenticacao *);

    // M�todo destrutor

    ~IAAutenticacao(){}

};

class CntrAUsuario : public IAUsuario{
public:

    // M�todo por meio do qual � solicitado o servi�o.

    bool runAprUsu() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    void setLinkUsu(ISUsuario *);

private:

    //M�todos de usu�rios

    bool aprCadastrar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);


    // M�todo destrutor virtual.

    ~IAUsuario(){}

};

class CntrACarona : public IACarona{
public:

    // M�todo por meio do qual � solicitado o servi�o.

    bool runAprCar() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    void setLinkCar(ISCarona *);

private:

    //M�todos de carona

    bool aprCadastrar() throw(runtime_error);
    void aprPesquisar() throw(runtime_error);
    bool aprReservar() throw(runtime_error);
    bool aprCancelar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

    // M�todo destrutor virtual.

    ~IACarona(){}
};

#endif // CONTROLADORAS_H_INCLUDED
