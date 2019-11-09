#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

// Declara��es adiantadas.

class ISAutenticacao;

class IAAutenticacao {
public:

    // M�todo por meio do qual � solicitado o servi�o.

    virtual bool autenticar(Email*) throw(runtime_error) = 0;

    // M�todo por meio do qual � estabelecida liga��o (link) com a controladora na camada de servi�o.

    virtual void setCntrSAutenticacao(ISAutenticacao *) = 0;

    // M�todo destrutor virtual.

    virtual ~IAAutenticacao(){}
};

// Declara��o de interface para servi�o de autentica��o na camada de servi�o.

class ISAutenticacao {
public:

    // M�todo por meio do qual � solicitado o servi�o.

    virtual bool autenticar(const Email&, const Senha&)throw(runtime_error)= 0;

    // M�todo destrutor virtual.

    virtual ~ISAutenticacao(){}
};









#endif // INTERFACES_H_INCLUDED
