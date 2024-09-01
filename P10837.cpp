#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define N 100
#define int long long
using namespace std;
int t[N], r[N], l[N], c[N];
signed main()
{
	int n, m;
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> t[i];
	}
	sort(t, t + n);
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			l[i] = t[i];
		}
		else
		{
			l[i] = max(t[i], t[i - 1] + m);
		}
		if (i == n - 1)
		{
			r[i] = t[i] + m;
		}
		else
		{
			r[i] = min(t[i + 1] , t[i] + m);
		}
		c[i]= max(0LL, r[i] - l[i]);
		cnt += max(0LL, r[i] - l[i]);
	}
	int ans = cnt;
	for (int i = 0; i < n; ++i)
	{
		int res = cnt - c[i] + m;
		if (i == 0)
		{
			res -= c[i + 1];
			res += r[i + 1] - t[i + 1];
		}
		else if (i == n - 1)
		{
			res -= c[n - 1];
			res += t[n - 2] + m - l[n - 2];
		}
		else
		{
			res -= c[i + 1] + c[i - 1];
			res += max(0LL, min(t[i + 1], t[i - 1] + m) - l[i - 1]);
			res += max(0LL, r[i + 1] - max(t[i + 1], t[i - 1] + m));
		}
		ans = max(ans, res);
	}	
	cout << ans;
	return 0;
}
