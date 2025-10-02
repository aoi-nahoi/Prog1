#include <stdio.h>

int main() {
    char c;
    
    printf("任意の文字を入力してください: ");
    
    while (1) {
        scanf("%c", &c);
        
        // 改行文字の場合はループを終了
        if (c == '\n') {
            break;
        }
        
        printf("'%c': 10進数で%d / 16進数で0x%x\n", c, c, c);
    }
    
    return 0;
}
