#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN 6
#define DRAW 3
#define LOSE 0

void part1(void);
void part2(void);

int main(int argc, char **argv) {
    int tasknum;
    printf("Type part number: ");
    scanf("%d", &tasknum);

    if(tasknum == 1) {
        part1();
    }
    else {
        part2();
    }

    return 0;
}

void part1(void) {
    char *f1, txt[128], themChar[4], meChar[4];
    int me=0, them=0, roundScore=0, totalScore=0;

    FILE *file;
    f1 = "day2input.txt";
    file = fopen(f1, "r");

    while(fgets(txt, 512, file)) {
        sscanf(txt, "%c %c", themChar, meChar);
        if(*themChar == 'A') {
            them = 1;
        }
        else if(*themChar == 'B') {
            them = 2;
        }
        else {
            them = 3;
        }
        if(*meChar == 'X') {
            me = 1;
        }
        else if(*meChar == 'Y') {
            me = 2;
        }
        else {
            me = 3;
        }        

        /* Comparison begins */
        if(me == them) {
            roundScore = me + DRAW;
        }
        else if(me == 3) {
            if(them == 2) {
                roundScore = me + WIN;
            }
            else if(them == 1) {
                roundScore = me + LOSE;
            }
        }
        else if(me == 2) {
            if(them == 1) {
                roundScore = me + WIN;
            }
            else if(them == 3) {
                roundScore = me + LOSE;
            }
        }
        else if(me == 1) {
            if(them == 3) {
                roundScore = me + WIN;
            }
            else if(them == 2) {
                roundScore = me + LOSE;
            }
        }
        totalScore += roundScore;
        roundScore = 0;
    }
    printf("totalScore = %d\n", totalScore);
    return;
}

void part2(void) {
    char *f1, txt[128], themChar[4], meChar[4];
    int me=0, them=0, roundScore=0, totalScore=0;

    FILE *file;
    f1 = "day2input.txt";
    file = fopen(f1, "r");

    while(fgets(txt, 512, file)) {
        sscanf(txt, "%c %c", themChar, meChar);
        if(*themChar == 'A') { /* Rock */
            them = 1;
        }
        else if(*themChar == 'B') { /* Paper */
            them = 2;
        }
        else { /* Scissors */
            them = 3;
        }
        if(*meChar == 'X') {
            me = 1;
        }
        else if(*meChar == 'Y') {
            me = 2;
        }
        else {
            me = 3;
        }        

        /* Comparison begins */
        /* X=Lose Y=Draw Z=Win */
        if(me == 1) {
            if(them == 1)
                roundScore = 3 + LOSE;
            else if(them == 2)
                roundScore = 1 + LOSE;
            else
                roundScore = 2 + LOSE;
        }
        else if(me == 2) {
            if(them == 1)
                roundScore = 1 + DRAW;
            else if(them == 2)
                roundScore = 2 + DRAW;
            else
                roundScore = 3 + DRAW;
        }
        else {
            if(them == 1)
                roundScore = 2 + WIN;
            else if(them == 2)
                roundScore = 3 + WIN;
            else
                roundScore = 1 + WIN;
        }
        totalScore += roundScore;
        roundScore = 0;
    }
    printf("totalScore = %d\n", totalScore);
    return;
}