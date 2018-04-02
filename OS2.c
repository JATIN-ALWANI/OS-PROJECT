#include<stdio.h>
void main()
{

struct prior
{
	char pname[10];
	int arrival_time,burst_time,waiting_time,waiting_t,turnaround;
	float priority;
}pr[6],pr1[6],temp;

int n,i;
printf("\t\tenter no. of processes:\t");
scanf("%d",&n);

for(i=0;i<n;i++)
{
	printf("\nenter process %d name:",i+1);
	scanf("%s",&pr[i].pname);
	
	printf("enter arrival time:");
	scanf("%d",&pr[i].arrival_time);
	
	printf("enter burst time:");
	scanf("%d",&pr[i].burst_time);
	
	printf("enter waiting time(as per shortest job first):");
	scanf("%d",&pr[i].waiting_time);
	
	pr[i].priority=1+((float)pr[i].waiting_time/(float)pr[i].burst_time);
	printf("priority of %s is:%f\n\n",pr[i].pname,pr[i].priority);
}
