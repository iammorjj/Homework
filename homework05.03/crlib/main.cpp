#include <bits/stdc++.h>

using namespace std;

#define sz 50

extern void selectionSort(vector<int>& v);

int main() {
	vector<int> v(sz);
	for(int i = 0; i < sz; i++)
		v[i] = rand() % 1000 + 1;
	selectionSort(v);
	for(int i = 0; i < sz; i++)
		cout << v[i] << ' ';
	return 0;
}  
