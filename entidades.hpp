/* Copyright 2019 Abner Soares e Kallebe Sousa */

#ifndef ENTIDADES_HPP_
#define ENTIDADES_HPP_

#include <string>
#include "dominios.hpp"

/**
 * @brief Entidade Usuário
 * @details
 *    A classe Usuário representa uma entidade dos usuários que utilizam o sistema
 *    de carona, tanto passageiros quanto motoristas. A entidade possui atributos
 *    privados cujos tipos são Domínios e métodos públicos de get e set para acesso
 *    a esses atributos.
 * @see Dominio
 */
class Usuario {
 private:
    Nome nome;          /**< @param nome     Nome do usuário */
    Telefone telefone;  /**< @param telefone Telefone do usuário */
    Email email;        /**< @param email    E-mail do usuário */
    Senha senha;        /**< @param senha    Senha de acesso do usuário */
    Cpf cpf;            /**< @param cpf      CPF do usuário */

 public:
    /**
     * @brief Método para adicionar nome à entidade Usuário
     * @param valor Valor do nome a ser adicionado ao usuário
     * @see Dominio
     */
    void setNome(string);
    /**
     * @brief Método para retornar o nome da entidade Usuário
     * @return Valor do tipo Nome com o nome do usuário
     * @see Dominio
     */
    Nome getNome() { return this->nome; }
    /**
     * @brief Método para adicionar telefone à entidade Usuário
     * @param valor Valor do telefone a ser adicionado ao usuário
     * @see Dominio
     */
    void setTelefone(string);
    /**
     * @brief Método para retornar o telefone da entidade Usuário
     * @return Valor do tipo Telefone com o telefone do usuário
     * @see Dominio
     */
    Telefone getTelefone() { return this->telefone; }
    /**
     * @brief Método para adicionar e-mail à entidade Usuário
     * @param valor Valor do e-mail a ser adicionado ao usuário
     * @see Dominio
     */
    void setEmail(string);
    /**
     * @brief Método para retornar o e-mail da entidade Usuário
     * @return Valor do tipo Email com o e-mail do usuário
     * @see Dominio
     */
    Email getEmail() { return this->email; }
    /**
     * @brief Método para adicionar senha à entidade Usuário
     * @param valor Valor da senha a ser adicionado ao usuário
     * @see Dominio
     */
    void setSenha(string);
    /**
     * @brief Método para retornar a senha da entidade Usuário
     * @return Valor do tipo Senha com a senha do usuário
     * @see Dominio
     */
    Senha getSenha() { return this->senha; }
    /**
     * @brief Método para adicionar CPF à entidade Usuário
     * @param valor Valor da CPF a ser adicionado ao usuário
     * @see Dominio
     */
    void setCpf(string);
    /**
     * @brief Método para retornar o CPF da entidade Usuário
     * @return Valor do tipo Cpf com o CPF do usuário
     * @see Dominio
     */
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
