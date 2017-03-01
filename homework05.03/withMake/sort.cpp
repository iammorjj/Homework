#include "sort.h"

void mergeSort(int lb, int ub) {
	if (ub - lb < 6)
		bubbleSort(lb, ub);
	else {
		int spl = (lb + ub) / 2;
		mergeSort(lb, spl);
		mergeSort(spl + 1, ub);
		merge(lb, spl + 1, ub);
	}
}
void merge(int lb, int spl, int ub) {
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
void bubbleSort(int lb, int ub) {
	for (int i = lb; i < ub; i++)
		for (int j = i + 1; j <= ub; j++)
			if (v[i] > v[j])
				swap(v[i], v[j]);
}
