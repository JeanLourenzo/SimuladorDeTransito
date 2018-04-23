#include <iostream>
#include <vector>
#include <random>
#include "Windows.h"
#include "Time.h"
#include <chrono>
#include <thread>
#include <conio.h>
#include "Veiculos.h"
#include "Moto.h"
#include "Carro.h"
#include "Caminhao.h"
#include "Mapa.h"



using namespace std;

// Função para movimentar coordenadas.
void Movimentar(int x, int y)
{
	COORD xy = { x ,y  };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void Tabela(vector<Moto>mx, vector<Carro>cx, vector<Caminhao>camx) {

	Movimentar(23, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "Motos: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << mx.size() << " ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	cout << "Carros: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << cx.size() << " ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	cout << "Caminhoes: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << camx.size() << " ";

}


int main() {

	// Usando a biblioteca Random.
	std::random_device numero;
	std::mt19937 eng(numero());

	// Sortendo numeros para o X e Y, variando de 3 até 57.
	std::uniform_int_distribution<> xinicial(3, 57);
	std::uniform_int_distribution<> yinicial(3, 27);

	vector<Carro> cx;
	vector<Caminhao> camx;
	vector<Moto> mx;
	Mapa m;	

	// Definindo velocidades dos Veiculos.
	int	CarroVelocidade = 0, CaminhaoVelocidade = 0, MotoVelocidade = 0;
	int i, j, infinito = 8;

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

		// Demonstrando quantos veiculos há no mapa.
		Tabela(mx, cx, camx);

		m.imprimeMapa();

		// Update da Movimentação das Motos através de sua velocidade.

		if (MotoVelocidade == 1) {

			for (i = 0; i < mx.size(); i++)
			{

				mx[i].ApagaAnterior();

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
				mx[i].MovimentoUpdate();
			}
			MotoVelocidade = 0;
		}
		else
		{
			for (i = 0; i < mx.size(); i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
				mx[i].Movimentar(mx[i].getX(), mx[i].getY());
				std::cout << " ";
			}
		}
		MotoVelocidade++;


		// Update da Movimentação dos Carros através de sua velocidade.

		if (CarroVelocidade == 2) {

			for (i = 0; i < cx.size(); i++) {

				cx[i].ApagaAnterior();

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 40);
				cx[i].MovimentoUpdate();
			}
			CarroVelocidade = 0;
		}
		else
		{
			for (i = 0; i < cx.size(); i++) 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 40);
				cx[i].Movimentar(cx[i].getX(),cx[i].getY());
				std::cout << " ";
			}
		}
		CarroVelocidade++;


		// Update da Movimentação dos Caminhões através de sua velocidade.

		if (CaminhaoVelocidade == 3) {

			for (i = 0; i < camx.size(); i++) {

				camx[i].ApagaAnterior();

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				camx[i].MovimentoUpdate();
			}
			CaminhaoVelocidade = 0;
		}
		else
		{
			for (i = 0; i < camx.size(); i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 70);
				camx[i].Movimentar(camx[i].getX(), camx[i].getY());
				std::cout << " ";
			}
		}
		CaminhaoVelocidade++;


		// Colisor Barreiras
		for (i = 0; i < cx.size(); i++) {
			cx[i].ColisorBarreira();
		}

		for (i = 0; i < camx.size(); i++) {
			camx[i].ColisorBarreira();
		}

		for (i = 0; i < mx.size(); i++) {
			mx[i].ColisorBarreira();
		}

		// Colisor Fabrica - Carro
		for (i = 0; i < cx.size(); i++)
		{
			if (cx[i].ColisorFabrica() == true)
			{
				cx.push_back(Carro(xinicial(eng), yinicial(eng)));
			}
		}

		// Colisor Fabrica - Moto
		for (i = 0; i < mx.size(); i++)
		{
			if (mx[i].ColisorFabrica() == true)
			{
				mx.push_back(Moto(xinicial(eng), yinicial(eng)));
			}
		}

		// Colisor Fabrica - Caminhão
		for (i = 0; i < camx.size(); i++)
		{
			if (camx[i].ColisorFabrica() == true)
			{
				camx.push_back(Caminhao(xinicial(eng), yinicial(eng)));
			}
		}

		// Colisor Carro - Moto

		for (i = 0; i < cx.size(); i++){
			for (j = 0; j < mx.size(); j++){

				if (cx[i].x == mx[j].x && cx[i].y == mx[j].y) {
					
					mx[j].ApagaAnterior();
					mx.erase(mx.begin() + j);
					
					break;
				}
			}
		}


		// Colisor Carro - Caminhao

		for (i = 0; i < cx.size(); i++) {
			for (j = 0; j < camx.size(); j++) {

				if (cx[i].x == camx[j].x && cx[i].y == camx[j].y) {
				
					cx[i].ApagaAnterior();
					cx.erase(cx.begin() + i);
					
					break;
				}
			}
		}

		// Colisor Moto - Caminhao

		for (i = 0; i < mx.size(); i++) {
			for (j = 0; j < camx.size(); j++) {

				if (mx[i].x == camx[j].x && mx[i].y == camx[j].y) {
					
					mx[i].ApagaAnterior();
					mx.erase(mx.begin() + i);
					
					break;
				}
			}
		}

		// Colisor Carro - Carro

		for (i = 0; i < cx.size(); i++) {
			for (j = 1; j < cx.size(); j++) {
				if (i != j) {
					if (cx[i].x == cx[j].x && cx[i].y == cx[j].y) {
					
						cx[i].ApagaAnterior();
						cx[j].ApagaAnterior();

						cx.erase(cx.begin() + i);
						if (i < j) {
							cx.erase(cx.begin() + (j - 1));

						}
						else {
							cx.erase(cx.begin() + j);
						}
						break;
					}
				}
			}
		}

		// Colisor Moto - Moto

		for (i = 0; i < mx.size(); i++) {
			for (j = 0; j < mx.size(); j++) {
				if (i != j) {
					if (mx[i].x == mx[j].x && mx[i].y == mx[j].y) {
					
						mx[i].ApagaAnterior();
						mx[j].ApagaAnterior();

						mx.erase(mx.begin() + i);
						if (i < j) {
							mx.erase(mx.begin() + (j - 1));

						}
						else {
							mx.erase(mx.begin() + j);
						}
						break;
					}
				}
			}
		}

		// Colisor Caminho - Caminhao

		for (i = 0; i < camx.size(); i++) {
			for (j = 0; j < camx.size(); j++) {
				if (i != j) {
					if (camx[i].x == camx[j].x && camx[i].y == camx[j].y) {
						
						camx[j].ApagaAnterior();
						camx[j].ApagaAnterior();

						camx.erase(camx.begin() + i);
						if (i < j) {
							camx.erase(camx.begin() + (j - 1));

						}
						else {
							camx.erase(camx.begin() + j);
						}
						break;
					}
				}
			}
		}
	
		// Deixar a mensagem "Pressione qualquer tecla para continuar.." na parte inferior do prompt.
		m.msgFinal();
		
		// Dando um delay para a atualização dos sprites dos Veiculos rodar mais suavemente.
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
	

		}

		return 0;

	}


