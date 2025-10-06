#include <stdio.h>

double seqavg_static(double new_data);

int main(void)
{
    double input_data;
    double average;
    int data_count = 0;
    
    printf("入力データ: ");
    while (scanf("%lf", &input_data) == 1) {
        data_count++;
        average = seqavg_static(input_data);
        printf("データ数:%d，平均:%f\n", data_count, average);
        printf("入力データ: ");
    }
    
    printf("最終結果はデータ数%dで、平均値%fでした\n", data_count, average);
    
    return 0;
}

double seqavg_static(double new_data)
{
    static double static_avg = 0.0;
    static int static_count = 0;
    
    static_count++;
    static_avg = (static_avg * (static_count - 1) + new_data) / static_count;
    
    return static_avg;
}
