#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>

using namespace std;

int main() {
    const int razmer = 4;
    double posl[razmer] = { 4.0, 9.0, 16.0, 25.0 };
    double summa = accumulate(posl, posl + razmer, 0.0, plus<double>());
    double srednee_arifm = summa / razmer;
    double summa_log = accumulate(posl, posl + razmer, 0.0,
        [](double acc, double x) {
            return acc + log(x);
        });
    double srednee_geometr = exp(summa_log/razmer);
    cout << "Posl: ";
    for (int i = 0; i < razmer; ++i) cout << posl[i] << " ";
    cout << endl;
    cout << "Srednee arifm: " << srednee_arifm << endl;
    cout << "Srednee geometr: " << srednee_geometr << endl;
    return 0;
}