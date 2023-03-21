#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/// <summary>
/// SWEA - ����ð����ϱ�
/// Ǯ�� ��� : ���� Ž��. ��ũ �ð��� �������� ����ϱ�
/// </summary>
int T, L, N, s, e;
vector <pair<int, int>> SE; //��ũ �ð���
int adTime[100100]; // ��ũ �ð��� �Ⱓ

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
			// �Ⱓ ���ʴ�� �����ֱ�
		}
		s = 0, e = 0;
		while (e < N)
		{
			// s , e ���̿� L ��ŭ�� �Ÿ��� ���涧 ���� ���
			while (s <= e && SE[s].first + L <= SE[e].second)
			{
				int len = SE[s].first + L - SE[e].first; // ��� �ִ�� �ϰ� ���� �Ⱓ
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