
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int time_isolate[1005] = { 0 };//����ʱ��
int pass[1005][1005] = { 0 };//��·ʱ��
bool visited[1005] = { false };//�Ƿ񱻷���
long long cost[1005];//�ܻ���
queue<int> que;//���У�������ȣ�

//����ȡС
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
		//˫��·��
		pass[a][b] = pass[b][a] = c;
	}
	//�Լ����Լ�����Ҫʱ��
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	//��n��1���в���Ҫ����
	time_isolate[n] = 0;
	time_isolate[1] = 0;
	//��1�������
	que.push(1);
	//��start��ʼ�����ܱ�
	int start;
	//�Լ����Լ�����Ϊ0
	cost[1] = 0;
	//dij�㷨
	while (que.size())
	{
		//start���ڶ��е�һλ
		start = que.front();
		que.pop();
		//�������нڵ㣨����1����Ϊ1��Ҫ�ã�
		for (int i = 2; i <= n; i++)
		{
			//��start�ڵ���ڽӵ�ȡ��Сֵ
			if (pass[start][i])
			{
				cost[i] = min(cost[i], cost[start] + pass[start][i] + time_isolate[i]);
			}
			//�ԡ����С�δ֪�Ľڵ������У�����֮����Ϊstart��ʼ�����ܱ߽ڵ�Ļ���
			if (!visited[i])
			{
				que.push(i);			
			}
		}
		//��Ϊstart�ڵ��Ѿ����������ܱߣ�����startΪ�ѷ���
		visited[start] = true;
	}
	//���n���е��������0
	if (cost[n] == 99999)
	{
		cout << 0;
		return 0;
	}
	//������ջ���ʱ��  
	cout << cost[n];
	return 0;
}