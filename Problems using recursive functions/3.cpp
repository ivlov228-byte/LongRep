#include <iostream>
#include <cmath>
using namespace std;
void p(int n, char a) {
    for (int i = 0; i < n; i++)
        cout << a;
}

void F(int n, int c, char a) {
    if (c <= n) {
        p(c, a);
        p(2 * (n - c), '-');
        p(c, a);
        cout << endl;
        F(n, c + 1, a + 1);
        p(c, a);
        p(2 * (n - c), '-');
        p(c, a);
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter n: "; cin >> n;
    F(n, 1, '1');
    return 0;
}
