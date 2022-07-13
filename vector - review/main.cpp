#include<iostream>
#include<vector>
#include<ctime>

void main() {

	std::vector<int>vNumbers;

	/*adding values*/
	for (unsigned short i = 1; i <= 5; ++i) {
		vNumbers.push_back(i); /*adding last position*/
	}
	/*adding random values*/
	srand(time(nullptr));
	for (unsigned short i = 1; i <= 5; ++i) {
		vNumbers.push_back((i + (2 + rand() % (9 - 2))) *  (2 + rand() % (9 - 2))); /*adding last position*/
	}

	vNumbers.insert(vNumbers.begin() + 4, 90); /*adding to a specific position*/

	/*deleting values*/
	vNumbers.pop_back(); /*deleting first item*/
	vNumbers.erase(vNumbers.begin() + 4); /*deleting to a specific position*/

	/*verifying empty array*/
	if (!vNumbers.empty()) {
		/*iterating vector*/
		/*1)*/
		for (int _iter : vNumbers) {
			std::cout << "_iter value: " << _iter << std::endl;
		}
		std::cout << "\n----------------------------------------------------------\n" << std::endl;
		/*2)*/
		for (auto it = vNumbers.begin(); it != vNumbers.end(); ++it) {
			std::cout << "it value: " << *it << std::endl;
			std::cout << "it address: " << &it << std::endl;
			std::cout << "value address (it): " << &(*it) << std::endl;
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "\n\tEmpty vector!";
	}

	std::cin.get();
}