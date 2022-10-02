#include<iostream> 
using namespace std;
int v[10000], p[5], W[25][30000];		//W表示价值=价格*重要程度，v表示价格，p表示重要度 
int max(int x, int y) { return x > y ? x : y; }//自定义x与y最大值max函数
int main()
{

	int n, m;
	cin >> n >> m;   //输入总钱数和总个数
	if (n < 30000 && m < 25) {
		for (int i = 1; i <= m; i++)	//输入每件物品的信息 
		{
			cin >> v[i] >> p[i];//输入物品的价格和重要程度 
			p[i] *= v[i];
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j <= n; j++) {				//j为总钱数或余钱数
				if (j >= v[i]) {				//如果可以买第i件物品。
					W[i][j] = max(W[i - 1][j], W[i - 1][j - v[i]] + p[i]);//判断是否值得买(不买第i个物品的价值，买第i个物品价值）

				}

			}
		}
	}
	cout << W[m][n];//最优
	return 0;
}
