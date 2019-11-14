#include "controladoras.hpp"
#include "telas.hpp"
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

bool CntrAUsuario::aprCadastrar() throw(runtime_error) {
    Usuario usuario;
    Conta conta;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de cadastro
    while (true) {
        TelaUsuario tu;
        if (tu.cadastrar(&usuario, &conta))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar cadastro
    try {
        sucesso = sUsuario->cadastrar(usuario, conta);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    sucesso ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastro do usuario!");

    return sucesso;
}

bool CntrAUsuario::aprExcluir() throw(runtime_error) {

}

bool CntrAAutenticacao::aprAutenticar() throw(runtime_error) {
    Email email;
    Senha senha;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de autenticacao
    while (true) {
        TelaAutenticacao ta;
        if (ta.autenticar(&email, &senha))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar autenticacao
    try {
        sucesso = sAutenticacao->autenticar(email, senha);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    if (!sucesso)
        tm.show("Falha na autenticacao do usuario!");

    return sucesso;
}

bool CntrACarona::aprCadastrar() throw (runtime_error) {
    Carona carona;
    Usuario user;       // temp
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de cadastro
    while (true) {
        TelaCarona tc;
        if (tc.cadastrar(&carona))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar cadastro
    try {
        sucesso = sCarona->cadastrar(carona, user);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    sucesso ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastramento da carona!");

    return sucesso;
}

bool CntrACarona::aprExcluir() throw (runtime_error) {
    Codigo_de_carona codCarona;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de exclusao
    while (true) {
        TelaCarona tc;
        if (tc.excluirCarona(&codCarona))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar exclusao
    try {
        sucesso = sCarona->excluir(codCarona);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    sucesso ? tm.show("Carona excluida com sucesso!") : tm.show("Falha na exclusao da carona!");

    return sucesso;
}

bool CntrACarona::aprReservar() throw (runtime_error) {
    Reserva reserva;
    Codigo_de_carona codCarona;
    Conta conta_motorista;
    Usuario user;      // temp
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de reserva
    while (true) {
        TelaCarona tc;
        if (tc.reservar(&reserva, &codCarona))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar reserva
    try {
        sucesso = sCarona->reservar(&reserva, codCarona, user, &conta_motorista);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }

    TelaCarona tc;
    sucesso ? tc.mostrarReserva(conta_motorista, reserva) : tm.show("Falha na exclusao da carona!");

    return sucesso;
}

bool CntrACarona::aprCancelar() throw (runtime_error) {

}

void CntrACarona::aprPesquisar() throw (runtime_error) {

}
