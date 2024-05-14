#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define kFlightsSize 10
#define kInputSize 31
struct Flight
{
    char *destination;
    char *date;
};

void fillFlightInfo(struct Flight *flight, char destination[], char date[]);

void printFlightInfo(struct Flight flights[]);

int main(void)
{
    struct Flight flights[kFlightsSize] = {0};
    char destinationInput[kInputSize] = "";
    char dateInput[kInputSize] = "";

    fillFlightInfo(&flights[0], "Kyoto", "25/12/2024");

    for (int i = 0; i < kFlightsSize; i++)
    {
        printf("Please input your destination: ");
        fgets(destinationInput, kInputSize, stdin);

        printf("Please inpute the date: ");
        fgets(dateInput, kInputSize, stdin);
    }
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

void printFlightInfo(struct Flight flights[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("Destination: %s   Date:%s", flights[i].destination, flights[i].date);
    }
}