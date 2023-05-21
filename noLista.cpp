#include "noLista.hpp"
#include <iostream>


//Builders
noLista::noLista(int info) :
	info(info),
	prox(nullptr)
	
{

}


// Setters

void noLista::setInfo(int Ninfo) {
	info = Ninfo;
};


void noLista::setProx(noLista* Nprox) {
	this->prox = Nprox;
};

// Getters

int noLista::getInfo() {
	return info;
};

noLista *noLista::getProx() {
	return prox;
};