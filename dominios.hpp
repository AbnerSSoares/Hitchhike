/* Copyright 2019 Abner Soares e Kallebe Sousa */

#ifndef DOMINIOS_HPP_
#define DOMINIOS_HPP_

#include <string>
#include <vector>

using std::string;

/**
 * @brief Classe Domínio responsável por definir a estrutura básica das classes de cada domínio
 * @details
 *  A classe Domínio é a classe base das classes de cada domínio do sistema.
 *  Um Domínio é uma classe que representa um tipo específico do sistema implementado.
 *  Cada domínio possui um atributo que representa seu valor, e métodos públicos de
 *  set e get para o acesso ao valor. Ainda, cada domínio possui um método de validação,
 *  assim, um valor só pode ser registrado em um domínio se ele for devidamente validado.
 */
class Dominio {
 private:
    string valor;   /**< @param valor Valor do domínio */

 public:
    /**
     * @brief Método para adicionar valor ao domínio
     * @param valor Valor a ser adicionado ao domínio
     * @see Dominio
     */
    void setValor(string);
    /**
     * @brief   Método para receber valor do domínio
     * @return  Valor armazenado no domínio
     * @see Dominio
     */
    string getValor() const { return valor; }
    /**
     * @brief   Método responsável pela validação do domínio
     * @param   valor Valor a ser validado para o domínio em questão
     * @throws  Lança exceção do tipo invalid_argument caso o valor seja inválido
     * @see Dominio
     */
    virtual void validar(string) = 0;

 protected:
    /**
     * @brief               Separa string em um vetor a partir de delimitador
     * @param str           String que se pretende dividir
     * @param delimitador   Define a partir de qual caractere a string deverá ser dividida
     * @return              Vetor contendo strings antes e depois do delimitador
     */
    std::vector<string> splitString(string, char);
    /**
     * @brief       Verifica se string possui apenas valores numéricos
     * @param str   String que será verificada
     * @return      true se string possui apenas valores numéricos, false, caso contrário
     */
    bool areDigits(string);
    /**
     * @brief       Verifica se string possui caracter especial, exceto ponto, espaço ou vogal acentuada
     * @param str   String que será verificada
     * @return      true se string possui caracter especial, exceto ponto, espaço ou vogal acentuada, false, caso contrário
     */
    bool isSpecial(string);
    /**
     * @brief       Verifica se string possui letra
     * @param str   String que será verificada
     * @return      true se string possui letra, false, caso contrário
     */
    bool hasAlpha(string);
    /**
     * @brief       Verifica se string possui número
     * @param str   String que será verificada
     * @return      true se string possui número, false, caso contrário
     */
    bool hasDigit(string);
};

/**
 * @brief Domínio Assento
 * @details
 *  A classe de Assento é uma classe filha de Domínio e serve
 *  para definir se o assento da carona é dianteiro ou traseiro.
 * @param valor string que pode ser "D" ou "T", representando dianteiro e traseiro, respectivamente
 * @see Dominio
 */
class Assento : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Bagagem
 * @details
 *  A classe de Bagagem é uma classe filha de Domínio e serve
 *  para definir o número de volumes da bagagem.
 * @param valor string que pode ser 0, 1, 2, 3 ou 4
 * @see Dominio
 */
class Bagagem : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Código de Banco
 * @details
 *  A classe Código de Banco é uma classe filha de Domínio e serve
 *  para identificar o banco do usuário.
 * @param valor string no formato XXX, onte X é dígito (0 a 9)
 * @see Dominio
 */
class Codigo_de_banco : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Código de Carona
 * @details
 *  A classe Código de Carona é uma classe filha de Domínio e serve
 *  para identificar cada carona no sistema.
 * @param valor string no formato XXXX, onte X é dígito (0 a 9)
 * @see Dominio
 */
class Codigo_de_carona : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Código de Reserva
 * @details
 *  A classe Código de Reserva é uma classe filha de Domínio e serve
 *  para identificar reservas feitas a cada carona por usuários passageiros.
 * @param valor string no formato XXXXX, onte X é dígito (0 a 9)
 * @see Dominio
 */
class Codigo_de_reserva : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Cidade
 * @details
 *  A classe Cidade é uma classe filha de Domínio e serve
 *  para representar uma cidade.
 * @param valor string de 1 a 10 caracteres, cada caractere
 *  sendo letra (mínimo 1 caractere), ponto ou espaço. Antes de
 *  ponto deve haver letra e não pode haver dois espaços seguidos
 * @see Dominio
 */
class Cidade : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Cpf
 * @details
 *  A classe Cpf é uma classe filha de Domínio e serve
 *  para identificar o um número de cpf de um usuário.
 * @param valor string no formato XXX.XXX.XXX-XX onde X é dígito (0 - 9).
 *  O número de CPF inclui dígitos verificadores calculados por meio de
 *  um algorítmo específico.
 * @see Dominio
 */
class Cpf : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Data
 * @details
 *  A classe Data é uma classe filha de Domínio e serve
 *  para representar a data de uma carona.
 * @param valor string no formato DD/MM/AAAA. DD é número de 1 e 31.
 *  MM é número de 1 e 12. AAAA é número de 2000 a 2099.
 * @see Dominio
 */
class Data : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Duracao
 * @details
 *  A classe Duração é uma classe filha de Domínio e serve
 *  para representar a duração de uma carona.
 * @param valor string de 1 a 48, onde representa horas.
 * @see Dominio
 */
class Duracao : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Estado
 * @details
 *  A classe Estado é uma classe filha de Domínio e serve
 *  para representar um estado brasileiro.
 * @param valor string da sigla do estado, podendo ser: AC,
 *  AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB,
 *  PR, PE, PI, RJ, RN, RS, RO, RR, SC, SP, SE ou TO.
 * @see Dominio
 */
class Estado : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Email
 * @details
 *  A classe Email é uma classe filha de Domínio e serve
 *  para identificar o email de um usuário.
 * @param valor string no formato local@domínio onde: a parte
 *  local pode ter até 20 caracteres; o domíno pode ter até 20
 *  caracteres; cada caracter pode ser letra (a - z) ou ponto(.);
 *  a parte local não pode ser iniciada e nem ser terminada por ponto;
 *  o domínio não pode ser iniciado por ponto; não podem existir dois
 *  pontos em sequência.
 * @see Dominio
 */
class Email : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Nome
 * @details
 *  A classe Nome é uma classe filha de Domínio e serve
 *  para identificar o nome de um usuário.
 * @param valor string que possui de 1 a 20 caracteres, onde cada caracter
 *  pode ser letra, ponto ou espaço. Pelo menos um caracter é letra, antes
 *  de ponto deve haver letra e não há espaços em sequência.
 * @see Dominio
 */
class Nome : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Numero_de_agencia
 * @details
 *  A classe Numero_de_agencia é uma classe filha de Domínio e serve
 *  para representar o número de agencia bancária de um usuário.
 * @param valor string no formato XXXX-Y onde X é dígito (0 - 9) e Y
 *  é dígito verificador calculado por meio do algorítimo de Luhn.
 * @see Dominio
 */
class Numero_de_agencia : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Numero_de_conta
 * @details
 *  A classe Numero_de_conta é uma classe filha de Domínio e serve
 *  para representar o número de conta bancária de um usuário.
 * @param valor string no formato XXXXXX-Y onde X é dígito (0 - 9)
 *  e Y é dígito verificador calculado por meio do algorítimo de Luhn.
 * @see Dominio
 */
class Numero_de_conta : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Preco
 * @details
 *  A classe Preco é uma classe filha de Domínio e serve
 *  para representar o preço de uma carona.
 * @param valor string de 1,00 a 5.000,00, Onde representa
 *  o preço em reais (R$).
 * @see Dominio
 */
class Preco : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Telefone
 * @details
 *  A classe Telefone é uma classe filha de Domínio e serve
 *  para representar o telefone de um usuário.
 * @param valor string no formato XX-YY-ZZZZZZZZZ, onde cada X, Y ou Z
 *  é dígito (0 - 9); o valor de XX não pode ser 00, o valor de YY não
 *  pode ser 00 e o valor de ZZZZZZZZZ não pode ser 000000000.
 * @see Dominio
 */
class Telefone : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Senha
 * @details
 *  A classe Senha é uma classe filha de Domínio e serve
 *  para representar a senha de acesso de um usuário.
 * @param valor string no formato XXXXX onde X pode ser letra
 *  (a - z ou A - Z), dígito (0 - 9), # , $ , % ou &. A senha
 *  tem que ter pelo menos uma letra e um dígito. Não podem haver
 *  caracteres repetidos.
 * @see Dominio
 */
class Senha : public Dominio {
    void validar(string);
};

/**
 * @brief Domínio Vagas
 * @details
 *  A classe Vagas é uma classe filha de Domínio e serve
 *  para representar o número de vagas disponível em uma carona.
 * @param valor string de 0 a 4.
 * @see Dominio
 */
class Vagas : public Dominio {
    void validar(string);
};

#endif  // DOMINIOS_HPP_
