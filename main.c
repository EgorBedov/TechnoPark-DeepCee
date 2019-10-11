#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynArray.h"
#include "DayWeather.h"

void input(DayWeather** new_day);
void printStats(size_t days, DynArray *dyn_array);

void run() {
    printf("How many days you want to enter? - ");
    size_t num = 0;
    char buffer[50];
    scanf("%s", buffer);
    num = atoi(buffer);
    while (!num) {
        puts("Invalid string!");
        scanf("%s", buffer);
        num = atoi(buffer);
    }

    DynArray *week_1 = NULL;
    new_DynArray(&week_1);


    puts("Precipitations: CLOUDY=1, FOG=2, RAIN=3, SHOWER=4, THUNDERSTORM=5, SNOW=6");
    for (size_t iii = 0; iii < num; iii++) {
        DayWeather *new_day = NULL;
        input(&new_day);

        Add(week_1, new_day);

        free(new_day);

        // char *str;
        // str = (char *)malloc(MAX_LEN * sizeof(char));
        // strcpy(str, print_weather_forecast(week_1->buffer[iii]));
        // printf("%s", str);
    }

    puts("Statistics for how many days? (1=today)");
    size_t stat = 0;
    scanf("%s", buffer);
    stat = atoi(buffer);
    while (!stat || stat > week_1->real_size) {
        puts("Invalid string!");
        scanf("%s", buffer);
        stat = atoi(buffer);
    }

    printStats(stat, week_1);

    delete_DynArray(week_1);
}

int main() {

    // run();
    return 0;
}

void input(DayWeather** new_day) {
    char buffer[50];
    *new_day = malloc(sizeof(DayWeather));

    // Input temperature
    printf("\nTemperature: ");
    scanf("%s", buffer);
    float temper = 0;
    char *endptr;
    temper = strtof(buffer, &endptr);
    while ( endptr == buffer ) {
        puts("Invalid string!");
        scanf("%s", buffer);
        temper = strtof(buffer, &endptr);
    }

    // Input precipitations
    printf("Precipitations: ");
    precipitations prec = NONE;
    while ( !prec ) {
        size_t temp = 0;
        scanf("%s", buffer);
        temp = atoi(buffer);
        switch (temp) {
            case 1: prec = CLOUDY;          break;
            case 2: prec = FOG;             break;
            case 3: prec = RAIN;            break;
            case 4: prec = SHOWER;          break;
            case 5: prec = THUNDERSTORM;    break;
            case 6: prec = SNOW;            break;
            default:puts("Invalid string!");break;
        }
    }

    // Input wind speed
    printf("Wind speed: ");
    float ws = 0;
    scanf("%s", buffer);
    ws = strtof(buffer, &endptr);
    while ( endptr == buffer ) {
        puts("Invalid string!");
        scanf("%s", buffer);
        ws = strtof(buffer, &endptr);
    }

    // Commit changes :)
    (*new_day)->temperature = temper;
    (*new_day)->precipitation = prec;
    (*new_day)->wind_speed = ws;
}

void printStats(size_t days, DynArray *dyn_array) {
    float stat = 0;
    for (int iii = 0; iii < days; iii++) {
        stat += dyn_array->buffer[iii].temperature;
    }
    stat /= days;
    printf("%f", stat);
}