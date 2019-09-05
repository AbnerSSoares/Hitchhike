#include "dominios.hpp"

/**
void Nome::validar(string nome) {
    if (nome.length() > 20) {
        throw invalid_argument;
    }
}**/

void Dominio::setNome(string valor) {
    // Implementar tratamento de exce��o com try catch
    //validar(nome);
    this->valor = valor;
}
