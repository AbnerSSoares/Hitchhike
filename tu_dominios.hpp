#ifndef TU_DOMINIOS_H
#define TU_DOMINIOS_H

#include "dominios.hpp"
#include <string>

using std::string;

class TU_Dominio {
protected:
    string VALOR_INVALIDO;
    string VALOR_VALIDO;

    Dominio *dominio;

    int estado;

    virtual void setUp() = 0;

    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

public:
    const static int SUCESSO    = 1;
    const static int FALHA      = 0;

    int run();  // Podemos mudar para lancar uma excecao
};

class TU_Assento : public TU_Dominio {
    void setUp();
public:
    TU_Assento(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Bagagem : public TU_Dominio {
    void setUp();
public:
    TU_Bagagem(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Codigo_de_banco : public TU_Dominio {
    void setUp();
public:
    TU_Codigo_de_banco(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Codigo_de_carona : public TU_Dominio {
    void setUp();
public:
    TU_Codigo_de_carona(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Codigo_de_reserva : public TU_Dominio {
    void setUp();
public:
    TU_Codigo_de_reserva(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Cpf : public TU_Dominio {
    void setUp();
public:
    TU_Cpf(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

#endif // TU_DOMINIOS_H
