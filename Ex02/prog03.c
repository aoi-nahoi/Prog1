#include <stdio.h>

#define MAX_ST_NUM 50                   /* 学生数の最大値 */
#define MAX_SCORE 115                   /* 115点満点 */
int student_id[MAX_ST_NUM];             /* 学籍番号  */
int abs_score[MAX_ST_NUM];              /* 点数 (補正前) */
char abs_grade[MAX_ST_NUM];             /* 補正前の評価 (A - F) */
int rel_score[MAX_ST_NUM];              /* 点数 (補正後) */
char rel_grade[MAX_ST_NUM];             /* 補正後の評価 (A - F) */
int grade_dist[2][5];                   /* 評価の分布 [0]:補正前, [1] 補正後 */
                                        /* 例 grade_dist[0][0] 補正前の Fの人数 */
char cgrade[5]={'F','D','C','B','A'};   /* 評価（A - F） */
int num_student;                        /* 実際に成績を読み込んだ学生の数 */
double abs_ave=0.0;                     /* 平均点（補正前） */
double rel_ave=0.0;                     /* 平均点（補正後） */

int calib(int score);                   /* 満点の補正を行う。内部では実数で計算し、小数点第１位で四捨五入した整数を返す */
char score_to_grade(int score);         /* 点数から評価を求める */
int grade_to_index(char grade);         /* 評価からcgrade配列用添字を求める */
void adjust_score(void);                /* 点数を補正し、補正後の点数の配列に書きこむ */
void print_grade(void);                 /* 補正前と後の点数と評価を表示 */
void print_stat(void);                  /* 統計と評価分布を表示 */

int main()
{
    int i;
    
    /* 標準入力から学籍番号と点数を読みこむ */
    num_student = 0;
    while (scanf("%d %d", &student_id[num_student], &abs_score[num_student]) == 2) {
        num_student++;
    }
    
    adjust_score();  /* 点数を補正し、補正後の点数の配列に書きこむ。*/
                     /* 補正前・補正後の各学生の評価(A～F)を決定し、それぞれ
                        平均点と評価分布を求める*/
    print_grade();   /* 補正前と後の点数と評価を表示。実行例参照 */
    print_stat();    /* 統計と評価分布を表示。フォーマットは実行例参照 */
    return 0;
}

int calib(int score)
{
    double corrected = (double)score * 100.0 / 115.0;
    return (int)(corrected + 0.5);  /* 小数点第1位で四捨五入 */
}

char score_to_grade(int score)
{
    if (score >= 80) return 'A';
    else if (score >= 65) return 'B';
    else if (score >= 50) return 'C';
    else if (score >= 35) return 'D';
    else return 'F';
}

int grade_to_index(char grade)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (cgrade[i] == grade) {
            return i;
        }
    }
    return -1;  /* エラー */
}

void adjust_score(void)
{
    int i;
    int abs_sum = 0, rel_sum = 0;
    
    /* 評価分布を初期化 */
    for (i = 0; i < 5; i++) {
        grade_dist[0][i] = 0;  /* 補正前 */
        grade_dist[1][i] = 0;  /* 補正後 */
    }
    
    for (i = 0; i < num_student; i++) {
        /* 補正前の評価を決定 */
        abs_grade[i] = score_to_grade(abs_score[i]);
        grade_dist[0][grade_to_index(abs_grade[i])]++;
        abs_sum += abs_score[i];
        
        /* 補正後の点数を計算 */
        rel_score[i] = calib(abs_score[i]);
        
        /* 補正後の評価を決定 */
        rel_grade[i] = score_to_grade(rel_score[i]);
        grade_dist[1][grade_to_index(rel_grade[i])]++;
        rel_sum += rel_score[i];
    }
    
    /* 平均点を計算 */
    abs_ave = (double)abs_sum / num_student;
    rel_ave = (double)rel_sum / num_student;
}

void print_grade(void)
{
    int i;
    
    printf(" ID   点数 評価 点数 評価\n");
    printf("      (補正前)  (補正後)\n");
    printf("-------------------------\n");
    
    for (i = 0; i < num_student; i++) {
        printf(" %d   %3d %c   %3d %c\n", 
               student_id[i], abs_score[i], abs_grade[i], 
               rel_score[i], rel_grade[i]);
    }
    printf("-------------------------\n");
}

void print_stat(void)
{
    printf("統計\n");
    printf("学生数 %d人 補正前平均点 %.1f点　補正後平均点 %.1f点\n", 
           num_student, abs_ave, rel_ave);
    printf("評価分布\n");
    printf("補正前 A %d B %d C %d D %d F %d \n", 
           grade_dist[0][4], grade_dist[0][3], grade_dist[0][2], 
           grade_dist[0][1], grade_dist[0][0]);
    printf("補正後 A %d B %d C %d D %d F %d \n", 
           grade_dist[1][4], grade_dist[1][3], grade_dist[1][2], 
           grade_dist[1][1], grade_dist[1][0]);
}
