#include<string>
#include<iostream>

class Persona {

private:
	/*atributos: caracteristicas del objeto/entidad.*/
	std::string nombre;
	std::string apellido;
	int edad;

public:
	/*Sobrecarga de constructor: Creas 2 o más constructores en una clase.*/
	/*Contructor de clase: Inicializamos los atributos.*/
	Persona(std::string _nombre, std::string _apellido, int _edad) {
		nombre = _nombre;
		apellido = _apellido;
		edad = _edad;
	}
	Persona(std::string _nombre, std::string _apellido) {
		nombre = _nombre;
		apellido = _apellido;
		edad = 20;
	}
	/*Destructor de clase: Liberar memoria*/
	~Persona() {
	}

	/*métodos: acciones del objeto/entidad.*/
	void saludar() {
		std::cout << "Hola";
	}
	void despedirse() {
		std::cout << "Adios";
	}
	void imprimir_datos() {
		std::cout << "\nNombre: " << getNombre();
		std::cout << "\nApellido: " << getApellido();
		std::cout << "\nEdad: " << getEdad() << std::endl;
	}

	/*métodos de acceso.*/
	/*Getters: Obtenemos un dato.*/
	std::string getNombre() {
		return nombre;
	}
	std::string getApellido() {
		return apellido;
	}
	int getEdad() {
		return edad;
	}
	/*Setters: Cambiamos un dato.*/
	void setNombre(std::string v) {
		nombre = v;
	}
	void setApellido(std::string v) {
		apellido = v;
	}
	void setEdad(int v) {
		edad = v;
	}
};

void main() {

	Persona* obj_persona1 = new Persona("Gonzalo", "Quedena");

	obj_persona1->saludar();
	obj_persona1->imprimir_datos();
	obj_persona1->despedirse();

	std::cout << "\n-----------\n";

	Persona* obj_persona2 = new Persona("Lucia", "Velez", 18);

	obj_persona2->saludar();
	obj_persona2->imprimir_datos();
	obj_persona2->despedirse();

	std::cout << "\n-----------\n";

	Persona* obj_persona3 = new Persona("Juan", "Caro", 50);

	obj_persona3->saludar();
	obj_persona3->imprimir_datos();
	obj_persona3->despedirse();

	std::cin.get();
}
