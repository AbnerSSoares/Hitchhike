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

<<<<<<< HEAD
    ~IAAutenticacao(){}
=======
    ~CntrAUntenticacao(){}
>>>>>>> CorreÃ§Ã£o de interfaces e controladoras

};

class CntrAUsuario : public IAUsuario{
public:

    // Método por meio do qual é solicitado o serviço.

    bool runAprUsu() throw(runtime_error);

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    void setLinkUsu(ISUsuario *);

<<<<<<< HEAD
=======
    // Método destrutor virtual.

    ~CntrAUsuario(){}

>>>>>>> CorreÃ§Ã£o de interfaces e controladoras
private:

    //Métodos de usuários

    bool aprCadastrar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

<<<<<<< HEAD

    // Método destrutor virtual.

    ~IAUsuario(){}

=======
>>>>>>> CorreÃ§Ã£o de interfaces e controladoras
};

class CntrACarona : public IACarona{
public:

    // Método por meio do qual é solicitado o serviço.

    bool runAprCar() throw(runtime_error);

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    void setLinkCar(ISCarona *);

<<<<<<< HEAD
=======
    // Método destrutor virtual.

    ~CntrACarona(){}
>>>>>>> CorreÃ§Ã£o de interfaces e controladoras
private:

    //Métodos de carona

    bool aprCadastrar() throw(runtime_error);
    void aprPesquisar() throw(runtime_error);
    bool aprReservar() throw(runtime_error);
    bool aprCancelar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

<<<<<<< HEAD
    // Método destrutor virtual.

    ~IACarona(){}
=======

>>>>>>> CorreÃ§Ã£o de interfaces e controladoras
};

#endif // CONTROLADORAS_HPP
