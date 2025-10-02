#include <stdio.h>

char score2Grade(int score);
int grade2Point(char grade);

int main() {
    int score, credit;
    int total_credits = 0;
    double total_gp_credits = 0.0;
    
    printf("Input score and credit (Ctrl+D to stop): ");
    
    while (scanf("%d %d", &score, &credit) == 2) {
        char grade = score2Grade(score);
        int gp = grade2Point(grade);
        
        printf("Grade for %d is %c, Grade Point (GP) is %d. (%d credits)\n", 
               score, grade, gp, credit);
        
        total_credits += credit;
        total_gp_credits += gp * credit;
        
        printf("Input score and credit (Ctrl+D to stop): ");
    }
    
    if (total_credits > 0) {
        double gpa = total_gp_credits / total_credits;
        printf("Grade Point Average (GPA): %.3f, (Total credits: %d)\n", 
               gpa, total_credits);
    } else {
        printf("No data entered.\n");
    }
    
    return 0;
}

char score2Grade(int score) {
    if (score >= 80 && score <= 100) {
        return 'A';
    } else if (score >= 65 && score <= 79) {
        return 'B';
    } else if (score >= 50 && score <= 64) {
        return 'C';
    } else if (score >= 35 && score <= 49) {
        return 'D';
    } else if (score >= 0 && score <= 34) {
        return 'F';
    } else {
        // 範囲外の場合はFを返す
        return 'F';
    }
}

int grade2Point(char grade) {
    switch (grade) {
        case 'A':
            return 4;
        case 'B':
            return 3;
        case 'C':
            return 2;
        case 'D':
        case 'F':
            return 0;
        default:
            return 0;
    }
}
