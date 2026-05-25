#include<iostream>
using namespace std;

int** create(int n) {
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    for (int j = 0; j < n; j++) {
        int base = n * n - 1 - j * n;
        if (j % 2 == 0) {
            for (int i = 0; i < n; i++) {
                a[i][j] = base - (n - 1 - i);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                a[i][j] = base - i;
            }
        }
    }
    return a;
}
void print(int** a, int n) {
    for (int i = 0; i < n; i++, cout << endl) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << "\t";
        }
    }
    cout << endl;
}
int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int** a = create(n);
    cout << "Result=" << endl;
    print(a, n);
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}