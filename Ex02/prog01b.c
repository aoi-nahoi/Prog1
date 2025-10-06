#include <stdio.h>

double global_avg = 0.0;
int global_count = 0;

void seqavg_global(double new_data);

int main(void)
{
    double input_data;
    
    printf("入力データ: ");
    while (scanf("%lf", &input_data) == 1) {
        seqavg_global(input_data);
        printf("データ数:%d，平均:%f\n", global_count, global_avg);
        printf("入力データ: ");
    }
    
    printf("最終結果はデータ数%dで、平均値%fでした\n", global_count, global_avg);
    
    return 0;
}

void seqavg_global(double new_data)
{
    global_count++;
    global_avg = (global_avg * (global_count - 1) + new_data) / global_count;
}
