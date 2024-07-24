#include <iostream>
#include <algorithm>
using namespace std; 
int main() {
    int N, M, locate[100010];
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> locate[i];
    }

    int maxDis = 0;
    for (int i = 1; i < M; i++) {
        if (locate[i] - locate[i-1] > maxDis)
            maxDis = locate[i]-locate[i-1];
    }
    
    if (maxDis % 2 == 0)
        maxDis = maxDis/2;
    else
        maxDis = maxDis/2 + 1;
    
    cout << max(locate[0], max(N-locate[M-1], maxDis));
}