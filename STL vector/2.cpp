#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

using namespace std;

int main() {
    const int razmer = 10;
    int posl[razmer] = { 5, 2, 8, 5, 3, 8, 1, 8, 4, 2 };
    int* maximalnyi_it = max_element(posl, posl + razmer);
    int maximalnoe = *maximalnyi_it;
    int bez_max[razmer] = { 0 };
    int new_razmer = 0;
    for (int i = 0; i < razmer; ++i) {
        if (posl[i] != maximalnoe) {
            bez_max[new_razmer++] = posl[i];
        }
    }
    int zamenyaem_chet[razmer];
    copy(posl, posl + razmer, zamenyaem_chet);

    int* minimalnyi_it = min_element(posl, posl + razmer);
    int minimalnoe = *minimalnyi_it;

    replace_if(zamenyaem_chet, zamenyaem_chet + razmer,
        [](int x) { return x % 2 == 0; },
        minimalnoe);
    int soort[razmer];
    copy(posl, posl + razmer, soort);
    sort(soort, soort + razmer);

    int* poslednii = unique(soort, soort + razmer);
    int razmer_soort = poslednii - soort;

    cout << "Without max: ";
    for (int i = 0; i < new_razmer; ++i) cout << bez_max[i] << " ";
    cout << endl;
    cout << "With povtor chetn na min: ";
    for (int i = 0; i < razmer; ++i) cout << zamenyaem_chet[i] << " ";
    cout << endl;
    cout << "Without povtor: ";
    for (int i = 0; i < razmer_soort; ++i) cout << soort[i] << " ";
    cout << endl;

    return 0;
}