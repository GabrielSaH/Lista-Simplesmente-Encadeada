#pragma once



class noLista {
public:
	int info;
	noLista *prox;


public:
	// Builders
	noLista(int info);
	
	// Setters
	
	void setInfo(int Ninfo);
	void setProx(noLista* Nprox);


	// Getters
	int getInfo();
	noLista *getProx();


};