#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// DP (LCS)
// ���� ���� ������ ������ ���ؼ� ����
// �ƴϸ� �� ���ڿ��� ���� ���� �ִ밪 ���ؼ� ���ϱ�

int T, dp[1001][1001];
string A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		memset(dp, 0, sizeof(dp));
		cin >> A >> B;
		int i = 0, j = 0;

		for (int i = 1; i <= A.size(); i++)
		{
			for (int j = 1; j <= B.size(); j++)
			{
				if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << "#" << tc << " " << dp[A.size()][B.size()] << "\n";
	}
}