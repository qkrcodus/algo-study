#include <stdio.h>
#include <string.h>  

void change(char str[], char result[]);

int main() {
	char str1[4] = { 0 }; //마지막 널 문자를 위해서 
	char str2[4] = { 0 };
	char Str1[4] = { 0 };
	char Str2[4] = { 0 };

	scanf("%s %s", str1, str2);

	// change 함수를 통해 str1과 str2를 Str1과 Str2에 넣기
	change(str1, Str1);
	change(str2, Str2);

	// 비교할 때 strcmp 함수 사용
	if (strcmp(Str1, Str2) > 0)
		printf("%s", Str1);
	else
		printf("%s", Str2);

	return 0;
}

void change(char str[], char result[]) {
	int temp = 0;
	temp = str[0];
	result[0] = str[2];
	result[2] = temp;
	result[1] = str[1];
}

