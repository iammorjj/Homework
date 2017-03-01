#include <bits/stdc++.h>
#include "sort.h"
#include "inout.h"

using namespace std;

int n;
vector<string> v;

int main() {
        cin >> n;
        v.resize(n);
        vector<string> v(n);
        in();
        mergeSort(0, n - 1);
        out();
        return 0;
}
