#include <iostream>
using namespace std;


//Struct geradora da lista
struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
	struct Funcionario *prox;
};

Funcionario* init(){
	return NULL;
};

int isEmpty(Funcionario* func){
	return (func == NULL);
};


//INSERSOR
Funcionario* insert(Funcionario* func, int pront, string nome, double salario){
	Funcionario* novo = new Funcionario();
	novo->prontuario = pront;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = func;
	return novo;
};

//LISTADOR
void print(Funcionario* func){
	Funcionario* aux = func;
	double total = 0;
	
	cout << "-- Lista com todos os funcion�rios: --" << endl;
	
	while (aux != NULL)
	{
		total = total + aux->salario; 
		cout << "------------- Funcion�rio -------------" << endl;
		cout << "Prontuario: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Sal�rio: R$ " << aux->salario << endl;
		aux = aux->prox;
		
	} 
	
	cout << "" << endl;
	cout << "-----------------" << endl;
	cout << "Folha de pagamento final: R$ " << total << endl;
};

Funcionario* find (Funcionario* func, int pront){
	   Funcionario* aux = func;
	   
	while(aux != NULL && aux->prontuario != pront)
	{
		aux = aux->prox;
	}
	   
	   return aux;
};

void returnFind(Funcionario* func, int pront){
	Funcionario *procurado;
	string result = "";
	
	Funcionario *funcionario = func;
	int i = pront;
	
	procurado = find(funcionario, i);
	
	if (procurado != NULL)
	{
		result = "Existe algu�m com esse prontu�rio.";
	}else{
		result = "N�o existe ningu�m com esse prontu�rio.";
	}
	cout << result << endl;
}

Funcionario* remove(Funcionario* func, int i){
	Funcionario* ant = NULL;
	Funcionario* aux = func;
	
	while(aux != NULL && aux->prontuario != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL){
		return func;
	}
	if (ant == NULL){
		func = aux->prox;
	}
	else{
		ant->prox = aux->prox;
	}
	return func;
}

//C�DIGO PRINCIPAL
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Portuguese");
	Funcionario *minhaLista;
	minhaLista = init();
	int quebra = 0;
	int pront = 1;
	
	cout << "Seja muito bem-vindo!" << endl;
	cout << "GUAR� JR - CONTROLE DE FUNCION�RIOS" << endl;
	
	while(quebra != 1)
	{
		cout << "" << endl;
		int i;
		string nome;
		double salario;
		
		cout << "" << endl;
		
		cout << "------/ MENU DE OP��ES /------" << endl;
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
		
		cout << "Selecione uma op��o" << endl;
		cout << "Op��o N�mero: ";
		cin >> i;
		cout << "" << endl;
		
		switch(i)
		{
		case 0:
			quebra = 1;
			break;
		case 1:
			
			cout << "-- Adicionando funcion�rio --" << endl;
			
			cout << "" << endl;
			cout << "Insira o nome: ";
			cin >> nome;
			
			cout << "Insira o salario: R$ ";
			cin >> salario;
			
			minhaLista = insert(minhaLista, pront, nome, salario);
			
			cout << "Funcion�rio " << nome << " cadastrado com sucesso." << endl;
			cout << "O prontu�rio �: " << pront << endl;
			pront++;
			break;
		case 2:
			
			cout << "Insira o prontu�rio do funcion�rio que deseja excluir: ";
			cin >> i;
			
			minhaLista = remove(minhaLista, i);
			break;
		case 3:
			
			cout << "Insira o prontu�rio para verificar se existe: ";
			cin >> i;
			
			returnFind(minhaLista, i);
			break;
		case 4: 
			print(minhaLista);
			break;
		default:
			cout << "Valor digitado incorreto." << endl;
			break;
		}
	}
	
	cout << "Muito obrigado por usar o nosso sistema! At� mais.";
}