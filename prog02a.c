#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isAlpha(char c);

int main() {
    char c;
    
    printf("Input any characters: ");
    
    while (1) {
        scanf("%c", &c);
        
        // 改行文字の場合はループを終了
        if (c == '\n') {
            break;
        }
        
        if (isAlpha(c)) {
            printf("'%c': %3d in Decimal / 0x%02x in Hexadecimal. It's an alphabetic character.\n", c, c, c);
        } else {
            printf("'%c': %3d in Decimal / 0x%02x in Hexadecimal. It's a non-alphabetic character.\n", c, c, c);
        }
    }
    
    return 0;
}

int isAlpha(char c) {
    // 大文字A-Z (ASCII 65-90) または小文字a-z (ASCII 97-122) かどうかを判定
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return TRUE;
    } else {
        return FALSE;
    }
}
