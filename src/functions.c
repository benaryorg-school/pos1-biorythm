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
    if(pruefeDatum(d1,m1,y1)||pruefeDatum(d2,m2,y2))
    {
        return -1;
    }
	struct tm t1=
	{
		.tm_sec=0,
		.tm_min=0,
		.tm_hour=0,
		.tm_mday=d1,
		.tm_mon=m1,
		.tm_year=y1,
	};
	struct tm t2=
	{
		.tm_sec=0,
		.tm_min=0,
		.tm_hour=0,
		.tm_mday=d2,
		.tm_mon=m2,
		.tm_year=y2,
	};
    return (int)(difftime(mktime(&t2),mktime(&t1))/86400);
}

double calc(int days,int val)
{
    return sin(2*(days%val)*M_PI/val);
}

