#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *f1, txt[128];
    int total=0, highest=0;
    int one=0, two=0, three=0;

    FILE *file;
    
    f1 = "day1input.txt";
    file = fopen(f1, "r");

    while(fgets(txt, 512, file)) {
        printf(">%d\n", atoi(txt));
        if(atoi(txt) == 0) {
            printf("Total = %d, Highest = %d\n", total, highest);
            
            if(total > one) {
                three = two;
                two = one;
                one = total;
                printf("1\n");
            }
            else if(total > two) {
                three = two;
                two = total;
                printf("2\n");
            }
            else if(total > three) {
                three = total;
                printf("3\n");
            }
            total = 0;
            printf("%d, %d, %d\n", one, two, three);

        }
        total += atoi(txt);
    }

    if(total > one) {
        three = two;
        two = one;
        one = total;
        printf("1\n");
    }
    else if(total > two) {
        three = two;
        two = total;
        printf("2\n");
    }
    else if(total > three) {
        three = total;
        printf("3\n");
    }

    printf("Total = %d, Highest = %d\n", total, highest);
    printf("%d, %d, %d\n", one, two, three);
    printf("Top 3 = %d\n", one+two+three);
        

    return 1;
}