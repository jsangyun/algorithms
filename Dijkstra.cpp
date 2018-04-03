//2016025032_¡§ªÛ¿±_508 

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define INF 100000

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > myQueue;
vector<pair<int, int> > node[5001];
int N, M;
int K;
int u, v, w;

int dijkstra(int st)
{
	int length[5001];
	for (int i = 1; i <= N; i++)
	{
		if (i != st)
			length[i] = INF;
		else
			myQueue.push(make_pair(length[i], i));
	}
	length[st] = 0;
	while (!myQueue.empty())
	{
		int u = myQueue.top().second, val = myQueue.top().first;
		myQueue.pop();
		for (int j = 0; j < node[u].size(); j++)
		{
			if (length[u] + node[u][j].second < length[node[u][j].first])
			{
				length[node[u][j].first] = length[u] + node[u][j].second;
				myQueue.push(make_pair(length[node[u][j].first], node[u][j].first));
			}
		}
	}
	int MAX = 0;
	for (int i = 1; i <= N; i++) {
		MAX = max(MAX, length[i]);
	}
	return MAX;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int temp, num;
		cin >> temp >> num;
		for (int j = 0; j < num; j++) {
			int v, w;
			cin >> v >> w;
			node[i].push_back(make_pair(v, w));
		}
	}
	cout << dijkstra(1);
	return 0;
}
