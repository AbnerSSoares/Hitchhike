#include "controladoras.hpp"
#include "telas.hpp"
#include "dominios/dominios.hpp"
#include "entidades/entidades.hpp"

void CntrAInicializacao::aprInicial() {
    TelaInicializacao ti;
    Usuario *current_user = new Usuario();

    while (true) {
        switch(ti.incializacao()) {
            case -1:
                return;
            case 1:
                this->aUsuario->aprCadastrar();
                break;
            case 2:
                if (this->aAutenticacao->aprAutenticar(current_user))
                    this->aprUsuario(current_user);
                break;
            case 3:
                this->aCarona->aprPesquisar();
                break;
            default:
                break;
        }
    }
}

void CntrAInicializacao::aprUsuario(Usuario *current_user) {
    TelaInicializacao ti;

    while (true) {
        switch(ti.usuario()) {
            case 1:     // Pesquisar Carona
                this->aCarona->aprPesquisar();
                break;
            case 2:     // Cadastrar Carona
                this->aCarona->aprCadastrar(current_user);
                break;
            case 3:     // Listar Reservas
                this->aCarona->aprListarReservas(current_user);
                break;
            case 4:     // Excluir Carona
                this->aCarona->aprExcluir(current_user);
                break;
            case 5:     // Reservar Carona
                this->aCarona->aprReservar(current_user);
                break;
            case 6:     // Cancelar Reserva
                this->aCarona->aprCancelar(current_user);
                break;
            case 7:     // Descadastrar do sistema
                if (this->aUsuario->aprExcluir(current_user))
                    goto end_loop;
                break;
            case -1:    // Sair
                goto end_loop;
            default:
                break;
        }
    }
    end_loop:
        return;
}

bool CntrAUsuario::aprCadastrar() {
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

bool CntrAUsuario::aprExcluir(Usuario *current_user) {
    TelaMensagem tm;
    bool sucesso;

    // Solicitar exclusao
    try {
        sucesso = sUsuario->excluir(*current_user);
    } catch (runtime_error e) {
        tm.show(e.what());
    }

    sucesso ? tm.show("Conta excluida com sucesso!") : tm.show("Falha no descadastramento!");

    return sucesso;
}

bool CntrAAutenticacao::aprAutenticar(Usuario *current_user) {
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
        sAutenticacao->autenticar(email, senha, current_user) ? sucesso = true : sucesso = false;
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    if (!sucesso)
        tm.show("Falha na autenticacao do usuario!");

    return sucesso;
}

bool CntrACarona::aprCadastrar(Usuario *current_user) {
    Carona carona;
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
        sucesso = sCarona->cadastrar(carona, *current_user);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    sucesso ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastramento da carona!");

    return sucesso;
}

bool CntrACarona::aprExcluir(Usuario *current_user) {
    Codigo_de_carona codCarona;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de exclusao
    while (true) {
        TelaCarona tc;
        if (tc.pesquisarCarona(&codCarona))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar exclusao
    try {
        sucesso = sCarona->excluir(codCarona, *current_user);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }
    sucesso ? tm.show("Carona excluida com sucesso!") : tm.show("Falha na exclusao da carona!");

    return sucesso;
}

bool CntrACarona::aprReservar(Usuario *current_user) {
    Reserva reserva;
    Codigo_de_carona codCarona;
    Conta conta_motorista;
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
        sucesso = sCarona->reservar(&reserva, codCarona, *current_user, &conta_motorista);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }

    TelaCarona tc;
    sucesso ? tc.mostrarReserva(conta_motorista, reserva) : tm.show("Falha na exclusao da carona!");

    return sucesso;
}

void CntrACarona::aprListarReservas(Usuario *current_user) {
    Codigo_de_carona codCarona;
    vector<Reserva> reservas;
    vector<Usuario> passageiros;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de pesquisa de carona
    while (true) {
        TelaCarona tc;
        if (tc.pesquisarCarona(&codCarona))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar listagem de reserva
    try {
        sucesso = sCarona->pesquisarReservas(codCarona, &reservas, &passageiros);
    } catch (runtime_error e) {
        tm.show(e.what());
        return;
    }

    TelaCarona tc;
    sucesso ? tc.mostrarReservas(reservas, passageiros) : tm.show("Nenhuma reserva encontrada!");

    return;
}

bool CntrACarona::aprCancelar(Usuario *current_user) {
    Codigo_de_reserva codReserva;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de cancelamento de reserva
    while (true) {
        TelaCarona tc;
        if (tc.cancelarReserva(&codReserva))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar cancelamento reserva
    try {
        sucesso = sCarona->cancelar(codReserva, *current_user);
    } catch (runtime_error e) {
        tm.show(e.what());
        return false;
    }

    sucesso ? tm.show("Reserva cancelada com sucesso!") : tm.show("Falha no cancelamento da reserva!");

    return sucesso;
}

void CntrACarona::aprPesquisar() {
    Carona carona;
    vector<Carona> caronas;
    vector<Usuario> motoristas;
    TelaMensagem tm;
    bool sucesso;

    // Apresentar tela de cancelamento de reserva
    while (true) {
        TelaCarona tc;
        if (tc.pesquisar(&carona))
            break;
        else
            tm.show("Preencha os dados corretamente!");
    }

    // Solicitar cancelamento reserva
    try {
        sucesso = sCarona->pesquisar(carona, &caronas, &motoristas);
    } catch (runtime_error e) {
        tm.show(e.what());
        return;
    }

    TelaCarona tc;
    sucesso ? tc.mostrarCaronas(caronas, motoristas) : tm.show("Nenhuma carona encontrada!");

    return;
}
