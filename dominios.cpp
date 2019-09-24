/* Copyright 2019 Abner Soares e Kallebe Sousa */
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "dominios.hpp"

using std::vector;
using std::invalid_argument;

void Dominio::setValor(string valor) throw(invalid_argument) {
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

vector<string> Dominio::splitString(string str, char delimitador) {
    vector<string> split;
    string temp;

    std::stringstream ss(str);
    while(getline(ss, temp, delimitador)) {
        split.push_back(temp);
    }

    return split;
}

void Assento::validar(string valor) {
    if (valor.length() == 1 && (valor == "D" || valor == "T")) {
        return;
    } else {
        throw invalid_argument("Assento inválido!");
    }
}

void Bagagem::validar(string valor) {
    if (valor.length() != 1 || valor > "4" || valor < "0") {
        throw invalid_argument("Valor de bagagem inválido!");
    } else {
        return;
    }
}

void Codigo_de_banco::validar(string valor) {
    if (valor.length() != 3 || !areDigits(valor)) {
        throw invalid_argument("Código de banco inválido!");
    } else {
        return;
    }
}

void Codigo_de_carona::validar(string valor) {
    if (valor.length() != 4 || !areDigits(valor)) {
        throw invalid_argument("Código de carona inválido!");
    } else {
        return;
    }
}

void Codigo_de_reserva::validar(string valor) {
    if (valor.length() != 5 || !areDigits(valor)) {
        throw invalid_argument("Código de reserva inválido!");
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
            throw invalid_argument("Cpf inválido!");
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
        throw invalid_argument("Cpf inválido!");
}

void Data::validar(string valor) {
    vector<string> data = splitString(valor, '/');

    if (data.size() == 3
        && data[0].length() == 2 && std::stoi(data[0]) >= 1 && std::stoi(data[0]) <= 31
        && data[1].length() == 2 && std::stoi(data[1]) >= 1 && std::stoi(data[1]) <= 12
        && data[2].length() == 4 && std::stoi(data[2]) >= 2000 && std::stoi(data[2]) <= 2099) {
        return;
    } else {
        throw invalid_argument("Formato de data inválido!");
    }
}

void Duracao::validar(string valor) {
    if (areDigits(valor) && std::stoi(valor) >= 0 && std::stoi(valor) <= 48)
        return;
    else
        throw invalid_argument("Duração inválida!");
}

void Estado::validar(string valor) {
    if (valor == "AC" || valor == "AL" || valor == "AP" || valor == "AM"
                        || valor == "BA" || valor == "CE" || valor == "DF"
                        || valor == "ES" || valor == "GO" || valor == "MA"
                        || valor == "MT" || valor == "MS" || valor == "MG"
                        || valor == "PA" || valor == "PB" || valor == "PR"
                        || valor == "PE" || valor == "PI" || valor == "RJ"
                        || valor == "RN" || valor == "RS" || valor == "RO"
                        || valor == "RR" || valor == "SC" || valor == "SP"
                        || valor == "SE" || valor == "TO")
        return;
    else
        throw invalid_argument("Estado inválido!");
}

void Email::validar(string valor) {
    vector<string> email = splitString(valor, '@');

    if (email.size() == 2 && email[0].length() <= 20
                            && email[1].length() <= 20
                            && email[0][0] != '.'
                            && email[0][email[0].length()-1] != '.'
                            && email[1][0] != '.') {
        int contPonto = 0;

        for (int i = 0; i < email[0].length(); i++) {
            if (email[0][i] == '.')
                contPonto++;
            else
                contPonto = 0;
            if (!(email[0][i] >= 'a' && !email[0][i] <= 'z' || email[1][i] == '.') || contPonto > 1)
                throw invalid_argument("Email inválido!");
        }
        for (int i = 0; i < email[1].length(); i++) {
            if (email[1][i] == '.')
                contPonto++;
            else
                contPonto = 0;
            if (!(email[1][i] >= 'a' && !email[1][i] <= 'z' || email[1][i] == '.') || contPonto > 1)
                throw invalid_argument("Email inválido!");
        }
    } else {
        throw invalid_argument("Email inválido!");
    }
}

void Nome::validar(string valor) {
    if (valor.length() > 0 && valor.length() <= 20 && valor[0] != '.') {
        int contLetra = 0, contEspaco = 0;
        for (int i = 0; i < valor.length(); i++) {
            if (isspace(valor[i]))
                contEspaco++;
            else
                contEspaco = 0;
            if (isalpha(valor[i]))
                contLetra++;
            if ((!isalpha(valor[i]) && !isspace(valor[i]) && valor[i] != '.')
                            || contEspaco > 1
                            || (valor[i] == '.' && !isalpha(valor[i-1])))
                throw invalid_argument("Nome inválido!");
        }
        if (contLetra == 0)
            throw invalid_argument("Nome inválido!");
    } else {
        throw invalid_argument("Nome inválido!");
    }
}
