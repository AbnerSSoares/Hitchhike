#ifndef CONTROLADORAS_HPP
#define CONTROLADORAS_HPP

// CONTROLADORAS DE APRESENTACAO

#include <stdexcept>
#include "interfaces.hpp"

using namespace std;

class CntrAInicializacao {
private:
    IAAutenticacao *aAutenticacao;
    IACarona *aCarona;
    IAUsuario *aUsuario;

public:
    // Metodo por meio do qual e chamada as telas iniciais
    void aprInicial();
    void aprUsuario(Usuario *);

    // Metodos por meio dos quais e estabelecida ligacao (link) com as controladoras de apresentacao
    void setLinkAut(IAAutenticacao *ref)    { this->aAutenticacao = ref; }
    void setLinkCar(IACarona *ref)          { this->aCarona = ref; }
    void setLinkUsu(IAUsuario *ref)         { this->aUsuario = ref; }
};

class CntrAAutenticacao : public IAAutenticacao {
private:
    ISAutenticacao *sAutenticacao;

public:
    // Metodo por meio do qual é solicitado o servico.
    bool aprAutenticar(Usuario *);

    // Metodo por meio do qual é estabelecida ligacao (link) com a controladora na camada de servico.
    void setLinkAut(ISAutenticacao *ref) { this->sAutenticacao = ref; }

    // Metodo destrutor
    ~CntrAAutenticacao(){}
};

class CntrAUsuario : public IAUsuario {
private:
    ISUsuario *sUsuario;

public:
    //Metodos de usuarios
    bool aprCadastrar();
    bool aprExcluir(Usuario *);

    // Metodo por meio do qual é estabelecida ligacao (link) com a controladora na camada de servico.
    void setLinkUsu(ISUsuario *ref) { this->sUsuario = ref; }

    // Metodo destrutor
    ~CntrAUsuario(){}
};

class CntrACarona : public IACarona{
private:
    ISCarona *sCarona;

public:
    //Metodos de carona
    bool aprCadastrar(Usuario *);
    void aprPesquisar();
    bool aprReservar(Usuario *);
    void aprListarReservas(Usuario *);
    bool aprCancelar(Usuario *);
    bool aprExcluir(Usuario *);

    // Metodo por meio do qual é estabelecida ligacao (link) com a controladora na camada de servico.
    void setLinkCar(ISCarona *ref) { this->sCarona = ref; }

    // Metodo destrutor virtual.
    ~CntrACarona(){}
};

#endif // CONTROLADORAS_HPP
