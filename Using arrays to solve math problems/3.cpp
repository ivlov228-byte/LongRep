#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int tr[100] = { 0 };
    tr[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            tr[j] = tr[j] + tr[j - 1];
        }
    }
    cout << "koef. (1 + x)^n" << endl;
    for (int i = 0; i <= n; i++) {
        cout << tr[i];
        if (i < n) cout << ", ";
    }
    cout << endl;

    return 0;
}