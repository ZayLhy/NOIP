#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int goal[5][5] = {{2, 2, 2, 2, 2}, {1, 2, 2, 2, 2}, {1, 1, 0, 2, 2}, {1, 1, 1, 1, 2}, {1, 1, 1, 1, 1}};
int status[5][5];
bool flag = false;

const int mx[8] = {1, 1, -1, -1, 2, 2, -2, -2};

const int my[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int evaluate() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (status[i][j] != goal[i][j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

bool check(int x, int y) {
	if (x < 0 || x > 4 || y < 0 || y > 4) {
		return false;
	}
	return true;
}

void dfs(int x, int y, int dep, int maxdep) {
	if (dep == maxdep) {
		if (!evaluate()) {
			flag = true;
		}
		return ;
	}
	for (int i = 0; i < 8; i++) {
		int nxtx = x + mx[i];
		int nxty = y + my[i];
		if (check(nxtx, nxty)) {
			swap(status[x][y], status[nxtx][nxty]);
			if (evaluate() + dep <= maxdep) {
				dfs(nxtx, nxty, dep + 1, maxdep);
			}
			swap(status[x][y], status[nxtx][nxty]);
		}
	}
}

void work() {
	flag = false;
	memset(status, 0, sizeof(status));
	string a[5];
	int x = 0, y = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		for (int j = 0; j < a[i].length(); j++) {
			if (a[i][j] == '*') {
				status[i][j] = 0;
				x = i;
				y = j;
			} else {
				status[i][j] = a[i][j] - '0' + 1;
			}
		}
	}
	if (!evaluate()) {
		cout << 0 << endl;
		return ;
	}
	for (int i = 1; i <= 15; i++) {
		dfs(x, y, 0, i);
		if (flag) {
			cout << i << endl;
			return ;
		}
	}
	cout << -1 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		work();
	}
	return 0;
}