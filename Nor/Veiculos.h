#pragma once

#include <Windows.h>
#include <random>

class Veiculos {

public:

	// Construtor Veiculos
	Veiculos(int x, int y) {

		this->x = x;
		this->y = y;

	}

	// Destrutor Veiculos
	~Veiculos(){
	}
	
	// Set's e Get's
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

	// Função para movimentar coordenadas.
	void Movimentar(int x, int y)
	{
		COORD xy = { x + 10,y + 10 };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);

	}

	// Colisor de veiculos com as barreiras laterais.
	void ColisorBarreira() {
		
		if (y == 29) {

			// Código para apagar a posição anterior e assim definir uma nova posição, fica mais bonito visualmente do que system("CLS").
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			Movimentar(x, 29);
			std::cout << " ";

			// Nova posição de Y, quando Y estiver valendo 29.
			y = 1;
		}

		if (y == 0) {

			// Indentico ao anterior.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			Movimentar(x, 0);
			std::cout << " ";

			// Nova posição de Y, quando Y estiver valendo 0.
			y = 28;
		}

		if (x == 0) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			Movimentar(0, y);
			std::cout << " ";

			x = 58;
		}

		if (x == 59) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
			Movimentar(59, y);
			std::cout << " ";

			x = 1;
		}

	}

	// Colisor de veiculos com fábricas.
	bool ColisorFabrica() {

		if (x >= 9 && x <= 13 || x >= 45 && x <= 49 || x >= 28 && x <= 32)
		{
			if (y >= 7 && y <= 9 || y >= 20 && y <= 22 || y >= 14 && y <= 16)
			{

				if (x == 9) {

					// Código para apagar a posição anterior, assim fica mais bonito visualmente do que system("CLS").
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(9, y);
					std::cout << " ";

					// Nova posição de X, quando X estiver valendo 9.
					x += -2;
				}

				if (x == 13) {

					// Identico ao anterior.
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(13, y);
					std::cout << " ";

					// Nova posição de X, quando X estiver valendo 13.
					x += 2;
				}

				if (y == 7) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(x, 7);
					std::cout << " ";

					y += -2;
				}

				if (y == 20) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(x, 20);
					std::cout << " ";

					y += -2;
				}

				if (y == 9) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(x, 9);
					std::cout << " ";

					y += 2;
				}

				if (y == 22) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(x, 22);
					std::cout << " ";

					y += 2;
				}

				if (x == 28) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(28, y);
					std::cout << " ";

					x += -2;
				}

				if (x == 32) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(32, y);
					std::cout << " ";

					x += +2;
				}

				if (y == 14) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(x, 14);
					std::cout << " ";

					y += -2;
				}

				if (y == 16) {

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					Movimentar(x, 16);
					std::cout << " ";

					y += +2;
				}
				return true;
			}

		}
	}

	// Criando a movimentação dos veiculos.
	void MovimentoUpdate() {


		std::random_device numero;
		std::mt19937 eng(numero());

		// Sortendo números de 1 até 3 para ambos X e Y.
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

			// Após sortear, setando para onde o veiculo irá andar.
			Movimentar(x,y);
			std::cout << " ";
		}

		// Código para apagar a posição anterior, fica mais bonito visualmente do que system("CLS").
		void ApagaAnterior(){
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		Movimentar(x,y);
		std::cout << " ";
		}

public:

	int x, y, i;

};
