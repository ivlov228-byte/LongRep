#include <iostream>
#include <cmath>
#include <bitset>

int main() {
	int n, i;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Binary = "<< std::bitset <8>(n); //Чтобы увидеть правильность решения выводим и в двоичном представлении
	std::cout << "\nEnter number bit (can start 0): "; // номер бита, начиная с нуля
	std::cin >> i; // вводим n и i
	int b_1 = (1 << i); // Единственная битовая единица (степнь двойки в двоичном представлении)
	std::cout << "Binary = " << std::bitset <8>(b_1); // Битовая единица в двоичном представлении
	int n_b_1 = n | b_1; // Используем поразрядную дизъюнкцию, чтобы при соединении 1 и 1 не превратились в 0, а 1 и 0 дали нам 1
	std::cout << "\nResult = " << n_b_1 << std::endl; 
	std::cout << "Binary = " << std::bitset <8>(n_b_1); // Чтобы удостовериться в ответе выводим и двоичное представление
}
