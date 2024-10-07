#include <stdio.h>

void findCombinations(int score, int td2pt, int td1pt, int td, int fg, int safety) {
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, td1pt, td, fg, safety);
        return;
    }
    if (score >= 8) findCombinations(score - 8, td2pt + 1, td1pt, td, fg, safety);
    if (score >= 7) findCombinations(score - 7, td2pt, td1pt + 1, td, fg, safety);
    if (score >= 6) findCombinations(score - 6, td2pt, td1pt, td + 1, fg, safety);
    if (score >= 3) findCombinations(score - 3, td2pt, td1pt, td, fg + 1, safety);
    if (score >= 2) findCombinations(score - 2, td2pt, td1pt, td, fg, safety + 1);
}

int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) break;
        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);
        findCombinations(score, 0, 0, 0, 0, 0);
    }
    return 0;
}