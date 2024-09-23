#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//그리디는 우리의 직관이 맞다는 것만 증명하면 된다.
//직관 : 제일 비싼 금액부터 고른다.
//증명 방법
//1. 귀류법 : 거짓을 가정하고 모순이 발견되면 참이다.
//ex)  루트 2 가 무리수임을 증명
//
//제일 비싼 걸 쓰지 않았을 때 최적의 해라고 가정하자.
//배수 조건 때문에 위 가정이 모순
//따라서 가장 비싼 동전부터 쓴다.

int greedy(vector<int>& array , int amount) {
	int num = 0;
	reverse(array.begin(),array.end());
	for (int coin : array) {
		num += amount / coin;
		amount = amount % coin;
	}
	return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count, amount;
	cin >> count >> amount;
	vector <int> array(count);
	for (int i=0;i<count;i++){
		cin >> array[i];
	}
	int result=greedy(array,amount);
	cout << result;

}