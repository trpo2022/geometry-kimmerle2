#include "Read.h"
#include "Area_and_Perimetr.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 256
float digit_treug[8] = {0};
float digit_circle[3] = {0};

void circle_f(char str[])
{
    int i = 0, c = 0;
    bool flag_c = false;

    while (str[i] != ')') {
        flag_c = false;
        if ((0x30 <= str[i] && str[i] <= 0x39) && str[i - 1] != '.') {
            if (str[i - 1] == '-') {
                flag_c = true;
            }
            if (str[i + 1] == '.') {
                digit_circle[c] = (str[i] & 0x0F) + (str[i + 2] & 0x0F) * 0.1;
                if (flag_c == true) {
                    digit_circle[c] *= -1;
                }
                c++;
            } else {
                digit_circle[c] = str[i] & 0x0F;
                if (flag_c == true) {
                    digit_circle[c] *= -1;
                }
                c++;
            }
        }
        i++;
    }
    printf("%s\n", str);
    if ((for_circle_area(digit_circle) && for_circle_perimetr(digit_circle))
        > 0) {
        printf("\nAREA CIRCLE: %.2f\nPERIMETR CIRCLE: %.2f\n",
               for_circle_area(digit_circle),
               for_circle_perimetr(digit_circle));
    }
    printf("\n");
    for_all_circle(digit_treug, digit_circle);
}

void triangle_f(char str[])
{
    int i = 0, c = 0;
    bool flag_t = false;

    while (str[i] != ')') {
        flag_t = false;
        if ((0x30 <= str[i] && str[i] <= 0x39) && str[i - 1] != '.') {
            if (str[i - 1] == '-') {
                flag_t = true;
            }
            if (str[i + 1] == '.') {
                digit_treug[c] = (str[i] & 0x0F) + (str[i + 2] & 0x0F) * 0.1;
                if (flag_t == true) {
                    digit_treug[c] *= -1;
                }
                c++;
            } else {
                digit_treug[c] = str[i] & 0x0F;
                if (flag_t == true) {
                    digit_treug[c] *= -1;
                }
                c++;
            }
        }
        i++;
    }
    printf("%s\n", str);
    if ((for_treug_area(digit_treug) && for_treug_perimetr(digit_treug)) > 0) {
        printf("\nPERIMETR TRIANGLE: %.2f\nAREA TRIANGLE: %.2f\n",
               for_treug_perimetr(digit_treug),
               for_treug_area(digit_treug));
    }
}

void Read()
{
    char str[size];
    FILE* input;
    if ((input = fopen("input.txt", "r")) == NULL) {
        perror("Error. File not found.\n");
        _Exit(1);
    }
    while ((fgets(str, size, input)) != 0) {
        if (str[0] == 'c')
            circle_f(str);
        if (str[0] == 't')
            triangle_f(str);
    }
}
