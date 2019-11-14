#ifndef CONTROLADORAS_HPP
#define CONTROLADORAS_HPP

// CONTROLADORAS DE APRESENTACAO

#include <stdexcept>
#include "interfaces.hpp"

using namespace std;

class CntrAAutenticacao : public IAAutenticacao{
private:
    ISAutenticacao *sAutenticacao;

public:
    // M�todo por meio do qual � solicitado o servi�o.
    bool autenticar() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    void setLinkAut(ISAutenticacao *ref) {
        this->sAutenticacao = ref;
    }

    // M�todo destrutor
    ~CntrAAutenticacao(){}
};

class CntrAUsuario : public IAUsuario{
private:
    ISUsuario *sUsuario;

public:
    //M�todos de usu�rios
    bool aprCadastrar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    void setLinkUsu(ISUsuario *ref) {
        this->sUsuario = ref;
    }

    // M�todo destrutor
    ~CntrAUsuario(){}
};

class CntrACarona : public IACarona{
private:
    ISCarona *sCarona;

public:
    //M�todos de carona
    bool aprCadastrar() throw(runtime_error);
    void aprPesquisar() throw(runtime_error);
    bool aprReservar() throw(runtime_error);
    bool aprCancelar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.
    void setLinkCar(ISCarona *ref) {
        this->sCarona = ref;
    }

    // M�todo destrutor virtual.
    ~CntrACarona(){}
};

#endif // CONTROLADORAS_HPP
