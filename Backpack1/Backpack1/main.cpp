#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct sub {
	double weight, value, piece;
	int num;
};
bool cmpV(sub& s1, sub& s2) {
	return s1.value < s2.value;
}
bool cmpN(sub& s1, sub& s2) {
	return s1.num < s2.num;
}

int main() {
	double w;
	int n;
	cin >> w >> n;
	vector<sub> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].weight >> v[i].value;
		v[i].num = i, v[i].piece = 0.0;
	}
	sort(v.rbegin(), v.rend(), cmpV);
	int k = 0;
	while (k < n)
		if (v[k].weight <= w)
			w -= v[k].weight, v[k++].piece = 1.0;
		else {
			v[k].piece = w / v[k].weight;
			break;
		}
	sort(v.begin(), v.end(), cmpN);
	for (int i = 0; i < n; i++)
		cout << v[i].piece << ' ';
	return 0;
}