#include <stdio.h>
#include <stdlib.h>
/* <stdlib.h> はexit関数の利用のために必要 */
/* プログラミング入門ハンドアウトのLec12-23 (p.67)を参照のこと */
 
int main() {
    char c; /* 文字読み取り用の変数 */
    int count = 0; /* 読み取り文字数記録用の変数 */
	int lcount = 0; /* 読み取り行数記録用の変数 */
    
    /* 入力用と出力用の二つのファイルポインタの宣言 */
    /* 複数のファイルポインタを一度に宣言する場合の書式は */
    /* ハンドアウトLec03-14 (p.97) を参照 */
    FILE *fpin, *fpout;
 
    /* 入力用ファイルinput1.txtを読み出し指定でオープン */
    /* エラーが生じた場合は標準エラー出力にメッセージを表示して終了 */
    if((fpin = fopen("input1.txt", "r")) == NULL){
        fprintf(stderr, "Failed to open: input1.txt\n");
        exit(1);
    }
 
    /* 出力用ファイルoutput1.txtを書き込み指定でオープン */
    /* エラーが生じた場合は標準エラー出力にメッセージを表示 */
    /* 既に開いている入力用ファイルはクローズしてから終了 */
    if((fpout = fopen("output1.txt", "w")) == NULL){
        fprintf(stderr, "Failed to open: output1.txt\n");
        fclose(fpin);
        exit(2);
    }
 
    /* 入力用ファイルから1文字づつ読み取るのをループで繰り返し */
    /* 読み取った文字をprintfで表示するとともに出力用ファイルに書き出し */
    /* 読み取った文字数と行数も記録する */
    /* ファイル終端まで到達したらループ終了 */
    /* 文字の読み取りとファイル終端到達判断の書き方は */
    /* ハンドアウトLec03-8 (p.95)、Lec03-9, -11, -12 (p.96) などを参照し */
    /* 文字の読み取りと結果の代入、条件判断を同時に行うこと */
    while((c = fgetc(fpin)) != EOF){
        printf("%c", c);
        fprintf(fpout, "%c", c);
        count++;
		if(c == '\n') lcount++;
    }
    
    /* 読み取った文字数を含むメッセージを標準エラー出力に表示 */
    fprintf(stderr, "%d characters / %d lines are read and copied.\n", count, lcount);
 
    /* 入力用と出力用の二つのファイルをクローズ */
    fclose(fpin);
    fclose(fpout);
 
    return 0;
 
}
