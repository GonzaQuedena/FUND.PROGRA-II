#pragma once
#include<string>

class CPersona {

private:
	std::string nombre;
	float peso, altura;
	int edad;
	long DNI;
	std::string sexo;

public:
	/*Constructores*/
	CPersona() {
		nombre = "";
		peso = altura = 0.0f;
		edad = 0;
		DNI = 0;
		sexo = "H";
	}
	CPersona(std::string nombre, int edad, std::string sexo) {
		this->nombre = nombre;
		this->edad = edad;
		this->sexo = sexo;
		peso = altura = 0.0f;
		if (generar_DNI()) {
			std::cout << "\nDNI generado";
		}
	}
	CPersona(std::string nombre, int edad, float peso, float altura, std::string sexo) {
		this->nombre = nombre;
		this->edad = edad;
		this->peso = peso;
		this->altura = altura;
		this->sexo = sexo;
		if (generar_DNI()) {
			std::cout << "\nDNI generado";
		}
	}
	/*métodos de clase*/
	int IMC() { /*.-1 si es menor a 20 | 0 si está entre 20 y 25 | 1 si es mayor a 25.*/
		float imc = (peso) / (pow(altura, 2));

		if (imc < 20) {
			return -1;
		}
		if (imc >= 20 && imc <= 25) {
			return 0;
		}
		if (imc > 25) {
			return 1;
		}
	}
	bool tiene_mayoria_edad() {
		if (edad >= 18) {
			return true;
		}
		return false;
	}
	bool saber_sexo(std::string s) {
		if (sexo == s) {
			return true;
		}
		sexo = 'H';
		return false;
	}
	std::string to_String() {

		std::string info = "\nNombre: " + nombre;
		info += "\nEdad: " + std::to_string(edad);
		info += "\nPeso: " + std::to_string(peso);
		info += "\nAltura: " + std::to_string(altura);
		info += "\nDNI: " + std::to_string(DNI);
		info += "\nSexo: " + sexo;

		return info;
	}
	bool generar_DNI() {
		srand(time(nullptr));
		DNI = 666888444 + rand() % (777999555 - 666888444);
		return true;
	}
	/*Métodos de acceso*/
	/*Get*/
	std::string getNombre() {
		return nombre;
	}
	int getEdad() {
		return edad;
	}
	float getPeso() {
		return peso;
	}
	float getAltura() {
		return altura;
	}
	std::string getSexo() {
		return sexo;
	}
	/*Set*/
	void setNombre(std::string v) {
		nombre = v;
	}
	void setEdad(int v) {
		edad = v;
	}
	void setPeso(float v) {
		peso = v;
	}
	void setAltura(float v) {
		altura = v;
	}
	void setSexo(char v) {
		sexo = v;
	}
};
