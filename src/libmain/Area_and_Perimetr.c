#include "Area_and_Perimetr.h"
#include "Check_intersection.h"
#include "Read.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
float all[9] = {0};

float for_treug_area(float digit_treug[])
{
    float area, p1, a, b, c, x1 = digit_treug[2], x2 = digit_treug[4],
                             x3 = digit_treug[6], y1 = digit_treug[3],
                             y2 = digit_treug[5], y3 = digit_treug[7];
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    if (a > 0 || b > 0 || c > 0) {
        p1 = (a + b + c) / 2;
        area = sqrtf(p1 * (p1 - a) * (p1 - b) * (p1 - c));
    } else {
        return 0;
    }
    return area;
}
float for_treug_perimetr(float digit_treug[])
{
    float perimetr, a, b, c, x1 = digit_treug[2], x2 = digit_treug[4],
                             x3 = digit_treug[6], y1 = digit_treug[3],
                             y2 = digit_treug[5], y3 = digit_treug[7];
    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    if (a > 0 || b > 0 || c > 0) {
        perimetr = a + b + c;
    } else {
        return 0;
    }
    return perimetr;
}

void for_all_circle(float digit_treug[], float digit_circle[])
{
    int i;
    for (i = 0; i < 6; i++) {
        all[i] = digit_treug[i];
    }
    for (i = 0; i < 3; i++) {
        all[i + 6] = digit_circle[i];
    }
    if (cross(all)) {
        printf("NOT CROSSING\n");
    } else {
        printf("CROSSING\n");
    }
}

float for_circle_area(float digit_circle[])
{
    if (digit_circle[2] < 0) {
        return 0;
    }
    float area, rad = digit_circle[2];
    area = rad * rad * M_PI;

    return area;
}

float for_circle_perimetr(float digit_circle[])
{
    if (digit_circle[2] < 0) {
        return 0;
    }
    float perimetr, rad = digit_circle[2];
    perimetr = rad * 2 * M_PI;
    return perimetr;
}
