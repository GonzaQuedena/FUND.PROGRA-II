#include<iostream>
#include<cmath>

class Cubo {

private:
	int lado;

public:
	/*Constructor de clase*/
	Cubo(int _lado) {
		lado = _lado;
	}
	/*Método de clase*/
	int calcular_volumen() {
		return pow(lado, 3);
	}
	/*Método de acceso*/
	/*Getters.*/
	int getLado() {
		return lado;
	}
};

void main() {

	Cubo* obj_cubo1 = new Cubo(5);
	std::cout << "Volumen del cubo de " << obj_cubo1->getLado() <<
		" lados es de: " << obj_cubo1->calcular_volumen();

	std::cout << "\n---------\n";

	Cubo* obj_cubo2 = new Cubo(8);
	std::cout << "Volumen del cubo de " << obj_cubo2->getLado() <<
		" lados es de: " << obj_cubo2->calcular_volumen();

	std::cout << "\n---------\n";

	Cubo* obj_cubo3 = new Cubo(12);
	std::cout << "Volumen del cubo de " << obj_cubo3->getLado() <<
		" lados es de: " << obj_cubo3->calcular_volumen();

	std::cin.get();
}