#include "lista.hpp"


// Builders

lista::lista() :
	prime(nullptr)

{

}

noLista* lista::getPrimeiro() {
	return prime;
}

void lista::insere(int novo) {


	if (prime == nullptr) {
		prime = new noLista(novo);

	}

	else {
		noLista* last = prime;

		while (last->getProx() != nullptr) {
			last = last->getProx();
		};
		
		
		last->setProx(new noLista(novo));
		last = last->getProx();
	}

};

int lista::imprime(int posicao) {
	
	noLista* ponteiro = prime;
	
	for (int i(0); i < posicao; i++) {

		ponteiro = ponteiro->getProx();
	};

	return ponteiro->getInfo();

};

bool lista::vazia() {
	if (prime == nullptr) return true;

	return false;
}

int lista::comprimento() {
	if (prime == nullptr) return 0;


	int contagem = 1;
	noLista* ponteiro = prime;

	while (ponteiro->prox != nullptr) {
		ponteiro = ponteiro->getProx();
		contagem++;
	}

	return contagem;
}

noLista* lista::busca(int alvo) {
	
	noLista* ponteiro = prime;
	int posicao = 0;

	while (ponteiro != nullptr) {
		if (ponteiro->getInfo() == alvo) {
			return ponteiro;
		};

		ponteiro = ponteiro->getProx();
		posicao++;

	};

	return nullptr;

}

noLista* lista::ultimo() {
	if (prime == nullptr) return nullptr;

	noLista* last = prime;

	while (last->getProx() != nullptr) {
		last = last->getProx();
	};

	return last;
};

void lista::retira(int alvo) {
	
	if (prime->getInfo() == alvo) {
	
		prime = prime->getProx();
		
		return;
	}

	noLista* ponteiro1 = prime->getProx();
	noLista* ponteiro2 = prime;

	while (ponteiro1 != nullptr && ponteiro1->getInfo() != alvo) {

		ponteiro2 = ponteiro1;
		ponteiro1 = ponteiro1->getProx();

	};

	if (ponteiro1 == nullptr) return;

	ponteiro2->setProx(ponteiro1->getProx());

	delete ponteiro1;

}

void lista::limpa() {

	if (prime == nullptr) return;

	if (prime->getProx() == nullptr) {
		delete prime;
		return;
	}

	noLista* ponteiro1 = prime;
	noLista* ponteiro2 = prime->getProx();

	while (ponteiro2->getProx() != nullptr) {

		delete ponteiro1;
		ponteiro1 = ponteiro2;
		ponteiro2 = ponteiro2->getProx();


	}

	delete ponteiro2;

	prime = nullptr;
}

void lista::insereUltimo(int valor) {

	if (ultimo() == nullptr) return;

	noLista* ultimo = this->ultimo();

	ultimo->setProx(new noLista(valor));

}

bool lista::igual(lista alvo) {
	noLista* lista1Ponteiro = prime;
	noLista* lista2Ponteiro = alvo.prime;

	if (lista1Ponteiro == nullptr && lista2Ponteiro == nullptr) return true;

	if (lista1Ponteiro == nullptr || lista2Ponteiro == nullptr) return false;

	while (lista1Ponteiro->getProx() != nullptr && lista2Ponteiro->getProx() != nullptr) {
		if (lista1Ponteiro->getInfo() != lista2Ponteiro->getInfo()) {
			return false;
		};

		lista1Ponteiro = lista1Ponteiro->getProx();
		lista2Ponteiro = lista2Ponteiro->getProx();
	}

	if (lista1Ponteiro->prox != nullptr or lista2Ponteiro->prox != nullptr) return false;

	return true;

}

void lista::retiraRecursivo(int alvo, noLista* atual) {

	if (prime->getInfo() == alvo) {
		
		noLista* ponteiro = prime;

		prime = prime->getProx();
	
		delete ponteiro;

		return;
	}

	if (atual == nullptr) atual = prime;

	if (atual->getProx() == nullptr) return;

	if (atual->getProx()->getInfo() == alvo) {
		
		noLista* ponteiro = atual->getProx();

		atual->setProx(ponteiro->getProx());

		delete ponteiro;
	
	}

	retiraRecursivo(alvo, atual->getProx());

}

bool lista::igualRecursivo(lista& alvo, noLista* ponteiro1, noLista* ponteiro2) {

	// Caso Inicial
	if (ponteiro1 == nullptr && ponteiro2 == nullptr) {
		ponteiro1 = prime;
		ponteiro2 = alvo.prime;
	
		if (ponteiro1 == nullptr || ponteiro2 == nullptr) {
			if (ponteiro1 == nullptr && ponteiro2 == nullptr) {
				return true;
			}
		
			return false;
		}
	}
	//


	if (ponteiro1->getInfo() != ponteiro2->getInfo()) return false;

	if (ponteiro1->getProx() == nullptr && ponteiro2->getProx() == nullptr) return true;

	if (ponteiro1->getProx() == nullptr || ponteiro2->getProx() == nullptr) return false;


	return igualRecursivo(alvo, ponteiro1->getProx(), ponteiro2->getProx());
}


std::ostream& operator<<(std::ostream& os, const lista list) {
	
	if (list.prime == nullptr) {
		os << "[]";

		return os;
	}


	noLista* ponteiro = list.prime;

	os << "[";

	if (ponteiro != nullptr) {
		os << ponteiro->getInfo();
		ponteiro = ponteiro->getProx();
	}

	while (ponteiro != nullptr) {
		os << ", " << ponteiro->getInfo();
		
		ponteiro = ponteiro->getProx();
	};

	os << "]";

	return os;

}


