#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
    cout << "Seja bem-vindo!" << endl;
    setlocale(LC_ALL, "");
	
	bool cadeiras[15][40];
	bool quebra = false;
	
	//Alguns espaços do array estavam aparecendo como true;
	for (int f = 0; f <= 14; f++){
		for (int p = 0; p <= 39; p++) {
			cadeiras[f][p] = false;
		}
	}
	
	do {
		cout << "Menu de opções:" << endl << endl;
		int seletor;
		
		cout << "0. - Finalizar" << endl;
		cout << "1. - Reservar poltrona" << endl;
		cout << "2. - Mapa de ocupação" << endl;
		cout << "3. - Faturamento" << endl;
		
		cout << "Selecione uma opção: ";
		cin >> seletor;
		
		// No mapa o "." foi alterado para "*" para facilitar a visibilidade
		
		if (seletor == 0){
			
			quebra = true;
			cout << endl << "Encerrando programa..." << endl;
			
		} else if (seletor == 1) 
		{
			
			int f;
			int p;
			
			cout << "Informe a fileira" << endl;
			cin >> f;
			
			cout << "Informe a poltrona" << endl;
			cin >> p;
			
			if(cadeiras[(f - 1)][(p - 1)] == false){
				cadeiras[(f - 1)][(p - 1)] = true;
				cout << "Poltrona reservada com sucesso" << endl;
			} else 
			{
				cout << "Poltrona indisponível" << endl;
			}
			
		} else if (seletor == 2) {
			
			for (int f = 0; f <= 14; f++){
				
				cout << "|| ";
				
				for (int p = 0; p <= 39; p++){
					if (cadeiras[f][p] == false){
						cout << "/" << "*";
					}
					else if (cadeiras[f][p] == true)
					{
						cout << "/" << "#";
					}
					else
					{
						cout << "/" << "error";
					}
				}
				
				cout << " ||" << endl;
			}
			
		} else if (seletor == 3) {
			
			//Contador de lugares ocupados:
			int qtde = 0;
			for (int f = 0; f <= 14; f++){
				for (int p = 0; p <= 39; p++){
					if (cadeiras[f][p] == true){
						qtde++;
					}
				}
			}
			
			cout << "Qtde de lugares ocupados: " << qtde << endl;
			
			//Verificador de faturamento:
			double faturamento;
			
			//Fileira 1 a 5:
			qtde = 0;
			for (int f = 0; f <= 4; f++){
				for (int p = 0; p <= 39; p++){
					if (cadeiras[f][p] == true){
						qtde++;
					}
				}
			}
			
			faturamento = (qtde * 50);
			
			//Fileira 6 a 10:
			qtde = 0;
			for (int f = 5; f <= 9; f++){
				for (int p = 0; p <= 39; p++){
					if (cadeiras[f][p] == true){
						qtde++;
					}
				}
			}
			
			faturamento = faturamento + (qtde * 30);
			
			//Fileira 11 a 15:
			qtde = 0;
			for (int f = 10; f <= 14; f++){
				for (int p = 0; p <= 39; p++){
					if (cadeiras[f][p] == true){
						qtde++;
					}
				}
			}
			
			faturamento = faturamento + (qtde * 15);
			
			cout << "Valor da bilheteria: R$ " << faturamento << endl;
			
		} else {
			cout << "Opção Inválida";
		}
		
		cout << endl;
	}
	while(quebra == false);
	
	
}