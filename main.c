#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415
#define rad PI / 180
#define DURATION 30 
double sineHeight(double);
int main() {
    system("clear");
    printf("HELLO THERE!\n");
    system("sleep 1");
     
    for (int i = 0; i < DURATION; i++) {
        double vals[DURATION];
        for (int j = 0; j < DURATION; j++) {
            vals[j] = sineHeight(((double)180/DURATION) * (i + j) * rad); 
        }

        for (int lin = 0; lin < 10; lin++) {
            for (int col = 0; col < DURATION; col++) {
                if (fabs(fabs(vals[col]) -((double)lin + 0.5)/10) < 0.1)
                    printf(".");
                else printf(" ");
            }
            printf("\n");
        }
        system("sleep 1");
        system("clear");
    }
    return 0;
}


double sineHeight(double arg) {
    return sin(arg);
}

