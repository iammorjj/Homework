#include <iostream>
#include "sort.h"

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	mergeSort(v, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << v[i] << endl;
}