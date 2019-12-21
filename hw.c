#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>


double incremental_deposit(double percent, double years, double sum);		//prototype of function
double capitalized_deposit(double percent, double years, double sum);		//prototype of function

/*
===========
VAERPROJECT 
===========
*/

int main (void){

	//TASK16

	double percentRate = 0;
	double yearsPeriod = 0;
	double sum = 0;

	do
	{
		printf("\nEnter rate of percent: ");
		scanf("%lf", &percentRate);
		printf("\nEnter period of years: ");
		scanf("%lf", &yearsPeriod);
		printf("\nEnter sum of deposit: ");
		scanf("%lf", &sum);

		printf("\n************************************************");
		printf("\nTotal sum for the period is(simple %%):\t%.2lf", incremental_deposit(percentRate, yearsPeriod, sum) );
		printf("\n------------------------------------------------");
		printf("\nTotal sum the period is(capitalized %%):\t%.2lf\n", capitalized_deposit(percentRate, yearsPeriod, sum) );
		printf("************************************************");
		printf("\n");
		
	}while(true);
	
	
	return 0;
}


//TASK16

//function that calculate % of money if U use simple increment deposit

double incremental_deposit(double percent, double years, double sum)
{
	double benefit = 0;
	double result = 0;

	for(int i = 1; i <= years; i++)
	{
		benefit += (sum * percent) / 100;
	}

	result = sum + benefit;

	return result;
} 

//function that calculate % of money if U use capitalized deposit (complicated %)

double capitalized_deposit(double percent, double years, double sum)
{
	double counter = 0;
	double result = 0;
	double incrementSum = 0;

	for(int i = 1; i <= years; i++)
	{
		counter = (incrementSum + sum) * percent / 100;
		incrementSum += counter;
	}

	result = sum + incrementSum;

	return result;
}
