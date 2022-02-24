#include <stdio.h>
#include <math.h>
int main()
{
   float x, y, z, s, p;
   printf("Enter circle x,y and radius: ");
   scanf("(%f, %f, %f)", &x, &y, &z);
   {
      s = M_PI * z * z;
      p = M_PI * z * 2;
      printf("Perimetr: %f\nS: %f", s, p);
   }
   return 0;
}
