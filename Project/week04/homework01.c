#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    char* s = malloc(sizeof(char) * 100);     // ���ڿ� �����͸� �����ϰ� ���ڿ� �Ҵ�

    printf("���ڿ��� �Է��ϼ���(100�� �̳�).\n");
    scanf("%s", s);    

    printf("�Էµ� ���ڴ� %s�Դϴ�.\n", s);
    free(s);
    return 0;
}