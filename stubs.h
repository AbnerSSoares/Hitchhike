#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

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
    bool excluir(Usuario&) throw(runtime_error);
};











#endif // STUBS_H_INCLUDED

