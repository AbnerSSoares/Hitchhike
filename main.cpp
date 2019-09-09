#include "entidades.hpp"
#include <iostream>

using std::cout;

int main() {
    // Código Teste
    Usuario user;

    user.nome.setValor("Jurandismar");
    user.cpf.setValor("123.456.789-10");

    cout << "Usuario " << user.nome.getValor() << " com CPF " << user.cpf.getValor();
    // Fim código teste
}
