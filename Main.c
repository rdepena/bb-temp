#include <stdio.h>
#include <string.h>
#include <bbgpio.h>

#define PIN 0

double vtoc(double v) {
    double mv =  (v / 4096) * 1800;
    return (mv - 500) /10;
}

double ctof(double c) {
    return ((c * 9) /5 ) + 32;
}

typedef enum
{
    celsius,
    fahrenheit
} measurement;

measurement unitOfMeasurement(int c, char** argv) {
    for (int i =1; i < c; i++) {
        if(strstr(argv[i], "-f")){
            return fahrenheit;
        }
        else if (strstr(argv[i], "-c")){
            return celsius;
        }
    }
    return fahrenheit;
}

int main(int argc, char** argv) {
    loadADC();
    double tmpInVolts = analogRead(PIN);
    double tmpInC = vtoc(tmpInVolts);
    measurement units = unitOfMeasurement(argc, argv);
    if (units == celsius) {
        printf("%4.2f\n", tmpInC);
    } else {
        printf("%4.2f\n", ctof(tmpInC));
    }
    unLoadADC();
    return 0;
}
