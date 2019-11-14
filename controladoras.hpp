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
    // Metodo por meio do qual é solicitado o servico.
    bool autenticar() throw(runtime_error);

    // Metodo por meio do qual é estabelecida ligacao (link) com a controladora na camada de servico.
    void setLinkAut(ISAutenticacao *ref) {
        this->sAutenticacao = ref;
    }

    // Metodo destrutor
    ~CntrAAutenticacao(){}
};

class CntrAUsuario : public IAUsuario{
private:
    ISUsuario *sUsuario;

public:
    //Metodos de usuarios
    bool aprCadastrar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

    // Metodo por meio do qual é estabelecida ligacao (link) com a controladora na camada de servico.
    void setLinkUsu(ISUsuario *ref) {
        this->sUsuario = ref;
    }

    // Metodo destrutor
    ~CntrAUsuario(){}
};

class CntrACarona : public IACarona{
private:
    ISCarona *sCarona;

public:
    //Metodos de carona
    bool aprCadastrar() throw(runtime_error);
    void aprPesquisar() throw(runtime_error);
    bool aprReservar() throw(runtime_error);
    bool aprCancelar() throw(runtime_error);
    bool aprExcluir() throw(runtime_error);

    // Metodo por meio do qual é estabelecida ligacao (link) com a controladora na camada de servico.
    void setLinkCar(ISCarona *ref) {
        this->sCarona = ref;
    }

    // Metodo destrutor virtual.
    ~CntrACarona(){}
};

#endif // CONTROLADORAS_HPP
