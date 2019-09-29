/* Copyright 2019 Abner Soares e Kallebe Sousa */
#ifndef TU_ENTIDADES_HPP_
#define TU_ENTIDADES_HPP_

#include "entidades.hpp"

class TU_Usuario{
    protected:
        string NOME_INVALIDO;
        string NOME_VALIDO;
        string TELEFONE_INVALIDO;
        string TELEFONE_VALIDO;
        string EMAIL_INVALIDO;
        string EMAIL_VALIDO;
        string SENHA_INVALIDO;
        string SENHA_VALIDO;
        string CPF_INVALIDO;
        string CPF_VALIDO;
        Usuario *usuario;
        int estado;

        void setUp();
        void testarCenario();
        void tearDown();

     public:
        TU_Usuario(string nomei, string nomev,
                    string telefonei, string telefonev,
                    string emaili, string emailv,
                    string senhai, string senhav,
                    string cpfi, string cpfv) {
            this->NOME_INVALIDO = nomei;
            this->NOME_VALIDO = nomev;
            this->TELEFONE_INVALIDO = telefonei;
            this->TELEFONE_VALIDO = telefonev;
            this->EMAIL_INVALIDO = emaili;
            this->EMAIL_VALIDO = emailv;
            this->SENHA_INVALIDO = senhai;
            this->SENHA_VALIDO = senhav;
            this->CPF_INVALIDO = cpfi;
            this->CPF_VALIDO = cpfv;
        }

    static const int SUCESSO    = 1;
    static const int FALHA      = 0;

    int run();
};

class TU_Reserva{
    protected:
        string CODIGO_INVALIDO;
        string CODIGO_VALIDO;
        string ASSENTO_INVALIDO;
        string ASSENTO_VALIDO;
        string BAGAGEM_INVALIDO;
        string BAGAGEM_VALIDO;
        Reserva *reserva;
        int estado;

        void setUp();
        void testarCenario();
        void tearDown();

    public:
        TU_Reserva(string codigoi, string codigov,
                   string assentoi, string assentov,
                   string bagagemi, string bagagemv){

            this->CODIGO_INVALIDO = codigoi;
            this->CODIGO_VALIDO = codigov;
            this->ASSENTO_INVALIDO = assentoi;
            this->ASSENTO_VALIDO = assentov;
            this->BAGAGEM_INVALIDO = bagagemi;
            this->BAGAGEM_VALIDO = bagagemv;
        }

        static const int SUCESSO    = 1;
        static const int FALHA      = 0;

        int run();
};

class TU_Carona{
    protected:
        string CODIGO_INVALIDO;
        string CODIGO_VALIDO;
        string CIDADE_ORIGEM_INVALIDO;
        string CIDADE_ORIGEM_VALIDO;
        string ESTADO_ORIGEM_INVALIDO;
        string ESTADO_ORIGEM_VALIDO;
        string CIDADE_DESTINO_VALIDO;
        string CIDADE_DESTINO_INVALIDO;
        string ESTADO_DESTINO_INVALIDO;
        string ESTADO_DESTINO_VALIDO;
        string DATA_VALIDO;
        string DATA_INVALIDO;
        string DURACAO_INVALIDO;
        string DURACAO_VALIDO;
        string VAGAS_INVALIDO;
        string VAGAS_VALIDO;
        string PRECO_INVALIDO;
        string PRECO_VALIDO;
        Carona *carona;
        int estado;

        void setUp();
        void testarCenario();
        void tearDown();

    public:
        TU_Carona(string codigoi, string codigov,
                   string cidade_origemi, string cidade_origemv,
                   string estado_origemi, string estado_origemv,
                   string cidade_destinoi, string cidade_destinov,
                   string estado_destinoi, string estado_destinov,
                   string datai, string datav,
                   string duracaoi, string duracaov,
                   string vagasi, string vagasv,
                   string precoi, string precov){

            this->CODIGO_INVALIDO = codigoi;
            this->CODIGO_VALIDO = codigov;
            this->CIDADE_ORIGEM_INVALIDO = cidade_origemi;
            this->CIDADE_ORIGEM_VALIDO = cidade_origemv;
            this->ESTADO_ORIGEM_INVALIDO = estado_origemi;
            this->ESTADO_ORIGEM_VALIDO = estado_origemv;
            this->CIDADE_DESTINO_INVALIDO = cidade_destinoi;
            this->CIDADE_DESTINO_VALIDO = cidade_destinov;
            this->ESTADO_DESTINO_INVALIDO = estado_destinoi;
            this->ESTADO_DESTINO_VALIDO = estado_destinov;
            this->DATA_INVALIDO = datai;
            this->DATA_VALIDO = datav;
            this->DURACAO_INVALIDO = duracaoi;
            this->CODIGO_VALIDO = duracaov;
            this->VAGAS_INVALIDO = vagasi;
            this->VAGAS_VALIDO = vagasv;
            this->PRECO_INVALIDO = precoi;
            this->PRECO_VALIDO = precov;
        }
        static const int SUCESSO    = 1;
        static const int FALHA      = 0;

        int run();
};

class TU_Conta{
    protected:
        string BANCO_INVALIDO;
        string BANCO_VALIDO;
        string AGENCIA_INVALIDO;
        string AGENCIA_VALIDO;
        string NUMERO_INVALIDO;
        string NUMERO_VALIDO;
        Conta *conta;
        int estado;

        void setUp();
        void testarCenario();
        void tearDown();

     public:
        TU_Conta(string bancoi, string bancov,
                   string agenciai, string agenciav,
                   string numeroi, string numerov){

            this->BANCO_INVALIDO = bancoi;
            this->BANCO_VALIDO = bancov;
            this->AGENCIA_INVALIDO = agenciai;
            this->AGENCIA_VALIDO = agenciav;
            this->NUMERO_INVALIDO = numeroi;
            this->NUMERO_VALIDO = numerov;
        }

        static const int SUCESSO    = 1;
        static const int FALHA      = 0;

        int run();

};

#endif  // TU_ENTIDADES_HPP_
