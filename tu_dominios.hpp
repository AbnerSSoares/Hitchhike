#ifndef TU_DOMINIOS_H
#define TU_DOMINIOS_H

#include "dominios.hpp"
#include <string>

using std::string;

class TU_Bagagem {
private:
    string VALOR_INVALIDO;
    string VALOR_VALIDO;

    Bagagem *bagagem;

    int estado;

    void setUp();
    void testarCenarioSucesso();
    void testarCenarioFalha();
    void tearDown();

public:
    TU_Bagagem(string vi, string vv) {
        this->VALOR_INVALIDO = vi;
        this->VALOR_VALIDO = vv;
    }
    const static int SUCESSO    = 1;
    const static int FALHA      = 0;

    int run();  // Podemos mudar para lancar uma excecao
};

#endif // TU_DOMINIOS_H
