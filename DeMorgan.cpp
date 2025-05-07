#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
	set<string> A, B, C;
	vector<string> result;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string x;
		cin >> x;
		A.insert(x);
	}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string x;
		cin >> x;
		B.insert(x);
	}
	
	int p;
	cin >> p;
	for (int i = 0; i < p; ++i) {
		string x;
		cin >> x;
		C.insert(x);
	}
	
	set<string> diffAB;
	set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(diffAB, diffAB.begin()));
	
	set<string> diffAC;
	set_difference(A.begin(), A.end(), C.begin(), C.end(), inserter(diffAC, diffAC.begin()));
	
	set_union(diffAB.begin(), diffAB.end(), diffAC.begin(), diffAC.end(), back_inserter(result));
	
	sort(result.begin(), result.end(), [](const string &a, const string &b) {
		bool isDigitA = isdigit(a[0]), isDigitB = isdigit(b[0]);
		if (isDigitA != isDigitB)
			return isDigitA > isDigitB;
		return a < b;
	});
	
	if (result.empty()) {
		cout << "none" << endl;
	} else {
		for (const auto &x : result) {
			cout << x << " ";
		}
		cout << endl;
	}
	
	return 0;
}
