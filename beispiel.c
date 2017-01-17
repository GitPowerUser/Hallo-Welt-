* beispiel.c
 *
 *  Created on: 26.02.2015
 *      Author: pyme04
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#define EXIT_SUCCESS 0

unsigned int fib(unsigned int n)
{
int i, f1=0, f2=1, f3;
if (n<2) return n;
for (i=2;i<=n;i++)
{
f3 = f1 + f2;
f1 = f2;
f2 = f3;
}
return f2;
}


int istEinSchaltjahr(const unsigned int uJahr)
{
  if ((uJahr % 400) == 0)
    return 1;
  else if ((uJahr % 100) == 0)
    return 0;
  else if ((uJahr % 4) == 0)
    return 1;

  return 0;
}

short getWochentag(const unsigned short int uTag, const unsigned short int uMonat, const unsigned short int uJahr)
{
//                                 ungült Jan Feb Mrz Apr Mai Jun Jul Aug Sep Okt Nov Dez
unsigned char arrMonatsOffset[13] = {  0,  0,  3,  3,  6,  1,  4,  6,  2,  5,  0,  3,  5};

unsigned char cbTagesziffer;
unsigned char cbMonatsziffer;
unsigned char cbJahresziffer;
unsigned char cbJahrhundertziffer;

short nErgebnis = 0;


cbTagesziffer = uTag % 7;
cbMonatsziffer = arrMonatsOffset[uMonat];
cbJahresziffer = ((uJahr % 100) + ((uJahr % 100) / 4)) % 7;
cbJahrhundertziffer = (3 - ((uJahr / 100) % 4)) * 2;

// check month day
if ((uTag > 31) || (uMonat > 12) || (uMonat <= 0) || (uTag <= 0) || (uJahr <= 0))
{
  return -1;
}

  //correction of leap-year:
  if ((uMonat <= 2) && (istEinSchaltjahr(uJahr)))
    cbTagesziffer = cbTagesziffer + 6;

  nErgebnis = (cbTagesziffer + cbMonatsziffer + cbJahresziffer + cbJahrhundertziffer) % 7;

  // Results:
  // 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday , 6 = Saturday
  return nErgebnis;
}




int main(int argc, char *argv[])
{

int i,var_srand;
unsigned short int uTag;
unsigned short int uMonat;
unsigned short int uJahr;
short nErgebnis = 0;
time_t t;

printf("Geben Sie das Jahr ein:\n");
scanf("%u", &uJahr);
printf("input Value = %u\n", uJahr);

printf("Geben Sie das Monat ein:\n");
scanf("%u", &uMonat);
printf("input Value = %u\n", uMonat);

printf("Geben Sie das Tag ein:\n");
scanf("%u", &uTag);
printf("input Value = %u\n", uTag);

nErgebnis=getWochentag(uTag, uMonat, uJahr);

if(nErgebnis==0)
	printf("Wochentag= Sonntag\n");
else if (nErgebnis==1)
	printf("Wochentag= Montag\n");
else if (nErgebnis==2)
	printf("Wochentag= Dienstag\n");
else if (nErgebnis==3)
	printf("Wochentag= Mittwoch\n");
else if (nErgebnis==4)
	printf("Wochentag= Donnerstag\n");
else if (nErgebnis==5)
	printf("Wochentag= Freitag\n");
else if (nErgebnis==6)
	printf("Wochentag= Samstag\n");
        else("Wochentag= Fehler\n");

return EXIT_SUCCESS;
}





/* Intializes random number generator * /
	var_srand=srand((unsigned) time(&t));
	printf("srand=%u\n",var_srand);*/
/*
for (i=0;i<10;i++)
printf("fib(%u)=%u\n",i,fib(i));

for (i=0;i<100;i++)
{
	printf("rand(%d)=%d\n",i,rand() % 50 + 1);
}
*/
