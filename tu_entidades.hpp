/* Copyright 2019 Abner Soares e Kallebe Sousa */
#ifndef TU_ENTIDADES_HPP_
#define TU_ENTIDADES_HPP_

#include "entidades.hpp"


class TU_Usuario{
    protected:
        string VALOR_INVALIDO;
        string VALOR_VALIDO;
        Usuario *usuario;
        int estado;

        void setUp();
        void testarCenarioSucesso();
        void testarCenarioFalha();
        void tearDown();

     public:
        TU_Enome(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Etelefone(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Eemail(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Esenha(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Ecpf(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
    static const int SUCESSO    = 1;
    static const int FALHA      = 0;

    int run();
};

class TU_Reserva{
    protected:
        string VALOR_INVALIDO;
        string VALOR_VALIDO;
        Reserva *reserva;
        int estado;

        void setUp();
        void testarCenarioSucesso();
        void testarCenarioFalha();
        void tearDown();

    public:
        TU_Ecodigo(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Eassento(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Ebagagem(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        static const int SUCESSO    = 1;
        static const int FALHA      = 0;

        int run();
};

class TU_Carona{
    protected:
        string VALOR_INVALIDO;
        string VALOR_VALIDO;
        Carona *carona;
        int estado;

        void setUp();
        void testarCenarioSucesso();
        void testarCenarioFalha();
        void tearDown();

    public:
        TU_Ecodigo(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Ecidade_origem(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Eestado_origem(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Ecidade_destino(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Eestado_destino(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Edata(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Eduracao(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Uvagas_destino(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Upreco(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        static const int SUCESSO    = 1;
        static const int FALHA      = 0;

        int run();
};

class TU_Conta{
    protected:
        string VALOR_INVALIDO;
        string VALOR_VALIDO;
        Conta *conta;
        int estado;

        void setUp();
        void testarCenarioSucesso();
        void testarCenarioFalha();
        void tearDown();

     public:
        TU_Ecodigo(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Eassento(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        TU_Ebagagem(string vi, string vv) {
            this->VALOR_INVALIDO = vi;
            this->VALOR_VALIDO = vv;
        }
        static const int SUCESSO    = 1;
        static const int FALHA      = 0;

        int run();

};

#endif //
