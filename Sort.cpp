#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

void solve(int n, vector<double> a) {
	sort(a.begin(), a.end());
}

int main() {
	int n;
	
	cin >> n;
	vector<double> a(n, 0);
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	tBegin = high_resolution_clock::now();
	solve(n, a);
	tEnd = high_resolution_clock::now();
    
	exec_time = duration_cast<duration<double>>(tEnd - tBegin);
    
    cout << (int)1000 * exec_time.count();
}
