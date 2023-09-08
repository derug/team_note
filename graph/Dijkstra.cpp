#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAX, INF;
vector<pll> adj[MAX];

vector<ll> Dijkstra(ll n, ll st)
{
	ll cnt = 0, sum = 0;
	vector<ll> dij(n + 10, INF), vst(n + 10);
	priority_queue<pll, vector<pll>, greater<pll>> pQ;

	dij[st] = 0, pQ.push({ 0, st });

	while (!pQ.empty())
	{
		pll qt = pQ.top(); pQ.pop();
		if (vst[qt.Y]) continue;

		cnt++, vst[qt.Y] = 1;
		if (cnt == n) break;

		for (pll pi : adj[qt.Y])
			if (!vst[pi.Y] && dij[pi.Y] > dij[qt.Y] + pi.X)
				dij[pi.Y] = dij[qt.Y] + pi.X, pQ.push({ dij[pi.Y], pi.Y });
	}

	return dij;
}
