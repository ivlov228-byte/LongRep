#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int razmer = 8;
    int posl[razmer] = { 3, 8, 2, 5, 10, 7, 4, 6 };
    int* minimalnyi_it = min_element(posl, posl + razmer);
    int minimalnoe = *minimalnyi_it;
    replace_if(posl, posl + razmer,
        [](int x) { return x % 2 == 0; },
        minimalnoe);
    cout << "Rezult: ";
    for (int i = 0; i < razmer; ++i) {
        cout << posl[i] << " ";
    }
    cout <<endl;

    return 0;
}