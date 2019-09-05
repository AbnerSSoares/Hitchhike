#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "dominios.hpp"

class Usuario {
private:
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    Cpf cpf;
}

class Reserva {
private:
    Codigo_de_reserva codigo;
    Assento assento;
    Bagagem bagagem;
}

class Carona {
private:
    Codigo_de_carona codigo;
    Cidade cidade_origem;
    Estado estado_origem;
    Cidade cidade_destino;
    Estado estado_destino;
    Data data;
    Duracao duracao;
    Vagas vagas;
    Preco preco;
}

class Conta {
private:
    Codigo_de_banco banco;
    Numero_de_agencia agencia;
    Numero_de_conta numero;
}

#endif
