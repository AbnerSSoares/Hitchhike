#ifndef DOMINIOS_H
#define DOMINIOS_H

#include <string>
#include <stdexcept>

using std::string;

class Dominio {
private:
    string valor;

public:
    void setValor(string) throw(std::invalid_argument);

    string getValor() const { return valor; }
    virtual void validar(string) throw(std::invalid_argument) { return; }
};

class Assento : public Dominio {

};

class Bagagem : public Dominio {


};

class Codigo_de_banco : public Dominio {


};

class Codigo_de_carona : public Dominio {


};

class Codigo_de_reserva : public Dominio {


};

class Cidade : public Dominio {


};

class Cpf : public Dominio {


};

class Data : public Dominio {


};

class Duracao : public Dominio {


};

class Estado : public Dominio {


};

class Email : public Dominio {


};

class Nome : public Dominio {

};

class Numero_de_agencia : public Dominio {


};

class Numero_de_conta : public Dominio {


};

class Preco : public Dominio {


};

class Telefone : public Dominio {


};

class Senha : public Dominio {


};

class Vagas : public Dominio {


};

#endif
