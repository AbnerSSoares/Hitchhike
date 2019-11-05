/* Copyright 2019 Abner Soares e Kallebe Sousa */

#include "../entidades/entidades.hpp"

void Usuario::setNome(string valor) {
    Nome nome;
    nome.setValor(valor);

    this->nome = nome;
}

void Usuario::setTelefone(string valor) {
    Telefone telefone;
    telefone.setValor(valor);

    this->telefone = telefone;
}

void Usuario::setEmail(string valor) {
    Email email;
    email.setValor(valor);

    this->email = email;
}

void Usuario::setSenha(string valor) {
    Senha senha;
    senha.setValor(valor);

    this->senha = senha;
}

void Usuario::setCpf(string valor) {
    Cpf cpf;
    cpf.setValor(valor);

    this->cpf = cpf;
}

void Reserva::setCodigo_de_reserva(string valor) {
    Codigo_de_reserva codigo;
    codigo.setValor(valor);

    this->codigo = codigo;
}

void Reserva::setAssento(string valor) {
    Assento assento;
    assento.setValor(valor);

    this->assento = assento;
}

void Reserva::setBagagem(string valor) {
    Bagagem bagagem;
    bagagem.setValor(valor);

    this->bagagem = bagagem;
}

void Carona::setCodigo_de_carona(string valor) {
    Codigo_de_carona codigo;
    codigo.setValor(valor);

    this->codigo = codigo;
}

void Carona::setCidade_origem(string valor) {
    Cidade cidade_origem;
    cidade_origem.setValor(valor);

    this->cidade_origem = cidade_origem;
}

void Carona::setEstado_origem(string valor) {
    Estado estado_origem;
    estado_origem.setValor(valor);

    this->estado_origem = estado_origem;
}

void Carona::setCidade_destino(string valor) {
    Cidade cidade_destino;
    cidade_destino.setValor(valor);

    this->cidade_destino = cidade_destino;
}

void Carona::setEstado_destino(string valor) {
    Estado estado_destino;
    estado_destino.setValor(valor);

    this->estado_destino = estado_destino;
}

void Carona::setData(string valor) {
    Data data;
    data.setValor(valor);

    this->data = data;
}

void Carona::setDuracao(string valor) {
    Duracao duracao;
    duracao.setValor(valor);

    this->duracao = duracao;
}

void Carona::setVagas(string valor) {
    Vagas vagas;
    vagas.setValor(valor);

    this->vagas = vagas;
}

void Carona::setPreco(string valor) {
    Preco preco;
    preco.setValor(valor);

    this->preco = preco;
}

void Conta::setCodigo_de_banco(string valor) {
    Codigo_de_banco banco;
    banco.setValor(valor);

    this->banco = banco;
}

void Conta::setNumero_de_agencia(string valor) {
    Numero_de_agencia agencia;
    agencia.setValor(valor);

    this->agencia = agencia;
}

void Conta::setNumero_de_conta(string valor) {
    Numero_de_conta numero;
    numero.setValor(valor);

    this->numero = numero;
}
