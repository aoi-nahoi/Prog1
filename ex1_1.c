#include <stdio.h>

int main() {
    char c;
    
    printf("文字を入力してください: ");
    scanf("%c", &c);
    
    printf("'%c': 10進数で%d / 16進数で0x%x\n", c, c, c);
    
    return 0;
}
