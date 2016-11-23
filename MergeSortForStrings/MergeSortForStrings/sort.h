#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>

using namespace std;

void mergeSort(vector<string>& v, int lb, int ub);
void merge(vector<string>& v, int lb, int spl, int ub);
void bubbleSort(vector<string>& v, int lb, int ub);
bool cmpStr(string& s1, string& s2);

#endif