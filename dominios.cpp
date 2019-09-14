cd d#include <stdexcept>
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

<<<<<<< HEAD


=======
void Codigo_de_banco::validar(string valor) {
    if (valor.length() != 3 || !areDigits(valor)) {
        throw std::invalid_argument("Valor de código de banco inválido!");
    } else {
        return;
    }
}

bool Dominio::areDigits(string valor) {
    for (int i = 0; i < valor.length(); i++) {
        if (!isdigit(valor[i]))
            return false;
    }
    return true;
}
>>>>>>> 1403d4c8f2097a2851d28a8d0dcfaf48f08a6633
