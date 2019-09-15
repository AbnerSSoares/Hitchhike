#include "tu_dominios.hpp"

void TU_Assento::setUp() {
    this->dominio = new Assento();
    estado = SUCESSO;
}

void TU_Bagagem::setUp() {
    this->dominio = new Bagagem();
    estado = SUCESSO;
}

void TU_Codigo_de_banco::setUp() {
    this->dominio = new Codigo_de_banco();
    estado = SUCESSO;
}

void TU_Codigo_de_carona::setUp() {
    this->dominio = new Codigo_de_carona();
    estado = SUCESSO;
}

void TU_Codigo_de_reserva::setUp() {
    this->dominio = new Codigo_de_reserva();
    estado = SUCESSO;
}

void TU_Cpf::setUp() {
    this->dominio = new Cpf();
    estado = SUCESSO;
}

void TU_Dominio::tearDown() {
    delete this->dominio;
}

void TU_Dominio::testarCenarioSucesso() {
    try {
        this->dominio->setValor(VALOR_VALIDO);
        if (this->dominio->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
}

void TU_Dominio::testarCenarioFalha() {
    try {
        this->dominio->setValor(VALOR_INVALIDO);
        if (this->dominio->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (this->dominio->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TU_Dominio::run() {
    setUp();
    testarCenarioFalha();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
