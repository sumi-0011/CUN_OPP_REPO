#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    char* s = malloc(sizeof(char) * 100);     // 문자열 포인터를 선언하고 문자열 할당

    printf("문자열을 입력하세요(100자 이내).\n");
    scanf("%s", s);    

    printf("입력된 문자는 %s입니다.\n", s);
    free(s);
    return 0;
}