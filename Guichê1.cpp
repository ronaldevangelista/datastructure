#include <iostream>
#include <locale.h>
using namespace std;

#define MAX 10

struct Fila {
	int ini;
	int fim;
	float nos[MAX];
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = 0;
	f->fim = 0;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == f->fim);
}

int incrementa(int i) {
	return (i==MAX?0:++i);
}

string incremetado(int pe){
	return (pe?"Incrementado":"Erro");
}

int count(Fila *f) {
	int qtde = 0;
	int i = f->ini;
	while (i != f->fim) {
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

//ENFILEIRAR
int enqueue(Fila *f, float v) {
	int podeEnfileirar = (incrementa(f->fim) != f->ini);
	if (podeEnfileirar) {
		f->nos[f->fim] = v;
		f->fim = incrementa(f->fim);
	}
    return podeEnfileirar;	
}

//DESENFILEIRADOR
float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		ret = f->nos[f->ini];
		f->ini = incrementa(f->ini);
	}
	return ret;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	Fila *senhasGeradas;
	Fila *senhasAtendidas;
	senhasGeradas = init();
	senhasAtendidas = init();
	int fim = 0;
	float senha = 1; 
	float senhaDaVez;
	
	cout << "Seja bem-vindo ao supermercado do bairrinho" << endl;
	
	while(fim==0){
		int opt;
		cout << "MENU DE OPÇÕES" << endl;
		cout << "--------------" << endl;
		
		cout << "Senhas aguardando: " << count(senhasGeradas) << endl;
		cout << "0. Sair" << endl << "1. Gerar senha" << endl << "2. Realizar atendimento" << endl << "--------------" << endl;
		cout << "Opção selecionada: ";
		cin >> opt;
		cout << "--------------" << endl;
		
		switch(opt)
		{
		case 0:
			fim = 1;
			break;
		case 1:
			if(count(senhasGeradas) < MAX){
				cout << incremetado(enqueue(senhasGeradas, senha)) << endl;
				senha++;
			} else
			{
				cout << "VALOR MÁXIMO DE SENHAS, POR FAVOR, GERE UM ATENDIMENTO" << endl;
			}
			break;
		case 2:
			senhaDaVez = dequeue(senhasGeradas);
			cout << "Atenção, senha: " << senhaDaVez << endl;
			cout << "Vá ao caixa" << endl;
			enqueue(senhasAtendidas, senhaDaVez);
			break;
		default:
			cout << "ERRO NO SELETOR" << endl;
			break;
		}
		
		cout << endl;
	}
	return 0;
	
	
}