#include <stdio.h>
#include <stdlib.h>
#include <bbgpio.h>
#include <unistd.h>
#include <time.h>

double vtoc(double v) {
    double mv =  (v / 4096) * 1800;
    return (mv - 500) /10;
}

double ctof(double c) {
    return ((c * 9) /5 ) + 32;
}

void logReadingToFile(char* file, double volts) {
    time_t rawtime;
    char buffer[256];
    struct tm * timeinfo;
    char timeBuffer[256];
    double celsius = vtoc(volts);
    double fahrenheit = ctof(celsius);

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime (timeBuffer,256,"%D %r",timeinfo);
    sprintf(buffer, "%s\t%f\t%f\t%f\n", timeBuffer, volts, celsius, fahrenheit);
    FILE *fd;

    fd = fopen(file, "a");
    fputs(buffer, fd);

    fclose(fd);
}

int main(void) {

    loadADC();

    while(1) {
        logReadingToFile("temp-log", analogRead(0));

        //sleep for 30 mins.
        sleep(60 * 30);
    }

    return 0;
}
