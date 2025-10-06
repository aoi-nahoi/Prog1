#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* 乱数初期設定に必要 */
#define ROW 6
#define COL 10
 
 
int main()
{
  int array[ROW][COL];
  int n=0,data;
  int i,j;
  int count = 0; /* 該当する数値の個数をカウント */
 
  /* データ作成 */
  srand((unsigned int)time(NULL)); /* 乱数初期設定 */
  for (i=0; i<ROW; i++) {
    for (j=0; j<COL; j++) {
      array[i][j]=rand()%100+1; /* 1-100の乱数生成 */
    }
  }
 
  printf("正の整数を入力して下さい：");
  scanf("%d",&data);
 
  /* 配列の各要素をチェックして表示 */
  for (i=0; i<ROW; i++) {
    for (j=0; j<COL; j++) {
      /* 入力された整数以上で割り切れるかチェック */
      if (array[i][j] >= data && array[i][j] % data == 0) {
        printf("%4d*", array[i][j]);
        count++;
      } else {
        printf("%4d ", array[i][j]);
      }
    }
    printf("\n"); /* 行の終わりで改行 */
  }
  
  /* 該当する数値の個数を表示 */
  if (count > 0) {
    printf("%d以上かつ%dで割り切れる値は%d個ありました\n", data, data, count);
  } else {
    printf("%d以上かつ%dで割り切れる値はありませんでした\n", data, data);
  }
 
  return 0;
}
