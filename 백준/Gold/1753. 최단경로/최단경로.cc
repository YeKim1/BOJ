#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define VERTEX_MAX 20001
#define EDGE_MAX 300001

vector<pair<int, int>> graph[VERTEX_MAX];
int dist[VERTEX_MAX];

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int vertex = pq.top().second;
		int cur_dist = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[vertex].size(); i++) {
			int next_vertex = graph[vertex][i].first;
			int next_dist = cur_dist + graph[vertex][i].second;

			if (dist[next_vertex] > next_dist) {
				pq.push({ next_dist, next_vertex });
				dist[next_vertex] = next_dist;
			}
		}
	}
}

int main() {
	int V, E, K;
	cin >> V >> E >> K;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = INT_MAX;
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
}