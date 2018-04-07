#include<stdio.h>

void main()
{

struct prior
{
	char pname[10];
	int arrival_time,burst_time;
	float waiting_time,waiting_t,turnaround;
	float priority;
	
}pr[6],pr1[6],temp;

int n,i;
printf("\t\t enter no. of processes:\t");
scanf("%d",&n);								//n=number of processes

for(i=0;i<n;i++)
{
	printf("\nenter process %d name:",i+1);
	scanf("%s",&pr[i].pname);               //name->process name
	
	printf("enter arrival time:");
	scanf("%d",&pr[i].arrival_time);		//arrival_time->process arrival time
	
	printf("enter burst time:");
	scanf("%d",&pr[i].burst_time);			//burst_time->process burst time
	
	printf("enter waiting time(as per shortest job first):");
	scanf("%f",&pr[i].waiting_time);							//waiting_time for process when shortest job first
	
	pr[i].priority=1+((float)pr[i].waiting_time/(float)pr[i].burst_time); //calculating priority as per (1+ waiting time/burst time)
	printf("priority of %s is:%f\n\n",pr[i].pname,pr[i].priority);		
}

float min_ar=pr[0].arrival_time;
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
printf("minimum arr time:%f of process %s\n",min_ar,pr[k].pname);  //min_ar=> minimum arrival time among processes

int j;
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(pr[j].priority>pr[j+1].priority)				//compairing priorities and sorting as per priorities
		{
			temp=pr[j];
			pr[j]=pr[j+1];				
			pr[j+1]=temp;
		}
	}
}
printf("\n-------------------------------------------------------------------------------");
printf("\nsequence of execution :");
for(i=0;i<n;i++)
{
	printf("\t%s->",pr[i].pname);						//printing sequence of execution of processes as per priority scheduling
}
printf("\n-------------------------------------------------------------------------------");

pr[0].waiting_t=pr[0].waiting_time;						//waiting_t==>waiting time when priority scheduling
pr[0].turnaround=pr[0].waiting_t+pr[0].burst_time;		//turnaround==>turn around time for each process
int tot=pr[0].turnaround;

for(i=1;i<n;i++)
{
	pr[i].waiting_t=tot-pr[i].arrival_time;				//calculating waiting time of processes in priority scheduling
	pr[i].turnaround=pr[i].waiting_t+pr[i].burst_time;
	tot=tot+pr[i].burst_time;
}

for(i=0;i<n;i++)
{
	printf("\n\nprocess %s\n",pr[i].pname);
	printf("************************************************");
	printf("\nWaiting time=%f",pr[i].waiting_t);					
	printf("\nTurn around time=%f\n\n",pr[i].turnaround);
	printf("************************************************\n");
}

int el=0;
float Avg_wait,Avg_turnaround;
for(i=0;i<n;i++)
{	if(pr[i].burst_time!=0)						//not counting the process with burst time=0
	{	el++;
		Avg_wait+=pr[i].waiting_t;
		Avg_turnaround+=pr[i].turnaround;
	}
}

Avg_wait=Avg_wait/el;						//Avg_wait==>Average waiting time when priority scheduling is done
Avg_turnaround=Avg_turnaround/el;			//Avg_turnaround==>Average turnaround time 

printf("\n-------------------------------------------------------------------------------");
printf("\nAverage Waiting Time(excluding process with burst time 0):     %f\n",Avg_wait);
printf("\nAverage turn around time(excluding process with burst time 0): %f",Avg_turnaround);	
printf("\n-------------------------------------------------------------------------------");
}

