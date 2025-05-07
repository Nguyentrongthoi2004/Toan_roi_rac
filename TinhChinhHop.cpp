#include <iostream>
#include <vector>

using namespace std;

int multiply(int res[], int x, int res_size) {
	int carry = 0;
	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}
	
	while (carry) {
		res[res_size] = carry % 10;
		carry /= 10;
		res_size++;
	}
	return res_size;
}

void chinhHop(int n, int k) {
	int res[1000];
	res[0] = 1;
	int res_size = 1;
	
	for (int i = n; i > n - k; i--) {
		res_size = multiply(res, i, res_size);
	}
	
	for (int i = res_size - 1; i >= 0; i--) {
		cout << res[i];
	}
	cout << endl;
}

int main() {
	int n, k;
	cin >> n >> k;
	chinhHop(n, k);
	return 0;
}
