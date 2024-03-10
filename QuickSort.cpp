#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

const int MAXN = 1e6 + 5;

int n;
double arr[MAXN];

int partition(int low, int high) {
	double pivot = arr[high]; 
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

int partition_r(int low, int high) {
	srand(time(NULL));
	int random = low + rand() % (high - low);
	swap(arr[random], arr[high]);
	return partition(low, high);
}

void quickSort(int low, int high) {
	if (low < high) {
		int pi = partition_r(low, high);
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

int main()
{
	int n;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    tBegin = high_resolution_clock::now();
	quickSort(0, n - 1);
	
	tEnd = high_resolution_clock::now();
    
	exec_time = duration_cast<duration<double>>(tEnd - tBegin);
    
    cout << (int)1000 * exec_time.count();	
	return 0;
}
