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
    virtual void validar(string) = 0;

protected:
    bool areDigits(string);
};

class Assento : public Dominio {
    void validar(string);
};

class Bagagem : public Dominio {
    void validar(string);
};

class Codigo_de_banco : public Dominio {
    void validar(string);
};

class Codigo_de_carona : public Dominio {
    void validar(string);
};

class Codigo_de_reserva : public Dominio {
    void validar(string);
};

class Cidade : public Dominio {
    void validar(string);
};

class Cpf : public Dominio {
    void validar(string);
};

class Data : public Dominio {
    void validar(string);
};

class Duracao : public Dominio {
    void validar(string);
};

class Estado : public Dominio {
    void validar(string);
};

class Email : public Dominio {
    void validar(string);
};

class Nome : public Dominio {
    void validar(string);
};

class Numero_de_agencia : public Dominio {
    void validar(string);
};

class Numero_de_conta : public Dominio {
    void validar(string);
};

class Preco : public Dominio {
    void validar(string);
};

class Telefone : public Dominio {
    void validar(string);
};

class Senha : public Dominio {
    void validar(string);
};

class Vagas : public Dominio {
    void validar(string);
};

#endif // DOMINIOS_H
