#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <string.h>

using std::string;

class Dominio {
private:
    string valor;

public:
    void setValor(string) throw(invalid_argument);

    string getValor() const {
            return valor;
        }
    virtual void validar(string) throw(invalid_argument);


};



class Assento : public Dominio {
/**private:
    char tipo;

public:
    void setAssento(char tipo) { this->tipo = tipo; }
    char getAssento() { return tipo; }
**/
};

class Bagagem : public Dominio{



};

class Codigo_de_banco : public Dominio{


};

class Codigo_de_carona : public Dominio{


};

class Codigo_de_reserva : public Dominio{


};

class Cidade : public Dominio{


};

class CPF : public Dominio{


};

class Data : public Dominio{


};

class Duração : public Dominio{


};

class Estado : public Dominio{


};

class Email : public Dominio{


};

class Nome : public Dominio {
/**private:
    string nome;

    void validar(string nome);

public:
    void setNome(string nome);
    string getNome() { return nome; }
**/
};

class Numero_de_agencia : public Dominio{


};

class Numero_de_conta : public Dominio{


};

class Preco : public Dominio{


};

class Telefone : public Dominio{


};

class Senha : public Dominio{


};

class Vagas : public Dominio{


};






#endif
