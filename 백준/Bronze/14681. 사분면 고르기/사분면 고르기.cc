// cpp

#include <iostream>

int main(){

    int x,y;

    scanf("%i %i", &x,&y);

    bool x_positive = x>0, y_positive = y>0;

    if (x_positive && y_positive)

        printf("%i", 1);

    else if (x_positive && !y_positive)

        printf("%i", 4);

    else if (!x_positive && y_positive)

        printf("%i", 2);

    else 

        printf("%i", 3);

}