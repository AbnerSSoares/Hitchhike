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
    CntrAInicializacao cntrAInicializacao;

    // Serviço
    StubSAutenticacao sAutenticacao;
    StubSCarona sCarona;
    StubSUsuario sUsuario;

    // Links
    cntrAAutenticacao.setLinkAut(&sAutenticacao);
    cntrACarona.setLinkCar(&sCarona);
    cntrAUsuario.setLinkUsu(&sUsuario);
    cntrAInicializacao.setLinkAut(&cntrAAutenticacao);
    cntrAInicializacao.setLinkCar(&cntrACarona);
    cntrAInicializacao.setLinkUsu(&cntrAUsuario);

    /* Tela inicialização */
    cntrAInicializacao.aprInicial();

    /* Testes t;
    t.executar();   // Executa testes de dominio e entidade */

    return 0;
}
