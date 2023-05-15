#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
	int qtde;
	int elementos[MAX];
	string nome;
};

Pilha* init(string n){
	Pilha *p = new Pilha();
	p->qtde = 0;
	p->nome = n;
	return p;
}

int isEmpty(Pilha *p){
	return (p->qtde == 0);
}

int count (Pilha *p){
	return p->qtde;
}

int push(Pilha *p, int v){
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar){
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

int pop(Pilha *p){
	int v;
	int podeDesempilhar = (! isEmpty(p));
	if (podeDesempilhar){
		v = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else
	{
		v = -31;
	}
	return v;
}

int isPar(int v){
	return ((v % 2) == 0);
}

void print(Pilha *p){
	cout << "Qtde de elementos na lista " << p->nome << ": " << count(p) << endl;
	cout << "------------------------" << endl;
	
	for(int i = (count(p) -1); 0 <= i; --i){
		cout << p->elementos[i] << ", ";
	}
	cout << endl;
	cout << "------------------------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *Par = new Pilha();
	Par = init("Par");
	
	Pilha *Impar = new Pilha();
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