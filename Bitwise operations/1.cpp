#include <iostream>
#include <cmath>
#include <bitset>

int main() {
	int i;
	std::cout << "i = ";
	std::cin >> i; //вводим число i
	int z = (1 << i); // чтобы потом вывести в двоичном представлении приравниваем Z к 2 в i степени
	std::cout << "your number = " << z << std::endl; // выводим найденное раннее число z
	std::cout << std::bitset <8>(z) << std::endl; // выводим число z в двоичном представлении/ длина ответа будет 8 бит (с наличием значащих нулей)
}