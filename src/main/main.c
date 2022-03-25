#include "libmain/areaCircle.h"
#include "libmain/checkEndStr.h"
#include "libmain/perimeterCircle.h"
#include "libmain/skipCircle.h"
#include "libmain/skipDigit.h"
#include "libmain/skipSign.h"
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256
#define _USE_MATH_DEFINES
#define PI 3.1415926535

int main()
{
    char str[SIZE];
    char* cursor = str;
    char* startcursor = str;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e', '\0'};
    double x1, y1, radius;

    printf("Enter circle(x y, r):\n");

    fgets(str, SIZE, stdin);

    if ((cursor = skipCircle(cursor, startcursor, circle)) == NULL) {
        printf("expected '<circle>'\n");
        return -1;
    }

    if ((cursor = skipSign(cursor, '(')) == NULL) {
        printf("expected '('\n");
        return -2;
    }

    if ((cursor = skipDigit(cursor, &x1)) == NULL) {
        printf("expected '<double>'\n");
        return -3;
    }

    if ((cursor = skipDigit(cursor, &y1)) == NULL) {
        printf("expected '<double>'\n");
        return -4;
    }

    if ((cursor = skipSign(cursor, ',')) == NULL) {
        printf("expected ','\n");
        return -5;
    }

    if ((cursor = skipDigit(cursor, &radius)) == NULL) {
        printf("expected '<double>'\n");
        return -6;
    }

    if (radius <= 0) {
        printf("The radius cannot be negative or equal 0\n");
        return -7;
    }

    if ((cursor = skipSign(cursor, ')')) == NULL) {
        printf("expected ')'\n");
        return -8;
    }

    if ((cursor = checkEndStr(cursor)) == NULL) {
        printf("An unexpected token at the end of a line\n");
        return -9;
    }

    perimeterCircle(radius);
    areaCircle(radius);

    printf("\nFigure name: %s\n", circle);
    printf("x = %lf\n", x1);
    printf("y = %lf\n", y1);
    printf("radius = %lf\n", radius);
    printf("perimeter = %lf \n", perimeterCircle(radius));
    printf("area = %lf\n \n", areaCircle(radius));

    return 0;
}
