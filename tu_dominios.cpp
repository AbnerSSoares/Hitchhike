#include "tu_dominios.hpp"

void TU_Bagagem::setUp() {
    this->bagagem = new Bagagem();
    estado = SUCESSO;
}

void TU_Bagagem::tearDown() {
    delete this->bagagem;
}

void TU_Bagagem::testarCenarioSucesso() {
    try {
        this->bagagem->setValor(VALOR_VALIDO);
        if (this->bagagem->getValor() != VALOR_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        estado = FALHA;
    }
}

void TU_Bagagem::testarCenarioFalha() {
    try {
        this->bagagem->setValor(VALOR_INVALIDO);
        if (this->bagagem->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    } catch(std::invalid_argument) {
        if (this->bagagem->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TU_Bagagem::run() {
    setUp();
    testarCenarioFalha();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
