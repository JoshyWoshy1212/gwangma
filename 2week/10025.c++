//10025
#include <iostream>

using namespace std;

int N, K, tmp, result = 0;
long long icebuck[1000002];
long long dist[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> icebuck[i];
		cin >> dist[i];
	}

	int locate = K;

	while (true) {
		locate++;

		for (int i = 0; i < N; i++)
			if (locate - K > dist[i]) {
				cout << tmp;
				return 0;
			}

		for (int i = 0; i < N; i++)
			if (dist[i] >= locate - K && dist[i] <= locate + K)
				tmp += icebuck[i];

		if (tmp > result)result = tmp;
	}
}