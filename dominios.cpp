#include "dominios.hpp"

void Nome::validar(string nome) {
    if (nome.length() > 20) {
        throw invalid_argument;
    }
}

void Nome::setNome(string nome) {
    // Implementar tratamento de exceção com try catch
    validar(nome);
    this->nome = nome;
}
