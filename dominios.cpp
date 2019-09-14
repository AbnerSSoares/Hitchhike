#include <stdexcept>
#include "dominios.hpp"

void Dominio::setValor(string valor) throw(std::invalid_argument) {
    // Implementar tratamento de exce��o com try catch
    this->validar(valor);
    this->valor = valor;
}


//Valida o valor passado em assento.
void Assento::validar(string valor){
    if (valor.length() == 1 && (valor == "D" || valor == "T")){
        return;
    }else
        throw std::invalid_argument("Assento inválido");

}


void Bagagem::validar(string valor) {
    if (valor.length() != 1 || valor > "4" || valor < "0") {
        throw std::invalid_argument("Valor de bagagem inválido!");
    } else {
        return;
    }
}



