#pragma once

#include <Windows.h>
#include <random>

class Veiculos {

public:

	Veiculos(int x, int y) {

		this->x = x;
		this->y = y;

	}
	~Veiculos(){
	}
	
	void setX(int ax) {
		x = ax;
	}

	void setY(int y) {
		this-> y = y;
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

	void colisorBarreira() {


		if (y == 29) {
			y = 2;
		}

		if (y == 1) {
			y = 28;
		}

		if (x == 1) {
			x = 58;
		}

		if (x == 59) {
			x = 2;
		}

	}

	bool colisorFabrica() {

		if (x >= 9 && x <= 13 || x >= 45 && x <= 49 || x >= 28 && x <= 32)
		{
			if (y >= 7 && y <= 9 || y >= 20 && y <= 22 || y >= 14 && y <= 16)
			{

				if (x == 9) {
					x += -2;
				}

				if (x == 13) {
					x += 2;
				}

				if (y == 7 || y == 20) {
					y += -2;
				}

				if (y == 9 || y == 22) {
					y += 2;
				}

				if (x == 28) {
					x += -2;
				}

				if (x == 32) {
					x += +2;
				}

				if (y == 14) {
					y += -2;
				}

				if (y == 16) {
					y += +2;
				}
				return true;
			}

		}
	}

	void MovimentoUpdate() {

		std::random_device numero;
		std::mt19937 eng(numero());

		std::uniform_int_distribution<> xr(1, 3);
		std::uniform_int_distribution<> yr(1, 3);
		

			if (xr(eng) == 1) {
				x += - 1;
			}

			if (xr(eng) == 3) {
				x+= 1;
			}

			if (yr(eng) == 1) {
				y+= - 1;
			}

			if (yr(eng) == 3) {
				y+= 1;
			}

			Movimentar(x,y);
			std::cout << " ";
		}

	

public:

	int x, y, i;

};
