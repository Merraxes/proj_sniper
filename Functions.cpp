#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"


int test()
{
    return rand() % 100;

}

int randomValue()
{
    return 50 + rand() % 45;
}

int weather(int d)
{
     int c=9;
     int e=rand() % 2;
     if (e==0 ){
        if (d>=c) d-=c;
        else if (d<=(100-c)) d+=c;}
     else  if (e==1 )
            if (d<=(100-c)) d+=c;
            else if (d>=c) d-=c;


     return d;

}

void weather_desription(int d)
{
    int a=d;
    printf("%s\t","Status pogody: " );
    if (a==0) printf("%s\n\t","idealne warunki na strzelanie...." );
    else if ((a>=1)&&(a<=4)) printf("%s\n\t","slaby deszcz..." );
    else if ((a>=5)&&(a<=6)) printf("%s\n\t","deszcz z wiatrem..." );
    else printf("%s\n\t","silny wiatr i ulewa" ) ;
}
