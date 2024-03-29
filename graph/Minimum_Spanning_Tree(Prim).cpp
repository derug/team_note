#define X first
#define Y second

typedef long long ll;
typedef pair<ll, ll> pll;

const ll MAX;
vector<pll> adj[MAX];

ll Prim(ll n)
{
	ll cnt = 0, sum = 0;
	vector<ll> vst(n + 10);
	priority_queue<pll, vector<pll>, greater<pll>> pQ;

	cnt++, vst[1] = 1;
	for (pll pi : adj[1]) pQ.push(pi);

	while (!pQ.empty())
	{
		pll qt = pQ.top(); pQ.pop();
		if (vst[qt.Y]) continue;

		cnt++, vst[qt.Y] = 1, sum += qt.X;
		if (cnt == n) break;

		for (pll pi : adj[qt.Y])
			if (!vst[pi.Y])
				pQ.push(pi);
	}

	if (cnt == n) return sum;
	return -1;
}
