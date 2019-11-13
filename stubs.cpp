#include "stubs.h"


// Definições de método da classe stub do controlador da lógica de negócio de autenticação.

bool StubSAutenticacao::autenticar(const Email &email, const Senha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubSAutenticacao::autenticar" << endl ;

    cout << "Email = " << email.getValor() << endl ;
    cout << "Senha     = " << senha.getValor()     << endl ;

    // Diferentes comportamentos dependendo do valor da matrícula.

    if(email.getValor() == TRIGGER_FALHA){
        return false;
    }else if (email.getValor() == TRIGGER_ERRO_SISTEMA){
        throw runtime_error("Erro de sistema");
    }

    return true;
}

bool StubSUsuario::cadastrar(Usuario &usuario, Conta &conta) throw(runtime_error){

   // Apresentar dados recebidos.

    cout << endl << "StubSUsuario::cadastrar" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getNome().getValor() == TRIGGER_FALHA_CAD){
        return false;
    }else if (usuario.getNome().getValor() == TRIGGER_ERRO_SISTEMA_CAD){
        throw runtime_error("Erro de sistema");
    }
}
bool StubSUsuario::excluir(Usuario &usuario) throw(runtime_error){

   // Apresentar dados recebidos.

    cout << endl << "StubSUsuario::excluir" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getEmail().getValor() == TRIGGER_FALHA_EXC){
        return false;
    }else if (usuario.getEmail().getValor() == TRIGGER_ERRO_SISTEMA_EXC){
        throw runtime_error("Erro de sistema");
    }
}

