#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int num;        /* 読み込む数値 */
    int max = 0;    /* 最大値（初期値：0） */
    int min = INT_MAX; /* 最小値（初期値：INT_MAX） */
    int sum = 0;    /* 読み取った数値の合計 */
    int count = 0;  /* 読み取った数値の数 */
    
    FILE *fpin, *fpout;
    
    /* 入力用ファイルinput2.txtを読み出し指定でオープン */
    if((fpin = fopen("input2.txt", "r")) == NULL){
        fprintf(stderr, "Failed to open: input2.txt\n");
        exit(1);
    }
    
    /* 出力用ファイルresult2.txtを書き込み指定でオープン */
    if((fpout = fopen("result2.txt", "w")) == NULL){
        fprintf(stderr, "Failed to open: result2.txt\n");
        fclose(fpin);
        exit(2);
    }
    
    /* ファイルから数値を1つずつ読み込み、最大値・最小値との比較・更新を行う */
    while(fscanf(fpin, "%d", &num) == 1){
        /* 最大値との比較・更新 */
        if(num > max){
            max = num;
        }
        
        /* 最小値との比較・更新 */
        if(num < min){
            min = num;
        }
        
        /* 合計と個数の更新 */
        sum += num;
        count++;
    }
    
    /* 結果をresult2.txtに出力 */
    fprintf(fpout, "max = %d, min = %d, ave = %.6f\n", max, min, (double)sum / count);
    
    /* ファイルをクローズ */
    fclose(fpin);
    fclose(fpout);
    
    return 0;
}
