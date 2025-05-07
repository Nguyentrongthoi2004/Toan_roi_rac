#include <stdio.h>
#include <string.h>

#define MAX 1000

void combination(int n, int k) {
	if (k > n) {
		printf("0\n");
		return;
	}
	
	if (k > n - k) {
		k = n - k;
	}
	
	int res[MAX] = {0};
	res[0] = 1;  
	
	int res_size = 1;
	
	for (int i = 0; i < k; i++) {
		
		int num = n - i;
		
		int den = i + 1;
		
		int carry = 0;
		for (int j = 0; j < res_size; j++) {
			long long prod = res[j] * num + carry; 
			res[j] = prod % 10;
			carry = prod / 10;
		}
		
		while (carry) {
			res[res_size] = carry % 10;
			carry /= 10;
			res_size++;
		}
		
		carry = 0;
		for (int j = res_size - 1; j >= 0; j--) {
			long long temp = carry * 10 + res[j];
			res[j] = temp / den;
			carry = temp % den; 
		}
		
		while (res_size > 1 && res[res_size - 1] == 0) {
			res_size--;
		}
	}
	
	for (int i = res_size - 1; i >= 0; i--) {
		printf("%d", res[i]);
	}
	printf("\n");
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	combination(n, k);
	return 0;
}
