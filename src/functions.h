#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int readDate(int *,int *,int *);
int leapyear(int);
int pruefeDatum(int,int,int);
int tage(int,int,int,int,int,int);
double calc(int,int);

#define physisch(x) calc((x),23)
#define emotionell(x) calc((x),28)
#define geistig(x) calc((x),33)

#endif /** FUNCTIONS_H **/

