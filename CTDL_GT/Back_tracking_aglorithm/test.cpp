#include <stdio.h>  // so N dc viet = tong cac so tu 1 den chinh no liet ke cac cach 
int daySo[10000];

void printSolution(int a) {
    for (int i = 0; i < a-1; i++) printf("%d + ", daySo[i]);
    printf("%d\n", daySo[a-1]);    
}

void TRY(int a, int left) {
    for (int i = 1; i <= left; i++)
    {
        daySo[a] = i;
        left = left - i;
        a++;
        if (left==0) printSolution(a);
        else TRY(a, left);
        left = left + i;
        a--;
    }
    
}

int main() {
    int N;
    scanf("%d", &N);
    int left = N;
    TRY(0, left);
    return 0;
}