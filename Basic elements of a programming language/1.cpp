int main() {
	cout << "NUMBER 1" << endl;
	int main() {
		double x, y;
		cout << "x = ";
		cin >> x; // вводим x
		cout << "y = ";
		cin >> y; // вводим y
		double c = 0.5 * ((sqrt(exp(x * x + y * y)) - (y * x)) / (x * x + y * y)) + log((sqrt(x * x * x * x)) / (sqrt(y * y * y * y))); // Записываем уравнение
		cout << "result: " << c << endl; //выводим ответ на экран
		return 0;
	}
}