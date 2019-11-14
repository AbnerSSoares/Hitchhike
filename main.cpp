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
    CntrACarona cntrACarona;
    CntrAUsuario cntrAUsuario;

    // Serviço
    StubSAutenticacao sAutenticacao;
    StubSCarona sCarona;
    StubSUsuario sUsuario;

    // Links
    cntrAAutenticacao.setLinkAut(&sAutenticacao);
    cntrACarona.setLinkCar(&sCarona);
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
                if (cntrAAutenticacao.aprAutenticar()) {
                    while (true) {
                        switch(ti.usuario()) {
                            case 1:     // Pesquisar Carona
                                cntrACarona.aprPesquisar();
                                break;
                            case 2:     // Cadastrar Carona
                                cntrACarona.aprCadastrar();
                                break;
                            case 3:     // Listar Reservas
                                break;
                            case 4:     // Excluir Carona
                                cntrACarona.aprExcluir();
                                break;
                            case 5:     // Reservar Carona
                                cntrACarona.aprReservar();
                                break;
                            case 6:     // Cancelar Reserva
                                cntrACarona.aprCancelar();
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
                break;
            case 3:
                cntrACarona.aprPesquisar();
                break;
            default:
                break;
        }
    }

    /* Testes t;
    t.executar();   // Executa testes de dominio e entidade */
}
