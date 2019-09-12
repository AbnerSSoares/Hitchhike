#include <stdexcept>
#include "dominios.hpp"

void Dominio::setValor(string valor) throw(std::invalid_argument) {
    // Implementar tratamento de exce��o com try catch
    this->validar(valor);
    this->valor = valor;
}

void Bagagem::validar(string valor) {
    if (valor.length() != 1 || valor > "4" || valor < "0") {
        throw std::invalid_argument("Valor de bagagem inválido!");
    } else {
        return;
    }
}
