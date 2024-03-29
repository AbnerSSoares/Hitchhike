/* Copyright 2019 Abner Soares e Kallebe Sousa */

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include "../dominios/dominios.hpp"

using std::vector;
using std::invalid_argument;

void Dominio::setValor(string valor) {
    this->validar(valor);
    this->valor = valor;
}

bool Dominio::areDigits(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

vector<string> Dominio::splitString(string str, char delimitador) {
    vector<string> split;
    string temp;

    std::stringstream ss(str);
    while (getline(ss, temp, delimitador)) {
        split.push_back(temp);
    }

    return split;
}

bool Dominio::isSpecial(string str) {
    int tamanho = str.length();

    for (int i = 0; i < tamanho; i++) {
        if (!isalpha(str[i])) {
            if (str[i] != '.' && str[i] != ' ' && str[i] != 'ã' && str[i] != 'á' && str[i] != 'ç'
                        && str[i] != 'à' && str[i] != 'â' && str[i] != 'é'
                        && str[i] != 'ê' && str[i] != 'í' && str[i] != 'õ'
                        && str[i] != 'ó' && str[i] != 'ô' && str[i] != 'ú') {
                return true;
            }
        }
    }
    return false;
}

bool Dominio::hasAlpha(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            return true;
        }
    }

    return false;
}
bool Dominio::hasDigit(string str) {
    int tamanho = str.length();
    for (int i = 0; i < tamanho; i++) {
            if (isdigit(str[i])) {
                return true;
            }
        }
    return false;
}

void Assento::validar(string valor) {
    if (valor == "D" || valor == "T")
        return;
    else
        throw invalid_argument("Assento inválido!");
}

void Bagagem::validar(string valor) {
    if (valor.length() != 1 || valor > "4" || valor < "0")
        throw invalid_argument("Valor de bagagem inválido!");
    else
        return;
}

void Codigo_de_banco::validar(string valor) {
    if (valor.length() != 3 || !areDigits(valor))
        throw invalid_argument("Código de banco inválido!");
    else
        return;
}

void Codigo_de_carona::validar(string valor) {
    if (valor.length() != 4 || !areDigits(valor))
        throw invalid_argument("Código de carona inválido!");
    else
        return;
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

    valor.erase(std::remove(valor.begin(), valor.end(), '-'), valor.end());
    valor.erase(std::remove(valor.begin(), valor.end(), '.'), valor.end());

    if (valor.length() != 11)
        throw invalid_argument("Cpf inválido!");

    for (int i = 0; i < 11; i++) {
        vcpf[i] = static_cast<int>(valor[i] - 48);

        if (isdigit(vcpf[i]))
            throw invalid_argument("Cpf inválido!");
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

    if (digito1 == vcpf[9] && digito2 == vcpf[10])
        return;
    else
        throw invalid_argument("Cpf inválido!");
}

void Cidade::validar(string valor) {
    if (valor.length() < 1 || valor.length() > 10
                || !hasAlpha(valor) || isSpecial(valor))
        throw invalid_argument("Cidade inválida!");

    for (int i = 1; i < valor.length(); i++) {
        if ((valor[i] == ' ' || valor[i] == '.') && valor[i-1] == ' ')
            throw invalid_argument("Cidade inválida!");
    }

    return;
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

void Numero_de_agencia::validar(string valor) {
    int soma = 0;

    valor.erase(std::remove(valor.begin(), valor.end(), '-'), valor.end());

    const int kTamanho = valor.length();
    int valoraux[kTamanho];

    if (!areDigits(valor))
        throw invalid_argument("Agencia inválida!");

    if (valor.length() < 1 || valor.length() > 5)
        throw invalid_argument("Agencia inválida!");

    for (int i = 0; i < kTamanho; i++) {
        valoraux[i] = valor[i] - '0';
    }

    for (int i = 1 ; i < kTamanho; i++) {
        if (i % 2 == 0) {
            valoraux[i-1] =  2 * valoraux[i-1];
        } else {
            valoraux[i-1] = valoraux[i-1];
        }
    }

    for (int i = 1; i <= kTamanho; i++) {
        if (valoraux[i-1] > 9 && i % 2 == 0) {
            int mod = valoraux[i-1] % 10;
            valoraux[i-1]  =  1 + mod;
        } else {
        valoraux[i-1] = valoraux[i-1];
        }
    }

    for (int i = 0; i < kTamanho; i++) {
        soma += valoraux[i];
    }

    if (soma % 10 == 0) {
        return;
    } else {
        throw invalid_argument("Agencia inválida!");
    }
}

void Numero_de_conta::validar(string valor) {
    int soma = 0;

    valor.erase(std::remove(valor.begin(), valor.end(), '-'), valor.end());

    int kTamanho = valor.length();
    int valoraux[kTamanho];

    if (!areDigits(valor))
        throw invalid_argument("Conta inválida!");

    if (valor.length() != 7)
        throw invalid_argument("Conta inválida!");

    for (int i = 0; i < kTamanho; i++) {
        valoraux[i] = valor[i] - '0';
    }

    for (int i = 1 ; i < kTamanho; i++) {
        if (i % 2 == 0) {
            valoraux[i-1] =  2 * valoraux[i-1];
        } else {
            valoraux[i-1] = valoraux[i-1];
        }
    }

    for (int i = 1; i <= kTamanho; i++) {
        if (valoraux[i-1] > 9 && i % 2 == 0) {
            int mod = valoraux[i-1] % 10;
            valoraux[i-1]  =  1 + mod;
        } else {
        valoraux[i-1] = valoraux[i-1];
        }
    }

    for (int i = 0; i < kTamanho; i++) {
        soma += valoraux[i];
    }

    if (soma % 10 == 0)
        return;
    else
        throw invalid_argument("Conta inválida");
}

void Preco::validar(string valor) {
    vector<string> preco;
    int int_preco[2];

    if (valor.find(',') != string::npos) {
        preco = splitString(valor, ',');
    } else {
        preco.push_back(valor);
        preco.push_back("00");
    }

    int_preco[0] = std::stoi(preco[0]);
    int_preco[1] = std::stoi(preco[1]);

    if (!areDigits(preco[0]) || !areDigits(preco[1])
                || int_preco[0] < 1 || int_preco[0] > 5000
                || int_preco[0] == 5000 && int_preco[1] > 0)
        throw invalid_argument("Preço inválido!");
}

void Telefone::validar(string valor) {
    vector<string> telefone = splitString(valor, '-');

    for (int i = 0; i < telefone.size(); i++) {
        if (telefone[i] == "00" || !areDigits(telefone[i]))
            throw invalid_argument("Telefone inválido!");
    }

    if (telefone.size() != 3
            || telefone[0].length() != 2
            || telefone[1].length() != 2
            || telefone[2].length() != 9
            || telefone[2] == "000000000")
        throw invalid_argument("Telefone inválido");
}

void Senha::validar(string valor) {
    int tamanho = valor.length();
    int cont = 0;

    if (tamanho < 1 || tamanho > 5) {
        throw invalid_argument("Senha inválida!");
    }

    if (!hasAlpha(valor)) {
        throw invalid_argument("Senha inválida!");
    } else if (!hasDigit(valor)) {
        throw invalid_argument("Senha inválida!");
    }

    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(valor[i])) {
            if (!isalpha(valor[i])) {
                if (valor[i]!= '#' && valor[i] != '$' && valor[i] != '%' && valor[i] != '&') {
                    throw invalid_argument("Senha inválida!");
                }
            }
        }
    }
    for (int i = 0; i < tamanho; i++) {
        if (isupper(valor[i])) {
            valor[i] = tolower(valor[i]);
        }
    }

    for (int i = 0; i < tamanho; i++) {
        for (int z = 0; z < tamanho; z++) {
            if (valor[i] == valor[z]) {
                    cont++;
        }
            if (cont > 1) {
                throw invalid_argument("Senha inválida!");
            }
        }
        cont = 0;
    }
    return;
}

void Vagas::validar(string valor) {
    if (std::stoi(valor) >= 0 && std::stoi(valor) <= 5)
        return;
    else
        throw invalid_argument("Valor de Vagas inválido!");
}
