#include<iostream>
#include<cstdlib>
#include<ctime>

int* generar_arreglo(int& size, int* arr) {
	int value;
	for (int i = 0; i < size; ++i) {
		value = 1 + rand() % (51 - 1); /*limInf + rand() % ((limSup + 1) - limInf).*/
		arr[i] = value;
	}
	return arr;
}

void swap(int* v1, int* v2) {
	int aux = *v1;
	*v1 = *v2;
	*v2 = aux;
}

void imprimir_arreglo(int& size, int* arr) {
	std::cout << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << "[" << i << "]: " << arr[i] << std::endl;
	}
}

void ordenar(int& size, int* arr) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	imprimir_arreglo(size, arr);
}

int* erase(int pos, int& size, int* arr) {
	int* aux = new int[size - 1];
	for (int i = 0; i < pos; ++i) {
		aux[i] = arr[i];
	}
	for (int i = pos; i < size; ++i) {
		aux[i] = arr[i + 1];
	}
	size -= 1;
	return aux;
}

int* push_back(int v, int& size, int* arr) {
	int* aux = new int[size + 1];
	for (int i = 0; i < size; ++i) {
		aux[i] = arr[i];
	}
	aux[size] = v;
	size += 1;
	return aux;
}

int* eliminar_multiplo3(int& size, int* arr) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] % 3 == 0) {
			arr = erase(i--, size, arr);
		}
	}
	return arr;
}

void main() {

	srand(time(nullptr));
	int* size = new int;
	int* arr;
	int value;

	std::cout << "\nIngresar tamanio del arreglo: ";
	std::cin >> *size;

	arr = new int[*size];

	arr = generar_arreglo(*size, arr);

	imprimir_arreglo(*size, arr);

	arr = eliminar_multiplo3(*size, arr);

	imprimir_arreglo(*size, arr);

	ordenar(*size, arr);


	std::cout << "\nIngresar nuevo elemento: ";
	std::cin >> value;

	arr = push_back(value, *size, arr);
	ordenar(*size, arr);

	delete[] arr;
	delete size;

	std::cin.get();
}