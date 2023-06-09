#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <locale.h>

using namespace std;

// STRUCT E METÓDOS FILA
struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* initFila() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while(no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "------------" << endl;
	while(no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------" << endl;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

// Enfileirar
void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
	   f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

// Desenfileirar
float dequeue(Fila *f) {
	float ret;
	
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}


// STRUCT E DADOS LISTA
struct Lista
{
	Fila *senhasAtendidas;
	int id;
	struct Lista *prox;
};

Lista* initLista()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, int i)
{
	Lista* novo = new Lista();
	novo->id = i;
	novo->prox = lista;
	return novo;
}

Lista* find(Lista* lista, int i)
{
	Lista* aux = lista;
	
	while (aux != NULL && aux->id != i)
	{
		aux = aux->prox;
	}
	return aux;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	
	
	int caixas = 1;
	Fila *senhasGeradas = initFila();
	Lista *listaGuiches = initLista();
	int unlocker = 0;
	float senhaDaVez = 1;
	
	do{
		cout << endl << endl;
		cout << "-- MENU SELETOR --" << endl;
		
		int opt = 0;
		cout << "--------------" << endl;
		
		cout << "Senhas aguardando: " << count(senhasGeradas) << endl;
		
		cout << "0. Sair" << endl;
		cout << "1. Gerar senha" << endl;
		cout << "2. Abrir guichê" << endl;
		cout << "3. Realizar atendimento" << endl;
		cout << "4. Listar senhas atendidas" << endl;
		cout << "--------------" << endl << "" << endl;
		
		cout << "Opção selecionada: ";
		cin >> opt;
		cout << "--------------" << endl;
		int idGuiche = 0;
		Lista *guicheEscolhido;
		
		switch(opt)
		{
		case 0:
			//GERAR ESTRUTURA VERIFICADORA
			if (isEmpty(senhasGeradas)){
				unlocker = 1;	
			}else{
				cout << "Ainda restam clientes para atender" << endl;
				cout << "Tome vergonha na cara e vá trabalhar" << endl;
			}
			break;
		case 1:
			enqueue(senhasGeradas, senhaDaVez);
			senhaDaVez++;
			break;
		case 2:
			//INSERIR NOVO GUICHÊ NA LISTA DE GUICHÊS
			listaGuiches = insert(listaGuiches, caixas);
			caixas++;
			listaGuiches->senhasAtendidas = initFila();
			cout << "Guichê " << listaGuiches->id << " aberto." << endl << endl;
			break;
		case 3:
			if(isEmpty(senhasGeradas)){
				cout << "Sem senhas para atender" << endl;
				break;
			}
			
			cout << "Digite o id do guichê que atenderá: ";
			cin >> idGuiche;
			
			guicheEscolhido = find(listaGuiches, idGuiche);
			if(guicheEscolhido != NULL){
				enqueue(guicheEscolhido->senhasAtendidas, dequeue(senhasGeradas));
			}else
			{
				cout << "Guichê inexistente" << endl;
			}
			break;
		case 4:
			cout << "Digite o id do guichê para verificar quais senhas ele atendeu: ";
			cin >> idGuiche;
			
			guicheEscolhido = find(listaGuiches, idGuiche);
			print(guicheEscolhido->senhasAtendidas);
			break;
		default:
			cout << "Erro, opção inválida." << endl;
			break;
		}
		
		
	}while(unlocker != 1);
	
	cout << "Ao todo, foram atendidas " << (senhaDaVez - 1) << " senhas.";
	return 0;
}