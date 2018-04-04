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
int min_ar=pr[0].arrival_time;
int k=0;
pr1[0]=pr[0];
for(i=1;i<n;i++)
{
	if(pr[i].arrival_time<=min_ar)
	{
		min_ar=pr[i].arrival_time;
		pr1[0]=pr[i];
		k=i;
	}
}
printf("minimum arr time:%d of process %s\n",min_ar,pr[k].pname);

int j;
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(pr[j].priority>pr[j+1].priority)
		{
			temp=pr[j];
			pr[j]=pr[j+1];
			pr[j+1]=temp;
		}
	}
}

printf("\nsequence of execution :");
for(i=0;i<n;i++)
{
	printf("\t%s->",pr[i].pname);
}

pr[0].waiting_t=pr[0].waiting_time;
pr[0].turnaround=pr[0].waiting_t+pr[0].burst_time;
int tot=pr[0].turnaround;

for(i=1;i<n;i++)
{
	pr[i].waiting_t=tot-pr[i].arrival_time;
	pr[i].turnaround=pr[i].waiting_t+pr[i].burst_time;
	tot=tot+pr[i].burst_time;
}

for(i=0;i<n;i++)
{
	printf("\n\nprocess %s\n",pr[i].pname);
	printf("************************************************");
	printf("\nWaiting time=%d",pr[i].waiting_t);
	printf("\nTurn around time=%d\n\n",pr[i].turnaround);
}

int Avg_wait,Avg_turnaround;
for(i=0;i<n;i++)
{
	Avg_wait+=pr[i].waiting_t;
	Avg_turnaround+=pr[i].waiting_t;
}
printf("-------------------------------------------------------------------");
printf("\n\t\tAverage Waiting Time:\t%d\n",Avg_wait);
printf("\n\t\tAverage turn around time:%d\t",Avg_turnaround);	
printf("\n-----------------------------------------------------------------");
}
