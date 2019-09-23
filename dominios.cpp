/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <stdexcept>
#include <vector>
#include <sstream>
#include "dominios.hpp"

void Dominio::setValor(string valor) throw(std::invalid_argument) {
    this->validar(valor);
    this->valor = valor;
}

bool Dominio::areDigits(string valor) {
    for (int i = 0; i < valor.length(); i++) {
        if (!isdigit(valor[i]))
            return false;
    }
    return true;
}

void Assento::validar(string valor) {
    if (valor.length() == 1 && (valor == "D" || valor == "T")) {
        return;
    } else {
        throw std::invalid_argument("Assento inválido!");
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
        throw std::invalid_argument("Código de banco inválido!");
    } else {
        return;
    }
}

void Codigo_de_carona::validar(string valor) {
    if (valor.length() != 4 || !areDigits(valor)) {
        throw std::invalid_argument("Código de carona inválido!");
    } else {
        return;
    }
}

void Codigo_de_reserva::validar(string valor) {
    if (valor.length() != 5 || !areDigits(valor)) {
        throw std::invalid_argument("Código de reserva inválido!");
    } else {
        return;
    }
}

void Cpf::validar(string valor) {
    int vcpf[11];
    int digito1, digito2, temp = 0;

    for (int i = 0; i < 11; i++) {
        /* Convertendo string para valor absoluto segundo tabela ASCII e
           passando para array de inteiros */
        vcpf[i] = static_cast<int>(valor[i] - 48);

        // Validando a entrada de dados
        if (vcpf[i] < 0 || vcpf[i] > 9) {
            throw std::invalid_argument("Cpf inválido!");
        }
    }

    // Obtendo o primeiro dígito verificador
    for (int i = 0; i < 9; i++)
        temp += (vcpf[i] * (10 - i));

    temp %= 11;

    if (temp < 2)
        digito1 = 0;
    else
        digito1 = 11 - temp;

    // Obtendo o segundo digito verificador:
    temp = 0;
    for (int i = 0; i < 10; i++)
        temp += (vcpf[i] * (11 - i));

    temp %= 11;

    if (temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    /* Se os digitos verificadores obtidos forem iguais aos informados pelo usuário,
       então o CPF é válido */
    if (digito1 == vcpf[9] && digito2 == vcpf[10])
        return;
    else
        throw std::invalid_argument("Cpf inválido!");
}

void Data::validar(string valor) {
    std::vector<string> data;
    string temp;

    std::stringstream ss(valor);
    while(getline(ss, temp, '/')) {
        data.push_back(temp);
    }

    if (data.size() == 3
        && data[0].length() == 2 && std::stoi(data[0]) >= 1 && std::stoi(data[0]) <= 31
        && data[1].length() == 2 && std::stoi(data[1]) >= 1 && std::stoi(data[1]) <= 12
        && data[2].length() == 4 && std::stoi(data[2]) >= 2000 && std::stoi(data[2]) <= 2099) {
        return;
    } else {
        throw std::invalid_argument("Formato de data inválido!");
    }
}

void Duracao::validar(string valor) {
    if (areDigits(valor) && std::stoi(valor) >= 0 && std::stoi(valor) <= 48)
        return;
    else
        throw std::invalid_argument("Duração inválida!");
}
