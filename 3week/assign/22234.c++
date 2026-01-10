#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, T, W, px, tx, cx, M;
queue<vector<int>> line;

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	cin >> N >> T >> W;

	for (int i = 0; i < N; i++) {
		cin >> px >> tx;
		line.push({ px,tx,0 });
	}
	
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> px >> tx >> cx;
		line.push({ px,tx,cx });
	}

	for (int i = 0; i < W; i++) {
		if (line.front()[2] <= i) {
			if (line.front()[1] > T) {
				if (i + T >= W) {
					for (i; i < W; i++) {
						cout << line.front()[0] << "\n";
						return 0;
					}
				}

				for (int j = 0; j < T; j++)
					cout << line.front()[0] << "\n";
				i += T - 1;
				line.front()[1] -= T;
				line.front()[2] += T;
				line.push(line.front());
				line.pop();
			}
			else {
				if (i + line.front()[1] >= W) {
					for (i; i < W; i++) {
						cout << line.front()[0] << "\n";
						return 0;
					}
				}

				for (int j = 0; j < line.front()[1]; j++)
					cout << line.front()[0] << "\n";
				i += line.front()[1] - 1;
				line.pop();
			}
		}
		else {
			line.push(line.front());
			line.pop();
			i--;
		}
	}

	return 0;
}