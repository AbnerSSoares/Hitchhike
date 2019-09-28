/* Copyright 2019 Abner Soares e Kallebe Sousa */
#ifndef ENTIDADES_HPP_
#define ENTIDADES_HPP_

#include "dominios.hpp"

class Usuario {
 private:
    Nome nome;
    Telefone telefone;
    Email email;
    Senha senha;
    Cpf cpf;

 public:
    void setNome(string);
    Nome getNome() { return this->nome; }

    void setTelefone(string);
    Telefone getTelefone() { return this->telefone; }

    void setEmail(string);
    Email getEmail() { return this->email; }

    void setSenha(string);
    Senha getSenha() { return this->senha; }

    void setCpf(string);
    Cpf getCpf() { return this->cpf; }
};

class Reserva {
 private:
    Codigo_de_reserva codigo;
    Assento assento;
    Bagagem bagagem;

 public:
    void setCodigo_de_reserva(string);
    Codigo_de_reserva getCodigo_de_reserva() { return this->codigo; }

    void setAssento(string);
    Assento getAssento() { return this->assento; }

    void setBagagem(string);
    Bagagem getBagagem() { return this->bagagem; }
};

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

 public:
    void setCodigo_de_carona(string);
    Codigo_de_carona getCodigo_de_carona() { return this->codigo; }

    void setCidade_origem(string);
    Cidade getCidadeOrigem() { return this->cidade_origem; }

    void setEstado_origem(string);
    Estado getEstado_origem() { return this->estado_origem; }

    void setCidade_destino(string);
    Cidade getCidadedestino() { return this->cidade_destino; }

    void setEstado_destino(string);
    Estado getEstado_destino() { return this->estado_destino; }

    void setData(string);
    Data getData() { return this->data; }

    void setDuracao(string);
    Duracao getDuracao() { return this->duracao; }

    void setVagas(string);
    Vagas getVagas() { return this->vagas; }

    void setPreco(string);
    Preco getPreco() { return this->preco; }
};

class Conta {
 private:
    Codigo_de_banco banco;
    Numero_de_agencia agencia;
    Numero_de_conta numero;

 public:
    void setCodigo_de_banco(string);
    Codigo_de_banco getCodigo_de_banco() { return this->banco; }

    void setNumero_de_agencia(string);
    Numero_de_agencia getNumero_de_agencia() { return this->agencia; }

    void setNumero_de_conta(string);
    Numero_de_conta getNumero_de_conta() { return this->numero; }
};

#endif  // ENTIDADES_HPP_
