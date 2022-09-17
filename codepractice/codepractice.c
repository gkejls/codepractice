#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	list<int> josephus;
	list<int>::iterator it;
	vector<int> answer;

	int n, k;
	cin >> n >> k;

	// 연결 리스트 초기화
	for (int i = 1; i <= n; i++) {
		josephus.push_back(i);
	}

	it = josephus.begin();

	// 요세푸스 순열 생성
	while (!josephus.empty()) {
		for (int i = 0; i < k - 1; i++) {
			it++;

			// 맨 끝에 도달했으면 다시 처음으로 돌아감
			if (it == josephus.end()) {
				it = josephus.begin();
			}
		}

		answer.push_back(*it);
		it = josephus.erase(it);

		// 맨 끝에 도달했으면 다시 처음으로 돌아감
		if (it == josephus.end()) {
			it = josephus.begin();
		}
	}

	// 요세푸스 순열 출력
	cout << "<";
	for (int i = 0; i < n; i++) cout << answer[i] << (i < n - 1 ? ", " : "");
	cout << ">\n";

	return 0;
}