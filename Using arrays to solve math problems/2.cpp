#include <iostream>
using namespace std;
int main() {
    int n;
    double A;
    cout << "Enter A: ";
    cin >> A;
    cout << "Enter n: ";
    cin >> n;
    double P[100];
    double result[100];
    cout << "Enter P(x): ";
    for (int i = 0; i <= n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < 100; i++) {
        result[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        result[i] += P[i] * A * A;        
        result[i + 1] += P[i] * 2 * A;    
        result[i + 2] += P[i];            
    }
    cout << "\n(x^2 + 2Ax + A^2)P(x) =" << endl;
    for (int i = 0; i <= n + 2; i++) {
        cout << result[i];
        if (i < n + 2) cout << ", ";
    }
    cout << endl;

    return 0;
}