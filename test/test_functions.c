#include <ctest.h>
#include <libmain/Area_and_Perimetr.h>
#include <libmain/Check_intersection.h>
#include <stdio.h>
#define size_intersects 9
#define size_circle 3
#define size_triangle 3

float intersects[size_intersects];
float circle_points[size_circle];
float triangle_points[size_triangle];

CTEST(geometry_suite, simple_intersection_0)
{
    const int exp = 0;
    intersects[0] = 3.2, intersects[1] = 2, intersects[2] = 1.5,
    intersects[3] = 2.8, intersects[4] = 1.5, intersects[5] = 5,
    intersects[6] = 0, intersects[7] = 1, intersects[8] = 2.5;
    int res = cross(intersects);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_intersection_1)
{
    const int exp = 1;
    intersects[0] = 3.2, intersects[1] = 15, intersects[2] = 1.5,
    intersects[3] = 2.8, intersects[4] = 1.5, intersects[5] = 5,
    intersects[6] = 0, intersects[7] = 1, intersects[8] = 0.5;
    int res = cross(intersects);
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_area_circle)
{
    const double exp = 28.274333882308139146163790449516;
    circle_points[0] = 1.5, circle_points[1] = 2.3, circle_points[2] = 3;
    double res = for_circle_area(circle_points);
    ASSERT_DBL_NEAR(exp, res);
}

CTEST(geometry_suite, simple_area_treug)
{
    triangle_points[0] = 2, triangle_points[1] = 1, triangle_points[2] = 4,
    triangle_points[3] = 3, triangle_points[4] = 5, triangle_points[5] = 9;
    const double exp = 10.5;
    double res = for_treug_area(triangle_points);
    ASSERT_DBL_NEAR(exp, res);
}

CTEST(geometry_suite, simple_perimetr_circle)
{
    circle_points[0] = 1.5, circle_points[1] = 2.3, circle_points[2] = 6;
    const double exp = 37.699111843077518861551720599354;
    double res = for_circle_perimetr(circle_points);
    ASSERT_DBL_NEAR(exp, res);
}

CTEST(geometry_suite, simple_perimetr_treug)
{
    triangle_points[0] = 2, triangle_points[1] = 1, triangle_points[2] = 4,
    triangle_points[3] = 3, triangle_points[4] = 5, triangle_points[5] = 9;
    const double exp = 21.378393;
    double res = for_treug_perimetr(triangle_points);
    ASSERT_DBL_NEAR(exp, res);
}
