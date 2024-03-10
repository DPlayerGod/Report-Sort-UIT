#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

double arr[1000006];

void Merge(int l, int mid, int r) {
    vector<double> A, B;
    
    for (int i = l; i <= mid; i++) A.push_back(arr[i]);
    for (int i = mid + 1; i <= r; i++) B.push_back(arr[i]);
    
	vector<double> addArr;
    
    int numA = mid - l + 1, numB = r - mid, pA = 0, pB = 0;
    
    while (pA < numA && pB < numB) {
    	if (A[pA] <= B[pB]) addArr.push_back(A[pA++]);
    	else addArr.push_back(B[pB++]);
	}
	
	for (int i = pA; i < numA; i++) addArr.push_back(A[i]);
	for (int i = pB; i < numB; i++) addArr.push_back(B[i]); 
	
	for (int i = 0; i <= r - l; i++) arr[l + i] = addArr[i];
}
 
void MergeSort(int st, int ed) {
    if (st >= ed) return; 
    int mid = st + (ed - st) / 2;
    MergeSort(st, mid);
    MergeSort(mid + 1, ed);
    Merge(st, mid, ed);
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
    cin >> n;
	
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	tBegin = high_resolution_clock::now();
	MergeSort(0, n - 1);
	
	tEnd = high_resolution_clock::now();
    
	exec_time = duration_cast<duration<double>>(tEnd - tBegin);
    
    cout << (int)1000 * exec_time.count();
 
    return 0;
}
