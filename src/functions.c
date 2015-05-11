#include <functions.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int readDate(int *day,int *month,int *year)
{
    static char buf[0x1000];
    *buf=0;

    fgets(buf,sizeof(buf),stdin);

    return sscanf(buf,"%d/%d/%d",day,month,year)!=3;
}

int leapyear(int year)
{
    return !(year%400)||(!(year%4)&&(year%100));
}

int pruefeDatum(int day,int month,int year)
{
    static int days[]={31,0,31,30,31,30,31,31,30,31,30,31};//static array
    days[1]=leapyear(year)?29:28;
    return !(month>0&&month<=12&&day>0&&day<=days[month-1]);//return valid
}

int tage(int d1,int m1,int y1,int d2,int m2,int y2)
{
    static int days[]={31,0,31,30,31,30,31,31,30,31,30,31};//static array
    if(pruefeDatum(d1,m1,y1)||pruefeDatum(d2,m2,y2))
    {
        return -1;
    }
    if(y1>y2||(y1==y2&&(m1>m2||(m1==m2&&d1>d2))))//date2>date1
    {
        y1^=y2;
        y2^=y1;
        y1^=y2;
        m1^=m2;
        m2^=m1;
        m1^=m2;
        d1^=d2;
        d2^=d1;
        d1^=d2;
    }
    days[1]=leapyear(y1)?29:28;
    int s;
    for(s=0;!(y1>y2||(y1==y2&&(m1>m2||(m1==m2&&d1>d2))));s++)
    {
        d1++;
        if(d1>days[m1-1])
        {
            d1=1;
            m1++;
        }
        if(m1>12)
        {
            m1=1;
            y1++;
            days[1]=leapyear(y1)?29:28;
        }
    }
    return s-1;
}

double calc(int days,int val)
{
    return sin(2*(days%val)*M_PI/val);
}

