#include<iostream>
#include"CPersona.hpp"

struct Util {

	std::string nombre = "";
	float peso = 0.0f, altura = 0.0f;
	int edad = 0;
	std::string sexo = " ";

}util;

void main() {

	std::cout << "\nIngresar nombre: ";
	std::getline(std::cin, util.nombre); std::cin.ignore();

	std::cout << "Ingresar edad: ";
	std::cin >> util.edad;

	std::cout << "Ingresar sexo: ";
	std::cin >> util.sexo;

	std::cout << "Ingresar peso: ";
	std::cin >> util.peso;

	std::cout << "Ingresar altura: ";
	std::cin >> util.altura;

	CPersona* obj_persona1 = new CPersona(util.nombre, util.edad, util.peso, util.altura, util.sexo);
	std::cout << obj_persona1->to_String();

	if (obj_persona1->IMC() == -1) {
		std::cout << "\nLa persona está por debajo de su peso ideal";
	}
	if (obj_persona1->IMC() == 0) {
		std::cout << "\nLa persona esta en su peso ideal";
	}
	if (obj_persona1->IMC() == 1) {
		std::cout << "\nLa persona esta en sobrepeso";
	}
	if (obj_persona1->tiene_mayoria_edad()) {
		std::cout << "\nTiene mayoria de edad";
	}
	else {
		std::cout << "\nNo tiene mayoria de edad";
	}

	std::cout << "\n-----------------------------\n";

	CPersona* obj_persona2 = new CPersona(util.nombre, util.edad, util.sexo);
	std::cout << obj_persona2->to_String();

	if (obj_persona2->IMC() == -1) {
		std::cout << "\nLa persona está por debajo de su peso ideal";
	}
	if (obj_persona2->IMC() == 0) {
		std::cout << "\nLa persona esta en su peso ideal";
	}
	if (obj_persona2->IMC() == 1) {
		std::cout << "\nLa persona esta en sobrepeso";
	}
	if (obj_persona2->tiene_mayoria_edad()) {
		std::cout << "\nTiene mayoria de edad";
	}
	else {
		std::cout << "\nNo tiene mayoria de edad";
	}

	std::cout << "\n-----------------------------\n";

	CPersona* obj_persona3 = new CPersona;
	std::cout << obj_persona3->to_String();

	if (obj_persona3->IMC() == -1) {
		std::cout << "\nLa persona está por debajo de su peso ideal";
	}
	if (obj_persona3->IMC() == 0) {
		std::cout << "\nLa persona esta en su peso ideal";
	}
	if (obj_persona3->IMC() == 1) {
		std::cout << "\nLa persona esta en sobrepeso";
	}
	if (obj_persona3->tiene_mayoria_edad()) {
		std::cout << "\nTiene mayoria de edad";
	}
	else {
		std::cout << "\nNo tiene mayoria de edad";
	}

	std::cin.get();
}