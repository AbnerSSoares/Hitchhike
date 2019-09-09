#include "dominios.hpp"

/**
void Nome::validar(string nome) {
    if (nome.length() > 20) {
        throw invalid_argument;
    }
}**/

void Dominio::setValor(string valor) throw(std::invalid_argument) {
    // Implementar tratamento de exce��o com try catch
    //validar(nome);
    this->valor = valor;
}
