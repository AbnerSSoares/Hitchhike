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
void TU_Usuario::testarCenario() {
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

void TU_Reserva::testarCenario() {
    try {
        reserva->setCodigo_de_reserva(CODIGO_INVALIDO);
        if (reserva->getCodigo_de_reserva().getValor() == CODIGO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (reserva->getCodigo_de_reserva().getValor() == CODIGO_INVALIDO)
            estado = FALHA;
    }
    try {
        reserva->setCodigo_de_reserva(CODIGO_VALIDO);
        if (reserva->getCodigo_de_reserva().getValor() != CODIGO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
     try {
        reserva->setAssento(ASSENTO_INVALIDO);
        if (reserva->getAssento().getValor() == ASSENTO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (reserva->getAssento().getValor() == ASSENTO_INVALIDO)
            estado = FALHA;
    }
    try {
        reserva->setAssento(ASSENTO_VALIDO);
        if (reserva->getAssento().getValor() != ASSENTO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
     try {
        reserva->setBagagem(BAGAGEM_INVALIDO);
        if (reserva->getBagagem().getValor() == BAGAGEM_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (reserva->getBagagem().getValor() == BAGAGEM_INVALIDO)
            estado = FALHA;
    }
    try {
        reserva->setBagagem(BAGAGEM_VALIDO);
        if (reserva->getBagagem().getValor() != BAGAGEM_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
}
void TU_Carona::testarCenario() {
    try {
        carona->setCodigo_de_carona(CODIGO_INVALIDO);
        if (carona->getCodigo_de_carona().getValor() == CODIGO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getCodigo_de_carona().getValor() == CODIGO_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setCodigo_de_carona(CODIGO_VALIDO);
        if (carona->getCodigo_de_carona().getValor() != CODIGO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        carona->setCidade_origem(CIDADE_ORIGEM_INVALIDO);
        if (carona->getCidadeOrigem().getValor() == CIDADE_ORIGEM_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getCidadeOrigem().getValor() == CIDADE_ORIGEM_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setCidade_origem(CIDADE_ORIGEM_VALIDO);
        if (carona->getCidadeOrigem().getValor() != CIDADE_ORIGEM_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        carona->setEstado_origem(ESTADO_ORIGEM_INVALIDO);
        if (carona->getEstado_origem().getValor() == ESTADO_ORIGEM_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getEstado_origem().getValor() == ESTADO_ORIGEM_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setEstado_origem(ESTADO_ORIGEM_VALIDO);
        if (carona->getEstado_origem().getValor() != ESTADO_ORIGEM_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        carona->setCidade_destino(CIDADE_DESTINO_INVALIDO);
        if (carona->getCidadedestino().getValor() == CIDADE_DESTINO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getCidadedestino().getValor() == CIDADE_DESTINO_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setCidade_destino(CIDADE_DESTINO_VALIDO);
        if (carona->getCidadedestino().getValor() != CIDADE_DESTINO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        carona->setEstado_destino(ESTADO_DESTINO_INVALIDO);
        if (carona->getEstado_destino().getValor() == ESTADO_DESTINO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getEstado_destino().getValor() == ESTADO_DESTINO_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setEstado_destino(ESTADO_DESTINO_VALIDO);
        if (carona->getEstado_destino().getValor() != ESTADO_DESTINO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }

    try {
        carona->setData(DATA_INVALIDO);
        if (carona->getData().getValor() == DATA_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getData().getValor() == DATA_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setData(DATA_VALIDO);
        if (carona->getData().getValor() != DATA_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
     try {
        carona->setDuracao(DURACAO_INVALIDO);
        if (carona->getDuracao().getValor() == DURACAO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getDuracao().getValor() == DURACAO_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setDuracao(DURACAO_VALIDO);
        if (carona->getDuracao().getValor() != DURACAO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
     try {
        carona->setVagas(VAGAS_INVALIDO);
        if (carona->getVagas().getValor() == VAGAS_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getVagas().getValor() == VAGAS_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setVagas(VAGAS_VALIDO);
        if (carona->getVagas().getValor() != VAGAS_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
     try {
        carona->setPreco(PRECO_INVALIDO);
        if (carona->getPreco().getValor() == PRECO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (carona->getPreco().getValor() == PRECO_INVALIDO)
            estado = FALHA;
    }
    try {
        carona->setPreco(PRECO_VALIDO);
        if (carona->getPreco().getValor() != PRECO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
}

void TU_Conta::testarCenario() {
    try {
        conta->setCodigo_de_banco(BANCO_INVALIDO);
        if (conta->getCodigo_de_banco().getValor() == BANCO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (conta->getCodigo_de_banco().getValor() == BANCO_INVALIDO)
            estado = FALHA;
    }
    try {
        conta->setCodigo_de_banco(BANCO_VALIDO);
        if (conta->getCodigo_de_banco().getValor() != BANCO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        conta->setNumero_de_agencia(AGENCIA_INVALIDO);
        if (conta->getNumero_de_agencia().getValor() == AGENCIA_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (conta->getNumero_de_agencia().getValor() == AGENCIA_INVALIDO)
            estado = FALHA;
    }
    try {
        conta->setNumero_de_agencia(AGENCIA_VALIDO);
        if (conta->getNumero_de_agencia().getValor() != AGENCIA_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
    try {
        conta->setNumero_de_conta(NUMERO_INVALIDO);
        if (conta->getNumero_de_conta().getValor() == NUMERO_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (conta->getNumero_de_conta().getValor() == NUMERO_INVALIDO)
            estado = FALHA;
    }
    try {
        conta->setNumero_de_conta(NUMERO_VALIDO);
        if (conta->getNumero_de_conta().getValor() != NUMERO_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
}


int TU_Usuario::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

int TU_Reserva::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

int TU_Carona::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

int TU_Conta::run() {
    setUp();
    testarCenario();
    tearDown();
    return estado;
}

