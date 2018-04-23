#pragma once

class Moto : public Veiculos  {

public:

	Moto(int x, int y) : Veiculos (x,y) {


		Movimentar(x, y);
		std::cout << " ";

	}

};