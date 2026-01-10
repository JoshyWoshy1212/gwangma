#include <iostream>
#include <stack>

using namespace std;

int K, ans = 0 , N;
stack<int> stk;

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> N;

		if (N == 0)stk.pop();
		else stk.push(N);
	}

	while (!stk.empty()) {
		ans += stk.top();
		stk.pop();
	}

	cout << ans;

	return 0;
}