#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool greedyCheck(vector< pair<int, int> >& v, int x, int n);
void anyCheck(vector< pair<int, int> >& v, int x, int n);

int main() {
	int n, x;
	cin >> n;
	vector< pair<int, int> > value(n);
	for (int i = 0; i < n; i++) {
		cin >> value[i].first;
		value[i].second = 0;
	}
	sort(value.begin(), value.end());
	cin >> x;
	if (!greedyCheck(value, x, n))
		anyCheck(value, x, n);
	return 0;
}

bool greedyCheck(vector< pair<int, int> >& v, int x, int n) {
	int i = n - 1;
	while (x > 0 && i > -1)
		if (x >= v[i].first)
			x -= v[i].first, v[i].second++;
		else --i;

		if (x) {
			cout << "Greedy Impossible" << endl;
			return 0;
		}

		cout << "Greedy Possible" << endl;
		for (int i = 0; i < n; i++)
			cout << v[i].first << "$ x" << v[i].second << endl;
		return 1;
}
void anyCheck(vector<pair<int, int> >& v, int x, int n) {
	int inf = 10000000;
	for (int i = 0; i < n; i++)
		v[i].second = 0;
	vector<int> m(x + 1, inf);
	m[0] = 0;
	for (int i = 1; i < x + 1; i++)
		for (int j = 0; j < n; j++)
			if (i >= v[j].first && m[i - v[j].first] + 1 < m[i])
				m[i] = m[i - v[j].first] + 1;
	if (m[x] == inf) {
		cout << "Impossible" << endl;
		return;
	}
	while (x > 0)
		for (int i = 0; i < n; i++)
			if (m[x - v[i].first] + 1 == m[x]) {
				x -= v[i].first, v[i].second++;
				break;
			}
	cout << "Possible" << endl;
	for (int i = 0; i < n; i++)
		cout << v[i].first << "$ x" << v[i].second << endl;
}