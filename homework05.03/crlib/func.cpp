#include "func.h"

void selectionSort(vector<int>& v) {
	int ind, val, min;
	for(size_t i = 0; i < v.size()-1; i++) {
		min = v[i];
		for(size_t j = i+1; j < v.size(); j++)
			if(v[j] < min) min = v[j], ind = j ;
		if(min < v[i]) {
			val = v[i];
			v[i] = min;
			v[ind] = val; 
		}
	}
}
