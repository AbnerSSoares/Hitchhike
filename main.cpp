#include "entidades.hpp"
#include <iostream>

using std::cout;

int main() {
    // C�digo Teste
    Usuario user;

    user.nome.setValor("Jurandismar");
    user.cpf.setValor("123.456.789-10");

    cout << "Usuario " << user.nome.getValor() << " com CPF " << user.cpf.getValor();
    // Fim c�digo teste
}
