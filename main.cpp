#include "lista.hpp"

#include <iostream>

void interface() {

	std::cout << "Ola, oque gostaria de testar?" << std::endl;
	std::cout << "1: void insere(int v):" << std::endl;
	std::cout << "2: void retira(int v):" << std::endl;
	std::cout << "3: void limpa():" << std::endl;
	std::cout << "4: void insereUltimo(int valor):" << std::endl;
	std::cout << "5: bool igual(list lista):" << std::endl;
	std::cout << "6: retiraRecursivo(int alvo):" << std::endl;
	std::cout << "7: igualRecursivo(list alvo):" << std::endl;
	std::cout << "8: mostrar a lista:" << std::endl;
	std::cout << "9: Sair:" << std::endl;

}

void testeInsere(lista& lista1){

	int quantidade = 0;
	int numero = 0;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Quantos numeros voce gostaria de inserir? ";
	std::cin >> quantidade;

	for (int i(0); i < quantidade; i++) {
		std::cout << "qual numero voce gostaria de inserir? ";
		std::cin >> numero;
		std::cout << std::endl;

		lista1.insere(numero);
	}



}

void testeRetira(lista& lista1) {
	
	int quantidade = 0;
	int numero = 0;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Quantos numeros voce gostaria de retirar? ";
	std::cin >> quantidade;

	for (int i(0); i < quantidade; i++) {
		std::cout << "qual numero voce gostaria de retirar? ";
		std::cin >> numero;
		std::cout << std::endl;

		lista1.retira(numero);
	}
}

void testeLimpa(lista& lista1) {

	char certeza = 'N';

	std::cout << std::endl << std::endl << "tem certeza que quer deletar a lista? [S/N]";
	std::cin >> certeza;

	if (certeza == 'S') {
		lista1.limpa();
	}
}

void testeInsereUltimo(lista& lista1) {

	int quantidade = 0;
	int numero = 0;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Quantos numeros voce gostaria de inserir? ";
	std::cin >> quantidade;

	for (int i(0); i < quantidade; i++) {
		std::cout << "qual numero voce gostaria de inserir? ";
		std::cin >> numero;
		std::cout << std::endl;

		lista1.insereUltimo(numero);
	}



}

void testeIgual(lista& lista1, lista& lista2) {
	if (lista1.igual(lista2)) {
		std::cout << std::endl << "e Igual" << std::endl << std::endl;
	}

	else {
		std::cout << std::endl << "nao e Igual" << std::endl << std::endl;
	}
}

void testeRetiraRecursivo(lista& lista1) {

	int quantidade = 0;
	int numero = 0;

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Quantos numeros voce gostaria de retirar? ";
	std::cin >> quantidade;

	for (int i(0); i < quantidade; i++) {
		std::cout << "qual numero voce gostaria de retirar? ";
		std::cin >> numero;
		std::cout << std::endl;

		lista1.retiraRecursivo(numero);
	}
}

void testeIgualRecursivo(lista& lista1, lista& lista2) {
	if (lista1.igualRecursivo(lista2)) {
		std::cout << std::endl << "e Igual" << std::endl << std::endl;
	}

	else {
		std::cout << std::endl << "nao e Igual" << std::endl << std::endl;
	}
}

int main() {

	int opcao = 0;

	int escolha2 = 0;


	lista lista1;

	lista lista2;

	while (opcao != 9) {

		interface();

		std::cin >> opcao;


		switch (opcao){
			
			case 1:
				testeInsere(lista1);
				
				break;

			case 2:
				testeRetira(lista1);

				break;

			case 3:
				testeLimpa(lista1);

				break;

			case 4:
				testeInsereUltimo(lista1);

				break;
			case 5:

				std::cout << std::endl << "Para testar e necessario duas listas. Escolha oque deseja fazer:" << std::endl;
				std::cout << "1: Adicionar numeros manualmente" << std::endl;
				std::cout << "2: criar uma copia da primeira lista" << std::endl;
				std::cin >> escolha2;

				if (escolha2 == 1) {

					std::cout << "Sua Lista atual e:" << std::endl << lista1 << std::endl;

					testeInsere(lista2);
					testeIgual(lista1, lista2);
				}

				if (escolha2 == 2) {

					noLista* ponteiro = lista1.getPrimeiro();

					while (ponteiro != nullptr && ponteiro->getProx() != nullptr) {
						lista2.insere(ponteiro->getInfo());
						ponteiro = ponteiro->getProx();
					}
					lista2.insere(ponteiro->getInfo());
					testeIgual(lista1, lista2);

				}

				lista2.limpa();

				break;
			
			case 6:
				testeRetiraRecursivo(lista1);

				break;

			case 7:

				std::cout << std::endl << "Para testar e necessario duas listas. Escolha oque deseja fazer:" << std::endl;
				std::cout << "1: Adicionar numeros manualmente" << std::endl;
				std::cout << "2: criar uma copia da primeira lista" << std::endl;
				std::cin >> escolha2;

				if (escolha2 == 1) {

					std::cout << "Sua Lista atual e:" << std::endl << lista1 << std::endl;

					testeInsere(lista2);
					testeIgualRecursivo(lista1, lista2);
				}

				if (escolha2 == 2) {

					noLista* ponteiro = lista1.getPrimeiro();

					while (ponteiro != nullptr && ponteiro->getProx() != nullptr) {
						lista2.insere(ponteiro->getInfo());
						ponteiro = ponteiro->getProx();
					}
					lista2.insere(ponteiro->getInfo());
					testeIgualRecursivo(lista1, lista2);
				}

				lista2.limpa();

				break;

			case 8:
				std::cout << std::endl << std::endl << lista1 << std::endl << std::endl;

		}

	}

	return 0;
}


