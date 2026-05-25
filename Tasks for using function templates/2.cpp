#include <iostream>
using namespace std;

template <typename X>
X** create(int& n, int& m) {
	cout << "n = "; cin >> n;
	cout << "m = "; cin >> m;
	X** a = new X * [n];
	for (int i = 0; i < n; i++) {
		a[i] = new X[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "a[" << i << "][" << j<<"] = "; cin >> a[i][j];
		}
	}
	return a;
}

template <typename X>
X* createX(int n) {
	X* z = new X [n];
	for (int i = 0; i < n; i++) {
		cout << "X[" << i << "] = "; cin >> z[i];
	}
	return z;
}

template <typename X>
void Print(X** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

template <typename X>
void replace(X** a, X* x, int n, int stolbec) {
	for (int i = 0; i < n; i++) {
		a[i][stolbec] = x[i];
	}
}

template <typename X>
int poick(X** a, int n, int m) {
	for (int j = 0; j < m; j++) {
		bool chetn = true;
		for (int i = 0; i < n; i++) {
			if (a[i][j] % 2 != 0) {
				chetn = false;
				break;
			}
		}
		if (chetn) {
			return j;
		}
	}
	return -1;
}

template <typename X>
void process() {
	int n, m;
	X** a = create<X>(n, m);
	Print(a, n, m);
	X* x = createX <X>(n);
	int stolbec = poick<X>(a, n, m);
	if (stolbec != -1) {
		replace(a, x, n, stolbec);
		Print(a, n, m);
	}
	for (int i = 0; i<n; i++) {
		delete[] a[i];
	}
	delete[] a;
	delete[] x;
}

int main() {
	process<int>();
	return 0;
}
