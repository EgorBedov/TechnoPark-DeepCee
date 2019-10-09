#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "DynArray.h"
#include "DayWeather.h"

void input(DayWeather** new_day);

int main() {

    puts("How many days you want to enter?");
    size_t num = 0;
    char buffer[50];
    scanf("%s", buffer);
    num = atoi(buffer);
    while( !num ) {
        puts("Invalid string!");
        scanf("%s", buffer);
        num = atoi(buffer);
    }

    DynArray *week_1 = NULL;
    new_DynArray(&week_1);

    for (size_t iii = 0; iii < num; iii++) {
        DayWeather* new_day = NULL;
        input(&new_day);

        Add(week_1, new_day);

        free(new_day);

        char *str;
        str = (char *)malloc(MAX_LEN * sizeof(char));
        strcpy(str, print_weather_forecast(week_1->buffer[iii]));
        printf("%s", str);
    }

    delete_DynArray(week_1);
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
    puts("Precipitations: CLOUDY=1, FOG=2, RAIN=3, SHOWER=4, THUNDERSTORM=5, SNOW=6");
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
    (*new_day)->temperature = temper;
    (*new_day)->precipitation = prec;
    (*new_day)->wind_speed = ws;
}