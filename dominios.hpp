#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <string>
using std::string;

class Assento {
private:
    char tipo;

public:
    void setAssento(char tipo) { this->tipo = tipo; }
    char getAssento() { return tipo; }
};

class Nome {
private:
    string nome;

    void validar(string nome);

public:
    void setNome(string nome);
    string getNome() { return nome; }
};

#endif
