#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c; /* 文字読み取り用の変数 */
    FILE *fpin, *fpout;
 
    /* 入力用ファイルinput1.txtを読み出し指定でオープン */
    /* エラーが生じた場合は標準エラー出力にメッセージを表示して終了 */
    if((fpin = fopen("input1.txt", "r")) == NULL){
        fprintf(stderr, "Failed to open: input1.txt\n");
        exit(1);
    }
 
    /* 出力用ファイルoutput1b.txtを書き込み指定でオープン */
    /* エラーが生じた場合は標準エラー出力にメッセージを表示 */
    /* 既に開いている入力用ファイルはクローズしてから終了 */
    if((fpout = fopen("output1b.txt", "w")) == NULL){
        fprintf(stderr, "Failed to open: output1b.txt\n");
        fclose(fpin);
        exit(2);
    }
 
    /* 1回目の読み込み：input1.txtの内容をそのまま標準出力に表示し、output1b.txtに書き込み */
    while((c = fgetc(fpin)) != EOF){
        printf("%c", c);
        fprintf(fpout, "%c", c);
    }
    
    /* 入力用ファイルをクローズ */
    fclose(fpin);
    
    /* output1b.txtに改行を書き込み、1行空ける */
    fprintf(fpout, "\n\n");
    
    /* 再度input1.txtを開く */
    if((fpin = fopen("input1.txt", "r")) == NULL){
        fprintf(stderr, "Failed to open: input1.txt\n");
        fclose(fpout);
        exit(1);
    }
    
    /* 2回目の読み込み：小文字を大文字に変換してoutput1b.txtに書き込み */
    while((c = fgetc(fpin)) != EOF){
        if(islower(c)) {
            c = toupper(c);
        }
        fprintf(fpout, "%c", c);
    }
 
    /* 入力用と出力用の二つのファイルをクローズ */
    fclose(fpin);
    fclose(fpout);
 
    return 0;
}
