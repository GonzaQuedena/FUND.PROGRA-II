#include<iostream>
#include<cstdlib>
#include<ctime>

/*
push_back(): agregar dato al final del arreglo.
push_front(): agregar dato al inicio del arreglo.
insert(): agregar dato en una pos. específica del arreglo.
pop_back(): eliminar dato al final del arreglo.
pop_front(): eliminar dato al inicio del arreglo.
erase(): eliminar dato en una pos. específica del arreglo.
sort(): ordenamiento.
*/

int* push_back(int v, int& size, int* arr) {
	int* aux = new int[size + 1];
	for (int i = 0; i < size; ++i) {
		aux[i] = arr[i];
	}
	aux[size] = v;

	size += 1;
	if (arr != nullptr)delete arr;

	arr = aux;
	return arr;
}

int* push_front(int v, int& size, int* arr) {
	int* aux = new int[size + 1];
	for (int i = 0; i < size; ++i) {
		aux[i + 1] = arr[i];
	}
	aux[0] = v;

	size += 1;
	if (arr != nullptr)delete arr;

	arr = aux;
	return arr;
}

int* insert(int v, int pos, int& size, int* arr) {

	if (pos == 0) {
		return push_front(v, size, arr);
	}

	int* aux = new int[size + 1];
	for (int i = 0; i < pos; ++i) {
		aux[i] = arr[i];
	}
	for (int i = pos; i < size; ++i) {
		aux[i + 1] = arr[i];
	}
	aux[pos] = v;

	size += 1;
	if (arr != nullptr)delete arr;

	arr = aux;
	return arr;
}

int* pop_back(int& size, int* arr) {
	int* aux = new int[size - 1];
	for (int i = 0; i < size - 1; ++i) {
		aux[i] = arr[i];
	}
	size -= 1;
	if (arr != nullptr)delete arr;

	if (size == 0) {
		arr = nullptr;
	}
	arr = aux;
	return arr;
}

int* pop_front(int& size, int* arr) {
	int* aux = new int[size - 1];
	for (int i = 0; i < size; ++i) {
		aux[i] = arr[i + 1];
	}
	size -= 1;
	if (arr != nullptr)delete arr;

	if (size == 0) {
		arr = nullptr;
		return arr;
	}
	arr = aux;
	return arr;
}

int* erase(int pos, int& size, int* arr) {

	if (pos == 0) {
		return pop_front(size, arr);
	}
	if (pos == size - 1) {
		return pop_back(size, arr);
	}

	int* aux = new int[size - 1];
	for (int i = 0; i < pos; ++i) {
		aux[i] = arr[i];
	}
	for (int i = pos; i < size; ++i) {
		aux[i] = arr[i + 1];
	}
	size -= 1;
	if (arr != nullptr)delete arr;

	if (size == 0) {
		arr = nullptr;
		return arr;
	}
	arr = aux;
	return arr;
}

void swap(int* n1, int* n2) {
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void sort(int& size, int*& arr) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void print_array(int& size, int*& arr) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
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
	/*Asignando a la variale size=0*/
	int size = 0;

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
	sort(size, arr);

	/*Eliminando datos del arreglo en última posición*/
	//arr = pop_back(size, arr);
	//arr = pop_back(size, arr);
	/*Eliminando datos del arreglo en primera posición*/
	//arr = pop_front(size, arr);
	//arr = pop_front(size, arr);
	//arr = pop_front(size, arr);
	/*Eliminando datos del arreglo en una posición específica*/
	//arr = erase(1, size, arr);

	if (empty(arr)) {
		std::cout << "\n\tArreglo vacio\n";
		return;
	}

	/*Imprimiendo arreglo*/
	print_array(size, arr);


	std::cin.get();
}