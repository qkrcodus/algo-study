#include <stdio.h>
#include <string.h>  


int main() {
	char str[16];//15개의 문자만 받음 +널문자까지
	scanf("%s", str);
	int i = 0, sum = 0, len = strlen(str);// 널문자 전까지 출력
	while (len > 0) {
		if (str[i] < 'P') {
			sum += (str[i] - 'A') / 3 + 3;
		}
		else if (str[i] < 'T') {
			sum += 8;
		}
		else if (str[i] < 'W') {
			sum += 9;
		}
		else {
			sum += 10;
		}
		i++;
		len--;

	}
	printf("%d\n", sum);
}


