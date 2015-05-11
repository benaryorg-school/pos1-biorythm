#include <functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
    static char buf[0x1000];
    int day,month,year;
    printf("Please enter a valid date(dd/mm/yyyy): ");
    readDate(&day,&month,&year);

    if(pruefeDatum(day,month,year))
    {
        printf("Invalid date!\n");
        return 1;
    }

    time_t sec;
    struct tm *sys;
    time(&sec);
    sys=localtime(&sec);

    int d=tage(day,month,year,sys->tm_mday,sys->tm_mon,sys->tm_year+1900);

    printf("\n\n%18s  |%10s  |%10s  |%10s\n","days from today","physical","emotional","psychical");

    int i;
    for(i=0;i<30;i++)
    {
        if(i)
        {
            sprintf(buf,"in %d days",i);
        }
        else
        {
            strcpy(buf,"today");
        }
        printf("%-18s  |%10.2lf  |%10.2lf  |%10.2lf\n",buf,physisch(d+i),emotionell(d+i),geistig(d+i));
    }

    return 0;
}

