#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define kFlightsSize 2
#define kInputSize 30
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

    // fillFlightInfo(&flights[0], "Kyoto", "25/12/2024");

    for (int i = 0; i < kFlightsSize; i++)
    {
        char destinationInput[kInputSize] = "";
        char dateInput[kInputSize] = "";

        printf("Please input your destination: ");
        fgets(destinationInput, kInputSize, stdin);
        destinationInput[strcspn(destinationInput, "\n")] = 0;

        printf("Please inpute the date: ");
        fgets(dateInput, kInputSize, stdin);
        dateInput[strcspn(dateInput, "\n")] = 0;

        fillFlightInfo(&flights[i], destinationInput, dateInput);
    }

    printFlightInfo(flights);

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
    for (int i = 0; i < kFlightsSize; i++)
    {
        printf("%-35s %-35s\n", flights[i].destination, flights[i].date);
    }
}