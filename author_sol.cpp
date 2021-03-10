#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<int> c_rank(n + 1), s_rank(m + 1);
		for (int i = 1; i <= n; i++) {
			cin >> c_rank[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> s_rank[i];
		}
		vector<vector<int>> app(m + 1);
		auto comp = [&](int a, int b) {
			return c_rank[a] < c_rank[b];
		};
		for (int i = 1; i <= m; i++) {
			int k;
			cin >> k;
			vector<int> id(k);
			for (int j = 0; j < k; j++) {
				cin >> id[j];
			}
			sort(id.begin(), id.end(), comp);
			app[i] = id;
		}
		auto comp2 = [&](int a, int b) {
			return s_rank[a] < s_rank[b];
		};
		vector<int> rank_wise_index(m), alloted(n + 1, 0);
		for (int i = 1; i <= m; i++) {
			rank_wise_index[i - 1] = i;
		}
		sort(rank_wise_index.begin(), rank_wise_index.end(), comp2);
		int found = 0;
		for (int i = 1; i <= m; i++) {
			int s_id = rank_wise_index[i - 1];
			for (int j = 0; j < (int) app[s_id].size(); j++) {
				int college_id = app[s_id][j];
				if (alloted[college_id] == 0) {
					if (s_id == 1) {
						cout << college_id << '\n';
						found = 1;
					}
					alloted[college_id] = 1;
					break;
				}
			}
		}
		if (found == 0) {
			cout << found << '\n';
		}
	}
	return 0;
}
