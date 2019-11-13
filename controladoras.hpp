#ifndef CONTROLADORAS_HPP
#define CONTROLADORAS_HPP

//CONTROLADORAS DE APRESENTAÇÃO

#include "interfaces.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

class CntrAUntenticacao : public IAAutenticacao{
public:
    // Método por meio do qual é solicitado o serviço.

    bool runAprAut() throw(runtime_error);

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    void setLinkAut(ISAutenticacao *);

    // Método destrutor

    ~CntrAUntenticacao(){}

};

class CntrAUsuario : public IAUsuario{
public:

    // Método por meio do qual é solicitado o serviço.

    bool runAprUsu() throw(runtime_error);

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    void setLinkUsu(ISUsuario *);

    // Método destrutor

    ~CntrAUsuario(){}

private:

    //Métodos de usuários

    bool aprCadastrar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

};

class CntrACarona : public IACarona{
public:

    // Método por meio do qual é solicitado o serviço.

    bool runAprCar() throw(runtime_error);

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    void setLinkCar(ISCarona *);

    // Método destrutor virtual.

    ~CntrACarona(){}
private:

    //Métodos de carona

    bool aprCadastrar() throw(runtime_error);
    void aprPesquisar() throw(runtime_error);
    bool aprReservar() throw(runtime_error);
    bool aprCancelar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

};

#endif // CONTROLADORAS_HPP
