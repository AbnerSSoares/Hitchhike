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
    // Fim codigo teste
}
