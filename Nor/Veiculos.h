#pragma once

#include <Windows.h>
#include "Carro.h"
#include "Moto.h"
#include "Caminhao.h"

class Veiculos {

public:
	int x, y;

	Veiculos(int x, int y) {

		this->x = x;
		this->y = y;

	}

	void Movimentar(int x, int y)
	{
		COORD xy = { x + 10,y + 10 };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);

	}



};
