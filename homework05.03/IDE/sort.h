#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

extern vector<string> v;

void mergeSort(int lb, int ub);
void merge(int lb, int spl, int ub);
void bubbleSort(int lb, int ub);

#endif // SORT_H_INCLUDED
