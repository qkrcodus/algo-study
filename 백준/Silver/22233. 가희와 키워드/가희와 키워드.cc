#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M;
	cin >> N >> M;

	unordered_set<string> keywords;
	vector<int> results;

	//키워드 받아서 undordered set 저장
	for (int i = 0; i < N; i++) {
		string keyword;
		cin >> keyword;
		keywords.insert(keyword);
	}
	cin.ignore();
	//남은 키워드 처리 vector 저장
	for (int i = 0; i < M; i++) {
		string line;
		getline(cin, line);
		stringstream ss(line);// , 구분된 키워드 추출하기 위해 stringstream으로 변환
		string keyword;
		while (getline(ss, keyword, ',')) {
			//find 메서드 keyword 없다면 end()와 같은 반복자 반환
			if (keywords.find(keyword) != keywords.end()) {
				keywords.erase(keyword);
			}
		}
		results.push_back(keywords.size());
	}



	// 결과 출력
	for (int result : results) {
		cout << result << "\n";
	}

	return 0;

}