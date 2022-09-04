#include <iostream>
#include <algorithm>
using namespace std;
int dairy_product[100000];

// 내림차순
bool DESC(int a, int b) {
	return a > b;
}

int main() {
	int N;
	int sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> dairy_product[i];
	}

	// 내림차순으로 정렬
	sort(dairy_product, dairy_product + N, DESC);

	for (int i = 0; i < N; i++) {

		// 3개씩 묶은 것 중 가장 작은 값 (3번째 값, 배열이므로 i+1)
		if ((i + 1) % 3 == 0) {
			continue;	// 계산하지 않음
		}
		else {
			sum += dairy_product[i];
		}
	}

	cout << sum;

	return 0;
}
