#pragma once

#include <Windows.h>
#include "Veiculos.h"


class Carro {

public:


	Carro(int x, int y)  {

	
		Movimentar(x , y);
		std::cout << " ";

		this->x = x;
		this->y = y;

	}

	void setX(int ax) {
		x = ax;
	}

	void setY(int ay) {
		y = ay;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;

	}

	void Movimentar(int x, int y)
	{
		COORD xy = { x + 10,y + 10 };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);

	}

	int x, y;



	




};


/*
#pragma once

#include "SFML\Graphics.hpp"
#include "Todos.h"
#include <time.h>
#include <iostream>

#include "Barreira.h"
#include "Fabrica.h"
#include "Caminhao.h"
#include <random>





class Carro : public Todos {

public:

sf::RectangleShape Car;
float base, esquerda, direita, topo;

// Setando posição inicial do Carro.

Carro(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Color cor) {

Car.setPosition(posicao);
Car.setSize(tamanho);
Car.setFillColor(cor);
}



// Função para dar movimento.



// Função para atualizar posição atual.

void Update() {

base = Car.getPosition().y  + Car.getSize().y;
esquerda = Car.getPosition().x;
direita = Car.getPosition().x + Car.getSize().x;
topo = Car.getPosition().y;
}

bool Colisor(Fabrica p)
{

return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

}

bool Colisor(Carro p)
{

return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

}

bool Colisor(Caminhao p)
{

return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

}

bool Colisor(Barreira p)
{
int a, b, c, d;
if (direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo) {

a = Car.getPosition().y + Car.getSize().y;
b = Car.getPosition().x;
c = Car.getPosition().x + Car.getSize().x;
d = Car.getPosition().y;

if (b <= 0) {
Car.setPosition(59, d);
}
if (b >= 60) {
Car.setPosition(1, d);
}
if (d <= 0) {
Car.setPosition(b,29);
}
if (d >= 30) {
Car.setPosition(b, 1);
}

}
return true;
}





};



*/
