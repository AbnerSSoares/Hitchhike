#include "entidades.hpp"
#include "tu_dominios.hpp"
#include <iostream>

using std::cout;

int main() {
    // C�digo Teste
    TU_Bagagem teste = TU_Bagagem("5", "0");
    if (teste.run()) {
        cout << "SUCESSO!";
    } else {
        cout << "FALHA!";
    }
    // Fim c�digo teste
}
