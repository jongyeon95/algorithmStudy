#include <stdio.h>
 
int main() {
    char input[100];
    scanf("%s ", input);
 
    int idx = -1;
    while (input[++idx]) {
        printf("%c", input[idx]);
        if (idx % 10 == 9) puts("");
    }
    return 0;
}