#pragma once

class Carro : public Veiculos {

public:
	
	Carro(int x, int y) : Veiculos (x, y)  {

	
		Movimentar(x , y);
		std::cout << " ";

	}
	
};

