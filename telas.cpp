#include "telas.hpp"
#include <string.h>
#include <iostream>
#include "curses.h"

using namespace std;

int TelaInicializacao::usuario() {
    int option = -1;
    char* choices[] = {"Pesquisar Caronas",
                        "Cadastrar Carona",
                        "Listar reservas de carona",
                        "Descadastrar Carona",
                        "Reservar Carona",
                        "Cancelar Reserva de carona",
                        "Descadastrar do sistema",
                        "Sair"};

    int n_choices = sizeof(choices) / sizeof(char *);
    option = this->montarTela(choices, n_choices);
    return option;
}

int TelaInicializacao::incializacao() {
    int option = -1;
    char* choices[] = {"Cadastrar Usuario",
                        "Autenticar Usuario",
                        "Pesquisar caronas",
                        "Exit"};

    int n_choices = sizeof(choices) / sizeof(char *);
    option = this->montarTela(choices, n_choices);
    return option;
}

int TelaInicializacao::montarTela(char* choices[], int n_choices) {
    int acao = -1;
    int c, choice = 0;
    int HEIGHT = 12, WIDTH = 30;
    int linha, coluna;
	WINDOW *menu_win;
	MEVENT event;

	/* Initialize curses */
	initscr();
	getmaxyx(stdscr, linha, coluna);
	clear();
	noecho();
	cbreak();	//Line buffering disabled. pass on everything

	/* Try to put the window in the middle of screen */
	startx = (coluna - WIDTH) / 2;
	starty = (linha - HEIGHT) / 2;

	attron(A_REVERSE);
	mvprintw(23, 1, "Click on Exit to quit (Works best in a virtual console)");
	refresh();
	attroff(A_REVERSE);

	/* Print the menu for the first time */
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	this->print_menu(menu_win, 1, choices, n_choices);
	/* Get all the mouse events */
	mousemask(ALL_MOUSE_EVENTS, NULL);
	keypad(menu_win, TRUE);

	while(acao == -1) {
        c = wgetch(menu_win);
		switch(c){
		    case KEY_MOUSE:
			if(nc_getmouse(&event) == OK) {	/* When the user clicks left mouse button */
				if(event.bstate & BUTTON1_PRESSED) {
				    this->report_choice(event.x + 1, event.y + 1, &choice, choices, n_choices);
					acao = choice;
					mvprintw(22, 1, "Choice made is : %d String Chosen is \"%10s\"", choice, choices[choice - 1]);
					goto end;
					refresh();
				}
			}
			this->print_menu(menu_win, choice, choices, n_choices);
			break;
		}
	}
end:
	endwin();
	return acao;
}

void TelaInicializacao::print_menu(WINDOW* menu_win, int highlight, char *choices[], int n_choices) {
    int x, y, i;

	x = 2;
	y = 2;
	box(menu_win, 0, 0);
	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1)
		{	wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

void TelaInicializacao::report_choice(int mouse_x, int mouse_y, int *p_choice, char *choices[], int n_choices) {
    int i,j, choice;

	i = startx + 2;
	j = starty + 3;

	for(choice = 0; choice < n_choices; ++choice)
		if(mouse_y == j + choice && mouse_x >= i && mouse_x <= i + strlen(choices[choice]))
		{	if(choice == n_choices - 1)
				*p_choice = -1;
			else
				*p_choice = choice + 1;
			break;
		}
}

void TelaMensagem::show(const char *mensagem) {
    int linha, coluna;
    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(linha/2, (coluna - strlen(mensagem))/2, "%s", mensagem);
    noecho();
    getch();
    echo();
    clear();
    endwin();
}

bool TelaAutenticacao::autenticar(Email *email, Senha *senha) {
    char *titulo   = "Autenticacao de Usuario";
    char *lblEmail = "Digite seu email: ";
    char *lblSenha = "Digite sua senha: ";
    char *mensErro = "Dados invalidos!";
    char txtEmailc[20], txtSenhac[15];
    int linha, coluna;
    bool sucess = true;

    initscr();
    getmaxyx(stdscr, linha, coluna);
    mvprintw(linha/8, (coluna - strlen(lblEmail))/2, "%s", titulo);
    mvprintw(linha/2, (coluna - strlen(lblEmail))/2, "%s", lblEmail);
    getstr(txtEmailc);
    mvprintw(linha/2 + 2, (coluna - strlen(lblSenha))/2, "%s", lblSenha);
    getstr(txtSenhac);

    string txtEmails = txtEmailc;
    string txtSenhas = txtSenhac;

    try {
        email->setValor(txtEmails);
    } catch (...) {
        mvprintw(linha/2 + 4, (coluna - 15)/2, "Email invalido!");
        sucess = false;
    }
    try {
        senha->setValor(txtSenhas);
    } catch (...) {
        mvprintw(linha/2 + 4, (coluna - 15)/2, "Senha invalida!");
        sucess = false;
    }
    clear();
    endwin();
    return sucess;
}

bool TelaUsuario::cadastrar(Usuario *user, Conta *conta) {
    char *titulo        = "Cadastro de usuario";
    char *lblNome       = "Nome: ";
    char *lblEmail      = "Email: ";
    char *lblTelefone   = "Telefone: ";
    char *lblSenha      = "Senha: ";
    char *lblCpf        = "Cpf: ";
    char *lblCodBanco   = "Codigo de banco: ";
    char *lblNumAgencia = "Numero da agencia: ";
    char *lblNumConta   = "Numero da conta: ";
    char *mensErro      = "Dados invalidos!";
    char txtNomec[21], txtEmailc[42], txtTelefonec[17], txtSenhac[6], txtCpfc[16];
    char txtCodBancoc[4], txtNumAgenciac[7], txtNumContac[9];
    int linha, coluna;
    bool sucess = true;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de cadastro de usuario
    mvprintw(linha/8, coluna/8, "%s", lblNome);
    getstr(txtNomec);

    mvprintw(linha/8+2, coluna/8, "%s", lblCpf);
    getstr(txtCpfc);

    mvprintw(linha/8+4, coluna/8, "%s", lblTelefone);
    getstr(txtTelefonec);

    mvprintw(linha/8+6, coluna/8, "%s", lblEmail);
    getstr(txtEmailc);

    mvprintw(linha/8+8, coluna/8, "%s", lblSenha);
    getstr(txtSenhac);

    // Campos cadastro conta
    mvprintw(linha/8+10, coluna/8, "%s", lblCodBanco);
    getstr(txtCodBancoc);

    mvprintw(linha/8+12, coluna/8, "%s", lblNumAgencia);
    getstr(txtNumAgenciac);

    mvprintw(linha/8+14, coluna/8, "%s", lblNumConta);
    getstr(txtNumContac);

    //Atribuição de valores
    string txtNome = txtNomec;
    string txtEmail = txtEmailc;
    string txtSenha = txtSenhac;
    string txtCpf = txtCpfc;
    string txtTelefone = txtTelefonec;

    string txtCodBanco = txtCodBancoc;
    string txtNumAgencia = txtNumAgenciac;
    string txtNumConta = txtNumContac;

    int i = 16;
    try {
        user->setNome(txtNome);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Nome invalido!");
        i++;
    }
    try {
        user->setEmail(txtEmail);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Email invalido!");
        i++;
    }
    try {
        user->setSenha(txtSenha);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Senha invalida!");
        i++;
    }
    try {
        user->setCpf(txtCpf);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "CPF invalido!");
        i++;
    }
    try {
        user->setTelefone(txtTelefone);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Telefone invalido!");
        i++;
    }
    try {
        conta->setCodigo_de_banco(txtCodBanco);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Codigo de Banco invalido!");
        i++;
    }
    try {
        conta->setNumero_de_agencia(txtNumAgencia);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Numero de Agencia invalido!");
        i++;
    }
    try {
        conta->setNumero_de_conta(txtNumConta);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Numero de Conta invalido!");
        i++;
    }

    (i > 16) ? sucess = false : sucess = true;

    noecho();
    getch();
    echo();
    clear();
    endwin();

    return sucess;
}

bool TelaCarona::cadastrar(Carona *carona) {
    char *titulo            = "Cadastrar Carona";
    char *lblcodCarona      = "Codigo de carona: ";
    char *lblCidOrigem      = "Cidade Origem: ";
    char *lblEstadoOrigem   = "Estado Origem: ";
    char *lblCidDestino     = "Cidade Destino: ";
    char *lblEstadoDestino  = "Estado Destino: ";
    char *lblData           = "Data Partida: ";
    char *lblDuracao        = "Duracao Trajeto: ";
    char *lblVagas          = "Qtd de Vagas: ";
    char *lblPreco          = "Preco: ";
    char *mensErro          = "Dados invalidos!";
    char txtVagasc[2], txtCodCaronac[5], txtCidOrigemc[11], txtEstadoOrigemc[3], txtCidadeDestinoc[11];
    char txtEstadoDestinoc[3], txtDatac[11], txtDuracaoc[4], txtPrecoc[9];
    int linha, coluna;
    bool sucess = true;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de cadastro de carona
    mvprintw(linha/8, coluna/8, "%s", lblcodCarona);
    getstr(txtCodCaronac);

    mvprintw(linha/8+2, coluna/8, "%s", lblCidOrigem);
    getstr(txtCidOrigemc);

    mvprintw(linha/8+4, coluna/8, "%s", lblEstadoOrigem);
    getstr(txtEstadoOrigemc);

    mvprintw(linha/8+6, coluna/8, "%s", lblCidDestino);
    getstr(txtCidadeDestinoc);

    mvprintw(linha/8+8, coluna/8, "%s", lblEstadoDestino);
    getstr(txtEstadoDestinoc);

    mvprintw(linha/8+10, coluna/8, "%s", lblData);
    getstr(txtDatac);

    mvprintw(linha/8+12, coluna/8, "%s", lblDuracao);
    getstr(txtDuracaoc);

    mvprintw(linha/8+14, coluna/8, "%s", lblVagas);
    getstr(txtVagasc);

    mvprintw(linha/8+16, coluna/8, "%s", lblPreco);
    getstr(txtPrecoc);

    //Atribuição de valores
    string txtVagas = txtVagasc;
    string txtPreco = txtPrecoc;
    string txtCodCarona = txtCodCaronac;
    string txtEstadoOrigem = txtEstadoOrigemc;
    string txtCidadeDestino = txtCidadeDestinoc;
    string txtCidOrigem = txtCidOrigemc;
    string txtEstadoDestino = txtEstadoDestinoc;
    string txtData = txtDatac;
    string txtDuracao = txtDuracaoc;

    int i = 18;
    try {
        carona->setVagas(txtVagas);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Qtd de Vagas invalido!");
        i++;
    }
    try {
        carona->setCodigo_de_carona(txtCodCarona);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Codigo de carona invalido!");
        i++;
    }
    try {
        carona->setEstado_origem(txtEstadoOrigem);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Estado Origem invalido!");
        i++;
    }
    try {
        carona->setCidade_destino(txtCidadeDestino);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Cidade Destino invalido!");
        i++;
    }
    try {
        carona->setCidade_origem(txtCidOrigem);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Cidade origem invalida!");
        i++;
    }
    try {
        carona->setEstado_destino(txtEstadoDestino);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Estado destino invalido!");
        i++;
    }
    try {
        carona->setData(txtData);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Data invalida!");
        i++;
    }
    try {
        carona->setDuracao(txtDuracao);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Duracao invalida!");
        i++;
    }
    try {
        carona->setPreco(txtPreco);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Preco invalido!");
        i++;
    }

    (i > 18) ? sucess = false : sucess = true;

    noecho();
    getch();
    echo();
    clear();
    endwin();

    return sucess;
}

bool TelaCarona::pesquisar(Carona *carona) {
    char *titulo            = "Pesquisar Caronas";
    char *lblCidadeOrigem   = "Cidade Origem: ";
    char *lblEstadoOrigem   = "Estado Origem: ";
    char *lblCidadeDestino  = "Cidade Destino: ";
    char *lblEstadoDestino  = "Estado Destino: ";
    char *lblData           = "Data partida: ";
    char txtCidadeOrigemc[11], txtEstadoOrigemc[3], txtCidadeDestinoc[11], txtEstadoDestinoc[3], txtDatac[11];
    int linha, coluna;
    bool sucesso = false;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de pesquisa de carona
    mvprintw(linha/8, coluna/8, "%s", lblCidadeOrigem);
    getstr(txtCidadeOrigemc);

    mvprintw(linha/8+2, coluna/8, "%s", lblEstadoOrigem);
    getstr(txtEstadoOrigemc);

    mvprintw(linha/8+4, coluna/8, "%s", lblCidadeDestino);
    getstr(txtCidadeDestinoc);

    mvprintw(linha/8+6, coluna/8, "%s", lblEstadoDestino);
    getstr(txtEstadoDestinoc);

    mvprintw(linha/8+8, coluna/8, "%s", lblData);
    getstr(txtDatac);

    string txtEstadoOrigem = txtEstadoOrigemc;
    string txtCidadeDestino = txtCidadeDestinoc;
    string txtCidOrigem = txtCidadeOrigemc;
    string txtEstadoDestino = txtEstadoDestinoc;
    string txtData = txtDatac;

    int i = 10;
    try {
        carona->setCidade_origem(txtCidOrigem);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Cidade Origem invalida!");
        i++;
    }
    try {
        carona->setEstado_origem(txtEstadoOrigem);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Estado Origem invalido!");
        i++;
    }
    try {
        carona->setCidade_destino(txtCidadeDestino);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Cidade Destino invalido!");
        i++;
    }
    try {
        carona->setEstado_destino(txtEstadoDestino);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Estado Destino invalido!");
        i++;
    }
    try {
        carona->setData(txtData);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Data invalida!");
        i++;
    }

    (i > 10) ? sucesso = false : sucesso = true;

    noecho();
    getch();
    echo();
    clear();
    endwin();

    return sucesso;
}

bool TelaCarona::descadastrarCarona(Codigo_de_carona *codCarona) {
    char *titulo        = "Descadastrar Carona";
    char *lblCodCarona  = "Codigo da Carona: ";
    char txtCodCaronac[5];
    int linha, coluna;
    bool sucesso = false;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de pesquisa de carona
    mvprintw(linha/8, coluna/8, "%s", lblCodCarona);
    getstr(txtCodCaronac);

    string txtCodCarona = txtCodCaronac;

    int i = 2;
    try {
        codCarona->setValor(txtCodCarona);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Codigo de carona Invalido!");
        i++;
    }

    (i > 2) ? sucesso = false : sucesso = true;

    noecho();
    getch();
    echo();
    clear();
    endwin();

    return sucesso;
}

bool TelaCarona::reservar(Reserva *reserva, Codigo_de_carona *carona) {
    char *titulo        = "Reservar Carona";
    char *lblCodCarona  = "Codigo da Carona: ";
    char *lblAssento    = "Preferencia de Assento: ";
    char *lblBagagem    = "Numero de volumes de bagagem: ";
    char txtCodCaronac[5], txtAssentoc[2], txtBagagemc[3];
    int linha, coluna;
    bool sucesso = false;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de pesquisa de carona
    mvprintw(linha/8, coluna/8, "%s", lblCodCarona);
    getstr(txtCodCaronac);

    mvprintw(linha/8+2, coluna/8, "%s", lblAssento);
    getstr(txtAssentoc);

    mvprintw(linha/8+4, coluna/8, "%s", lblBagagem);
    getstr(txtBagagemc);

    string txtAssento = txtAssentoc;
    string txtBagagem = txtBagagemc;
    string txtCodCarona = txtCodCaronac;

    int i = 6;
    try {
        reserva->setAssento(txtAssento);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Assento Invalido!");
        i++;
    }
    try {
        reserva->setBagagem(txtBagagem);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Numero de Bagagem Invalido!");
        i++;
    }
    try {
        carona->setValor(txtCodCarona);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Codigo de carona Invalido!");
        i++;
    }

    (i > 6) ? sucesso = false : sucesso = true;

    noecho();
    getch();
    echo();
    clear();
    endwin();

    return sucesso;
}

bool TelaCarona::cancelarReserva(Codigo_de_carona *codCarona) {
    char *titulo        = "Cancelar Reserva Carona";
    char *lblCodCarona  = "Codigo da Carona: ";
    char txtCodCaronac[5];
    int linha, coluna;
    bool sucesso = false;

    initscr();
    getmaxyx(stdscr, linha, coluna);

    // Titulo
    mvprintw(2, (coluna - strlen(titulo))/2, "%s", titulo);

    // Campos de pesquisa de carona
    mvprintw(linha/8, coluna/8, "%s", lblCodCarona);
    getstr(txtCodCaronac);

    string txtCodCarona = txtCodCaronac;

    int i = 2;
    try {
        codCarona->setValor(txtCodCarona);
    } catch (...) {
        mvprintw(linha/8 + i, (coluna)/8, "Codigo de carona Invalido!");
        i++;
    }

    (i > 2) ? sucesso = false : sucesso = true;

    noecho();
    getch();
    echo();
    clear();
    endwin();

    return sucesso;
}
