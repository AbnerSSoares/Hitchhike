#include "entidades.hpp"
#include "tu_dominios.hpp"
#include <iostream>

using std::cout;

int main() {
    // Código Teste
    TU_Bagagem teste_bag = TU_Bagagem("D", "0");
    TU_Codigo_de_banco teste_banco = TU_Codigo_de_banco("asd", "123");
    if (teste_bag.run()) {
        cout << "SUCESSO NO TESTE BAGAGEM!\n";
    } else {
        cout << "FALHA NO TESTE BAGAGEM!\n";
    }
    if (teste_banco.run()) {
        cout << "SUCESSO NO TESTE Banco!\n";
    } else {
        cout << "FALHA NO TESTE Banco!\n";
    }
    // Fim código teste
}
