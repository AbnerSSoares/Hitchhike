#include <stdexcept>
#include "dominios.hpp"

void Dominio::setValor(string valor) throw(std::invalid_argument) {
    // Implementar tratamento de exce��o com try catch
    this->validar(valor);
    this->valor = valor;
}

// Valida o valor passado em assento.
void Assento::validar(string valor) {
    if (valor.length() == 1 && (valor == "D" || valor == "T")) {
        return;
    } else {
        throw std::invalid_argument("Assento inválido");
    }
}

void Bagagem::validar(string valor) {
    if (valor.length() != 1 || valor > "4" || valor < "0") {
        throw std::invalid_argument("Valor de bagagem inválido!");
    } else {
        return;
    }
}

void Codigo_de_banco::validar(string valor) {
    if (valor.length() != 3 || !areDigits(valor)) {
        throw std::invalid_argument("Valor de código de banco inválido!");
    } else {
        return;
    }
}

void Codigo_de_carona::validar(string valor) {
    if (valor.length() != 4 && !areDigits(valor)) {
        throw std::invalid_argument("Valor de código de carona inválido!");
    } else {
        return;
    }
}

void Codigo_de_reserva::validar(string valor) {
    if (valor.length() != 5 && !areDigits(valor)) {
        throw std::invalid_argument("Valor de código de reserva inválido!");
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

void Cpf::validar(string valor){

    int vcpf[11];

    for(int i = 0; i < 11; i++){
        vcpf[i] = static_cast<int>(valor[i] - 48); //Convertendo string para valor absoluto segundo tabela ASCII e passando para array de inteiros//

        if(vcpf[i] < 0 || vcpf[i] > 9){ //Validando a entrada de dados
            throw std::invalid_argument("Cpf Inválido");
        }
    }

    int digito1,
        digito2,
        temp = 0;

    //Obtendo o primeiro dígito verificador

    for(int i = 0; i < 9; i++)
        temp += (vcpf[i] * (10 - i));

    temp %= 11;

    if(temp < 2)
        digito1 = 0;
    else
        digito1 = 11 - temp;

    //Obtendo o segundo digito verificador:

    temp = 0;
    for(int i = 0; i < 10; i++)
        temp += (vcpf[i] * (11 - i));

    temp %= 11;

    if(temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    /* Se os digitos verificadores obtidos forem iguais aos informados pelo usuário,
       então o CPF é válido */

    if(digito1 == vcpf[9] && digito2 == vcpf[10])
        return;
    else
        throw std::invalid_argument("Cpf Inválido");
}
