#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <tuple>
using namespace std;

//그래프 알고리즘
//정점과 간선들로 구성된 그래프, 객체 간 연결관계를 표현하는데 적합한 그래프 알고리즘
//그 중 가장 낮은 비용으로 사이클 형성하지 않으며 모든 정점을 연결하는 최소 신장 트리
//MST는 크루스칼, 프림 알고리즘 사용
//크루스칼 과정
//1. 간선들 가중치 오름차순으로 정렬
//2. 사이클 형성하지 않게 오름차순으로 정렬된 간선들 하나씩 선택
//사이클의 존재 여부는 추가하려는 간선의 부모가 집합에 포함되는지를 확인해보면 된다.
//union-find  알고리즘
//주로 배열을 사용하여 각 요소의 부모 노드를 저장
//3. 해당 간선을 MST 집합에 추가

vector <tuple<int, int, int>> edges;
//가중치, 시작점, 끝점 모두 int 타입인데 왜 튜플 사용하는지
//벡터==배열은 동적으로 메모리 할당 가능하다. 튜플은 불가능
//명시적으로 고정된 크기를 갖는 구조임을 표현 가능, 접근 속도도 빠르다

vector <int> parent(100001, -1); 
//union-find 배열 초기화 -1은 모든 요소가 독립적인 상태임을 뜻함

// Union-Find Find 함수
int find(int x) 
//x의 루트 노드를 찾는
{
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

// Union-Find Union 함수
bool unionSet(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false; // 이미 같은 그룹
	parent[b] = a; // b의 부모를 a로 설정
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M; cin >> N >> M; 
	//입력 받음
	for (int i = 0; i < M; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		edges.push_back(make_tuple(weight, start, end));
	}
	//오름차순으로 정렬
	sort(edges.begin(), edges.end());

	long long totalCost = 0;
	int maxWeight = 0; // 가장 큰 간선의 가중치 저장

	for (auto& edge : edges) {
		int weight, u, v;
		tie(weight, u, v) = edge;
		if (unionSet(u, v)) { // 사이클이 형성되지 않으면 간선을 추가
			totalCost += weight;
			maxWeight = max(maxWeight, weight); // 최대 가중치 업데이트
		}
	}
	// 최대 가중치 간선을 제외한 총 비용 출력
	cout << totalCost - maxWeight << "\n";
}
