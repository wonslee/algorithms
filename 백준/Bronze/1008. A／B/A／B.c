#include <stdio.h>
#include <float.h>

int main(){
    double a,b;
    scanf("%lf %lf", &a,&b);
    // printf("%.20f\n", a/b);
    // printf("%.17g\n", a/b);
    // .*e : maximum precision
    printf("%.*e\n",DECIMAL_DIG, a/b);
    return 0;
}