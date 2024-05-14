#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Flight
{
    char *destination;
    char *date;
};

void fillFlightInfo(struct Flight *flight, char destination[], char date[]);

void printFlightInfo(struct Flight flights[]);

int main(void)
{
    return 0;
}