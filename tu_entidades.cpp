/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include "tu_entidades.hpp"


void TU_Usuario::setUp() {
    this-> usuario = new Usuario();
    estado = SUCESSO;
}

void TU_Reserva::setUp() {
    this-> reserva = new Reserva();
    estado = SUCESSO;
}

void TU_Carona::setUp() {
    this-> carona = new Carona();
    estado = SUCESSO;
}

void TU_Conta::setUp() {
    this-> conta = new Conta();
    estado = SUCESSO;
}

void TU_Usuario::tearDown() {
    delete this->usuario;
}

void TU_Reserva::tearDown() {
    delete this->reserva;
}

void TU_Carona::tearDown() {
    delete this->carona;
}

void TU_Conta::tearDown() {
    delete this->conta;
}

//Arrumar cenário de sucesso e falha e arrumar a chamada dos métodos
void TU_Usuario::testarCenarioSucesso() {
    try {

    } catch(std::invalid_argument) {

    }
}

void TU_Usuario::testarCenarioFalha() {
    try {

    } catch(std::invalid_argument) {

    }
}

//fazer uma chamada para cada um
int TU_Usuario::run() {
    setUp();
    testarCenarioFalha();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
