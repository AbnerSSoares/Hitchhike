/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <stdexcept>
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

// Teste simultâneo (no mesmo objeto) de sucesso e falha da classe Usuário
void TU_Usuario::testarCenarioSucesso() {
    try {
        usuario->setNome(NOME_INVALIDO);
        if (usuario->getNome().getValor() == NOME_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (usuario->getNome().getValor() == NOME_INVALIDO)
            estado = FALHA;
    }
    try {
        usuario->setNome(NOME_VALIDO);
        if (usuario->getNome().getValor() != NOME_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        usuario->setTelefone(TELEFONE_INVALIDO);
        if (usuario->getTelefone().getValor() == TELEFONE_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (usuario->getTelefone().getValor() == TELEFONE_INVALIDO)
            estado = FALHA;
    }
    try {
        usuario->setTelefone(TELEFONE_VALIDO);
        if (usuario->getTelefone().getValor() != TELEFONE_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        usuario->setEmail(EMAIL_INVALIDO);
        if (usuario->getEmail().getValor() == EMAIL_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (usuario->getEmail().getValor() == EMAIL_INVALIDO)
            estado = FALHA;
    }
    try {
        usuario->setEmail(EMAIL_VALIDO);
        if (usuario->getEmail().getValor() != EMAIL_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        usuario->setSenha(SENHA_INVALIDO);
        if (usuario->getSenha().getValor() == SENHA_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (usuario->getSenha().getValor() == SENHA_INVALIDO)
            estado = FALHA;
    }
    try {
        usuario->setSenha(SENHA_VALIDO);
        if (usuario->getSenha().getValor() != SENHA_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        usuario->setCpf(CPF_INVALIDO);
        if (usuario->getCpf().getValor() == CPF_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (usuario->getCpf().getValor() == CPF_INVALIDO)
            estado = FALHA;
    }
    try {
        usuario->setCpf(CPF_VALIDO);
        if (usuario->getCpf().getValor() != CPF_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
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
    //testarCenarioFalha();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
