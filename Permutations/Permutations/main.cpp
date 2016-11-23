#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, p = 0;
vector<int> v;
vector<bool> u;
int *lifo;

void dfs(int q); 

int main() {
	cin >> n >> k;
	v.resize(n);
	u.resize(n, 0);
	lifo = new int[n];
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
		dfs(i);
	return 0;
}

void dfs(int q) {
	lifo[p++] = q; u[q] = 1;
	if (p >= k) {
		for (int i = 0; i < k; i++)
			cout << v[lifo[i]] << ' ';
		cout << endl;
	}
	else
		for (int i = 0; i < n; i++)
			if (!u[i]) dfs(i);
	--p; u[q] = 0;
}

