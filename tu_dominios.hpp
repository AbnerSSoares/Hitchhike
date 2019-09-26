/* Copyright 2019 Abner Soares e Kallebe Sousa */
#ifndef TU_DOMINIOS_HPP_
#define TU_DOMINIOS_HPP_

#include <string>
#include "dominios.hpp"

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
    static const int SUCESSO    = 1;
    static const int FALHA      = 0;

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

class TU_Cidade : public TU_Dominio {
    void setUp();
 public:
    TU_Cidade(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Data : public TU_Dominio {
    void setUp();
 public:
    TU_Data(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Duracao : public TU_Dominio {
    void setUp();
 public:
    TU_Duracao(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Estado : public TU_Dominio {
    void setUp();
 public:
    TU_Estado(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Email : public TU_Dominio {
    void setUp();
 public:
    TU_Email(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Nome : public TU_Dominio {
    void setUp();
 public:
    TU_Nome(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};
class TU_Numero_de_agencia : public TU_Dominio {
    void setUp();
 public:
    TU_Numero_de_agencia(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};
class TU_Numero_de_conta : public TU_Dominio {
    void setUp();
 public:
    TU_Numero_de_conta(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};


class TU_Preco : public TU_Dominio {
    void setUp();
 public:
    TU_Preco(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Telefone : public TU_Dominio {
    void setUp();
 public:
    TU_Telefone(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};
class TU_Senha : public TU_Dominio {
    void setUp();
 public:
    TU_Senha(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

class TU_Vagas : public TU_Dominio {
    void setUp();
 public:
    TU_Vagas(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
};

#endif  // TU_DOMINIOS_HPP_
