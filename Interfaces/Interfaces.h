#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declarações adiantadas.

class ISAutenticacao;

class IAAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual bool autenticar(Email*) throw(runtime_error) = 0;

    // Método por meio do qual é estabelecida ligação (link) com a controladora na camada de serviço.

    virtual void setCntrSAutenticacao(ISAutenticacao *) = 0;

    // Método destrutor virtual.

    virtual ~IAAutenticacao(){}
};

// Declaração de interface para serviço de autenticação na camada de serviço.

class ISAutenticacao {
public:

    // Método por meio do qual é solicitado o serviço.

    virtual bool autenticar(const Email&, const Senha&)throw(runtime_error)= 0;

    // Método destrutor virtual.

    virtual ~ISAutenticacao(){}
};









#endif // INTERFACES_H_INCLUDED
