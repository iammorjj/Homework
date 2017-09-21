#include <bits/stdc++.h>

using namespace std;

void mySort(int *v, int n) {
	sort(v, v+n);
}

int main() {
	
	int n;
	cin >> n;
	
	int **vv = new int*[n];
	for(int i = 0; i < n; ++i)
		vv[i] = new int[n];
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> vv[j][i];
			
	vector<thread> gr;
	for(int i = 0; i < n; ++i)
		gr.push_back(thread(mySort, vv[i], n));
		
	for(auto &thread : gr)
		if(thread.joinable())
			thread.join();
			
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			cout << vv[j][i] << ' ';
		cout << endl;
	}
	
	return 0;
}
