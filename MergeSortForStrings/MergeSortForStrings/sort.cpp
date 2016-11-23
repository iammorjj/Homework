#include "sort.h"

void mergeSort(vector<string>& v, int lb, int ub) {
	if (ub - lb < 6)
		bubbleSort(v, lb, ub);
	else {
		int spl = (lb + ub) / 2;
		mergeSort(v, lb, spl);
		mergeSort(v, spl + 1, ub);
		merge(v, lb, spl + 1, ub);
	}
}
void merge(vector<string>& v, int lb, int spl, int ub) {
	int pos1 = lb, pos2 = spl, pos3 = 0;
	vector<string> t(ub - lb + 1);
	while (pos1 < spl && pos2 <= ub) {
		if (v[pos1] < v[pos2])
			t[pos3++] = v[pos1++];
		else
			t[pos3++] = v[pos2++];
	}
	while (pos1 < spl)
		t[pos3++] = v[pos1++];
	while (pos2 <= ub)
		t[pos3++] = v[pos2++];
	for (int i = 0; i < pos3; i++)
		v[lb + i] = t[i];
}
void bubbleSort(vector<string>& v, int lb, int ub) {
	for (int i = lb; i < ub; i++)
		for (int j = i + 1; j <= ub; j++)
			if (cmpStr(v[i], v[j]))
				swap(v[i], v[j]);
}
bool cmpStr(string& s1, string& s2) {
	int i = 0;
	for (i; i < s1.length() && s1[i] == s2[i]; i++);
	return ((i < s1.length() && s1[i] > s2[i]) ? true : false);
}