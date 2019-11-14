#include "stubs.hpp"

// Definicoes de metodo da classe stub do controlador da logica de negocio de autenticacao.

bool StubSAutenticacao::autenticar(const Email &email, const Senha &senha, Usuario *current_user) throw(runtime_error) {

    // Apresentar dados recebidos.

    cout << endl << "StubSAutenticacao::autenticar" << endl ;

    cout << "Email = " << email.getValor() << endl ;
    cout << "Senha     = " << senha.getValor()     << endl ;

    // Diferentes comportamentos dependendo do valor do email.

    if (email.getValor() == TRIGGER_FALHA) {
        current_user = NULL;
        return false;
    } else if (email.getValor() == TRIGGER_ERRO_SISTEMA) {
        current_user = NULL;
        throw runtime_error("Erro de sistema!");
    }

    // Simula usuario encontrado na base de dados
    current_user->setCpf("591.581.540-51");
    current_user->setEmail(email.getValor());
    current_user->setNome("Jurandismar");
    current_user->setSenha(senha.getValor());
    current_user->setTelefone("55-61-999999999");

    return true;
}

bool StubSUsuario::cadastrar(Usuario &usuario, Conta &conta) throw(runtime_error) {

   // Apresentar dados recebidos.

    cout << endl << "StubSUsuario::cadastrar" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getNome().getValor() == TRIGGER_FALHA_CAD) {
        return false;
    } else if (usuario.getNome().getValor() == TRIGGER_ERRO_SISTEMA_CAD) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

void StubSUsuario::pesquisar(Usuario &usuario) throw(runtime_error) {

   // Apresentar dados recebidos.

    /*cout << endl << "StubSUsuario::cadastrar" << endl ;
    cout << "Nome = " << usuario.getNome().getValor() << endl ;

    if(usuario.getNome().getValor() == TRIGGER_FALHA_CAD) {
        return false;
    } else if (usuario.getNome().getValor() == TRIGGER_ERRO_SISTEMA_CAD) {
        throw runtime_error("Erro de sistema");
    }*/

    return;
}

bool StubSUsuario::excluir(Usuario &usuario) throw(runtime_error) {
   // Apresentar dados recebidos.

    if (usuario.getEmail().getValor() == TRIGGER_FALHA_EXC) {
        return false;
    } else if (usuario.getEmail().getValor() == TRIGGER_ERRO_SISTEMA_EXC) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}
bool StubSCarona::cadastrar(Carona &carona, Usuario &usuario) throw(runtime_error) {
    //Apresentar dados recebidos

    cout << endl << "StubSCarona::cadastrar" << endl ;
    cout << "Nome = " << carona.getCodigo_de_carona().getValor() << endl ;

    if(carona.getCodigo_de_carona().getValor() == TRIGGER_FALHA_CAD) {
        return false;
    } else if (carona.getCodigo_de_carona().getValor() == TRIGGER_ERRO_SISTEMA_CAD) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

bool StubSCarona::pesquisar(Carona &carona, vector<Carona> *caronas, vector<Usuario> *motoristas) throw(runtime_error) {
    //Apresentar dados recebidos

    if (carona.getCidadeOrigem().getValor() == TRIGGER_FALHA_PES) {
        return false;
    } else if (carona.getCidadeOrigem().getValor() == TRIGGER_ERRO_SISTEMA_PES) {
        throw runtime_error("Erro de sistema!");
    }

    // Simula motoristas de caronas
    Usuario m1;
    m1.setCpf("591.581.540-51");
    m1.setEmail("juris@uvt.com");
    m1.setNome("Jurandismar");
    m1.setSenha("S3nh4");
    m1.setTelefone("55-61-999999999");
    motoristas->push_back(m1);

    Usuario m2;
    m2.setCpf("608.596.560-55");
    m2.setEmail("hermenegildo@uvt.com");
    m2.setNome("Hermenegildo");
    m2.setSenha("P3ixe");
    m2.setTelefone("55-61-555555555");
    motoristas->push_back(m2);

    // Simula caronas
    Carona c1;
    c1.setCodigo_de_carona("0123");
    c1.setCidade_origem(carona.getCidadeOrigem().getValor());
    c1.setCidade_destino(carona.getCidadedestino().getValor());
    c1.setEstado_origem(carona.getEstado_origem().getValor());
    c1.setEstado_destino(carona.getEstado_destino().getValor());
    c1.setData(carona.getData().getValor());
    c1.setVagas("3");
    c1.setDuracao("22");
    c1.setPreco("550,00");
    caronas->push_back(c1);

    Carona c2;
    c2.setCodigo_de_carona("4735");
    c2.setCidade_origem(carona.getCidadeOrigem().getValor());
    c2.setCidade_destino(carona.getCidadedestino().getValor());
    c2.setEstado_origem(carona.getEstado_origem().getValor());
    c2.setEstado_destino(carona.getEstado_destino().getValor());
    c2.setData(carona.getData().getValor());
    c2.setVagas("4");
    c2.setDuracao("48");
    c2.setPreco("360,99");
    caronas->push_back(c2);
    return true;
}

bool StubSCarona::reservar(Reserva *reserva, Codigo_de_carona &codCarona, Usuario &usuario, Conta *conta_motorista) throw(runtime_error) {
    //Apresentar dados recebidos

    if (codCarona.getValor() == TRIGGER_FALHA_RES) {
        return false;
    } else if (codCarona.getValor() == TRIGGER_ERRO_SISTEMA_RES) {
        throw runtime_error("Erro de sistema!");
    }

    // Simula geração de codigo de carona
    reserva->setCodigo_de_reserva("12345");

    // Simula conta do motorista
    conta_motorista->setCodigo_de_banco("123");
    conta_motorista->setNumero_de_agencia("7992-1");
    conta_motorista->setNumero_de_conta("799273-8");

    return true;
}

bool StubSCarona::cancelar(Codigo_de_reserva &codReserva, Usuario &current_user) throw(runtime_error) {
    //Apresentar dados recebidos

    cout << endl << "StubSCarona::cancelar" << endl ;
    cout << "Nome = " << codReserva.getValor() << endl ;

    if(codReserva.getValor() == TRIGGER_FALHA_CAN) {
        return false;
    } else if (codReserva.getValor() == TRIGGER_ERRO_SISTEMA_CAN) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}

bool StubSCarona::excluir(Codigo_de_carona &codigo, Usuario &current_user) throw(runtime_error) {
    //Apresentar dados recebidos

    cout << endl << "StubSCarona::excluir" << endl ;
    cout << "Nome = " << codigo.getValor() << endl ;

    if(codigo.getValor() == TRIGGER_FALHA_DEL) {
        return false;
    } else if (codigo.getValor() == TRIGGER_ERRO_SISTEMA_DEL) {
        throw runtime_error("Erro de sistema!");
    }

    return true;
}
