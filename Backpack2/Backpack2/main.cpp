#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct bag {
	int weight, value;
	bool b;
	bag() { b = false; }
};

vector<bag> v;
vector< vector<int> > a;

void ans(int n, int w);

int main() {
	int w, n;
	cin >> w >> n;
	v.resize(n + 1);
	for (int i = 1; i < n + 1; i++) 
		cin >> v[i].weight >> v[i].value;
	a.resize(n + 1, vector<int>(w + 1));
	for (int i = 0; i < n + 1; i++)
		a[i][0] = 0;
	for (int i = 0; i < w + 1; i++)
		a[0][i] = 0;
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j < w + 1; j++)
			if (j >= v[i].weight)
				a[i][j] = max(a[i - 1][j], a[i - 1][j - v[i].weight] + v[i].value);
			else a[i][j] = a[i - 1][j];
	ans(n, w);
	for (int i = 1; i < n + 1; i++)
		cout << v[i].b << ' ';
}

void ans(int n, int w) {
	if (!a[n][w])
		return;
	if (a[n - 1][w] == a[n][w])
		ans(n - 1, w);
	else
		v[n].b = true, ans(n - 1, w - v[n].weight);
}