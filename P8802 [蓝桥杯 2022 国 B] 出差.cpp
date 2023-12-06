
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int time_isolate[1005] = { 0 };//隔离时间
int pass[1005][1005] = { 0 };//赶路时间
bool visited[1005] = { false };//是否被访问
long long cost[1005];//总花费
queue<int> que;//队列（广度优先）

//二者取小
long long min(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> time_isolate[i];
		cost[i] = 99999;
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		//双向路径
		pass[a][b] = pass[b][a] = c;
	}
	//自己走自己不需要时间
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	//到n、1城市不需要隔离
	time_isolate[n] = 0;
	time_isolate[1] = 0;
	//将1加入队列
	que.push(1);
	//从start开始搜索周边
	int start;
	//自己到自己花费为0
	cost[1] = 0;
	//dij算法
	while (que.size())
	{
		//start等于队列第一位
		start = que.front();
		que.pop();
		//遍历所有节点（除了1，因为1不要用）
		for (int i = 2; i <= n; i++)
		{
			//和start节点的邻接点取最小值
			if (pass[start][i])
			{
				cost[i] = min(cost[i], cost[start] + pass[start][i] + time_isolate[i]);
			}
			//对【所有】未知的节点加入队列，并在之后作为start开始更新周边节点的花费
			if (!visited[i])
			{
				que.push(i);			
			}
		}
		//因为start节点已经搜索完了周边，则标记start为已访问
		visited[start] = true;
	}
	//如果n城市到不了输出0
	if (cost[n] == 99999)
	{
		cout << 0;
		return 0;
	}
	//输出最终花费时间  
	cout << cost[n];
	return 0;
}
