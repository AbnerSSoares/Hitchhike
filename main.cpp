/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <iostream>
#include "controladoras.hpp"
#include "stubs.hpp"
#include "entidades/entidades.hpp"
#include "dominios/dominios.hpp"
#include "testes.hpp"
#include "telas.hpp"
#include "tu_dominios/tu_dominios.hpp"
#include "tu_entidades/tu_entidades.hpp"

using namespace std;

int main() {
    /* Build */
    // Apresentação
    CntrAAutenticacao cntrAAutenticacao;
    //CntrACarona cntrACarona;
    CntrAUsuario cntrAUsuario;

    // Serviço
    StubSAutenticacao sAutenticacao;
    //StubSCarona sCarona;
    StubSUsuario sUsuario;

    // Links
    cntrAAutenticacao.setLinkAut(&sAutenticacao);
    //cntrACarona.setLinkCar(&sCarona);
    cntrAUsuario.setLinkUsu(&sUsuario);

    /* Tela inicialização */
    TelaInicializacao ti;

    while (true) {
        switch(ti.incializacao()) {
            case -1:
                return 0;
            case 1:
                cntrAUsuario.aprCadastrar();
                break;
            case 2:
                if (cntrAAutenticacao.autenticar()) {
                    while (true) {
                        switch(ti.usuario()) {
                            case 1:     // Pesquisar Carona
                                break;
                            case 2:     // Cadastrar Carona
                                break;
                            case 3:     //
                                break;
                            case 4:     // Excluir Carona
                                break;
                            case 5:     // Reservar Carona
                                break;
                            case 6:     // Cancelar Reserva
                                break;
                            case 7:     // Descadastrar do sistema
                                break;
                            case -1:    // Sair
                                goto end_loop;
                            default:
                                break;
                        }
                    }
                    end_loop:
                        break;
                }
                // if (ta.autenticar(&email, &senha)) {
                //     tm.show("Autenticacao realizada com sucesso!");
                //     switch (ti.usuario()) {
                //         case 1:
                //             tc.pesquisar(&carona) ? tm.show("Dados da pesquisa corretos!") : tm.show("Falha na pesquisa de caronas!");
                //             break;
                //         case 2:
                //             tc.cadastrar(&carona) ? tm.show("Cadastramento realizado com sucesso!") : tm.show("Falha no cadastro de carona!");
                //             break;
                //         case 4:
                //             tc.descadastrarCarona(&codCarona) ? tm.show("Descadastramento realizado com sucesso!") : tm.show("Falhaao remover carona!");
                //             break;
                //         case 5:
                //             tc.reservar(&reserva, &codCarona) ? tm.show("Reserva realizada com sucesso!") : tm.show("Falha na reserva de carona!");
                //             break;
                //         case 6:
                //             tc.cancelarReserva(&codCarona) ? tm.show("Reserva cancelada com sucesso!") : tm.show("Falha no cancelamento da reserva!");
                //         default:
                //             break;
                //     }
                // } else {
                //     tm.show("Falha na autenticacao do usuario!");
                // }
                break;
            /*case 3:
                tc.pesquisar(&carona) ? tm.show("Dados da pesquisa corretos!") : tm.show("Falha na pesquisa de caronas!");
                break;*/
            default:
                break;
        }
    }

    /* Testes t;
    t.executar();   // Executa testes de dominio e entidade */
}
