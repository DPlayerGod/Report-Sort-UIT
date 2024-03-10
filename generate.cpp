#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

int Rand(int l, int h) {
    return rd() % (h - l + 1) + l;
}

double getLR(int L, int R) {
	return Rand(L, R) / (1.0 * Rand(300, 500));
}

int main(int argc, char* argv[]) {
   	registerGen(argc, argv, 1);
   	int g = argc >= 2 ? stoll(argv[1], nullptr, 10) : 2;

	int n = 1000000;
	
	if (g == 1) {
		cout << n << '\n';
		
		double cur = getLR(-1000000, -900000);
		for (int i = 1; i <= n; i++) {
			cur = cur + getLR(300, 5000);
			cout << fixed << setprecision(4) << cur << " ";
		}
	}
	else if (g == 2) {
		cout << n << '\n';
		
		double cur = getLR(90000, 100000);
		for (int i = 1; i <= n; i++) {
			cur = cur + getLR(-5000, -300);
			cout << fixed << setprecision(4) << cur << " ";
		}
	}
	else {
		cout << n << '\n';
		
		for (int i = 1; i <= n; i++) {
			cout << getLR(-10000000, 10000000) << " ";
		}
	} 
}
