#include<iostream>
#include<cstdlib>
#include<ctime>

int* generar_arreglo(int& size, int* arr) {
	int value;
	for (int i = 0; i < size; ++i) {
		value = 1 + rand() % (11 - 1); /*limInf + rand() % ((limSup + 1) - limInf).*/
		arr[i] = value;
	}
	return arr;
}

void encontrar_mayor(int& size, int* arr) {
	int major = -1, pos_major;
	for (int i = 0; i < size; ++i) {
		if (arr[i] > major) {
			major = arr[i];
		}
	}
	for (int i = 0; i < size; ++i) {
		if (arr[i] == major) {
			pos_major = i;
		}
	}
	std::cout << "\nNumero mayor es: " << major;
	std::cout << "\nPosicion del nro es: " << pos_major;
}

void encontrar_menor(int& size, int* arr) {
	int menor = 20, pos_menor;
	for (int i = 0; i < size; ++i) {
		if (arr[i] < menor) {
			menor = arr[i];
		}
	}
	for (int i = 0; i < size; ++i) {
		if (arr[i] == menor) {
			pos_menor = i;
		}
	}
	std::cout << "\nNumero menor es: " << menor;
	std::cout << "\nPosicion del nro es: " << pos_menor;
}

void swap(int* v1, int* v2) {
	int aux = *v1;
	*v1 = *v2;
	*v2 = aux;
}

void imprimir_arreglo(int& size, int* arr) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}

void ordenar(int& size, int* arr) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}

	imprimir_arreglo(size, arr);
}

void main() {

	srand(time(nullptr));
	int* size = new int;
	*size = 10;
	int* arr = new int[*size];

	arr = generar_arreglo(*size, arr);

	imprimir_arreglo(*size, arr);

	std::cout << "\n-----" << std::endl;

	encontrar_mayor(*size, arr);

	std::cout << "\n-----" << std::endl;

	encontrar_menor(*size, arr);

	std::cout << "\n-----" << std::endl;

	ordenar(*size, arr);

	delete[] arr;
	delete size;

	std::cin.get();
}