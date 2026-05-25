#include <iostream>
using namespace std;
int main() {
    int a[100], n, x, y;
    cout << "Enter n :"; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
    cout << "Enter x : "; cin >> x;
    cout << "Enter y : "; cin >> y;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % 10 == x) {
            for (int j = n; j > i; j--) {
                a[j] = a[j - 1];
            }
            a[i] = y;
            n++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}