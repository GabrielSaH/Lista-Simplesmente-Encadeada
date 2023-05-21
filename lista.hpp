#pragma once

#include "noLista.hpp"

#include <iostream>

class lista {
private:
	noLista* prime;


public:
	// Builders
	lista();
	
	noLista* getPrimeiro();

	void insere(int novo);

	int imprime(int posicao);
	
	bool vazia();

	int comprimento();

	noLista* busca(int alvo);
	
	noLista* ultimo();

	void retira(int v);
	
	void limpa();

	void insereUltimo(int valor);

	bool igual(lista alvo);

	void retiraRecursivo(int alvo, noLista* atual = nullptr);

	bool igualRecursivo(lista& alvo, noLista* ponteiro1 = nullptr, noLista* ponteiro2 = nullptr);

	friend std::ostream& operator<<(std::ostream& os, const lista list);

	
	
	/*
	insereFim:
	igual(list lista2):


	*/


	/*
		void insere(int novo);

	int imprime(int posicao);
	
	bool vazia();

	int comprimento();

	noLista* busca(int alvo);
	
	noLista* ultimo();
	*/
};

