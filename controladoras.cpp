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

    // Solicitar autenticacao
    try {
        sucesso = sUsuario->cadastrar(usuario, conta);
    } catch (runtime_error e) {
        tm.show("Erro de sistema!");
        return false;
    }
    sucesso ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastro do usuario!");

    return sucesso;
}

bool CntrAUsuario::aprExcluir() throw(runtime_error) {

}
