#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int N; vector<string> ans;
stack<char> vps;
string str;

int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;

		for (char c : str) {
			if (c == '(') {
				vps.push(c);
			}
			else if (!vps.empty()) {
				if (c == ')' && vps.top() == '(')
					vps.pop();
			}
			else {
				vps.push(c);
				break;
			}
		}

		if (vps.empty()) ans.push_back("YES");
		else ans.push_back("NO");

		while (!vps.empty())
			vps.pop();
	}

	for (string& s : ans)
		cout << s << "\n";


	return 0;
}