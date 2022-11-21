#include <cstdio>
const int N = 20;
char g[N][N];
int n, col[N], d[N], ud[N];
//x������  y������ 
bool check(int x, int y) {
	//ֻҪ��һ������ �Ǵ������ڣ�x,y�� ���λ�÷Żʺ� 
	if (col[y] || d[x + y] || ud[n - x + y]) return false;
	return true;
}

void dfs(int row) {
	if (row == n) {
		//�����Ѿ�������n����
		for (int i = 0; i < n; i++) printf("%s\n", g[i]);
		printf("\n");
		return;
	}

	//���ԶԸ��е�ĳ�н��зŻʺ�
	for (int i = 0; i < n; i++) {
		int x = row, y = i;
		if (check(x, y)) {
			//���뵽���������λ�ÿ��Է��ûʺ� 
			col[y] = d[x + y] = ud[n - x + y] = 1;
			g[x][y] = 'Q';
			//������һ�е�����
			dfs(row + 1);
			//��������ִ����  ����-�ָ��ֳ�
			g[x][y] = '.';
			col[y] = d[x + y] = ud[n - x + y] = 0;
		}
	}
}
int main() {
	scanf("%d", &n);
	//��ʼ��һ�µ�ͼ 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = '.';
		}
	}
	//�ӵ�0�п�ʼ���� 
	dfs(0);
	return 0;
}
