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

/**
 * @brief Entidade Reserva
 * @details
 *   A classe Reserva representa uma entidade das reservas de caronas que são
 *   realizadas por usuários. A entidade possui atributos privados cujos tipos
 *   são Domínios e métodos públicos de get e set para acesso a esses atributos.
 * @see Dominio
 */
class Reserva {
 private:
    Codigo_de_reserva codigo;    /**< @param codigo      Código da reserva */
    Assento assento;             /**< @param assento     Assento escolhido para a reserva */
    Bagagem bagagem;             /**< @param bagagem     Quantidade de bagagem */

 public:
     /**
     * @brief Método para adicionar um Código de reserva a entidade Reserva
     * @param valor Valor do código a ser adicionado a reserva
     * @see Dominio
     */
    void setCodigo_de_reserva(string);
    /**
     * @brief Método para retornar o Código de reserva da entidade Reserva
     * @return Valor do tipo Codigo_de_reserva com o código da reserva
     * @see Dominio
     */
    Codigo_de_reserva getCodigo_de_reserva() { return this->codigo; }
    /**
     * @brief Método para adicionar um assento a entidade Reserva
     * @param valor Valor do assento a ser adicionado a reserva
     * @see Dominio
     */
    void setAssento(string);
    /**
     * @brief Método para retornar o Assento da entidade Reserva
     * @return Valor do tipo Assento com o assento da reserva
     * @see Dominio
     */
    Assento getAssento() { return this->assento; }
    /**
     * @brief Método para adicionar bagagem a entidade Reserva
     * @param valor Valor da bagagem a ser adicionada a reserva
     * @see Dominio
     */
    void setBagagem(string);
    /**
     * @brief Método para retornar a Bagagem da entidade Reserva
     * @return Valor do tipo Bagagem com a bagagem da reserva
     * @see Dominio
     */
    Bagagem getBagagem() { return this->bagagem; }
};

/**
 * @brief Entidade Carona
 * @details
 *   A classe Carona representa uma entidade das caronas. A entidade possui
 *   atributos privados cujos tipos são Domínios e métodos públicos de get
 *   e set para acesso a esses atributos.
 * @see Dominio
 */
class Carona {
 private:
    Codigo_de_carona codigo;        /**< @param codigo               Código da carona */
    Cidade cidade_origem;           /**< @param cidade_origem        Cidade de origem da carona */
    Estado estado_origem;           /**< @param estado_origem        Estado de origem da carona */
    Cidade cidade_destino;          /**< @param cidade_destino       Cidade de destino da carona */
    Estado estado_destino;          /**< @param estado_destino       Estado de destino da carona */
    Data data;                      /**< @param data                 Data da carona */
    Duracao duracao;                /**< @param duracao              Duração da carona */
    Vagas vagas;                    /**< @param vagas                Número de vagas da carona */
    Preco preco;                    /**< @param preco                Preço da carona */

 public:
     /**
     * @brief Método para adicionar um Código de carona a entidade Carona
     * @param valor Valor do código a ser adicionado a carona
     * @see Dominio
     */
    void setCodigo_de_carona(string);
    /**
     * @brief Método para retornar o Código da entidade Carona
     * @return Valor do tipo Codigo_de_carona com o código da carona
     * @see Dominio
     */
    Codigo_de_carona getCodigo_de_carona() { return this->codigo; }
    /**
     * @brief Método para adicionar uma Cidade de origem a entidade Carona
     * @param valor Valor da cidade de origem a ser adicionada a carona
     * @see Dominio
     */
    void setCidade_origem(string);
    /**
     * @brief Método para retornar a Cidade de origem da entidade Carona
     * @return Valor do tipo Cidade_de_origem com a cidade de origem da carona
     * @see Dominio
     */
    Cidade getCidadeOrigem() { return this->cidade_origem; }
    /**
     * @brief Método para adicionar um Estado de origem a entidade Carona
     * @param valor Valor do estado de origem a ser adicionado a carona
     * @see Dominio
     */
    void setEstado_origem(string);
    /**
     * @brief Método para retornar o Estado de origem da entidade Carona
     * @return Valor do tipo Estado_de_origem com o estado de origem da carona
     * @see Dominio
     */
    Estado getEstado_origem() { return this->estado_origem; }
    /**
     * @brief Método para adicionar uma Cidade de destino a entidade Carona
     * @param valor Valor da cidade de destino a ser adicionada a carona
     * @see Dominio
     */
    void setCidade_destino(string);
    /**
     * @brief Método para retornar a Cidade de destino da entidade Carona
     * @return Valor do tipo Cidade_de_destino com a cidade de destino da carona
     * @see Dominio
     */
    Cidade getCidadedestino() { return this->cidade_destino; }
    /**
     * @brief Método para adicionar um Estado de destino a entidade Carona
     * @param valor Valor do estado de destino a ser adicionado a carona
     * @see Dominio
     */
    void setEstado_destino(string);
    /**
     * @brief Método para retornar o Estado de destino da entidade Carona
     * @return Valor do tipo Estado_de_destino com a cidade de origem da carona
     * @see Dominio
     */
    Estado getEstado_destino() { return this->estado_destino; }
    /**
     * @brief Método para adicionar uma Data a entidade Carona
     * @param valor Valor da data a ser adicionada a carona
     * @see Dominio
     */
    void setData(string);
    /**
     * @brief Método para retornar a Data da entidade Carona
     * @return Valor do tipo Data com a data da carona
     * @see Dominio
     */
    Data getData() { return this->data; }
    /**
     * @brief Método para adicionar uma Duracao a entidade Carona
     * @param valor Valor da duracao a ser adicionada a carona
     * @see Dominio
     */
    void setDuracao(string);
    /**
     * @brief Método para retornar a Duração da entidade Carona
     * @return Valor do tipo Duracao com a duração da carona
     * @see Dominio
     */
    Duracao getDuracao() { return this->duracao; }
    /**
     * @brief Método para adicionar Vagas a entidade Carona
     * @param valor Quantidade de vagas a ser adicionada a carona
     * @see Dominio
     */
    void setVagas(string);
    /**
     * @brief Método para retornar as Vagas da entidade Carona
     * @return Valor do tipo Vagas com as vagas da carona
     * @see Dominio
     */
    Vagas getVagas() { return this->vagas; }
    /**
     * @brief Método para adicionar um Preco a entidade Carona
     * @param valor Valor preço a ser adicionada a carona
     * @see Dominio
     */
    void setPreco(string);
    /**
     * @brief Método para retornar o Preço da entidade Carona
     * @return Valor do tipo Preço com o preço da carona
     * @see Dominio
     */
    Preco getPreco() { return this->preco; }
};

/**
 * @brief Entidade Conta
 * @details
 *   A classe Conta representa uma entidade das contas de usuários para pagamento.
 *   A entidade possui atributos privados cujos tipos são Domínios e métodos públicos
 *   de get e set para acesso a esses atributos.
 * @see Dominio
 */
class Conta {
 private:
    Codigo_de_banco banco;          /**< @param banco             Código do banco da conta */
    Numero_de_agencia agencia;      /**< @param agencia           Número da agencia da conta */
    Numero_de_conta numero;         /**< @param numero            Número da conta */

 public:
    /**
     * @brief Método para adicionar um Código de banco a entidade Conta
     * @param valor Valor do código de banco a ser adicionado a conta
     * @see Dominio
     */
    void setCodigo_de_banco(string);
    /**
     * @brief Método para retornar o Código de banco da entidade Conta
     * @return Valor do tipo Codigo_de_banco com o código do banco da conta
     * @see Dominio
     */
    Codigo_de_banco getCodigo_de_banco() { return this->banco; }
    /**
     * @brief Método para adicionar um Número de agencia a entidade Conta
     * @param valor Valor do número de agencia a ser adicionado a conta
     * @see Dominio
     */
    void setNumero_de_agencia(string);
    /**
     * @brief Método para retornar o Número de agencia da entidade Conta
     * @return Valor do tipo Numero_de_agencia com o número da agencia da conta
     * @see Dominio
     */
    Numero_de_agencia getNumero_de_agencia() { return this->agencia; }
    /**
     * @brief Método para adicionar um Número de conta a entidade Conta
     * @param valor Valor do número de conta a ser adicionado a conta
     * @see Dominio
     */
    void setNumero_de_conta(string);
    /**
     * @brief Método para retornar o Número de conta da entidade Conta
     * @return Valor do tipo Numero_de_conta com o número da conta
     * @see Dominio
     */
    Numero_de_conta getNumero_de_conta() { return this->numero; }
};

#endif  // ENTIDADES_HPP_
