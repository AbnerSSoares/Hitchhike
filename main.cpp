#include "dominios.hpp"
#include <iostream>

using std::cout;

int main() {
    // C�digo Teste
    Nome nome;
    Assento assento;

    assento.setAssento('D');
    nome.setNome("Hermenegildo");

    cout << "Nome inserido: " << nome.getNome() << "\nAssento: " << assento.getAssento();
    // Fim c�digo teste
}
