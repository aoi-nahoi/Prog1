#include <stdio.h>

double seqavg_local(double new_data, double prev_avg, int prev_count);

int main(void)
{
    double input_data;
    double average = 0.0;
    int data_count = 0;
    
    printf("入力データ: ");
    while (scanf("%lf", &input_data) == 1) {
        data_count++;
        average = seqavg_local(input_data, average, data_count - 1);
        printf("データ数:%d，平均:%f\n", data_count, average);
        printf("入力データ: ");
    }
    
    printf("最終結果はデータ数%dで、平均値%fでした\n", data_count, average);
    
    return 0;
}

double seqavg_local(double new_data, double prev_avg, int prev_count)
{
    double new_avg = (prev_avg * prev_count + new_data) / (prev_count + 1);
    return new_avg;
}
