/*Linear Regression*/ 

#include<stdio.h> 

#include<conio.h> 

#include<alloc.h> 

void main() 

{ 

float *x,*y,n,i,x1=0,x12=0,y1=0,x1y1=0,a1,a0,e; 

puts("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"); 

printf("How many values You are Entering"); 

scanf("%f",&n); 

puts("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"); 

x=(float*)malloc(n*4); 

y=(float*)malloc(n*4); 

puts("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"); 

puts("Enter coressponding Elements X & Y"); 

for(i=0;i<n;i++) 

{ 

scanf("%f %f",&x[i],&y[i]); 

x1+=x[i]; 

y1+=y[i]; 

x1y1+=(x[i]*y[i]); 

x12+=(x[i]*x[i]); 

} 

a1=(n*x1y1-x1*y1)/(n*x12-x1*x1); 

a0=y1/n-a1*x1/n; 

e=y[0]-a0-a1*x[0]; 

a0+=e; 

puts("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"); 

printf("\nY=%f+%fX",a0,a1); 

puts("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"); 

} 
