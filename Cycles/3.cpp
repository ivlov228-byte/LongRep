#include <iostream>
#include <cmath>

int main() {
    double a, b, h;

    std::cout << "Enter Nachalo: "; // вводим начало диапазона
    std::cin >> a;

    std::cout << "Enter Konec: "; // вводим конец диапазона
    std::cin >> b;

    std::cout << "Enter shag: "; // // вводим шаг
    std::cin >> h;

    if (h <= 0) {
        std::cout << "Wrong, otric \n"; //выводим ошибку, если шаг отрицательный
        return 1;
    }

    std::cout << "\nReslut:\n"; // 

    for (double x = a; x <= b; x += h) {
        int x1 = x * x - 1;
        if (x1 < 0) {
            std::cout << "Koren is otric chisla\n"; //если х1 отрицательный, выводим ошибку
            return 0;
        }
        double skobka = 2 * x - 8;
        if (skobka <= 0) {
            std::cout << "Logarifm iz nepologitel chisla\n"; // если лог отрицтельный или равен нулю выводим ошибку
            return 0;
        }
        double znamenatel = log(skobka);
        if (znamenatel == 0) {
            std::cout << "Delenie na nolb\n"; // если логарифм равен нулю, то выводим оишбку
            return 0;
        }
        double chislitel = sqrt(x1); //вычисляем числитель
        double result = chislitel / znamenatel;

        std::cout << "Otvet= " << result << '\n'; // выводим ответ
    }

    return 0;
}