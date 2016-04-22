#include <stdio.h>
#include <stdlib.h>
#include <bbbgpio.h>
#include <unistd.h>

#define blueLed 60
#define buttonPin 44

double vtoc(double v) {
    double mv =  (v / 4096) * 1800;
    return (mv - 500) /10;
}

double ctof(double c) {
    return ((c * 9) /5 ) + 32;
}

int main(void) {

    loadADC();

    double celsius = 0;
    double fahrenheit = 0;

    while(1) {
        celsius = vtoc(analogRead(0));
        fahrenheit = ctof(celsius);

        printf("celsius %f - fahrenheit %f\n", celsius, fahrenheit);

        sleep(5);
    }

    return 0;
}
