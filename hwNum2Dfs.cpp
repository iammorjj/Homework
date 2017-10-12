#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > gr;
vector<bool> used;
mutex used_mutex;

void dfs(int v) {
	
	used_mutex.try_lock();
	
	used[v] = 1;
	int adj;
	
	for(size_t i = 0; i < gr[v].size(); ++i) {
		adj = gr[v][i];
		if(!used[adj])
			dfs(adj);
	}
	
	used_mutex.unlock();
}

int main() {
	
	int m, a, b, compCon = 0;
	cin >> n >> m;
	gr.resize(n), used.resize(n, 0);
	
	for(int i = 0; i < m; ++i) {
		cin >> a >> b; --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	
	for(int i = 0; i < n; ++i) {
		if(!used[i]) {
			used[i] = 1, ++compCon;
			vector<thread> group;
			
			for(size_t j = 0; j < gr[i].size(); ++j)
				group.push_back(thread(dfs, gr[i][j])); // создание потоков для смежных
			
			for(auto &thread : group)
				if(thread.joinable())
					thread.join(); // запуск
		}
	}
	
	cout << compCon;
	
	return 0;
}
