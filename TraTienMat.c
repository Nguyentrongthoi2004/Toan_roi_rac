#include <stdio.h>
//Quy uoc : m la so to 200, k la so to 100, i la so to 50

int SoCachTraIien(int n) {
	int count = 0;
	for (int m = 0; m <= n / 200; ++m) {
		for (int k = 0; k <= (n - 200 * m) / 100; ++k) {
			int i = (n - 200 * m - 100 * k) / 50;
			if (50 * i + 100 * k + 200 * m == n) {
				++count;
			}
		}
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", SoCachTraIien(n));
	return 0;
}
