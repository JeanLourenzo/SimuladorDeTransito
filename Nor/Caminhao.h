#pragma once

class Caminhao : public Veiculos {

public:
	
	Caminhao(int x, int y) : Veiculos (x,y) {
		

		Movimentar(x, y);
		std::cout << " ";

	}
	
};
