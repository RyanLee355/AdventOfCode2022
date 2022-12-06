#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char *f1, txt[128];
    int total=0, highest=0;

    FILE *file;
    
    f1 = "day1input.txt";
    file = fopen(f1, "r");

    
        while(fgets(txt, 512, file)) {

            if(atoi(txt) == 0) {
                printf("Total = %d\n", total);
                if(total > highest) {
                    highest = total;
                }
                total = 0;
            }

            total += atoi(txt);

            printf(">%d\n", atoi(txt));
        }
        printf("Total = %d\n", total);
        printf("Highest = %d", highest);

        


}