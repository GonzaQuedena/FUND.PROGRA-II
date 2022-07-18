#include<iostream>

int* push_back(int v, int* size, int* arr) {
	int* aux = new int[*size + 1];
	for (int i = 0; i < *size; ++i) {
		aux[i] = arr[i];
	}
	aux[*size] = v;
	*size += 1;
	return aux;
}
int* push_front(int v, int* size, int* arr) {
	int* aux = new int[*size + 1];
	for (int i = 0; i < *size; ++i) {
		aux[i + 1] = arr[i];
	}
	aux[0] = v;
	*size += 1;
	return aux;
}
int* insert(int v, int pos, int* size, int* arr) {

	if (pos == 0) {
		return push_front(v, size, arr);
	}

	int* aux = new int[*size + 1];
	for (int i = 0; i < pos; ++i) {
		aux[i] = arr[i];
	}
	for (int i = pos; i < *size; ++i) {
		aux[i + 1] = arr[i];
	}
	aux[pos] = v;
	*size += 1;
	return aux;
}

int* pop_back(int* size, int* arr) {
	int* aux = new int[*size - 1];
	for (int i = 0; i < *size - 1; ++i) {
		aux[i] = arr[i];
	}
	*size -= 1;
	if (*size == 0) {
		return nullptr;
	}
	return aux;
}

int* pop_front(int* size, int* arr) {
	int* aux = new int[*size - 1];
	for (int i = 0; i < *size; ++i) {
		aux[i] = arr[i + 1];
	}
	*size -= 1;
	if (*size == 0) {
		return nullptr;
	}
	return aux;
}

int* erase(int pos, int* size, int* arr) {
	int* aux = new int[*size - 1];
	for (int i = 0; i < pos; ++i) {
		aux[i] = arr[i];
	}
	for (int i = pos; i < *size; ++i) {
		aux[i] = arr[i + 1];
	}
	*size -= 1;
	if (*size == 0) {
		return nullptr;
	}
	return aux;
}

int* sort_arr(int* size, int* arr) {
	int aux = 0;
	for (int i = 0; i < *size; ++i) {
		for (int j = 0; j < *size - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
	return arr;
}

bool empty(int* arr) {
	if (arr == nullptr) {
		return true;
	}
	return false;
}

void main() {
	/*Inicializando arreglo en nullptr*/
	int* arr = nullptr;
	/*Asignando memoria a la variale size*/
	int* size = new int;
	/*Dándole valor a ese slot de memoria reservada*/
	*size = 0;

	/*Agregando datos al arreglo en última posición*/
	arr = push_back(4, size, arr);
	arr = push_back(2, size, arr);
	/*Agregando datos al arreglo en primera posición*/
	arr = push_front(1, size, arr);
	arr = push_front(5, size, arr);
	arr = push_front(6, size, arr);
	/*Agregando datos al arreglo en una posición específica*/
	arr = insert(-2, 4, size, arr);

	/*Ordenando datos del arreglo*/
	arr = sort_arr(size, arr);

	/*Eliminando datos del arreglo en última posición*/
	//arr = pop_back(size, arr);
	//arr = pop_back(size, arr);
	/*Eliminando datos del arreglo en primera posición*/
	//arr = pop_front(size, arr);
	//arr = pop_front(size, arr);
	/*Eliminando datos del arreglo en una posición específica*/
	//arr = erase(4, size, arr);

	if (empty(arr)) {
		std::cout << "\nArreglo vacio";
		return;
	}

	for (int i = 0; i < *size; ++i) {
		std::cout << arr[i] << " ";
	}


	std::cin.get();
}