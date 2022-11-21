#include <cstdio>
const int N = 20;
char g[N][N];
int n, col[N], d[N], ud[N];
//x代表行  y代表列 
bool check(int x, int y) {
	//只要有一个满足 那代表不能在（x,y） 这个位置放皇后 
	if (col[y] || d[x + y] || ud[n - x + y]) return false;
	return true;
}

void dfs(int row) {
	if (row == n) {
		//代表已经放置了n行了
		for (int i = 0; i < n; i++) printf("%s\n", g[i]);
		printf("\n");
		return;
	}

	//尝试对该行的某列进行放皇后
	for (int i = 0; i < n; i++) {
		int x = row, y = i;
		if (check(x, y)) {
			//进入到这里表明该位置可以放置皇后 
			col[y] = d[x + y] = ud[n - x + y] = 1;
			g[x][y] = 'Q';
			//进行下一行的搜索
			dfs(row + 1);
			//上面搜索执行完  回溯-恢复现场
			g[x][y] = '.';
			col[y] = d[x + y] = ud[n - x + y] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	//初始化一下地图 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = '.';
		}
	}
	//从第0行开始搜索 
	dfs(0);
	return 0;
}
