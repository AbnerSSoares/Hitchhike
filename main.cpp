/* Copyright 2019 Abner Soares e Kallebe Sousa */

#include <iostream>
#include "entidades.hpp"
#include "tu_dominios.hpp"
#include "tu_entidades.hpp"

using std::cout;

int main() {
    setlocale(LC_ALL, "portuguese");
    // Codigo Teste
    TU_Assento teste_assento            = TU_Assento("A", "T");
    TU_Bagagem teste_bag                = TU_Bagagem("D", "0");
    TU_Codigo_de_banco teste_banco      = TU_Codigo_de_banco("5sd", "123");
    TU_Codigo_de_carona teste_ccarona    = TU_Codigo_de_carona("123A", "0123");
    TU_Codigo_de_reserva teste_creserva  = TU_Codigo_de_reserva("9414", "46175");
    TU_Cpf teste_cpf                    = TU_Cpf("123.456.789-10", "591.581.540-51");
    TU_Cidade teste_cidade              = TU_Cidade("Cida345de", "Brasília");
    TU_Data teste_data                  = TU_Data("1/12/2000", "10/12/2000");
    TU_Duracao teste_duracao            = TU_Duracao("5h", "22");
    TU_Estado teste_estado              = TU_Estado("Acre", "AC");
    TU_Email teste_email                = TU_Email("hermenegildo.@ocmd.com", "juris@uvt.com.br");
    TU_Nome teste_nome                  = TU_Nome("Karen112780", "Hermenegildo.");
    TU_Numero_de_agencia teste_agencia  = TU_Numero_de_agencia("1234-5", "7992-1");
    TU_Numero_de_conta teste_nconta      = TU_Numero_de_conta("123456-7", "799273-8");
    TU_Preco teste_preco                = TU_Preco("5000,01", "3500,45");
    TU_Telefone teste_telefone          = TU_Telefone("55-61-000000000", "55-55-555555555");
    TU_Vagas teste_vagas                = TU_Vagas("7", "3");
    TU_Senha teste_senha                = TU_Senha("11ert", "Zj9$2");

    if (teste_bag.run()) {
        cout << "SUCESSO NO TESTE BAGAGEM!\n";
    } else {
        cout << "FALHA NO TESTE BAGAGEM!\n";
    }
    if (teste_banco.run()) {
        cout << "SUCESSO NO TESTE BANCO!\n";
    } else {
        cout << "FALHA NO TESTE BANCO!\n";
    }
    if (teste_assento.run()) {
        cout << "SUCESSO NO TESTE ASSENTO!\n";
    } else {
        cout << "FALHA NO TESTE ASSENTO!\n";
    }
    if (teste_ccarona.run()) {
        cout << "SUCESSO NO TESTE CARONA!\n";
    } else {
        cout << "FALHA NO TESTE CARONA!\n";
    }
    if (teste_creserva.run()) {
        cout << "SUCESSO NO TESTE RESERVA!\n";
    } else {
        cout << "FALHA NO TESTE RESERVA!\n";
    }
    if (teste_cpf.run()) {
        cout << "SUCESSO NO TESTE CPF!\n";
    } else {
        cout << "FALHA NO TESTE CPF!\n";
    }
    if (teste_cidade.run()) {
        cout << "SUCESSO NO TESTE CIDADE!\n";
    } else {
        cout << "FALHA NO TESTE CIDADE!\n";
    }
    if (teste_data.run()) {
        cout << "SUCESSO NO TESTE DATA!\n";
    } else {
        cout << "FALHA NO TESTE DATA!\n";
    }
    if (teste_duracao.run()) {
        cout << "SUCESSO NO TESTE DURACAO!\n";
    } else {
        cout << "FALHA NO TESTE DURACAO!\n";
    }
    if (teste_estado.run()) {
        cout << "SUCESSO NO TESTE ESTADO!\n";
    } else {
        cout << "FALHA NO TESTE ESTADO!\n";
    }
    if (teste_email.run()) {
        cout << "SUCESSO NO TESTE EMAIL!\n";
    } else {
        cout << "FALHA NO TESTE EMAIL!\n";
    }
    if (teste_nome.run()) {
        cout << "SUCESSO NO TESTE NOME!\n";
    } else {
        cout << "FALHA NO TESTE NOME!\n";
    }
    if (teste_agencia.run()) {
        cout << "SUCESSO NO TESTE AGENCIA!\n";
    } else {
        cout << "FALHA NO TESTE AGENCIA!\n";
    }
    if (teste_nconta.run()) {
        cout << "SUCESSO NO TESTE CONTA!\n";
    } else {
        cout << "FALHA NO TESTE CONTA!\n";
    }
    if (teste_preco.run()) {
        cout << "SUCESSO NO TESTE PRECO!\n";
    } else {
        cout << "FALHA NO TESTE PRECO!\n";
    }
    if (teste_telefone.run()) {
        cout << "SUCESSO NO TESTE TELEFONE!\n";
    } else {
        cout << "FALHA NO TESTE TELEFONE!\n";
    }
    if (teste_senha.run()) {
        cout << "SUCESSO NO TESTE SENHA!\n";
    } else {
        cout << "FALHA NO TESTE SENHA!\n";
    }
    if (teste_vagas.run()) {
        cout << "SUCESSO NO TESTE VAGAS!\n";
    } else {
        cout << "FALHA NO TESTE VAGAS!\n";
    }

    cout << std::endl;

    // Teste de Entidade

    TU_Usuario teste_usuario = TU_Usuario("Jurandismar12780", "Jurandismar",
                                            "00-00-0000", "55-61-999999999",
                                            ".juris@uvt.com", "juris@uvt.com",
                                            "senhaa", "S3nh4",
                                            "12345678910", "591.581.540-51");

    TU_Reserva teste_reserva = TU_Reserva("9414", "46175",
                                           "A", "T",
                                           "D", "0");

    TU_Carona teste_carona   = TU_Carona("123A", "0123",
                                        "Cida345de", "Salvador",
                                        "Acre", "AC",
                                        "Cida345de", "Salvador",
                                        "Acre", "AC",
                                        "1/12/2000", "10/12/2000",
                                        "5h", "22",
                                        "7", "3",
                                        "5000,01", "3500,45");

    TU_Conta teste_conta    = TU_Conta("5sd", "123",
                                       "1234-5", "7992-1",
                                       "123456-7", "799273-8");


    if (teste_usuario.run())
        cout << "SUCESSO NO TESTE DE USUARIO!\n";
    else
        cout << "FALHA NO TESTE DE USUARIO!\n";

    if (teste_reserva.run())
        cout << "SUCESSO NO TESTE DE RESERVA!\n";
    else
        cout << "FALHA NO TESTE DE RESERVA!\n";

    if (teste_carona.run())
        cout << "SUCESSO NO TESTE DE CARONA!\n";
    else
        cout << "FALHA NO TESTE DE CARONA!\n";

    if (teste_conta.run())
        cout << "SUCESSO NO TESTE DE CONTA!\n";
    else
        cout << "FALHA NO TESTE DE CONTA!\n";
    // Fim codigo teste
}
