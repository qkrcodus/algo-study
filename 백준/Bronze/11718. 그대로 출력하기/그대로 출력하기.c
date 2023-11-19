#include <stdio.h>

int main() {
    char a[101];

    while(scanf("%[^\n]", a) != EOF) {
        printf("%s\n", a);
        getchar(); // %[^\n]을 사용해 \n이 나올 때까지 입력받고 \n을 버퍼에 남겨두었을 것이므로 제거해준다.
    }

    return 0;
}