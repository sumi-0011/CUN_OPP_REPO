#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    char* s = malloc(sizeof(char) * 100);     // ���ڿ� �����͸� �����ϰ� malloc���� �޸𸮸� �Ҵ�

    printf("%s\n","���ڿ��� �Է��ϼ���(100�� �̳�).");   //cmdâ�� ���ڿ� ���
    scanf("%s", s);    

    printf("�Էµ� ���ڴ� %s�Դϴ�.\n", s);
    free(s);
    return 0;
}