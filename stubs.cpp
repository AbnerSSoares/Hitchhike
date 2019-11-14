#include "stubs.hpp"

// Definicoes de metodo da classe stub do controlador da logica de negocio de autenticacao.

bool StubSAutenticacao::autenticar(const Email &email, const Senha &senha) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubSAutenticacao::autenticar" << endl ;

    cout << "Email = " << email.getValor() << endl ;
    cout << "Senha     = " << senha.getValor()     << endl ;

    // Diferentes comportamentos dependendo do valor do email.

    if(email.getValor() == TRIGGER_FALHA) {
        return false;
    } else if (email.getValor() == TRIGGER_ERRO_SISTEMA) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

bool StubSUsuario::cadastrar(Usuario &usuario, Conta &conta) throw(runtime_error) {

   // Apresentar dados recebidos.

    cout << endl << "StubSUsuario::cadastrar" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getNome().getValor() == TRIGGER_FALHA_CAD) {
        return false;
    } else if (usuario.getNome().getValor() == TRIGGER_ERRO_SISTEMA_CAD) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

void StubSUsuario::pesquisar(Usuario &usuario) throw(runtime_error) {

   // Apresentar dados recebidos.

    /*cout << endl << "StubSUsuario::cadastrar" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getNome().getValor() == TRIGGER_FALHA_CAD) {
        return false;
    } else if (usuario.getNome().getValor() == TRIGGER_ERRO_SISTEMA_CAD) {
        throw runtime_error("Erro de sistema");
    }*/

    return;
}

bool StubSUsuario::excluir(Usuario &usuario) throw(runtime_error) {

   // Apresentar dados recebidos.

    cout << endl << "StubSUsuario::excluir" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getEmail().getValor() == TRIGGER_FALHA_EXC) {
        return false;
    } else if (usuario.getEmail().getValor() == TRIGGER_ERRO_SISTEMA_EXC) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}
bool StubSCarona::cadastrar(Carona &carona, Usuario &usuario) throw(runtime_error) {
    //Apresentar dados recebidos

    cout << endl << "StubSCarona::cadastrar" << endl ;
    cout << "Nome = " << carona.getCodigo_de_carona().getValor() << endl ;

    if(carona.getCodigo_de_carona().getValor() == TRIGGER_FALHA_CAD) {
        return false;
    } else if (carona.getCodigo_de_carona().getValor() == TRIGGER_ERRO_SISTEMA_CAD) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

Carona StubSCarona::pesquisar(Carona &carona)throw(runtime_error) {
    //Apresentar dados recebidos

    /*cout << endl << "StubSCarona::pesquisar" << endl ;
    cout << "Nome = " << carona.getCidadeOrigem().getValor() << endl ;

    if (carona.getCidadeOrigem().getValor() == TRIGGER_FALHA_PES) {
        return NULL;
    } else if (carona.getCidadeOrigem().getValor() == TRIGGER_ERRO_SISTEMA_PES) {
        throw runtime_error("Erro de sistema!");
    }
    return carona;*/
}

bool StubSCarona::reservar(Reserva &reserva, Codigo_de_carona &codCarona, Usuario &usuario, Conta *conta_motorista) throw(runtime_error) {
    //Apresentar dados recebidos

    if (codCarona.getValor() == TRIGGER_FALHA_RES) {
        return false;
    } else if (codCarona.getValor() == TRIGGER_ERRO_SISTEMA_RES) {
        throw runtime_error("Erro de sistema!");
    }

    // Simula conta do motorista
    conta_motorista->setCodigo_de_banco("123");
    conta_motorista->setNumero_de_agencia("7992-1");
    conta_motorista->setNumero_de_conta("799273-8");

    return true;
}

bool StubSCarona::cancelar(Carona &carona, Usuario &usuario)throw(runtime_error) {
    //Apresentar dados recebidos

    cout << endl << "StubSCarona::cancelar" << endl ;
    cout << "Nome = " << carona.getCodigo_de_carona().getValor() << endl ;

    if(carona.getCodigo_de_carona().getValor() == TRIGGER_FALHA_CAN) {
        return false;
    } else if (carona.getCodigo_de_carona().getValor() == TRIGGER_ERRO_SISTEMA_CAN) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

bool StubSCarona::excluir(Codigo_de_carona &codigo) throw(runtime_error) {
    //Apresentar dados recebidos

    cout << endl << "StubSCarona::excluir" << endl ;
    cout << "Nome = " << codigo.getValor() << endl ;

    if(codigo.getValor() == TRIGGER_FALHA_DEL) {
        return false;
    } else if (codigo.getValor() == TRIGGER_ERRO_SISTEMA_DEL) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}
