#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define PI 3.1415
#define rad PI / 180
#define DURATION 100
#define clear() printf("\033[H\033[J")

double sineHeight(double);

int main() {
    clear();

    struct timespec remaining, requested;
     
    for (int i = 0; i < DURATION; i++) {
        double vals[DURATION];
        for (int j = 0; j < DURATION; j++) {
            vals[j] = sineHeight(((double)180 / DURATION) * (i + j) * rad); 
        }

        for (int lin = 0; lin < 10; lin++) {
            for (int col = 0; col < DURATION; col++) {
                if (fabs(fabs(vals[col]) -((double)lin + 0.5)/10) < 0.1)
                    printf(".");
                else printf(" ");
            }
            printf("\n");
        }
        requested.tv_sec = 0;
        requested.tv_nsec = 70000000;
        nanosleep(&requested, &remaining);
        clear();
    }
    return 0;
}


double sineHeight(double arg) {
    return sin(arg);
}

