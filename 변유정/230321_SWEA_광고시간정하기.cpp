#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/// <summary>
/// SWEA - 광고시간정하기
/// 풀이 방법 : 이진 탐색. 피크 시간대 누적으로 계산하기
/// </summary>
int T, L, N, s, e;
vector <pair<int, int>> SE; //피크 시간대
int adTime[100100]; // 피크 시간대 기간

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		SE.clear();
		memset(adTime, 0, sizeof(adTime));
		cin >> L >> N;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> s >> e;
			SE.push_back({ s,e });
			adTime[i + 1] = adTime[i] + e - s;
			// 기간 차례대로 더해주기
		}
		s = 0, e = 0;
		while (e < N)
		{
			// s , e 사이에 L 만큼의 거리가 생길때 부터 계산
			while (s <= e && SE[s].first + L <= SE[e].second)
			{
				int len = SE[s].first + L - SE[e].first; // 계산 최대로 하고 남은 기간
				if (len > 0) ans = max(ans, adTime[e] - adTime[s] + len);
				else ans = max(ans, adTime[e] - adTime[s]);
				s++;
			}
			e++;
		}
		ans = max(ans, adTime[N] - adTime[s]);
		cout << "#" << tc << " " << ans << "\n";
	}
}