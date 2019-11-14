#ifndef STUBS_HPP
#define STUBS_HPP

#include "interfaces.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

// Declara��o de classe stub da interface ISAutenticacao.

class StubSAutenticacao : public ISAutenticacao{
public:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.

    const string TRIGGER_FALHA        = "falha@erro.com";
    const string TRIGGER_ERRO_SISTEMA = "sistema@erro.com";

    // Declara��o de m�todo previsto na interface.

    bool autenticar(const Email&, const Senha&) throw(runtime_error);
};

class StubSUsuario : public ISUsuario{
public:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.
    //O gatilho em usu�rio ser� o nome

    const string TRIGGER_FALHA_CAD           = "Falha";
    const string TRIGGER_ERRO_SISTEMA_CAD    = "Erro";

     //O gatilho em usu�rio ser� o e-mail
    const string TRIGGER_FALHA_EXC           = "falha@erro.com";
    const string TRIGGER_ERRO_SISTEMA_EXC    = "sistema@erro.com";

    //Declara��es de m�todos previstos na interface

    bool cadastrar(Usuario&, Conta&) throw(runtime_error);
    void pesquisar(Usuario&) throw(runtime_error);
    bool excluir(Usuario&) throw(runtime_error);
};

class StubSCarona : public ISCarona{
public:

    // Definicoes de valores a serem usados como gatilhos para notificacoes de erros.
    // Gatilho para cadastramento sera o codigo de carona

    const string TRIGGER_FALHA_CAD        = "9999";
    const string TRIGGER_ERRO_SISTEMA_CAD = "0000";

    // Gatilho para Pesquisa ser� Cidade de partida

    const string TRIGGER_FALHA_PES        = "Formosa";
    const string TRIGGER_ERRO_SISTEMA_PES = "Sobradinho";

    // Gatilho para Reserva de carona ser� c�digo de carona

    const string TRIGGER_FALHA_RES          = "1111";
    const string TRIGGER_ERRO_SISTEMA_RES   = "2222";

    // Gatilho para cancelar reserva de carona ser� c�digo da reserva

    const string TRIGGER_FALHA_CAN          = "00000";
    const string TRIGGER_ERRO_SISTEMA_CAN   = "99999";

    // Gatilho para excluir carona ser� c�digo da carona

    const string TRIGGER_FALHA_DEL          = "5555";
    const string TRIGGER_ERRO_SISTEMA_DEL   = "4444";

    bool cadastrar(Carona&, Usuario&) throw(runtime_error);
    Carona pesquisar(Carona&) throw(runtime_error);
    bool reservar(Reserva*, Codigo_de_carona&, Usuario&, Conta*) throw(runtime_error);
    bool cancelar(Carona&, Usuario&) throw(runtime_error);
    bool excluir(Codigo_de_carona&) throw(runtime_error);

};
#endif // STUBS_HPP
