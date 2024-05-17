#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_day_of_week(int year, int month, int day) {
    struct tm date = {0};
    date.tm_year = year - 1900;  // tm_year is years since 1900
    date.tm_mon = month - 1;     // tm_mon is 0-based
    date.tm_mday = day;

    mktime(&date);  // Normalize the tm structure and set the weekday

    char buffer[16];
    strftime(buffer, sizeof(buffer), "%A", &date);
    printf("%d.%d.%d is a %s\n", year, month, day, buffer);
}

void print_month_calendar(int year, int month) {
    struct tm date = {0};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    mktime(&date);  // Normalize the tm structure

    int days_in_month = 31 - (month == 4 || month == 6 || month == 9 || month == 11) - 2 * (month == 2) + ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && month == 2);
    
    printf("Calendar for %d-%02d:\n", year, month);
    printf("Mo Tu We Th Fr Sa Su\n");

    // Set to the first day of the month
    date.tm_mday = 1;
    mktime(&date);
    int start_day = date.tm_wday;  // 0 is Sunday

    for (int i = 0; i < (start_day + 6) % 7; i++) {
        printf("   ");
    }

    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);
        if ((start_day + day) % 7 == 0) {
            printf("\n");
        }
    }

    if ((start_day + days_in_month) % 7 != 0) {
        printf("\n");
    }
}

void print_year_calendar(int year) {
    for (int month = 1; month <= 12; month++) {
        print_month_calendar(year, month);
        printf("\n");
    }
}

int main() {
    char input[20];
    printf("Enter a date (yyyy.mm.dd, yyyy.mm, yyyy, or 'now'): ");
    fgets(input, 20, stdin);
    input[strcspn(input, "\n")] = 0;  // Strip newline character

    if (strcmp(input, "now") == 0) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        strftime(input, sizeof(input), "%Y.%m.%d", t);
        printf("Current date is: %s\n", input);
    } else if (strlen(input) == 4) {  // yyyy
        int year = atoi(input);
        print_year_calendar(year);
    } else if (strlen(input) == 7) {  // yyyy.mm
        int year, month;
        sscanf(input, "%d.%d", &year, &month);
        print_month_calendar(year, month);
    } else if (strlen(input) == 10) {  // yyyy.mm.dd
        int year, month, day;
        sscanf(input, "%d.%d.%d", &year, &month, &day);
        print_day_of_week(year, month, day);
    } else {
        printf("Invalid input format.\n");
    }

    return 0;
}
