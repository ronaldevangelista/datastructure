#include <iostream>
using namespace std;

struct Corda
{
	int dado;
	struct Corda *prox;
};

struct Pilha {
	Corda *topo;
	string nome;
};

Pilha* init(string n){
	Pilha *p = new Pilha();
	p->topo = NULL;
	p->nome = n;
	return p;
}

int isEmpty(Pilha *p){
	return (p->topo == NULL);
}

int count(Pilha *p){
	int i = 0;
	Corda *c = p->topo;
	
	while(c != NULL){
		i++;
		c = c->prox;
	}
	return i;
}

void print(Pilha *p){
	Corda *c = p->topo;
	cout << "----------------" << endl;
	cout << "Qtde de elementos: " << count(p) << endl;
	cout << "----------------" << endl;
	
	while(c != NULL){
		cout << c->dado << endl;
		c = c->prox;
	}
	cout << "----------------" << endl;
}

void push(Pilha *p, int v){
	Corda *c = new Corda();
	c->dado = v;
	c->prox = p->topo;
	p->topo = c;
}

int isPar(int v){
	return ((v % 2) == 0);
}

int main(int argc, char** argv)
{
	Pilha *Par;
	Par = init("Par");
	
	Pilha *Impar;
	Impar = init("Impar");
	
	print(Par);
	print(Impar);
	
	int i = 0;
	int last = 0;
	
	while (i <= 29){
		int v;
		cout << "Por favor, insira um valor inteiro:";
		cin >> v;
		
		if(v > last){
			if (isPar(v)){
				push(Par, v);
				last = v;
				i++;
			} else {
				push(Impar, v);
				last = v;
				i++;
			}
		} else {
			cout << "Valor inválido!!!" << endl;
			cout << "!!!Atenção!!!" << endl;
		}
	}
	
	print(Par);
	print(Impar);
	return 0;
}