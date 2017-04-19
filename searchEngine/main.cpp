#include <bits/stdc++.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

string name;
int val;
set<pair<int, string> > rating10;

int flow() {
    int i;
    in >> name >> val;
    i = in.rdstate();
    if(i & ios::eofbit)
        return 0;
    rating10.insert(make_pair(val, name));
    return 1;
}
void upd() {
    if(rating10.size() > 10) {
        auto it = rating10.end();
        for(int i = 0; i < 10; ++i, --it);
        rating10.erase(rating10.begin(), it);
    }
}
void res() {
    auto it = rating10.end(); --it;
    for(it; it != rating10.begin(); --it)
        out << it->first << ' ' << it->second << endl;
    out << it->first << ' ' << it->second << endl;
}

int main() {
    while(flow()) {
        upd();
    }
    res();
    return 0;
}
