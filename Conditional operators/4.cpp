#include <iostream>
#include <cmath>
#include <iomanip>

const double EPS = 1e-6;
bool isTriangle(double a, double b, double c) { //точно треугольник
	return (a + b > c) && (a + c > b) && (b + c > a);
}
double area(double a, double b, double c) {
	double s = (a + b + c) / 2.0; //формула Герона для треугольника
	return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
double inRadius(double a, double b, double c) { //радиус вписанной окр
	double s = (a + b + c) / 2.0;
	return area(a, b, c) / s;
}
double outRadius(double a, double b, double c) { //радиус описанной окр
	return (a * b * c) / (4 * area(a, b, c));
}

double median(double a, double b, double c) { //медиана
	return std::sqrt(2 * (a * a + b * b) - c * c) / 2;
}

double height(double a, double b, double c) { //высота
	return (2 * area(a, b, c)) / c;
}
double bisector(double a, double b, double c) { // для биссектрисы
	return std::sqrt(a * b * (a + b + c) * (a + b - c)) / (a + b);
}
int main() {
	double a, b, c;
	std::cout << "Enter a = ";
	std::cin >> a;
	std::cout << "Enter b =";
	std::cin >> b;
	std::cout << "Enter c =";
	std::cin >> c;
	if (!isTriangle(a, b, c)) {// Существует ли треуг
		std::cout << "Wrong! Such a triangle does not exist" << std::endl; 
		return 0;
	}
	double S = area(a, b, c); // Выводим площадь и радиусы
	double r_in = inRadius(a, b, c);
	double r_out = outRadius(a, b, c);
	std::cout << "Triangle square: " << std::fixed << std::setprecision(2) << S << std::endl;
	std::cout << "Radius of the inscribed circle: " << std::fixed << std::setprecision(2) << r_in << std::endl;
	std::cout << "Radius of the circumscribed circle: " << std::fixed << std::setprecision(2) << r_out << std::endl;

	if (std::fabs(a - b) < EPS && std::fabs(b - c) < EPS) { //типы треугольники
		std::cout << "Equilateral triangle" << std::endl;  // равносторонний
		std::cout << "Height (median, bisectors) =" << std::fixed << std::setprecision(2) << height(a, b, c) << std::endl;
	}
	else if (std::fabs(a * a + b * b - c * c) < EPS || std::fabs(a * a + c * c - b * b) < EPS || std::fabs(b * b + c * c - a * a) < EPS) { //прямоуг
		std::cout << "rectangular square" << std::endl;
		if (std::fabs(a * a + b * b - c * c) < EPS) {
			std::cout << "kateti: a, b. gipotenuza: c." << std::endl;
		}
		else if (std::fabs(a * a + c * c - b * b) < EPS) {
			std::cout << "kateti: a, gipotenuza: c. : b." << std::endl;
		}
		else {
			std::cout << "kateti: b, c. gipotenuza: a." << std::endl;
		}
		std::cout << "heigh = " << std::fixed << std::setprecision(2) << height(a, b, c) << std::endl;
		std::cout << "median pryamogo ugla = " << std::fixed << std::setprecision(2) << median(a, b, c) << std::endl;
	}
	else if (std::fabs(a - b) < EPS || std::fabs(b - c) < EPS || std::fabs(a - c) < EPS) { //равнобедр треугольник
		std::cout << "Triangle ravnobedr" << std::endl;
		if (std::fabs(a - b) < EPS) {
			std::cout << "Bok st: a, b. Osn: c." << std::endl;
		}
		else if (std::fabs(b - c) < EPS) {
			std::cout << "Bok st: b, c. Osn: a." << std::endl;
		}
		else {
			std::cout << "Bok st: a, c. Osn: b." << std::endl;
		}
		std::cout << "Heigh= " << std::fixed << std::setprecision(2) << height(a, b, c) << std::endl;
		std::cout << "Median = " << std::fixed << std::setprecision(2) << median(a, b, c) << std::endl;
		std::cout << "Krisa = " << std::fixed << std::setprecision(2) << bisector(a, b, c) << std::endl;
	}
	else {

		std::cout << "Triangle" << std::endl; // обычный разносторонний треугольник
	}

	return 0;
}