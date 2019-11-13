#ifndef CONTROLADORAS_HPP
#define CONTROLADORAS_HPP

//CONTROLADORAS DE APRESENTA��O

#include "interfaces.hpp"
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

<<<<<<< HEAD
    ~IAAutenticacao(){}
=======
    ~CntrAUntenticacao(){}
>>>>>>> Correção de interfaces e controladoras

};

class CntrAUsuario : public IAUsuario{
public:

    // M�todo por meio do qual � solicitado o servi�o.

    bool runAprUsu() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    void setLinkUsu(ISUsuario *);

<<<<<<< HEAD
=======
    // M�todo destrutor virtual.

    ~CntrAUsuario(){}

>>>>>>> Correção de interfaces e controladoras
private:

    //M�todos de usu�rios

    bool aprCadastrar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

<<<<<<< HEAD

    // M�todo destrutor virtual.

    ~IAUsuario(){}

=======
>>>>>>> Correção de interfaces e controladoras
};

class CntrACarona : public IACarona{
public:

    // M�todo por meio do qual � solicitado o servi�o.

    bool runAprCar() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    void setLinkCar(ISCarona *);

<<<<<<< HEAD
=======
    // M�todo destrutor virtual.

    ~CntrACarona(){}
>>>>>>> Correção de interfaces e controladoras
private:

    //M�todos de carona

    bool aprCadastrar() throw(runtime_error);
    void aprPesquisar() throw(runtime_error);
    bool aprReservar() throw(runtime_error);
    bool aprCancelar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

<<<<<<< HEAD
    // M�todo destrutor virtual.

    ~IACarona(){}
=======

>>>>>>> Correção de interfaces e controladoras
};

#endif // CONTROLADORAS_HPP
