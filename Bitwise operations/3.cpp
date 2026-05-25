#include <iostream>
#include <cmath>
#include <bitset>

int main() {
	int n, i;
	std::cout << "Enter n: ";
	std::cin >> n;  //Вводим значение n
	std::cout << "Binary = " << std::bitset <8>(n); // Выводим двоичное представление N для виденья правильного результата
	std::cout << "\nEnter number bit (can start 0): ";
	std::cin >> i; // Вводим значение i
	int b_1 = (1 << i); // Приравниваем b_1 к 2 в i степени
	std::cout << "Binary = " << std::bitset <8>(~b_1); //Инвертируем двоичное представление, чтобы в i-бите был 0
	int n_b_1 = n & ~b_1; //используем конъюнкию, чтобы при соединении 1 и 0 дали нам 0, а 1 и 1 дали ту же 1
	std::cout << "\nResult = " << n_b_1 << std::endl; // Выводим результат на экран
	std::cout << "Binary = " << std::bitset <8>(n_b_1); // вместе с его двоичным представлением
}
