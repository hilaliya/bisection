// Hilal YILMAZ -511606002  (Fibonacci Search & Bisection Search)

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

double func(double x, int terms, double coef[], double deg[])
{
	double z=0;
	for(int i=0; i<terms; i++)
	{
		z= z + coef[i]*pow(x, deg[i]);	
	}	
	return z;	
}
double dif(double x, int terms, double coef[], double deg[])
{
	double z=0;
	for(int i=0; i<terms; i++)
	{
		z= z + coef[i]*deg[i]*pow(x, deg[i]-1);	
	}	
	return z;
}


int main(){
	
cout<<"\nEnter the number of terms in your function: ";
int terms;
cin>> terms;

double coef[terms];
for(int i=0; i<terms; i++)
{
	cout<<"\nEnter the coefficient of "<<i+1<<". term: ";	
	cin>>coef[i];
}

double deg[terms];
for(int i=0; i<terms; i++)
{
	cout<<"\nEnter the degree of "<<i+1<<". term: ";	
	cin>>deg[i];
}

cout<<"\n\nYour function is ";

cout<<"f(x)=";
for(int i=0; i<terms; i++)
{
	cout<<" "<<coef[i]<<"x^"<<deg[i];
}


cout<<"\n\n\nEnter the interval \n";
double a,b;
cout<<"\nMinimum value of x: ";
cin>>a;
cout<<"\nMaximum value of x: ";
cin>>b;		
cout<<"\nThe Interval is ["<<a<<","<<b<<"]\n"; 	

cout<<"\n\nEnter the number of iterations: ";
int n;
cin>>n;

cout<<"\nSearch method: Bisection";

		double lamda=(a+b)/2;
				
		for(int i=1; i<=n; i++)
		{
			if(dif(lamda,terms,coef,deg)==0){ cout<<"\nThe optimal point is "<<lamda<<endl;break;	}	   
			else if(dif(lamda,terms,coef,deg)>0)	b=lamda;
			else if(dif(lamda,terms,coef,deg)<0)	a=lamda;
			lamda=(a+b)/2;		
		}
		
		cout<<"\nOptimal solution lies in the interval ["<<a<<","<<b<<"].\n";
		cout<<"f("<<a<<")="<<func(a,terms,coef,deg)<<"\n";
		cout<<"f("<<b<<")="<<func(b,terms,coef,deg)<<"\n";	
}
		
		
		
		

