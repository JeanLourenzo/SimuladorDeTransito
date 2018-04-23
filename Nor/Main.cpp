#include <iostream>
#include <vector>
#include <random>
#include "Windows.h"

#include "Veiculos.h"
#include "Moto.h"
#include "Carro.h"
#include "Caminhao.h"
#include "Mapa.h"



using namespace std;


int main() {

	// Usando a biblioteca random, por que o rand() é uma porcaria.
	std::random_device numero;
	std::mt19937 eng(numero());

	std::uniform_int_distribution<> xinicial(3, 57);
	std::uniform_int_distribution<> yinicial(3, 27);

	std::uniform_int_distribution<> xr(1, 3);
	std::uniform_int_distribution<> yr(1, 3);

	vector<Carro> cx;
	vector<Caminhao> camx;
	vector<Moto> mx;
	Mapa m;


	int i, infinito = 8;

	// Criando 10 Carros, 10 Motos e 10 Caminhões.
	for (i = 0; i < 10; i++) {
		cx.push_back(Carro(xinicial(eng), yinicial(eng)));
	}

	for (i = 0; i < 10; i++) {
		camx.push_back(Caminhao(xinicial(eng), yinicial(eng)));
	}

	for (i = 0; i < 10; i++) {
		mx.push_back(Moto(xinicial(eng), yinicial(eng)));
	}

	while (infinito == 8) {

		 m.imprimeMapa();


		// Update da Movimentação dos Carros.
		 for (i = 0; i < cx.size(); i++) {
			 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 40);
			 cx[i].MovimentoUpdate();
		 }

		// Update da Movimentação dos Caminhões.
		for (i = 0; i < camx.size(); i++) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
			camx[i].MovimentoUpdate();
		}

		// Update da Movimentação das Motos.
		for (i = 0; i < mx.size(); i++) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
			mx[i].MovimentoUpdate();
		}

		// Colisor Barreiras
		for (i = 0; i < cx.size(); i++) {
			cx[i].colisorBarreira();
		}

		for (i = 0; i < camx.size(); i++) {
			camx[i].colisorBarreira();
		}

		for (i = 0; i < mx.size(); i++) {
			mx[i].colisorBarreira();
		}

		// Colisor Fabrica - Carro
		for (i = 0; i < cx.size(); i++)
		{
			if (cx[i].colisorFabrica() == true)
			{
				cx.push_back(Carro(xinicial(eng), yinicial(eng)));
			}
		}

		// Colisor Fabrica - Moto
		for (i = 0; i < mx.size(); i++)
		{
			if (mx[i].colisorFabrica() == true)
			{
				mx.push_back(Moto(xinicial(eng), yinicial(eng)));
			}
		}

		// Colisor Fabrica - Caminhão
		for (i = 0; i < camx.size(); i++)
		{
			if (camx[i].colisorFabrica() == true)
			{
				camx.push_back(Caminhao(xinicial(eng), yinicial(eng)));
			}
		}
	
		m.msgFinal();
		
		system("Pause");
		system("CLS");

		}

		return 0;

	}


