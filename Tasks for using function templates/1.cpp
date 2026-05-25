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
void poisk(X** a, int n, int m, int& minn, int& maxx) {
	minn = 0;
	maxx = 0;
	X minV = a[0][0];
	X maxV = a[0][0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < minV) {
				minV = a[i][j];
				minn = i;
			}
			if (a[i][j] > maxV) {
				maxV = a[i][j];
				maxx = i;
			}
		}
	}
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
void process() {
	int n, m;
	X** a = create<X>(n, m);
	Print(a, n, m);
	int minn, maxx;
	poisk(a, n, m, minn, maxx);
	if (minn != maxx) {
		for (int j = 0; j < m; j++) {
			swap(a[minn][j], a[maxx][j]);
		}
		cout << "\nAfter: \n";
		Print(a, n, m);
	}
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}
int main() {
	cout << "1-int; 2-double; 3-float; 4-char;" << endl;
	int type;
	cout << "Your selection: "; cin >> type;
	switch (type) {
	case 1:
		process<int>();
		break;
	case 2:
		process<double>();
		break;
	case 3:
		process<float>();
		break;
	case 4:
		process<char>();
		break;
	default:
		process<int>();
		break;
	}
	return 0;
}