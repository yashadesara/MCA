#include<stdio.h>

void main()
{
    int a=20,b=10,c=10,d=10,e=10,total,avg;
    float af=20.5,bf=10.5,cf=10.5,df=10.5,ef=10.5,totalf,avgf;
    
    total = a+b+c+d+e;
    avg = total/5;
    
    totalf = af+bf+cf+df+ef;
    avgf = totalf/5;
    
    printf("int data \n");
    printf("total is: %d \n",total);
    printf("avg is: %d \n",avg);
    
    printf("float data \n");
    printf("total is: %f \n",totalf);
    printf("avg is: %f \n",avgf);
}