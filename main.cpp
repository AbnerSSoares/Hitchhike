/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <iostream>
#include "entidades.hpp"
#include "tu_dominios.hpp"

using std::cout;

int main() {
    // Codigo Teste
    TU_Assento teste_assento            = TU_Assento("A", "T");
    TU_Bagagem teste_bag                = TU_Bagagem("D", "0");
    TU_Codigo_de_banco teste_banco      = TU_Codigo_de_banco("5sd", "123");
    TU_Codigo_de_carona teste_carona    = TU_Codigo_de_carona("123A", "0123");
    TU_Codigo_de_reserva teste_reserva  = TU_Codigo_de_reserva("9414", "46175");
    TU_Cpf teste_cpf                    = TU_Cpf("12345678910", "70624833119");
    TU_Cidade teste_cidade              = TU_Cidade("Cida345de", "Bras�lia");
    TU_Data teste_data                  = TU_Data("1/12/2000", "10/12/2000");
    TU_Duracao teste_duracao            = TU_Duracao("5h", "22");
    TU_Estado teste_estado              = TU_Estado("Acre", "AC");
    TU_Email teste_email                = TU_Email("hermenegildo.@ocmd.com", "juris@uvt.com.br");
    TU_Nome teste_nome                  = TU_Nome("Karen112780", "Hermenegildo.");
    TU_Numero_de_agencia teste_agencia  = TU_Numero_de_agencia("12345", "79921");
    TU_Numero_de_conta teste_conta      = TU_Numero_de_conta("1234567", "7992738");

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
    if (teste_carona.run()) {
        cout << "SUCESSO NO TESTE CARONA!\n";
    } else {
        cout << "FALHA NO TESTE CARONA!\n";
    }
    if (teste_reserva.run()) {
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
    if (teste_conta.run()) {
        cout << "SUCESSO NO TESTE CONTA!\n";
    } else {
        cout << "FALHA NO TESTE CONTA!\n";
    }

    // Fim codigo teste
}
