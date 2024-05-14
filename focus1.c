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

void fillFlightInfo(struct Flight *flight, char destination[], char date[])
{
    size_t destinationLength = strlen(destination);
    size_t dateLength = strlen(date);

    flight->destination = (char *)malloc(destinationLength + 1);

    if (flight->destination == NULL)
    {
        printf("Memory not available");
        return;
    }

    strcpy(flight->destination, destination);

    flight->date = (char *)malloc(dateLength + 1);

    if (flight->date == NULL)
    {
        printf("Memory not availble");
        return;
    }

    strcpy(flight->date, date);
}