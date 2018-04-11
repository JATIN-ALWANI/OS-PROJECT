#include<stdio.h>
#include<time.h>

struct prior
{
	char pname[10];
	int arrival_time,burst_time;
	int execute;
	float waiting_time,turnaround;
	float priority;
	
}pr[20],pr1[20],temp;

int ta=0,tot_bt=0,n;

void calc_prior()			//function to calculate priorities
{    int i;
	for(i=0;i<n;i++)
	{
	 if(pr[i].execute==0)		//only priorities of processes whose execute=0 that are not yet executed will be calculated
	 {
	 	if(pr[i].arrival_time<=tot_bt)
		{	
			if(pr[i].burst_time==0)
			{
				pr[i].waiting_time=tot_bt-pr[i].arrival_time;
				pr[i].priority=9999;					//taking a possible larger value instead of infinity for process with burst=0
			}
			else
			{
				pr[i].waiting_time=tot_bt-pr[i].arrival_time;
		
				pr[i].priority=1+(pr[i].waiting_time/pr[i].burst_time);
			}
		}
	 }
    
	}
}

void prior_sort()			//function to sort the processes as per priority after every execution
{	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{		
			if(pr[j].priority<pr[j+1].priority)	
			{
				temp=pr[j];
				pr[j]=pr[j+1];				
				pr[j+1]=temp;
			}
		}
	}
	pr[0].execute=1;			//setting execute to 1 i.e the process is executed
	pr1[ta]=pr[0];
	
	for(i=0;i<n;i++)
	{
		pr[i].priority=0;
        }
}



void main()
{

int i,j;

printf("\t\t\tHIGHEST RESPONSE RATIO NEXT(HRRN)");
printf("\n________________________________________________________________________________\n");
printf("\t\t\t   enter no. of processes:");
scanf("%d",&n);								//n=number of processes
printf("________________________________________________________________________________");

for(i=0;i<n;i++)
{
	printf("\nenter process %d name:",i+1);
	scanf("%s",&pr[i].pname);               	//pname->process name
	
	printf("enter arrival time:");
	scanf("%d",&pr[i].arrival_time);		//arrival_time->process arrival time
	
	printf("enter burst time:");
	scanf("%d",&pr[i].burst_time);			//burst_time->process burst time
	
}

for(i=0;i<n;i++)
{
	pr[i].execute=0;				//initialising execute=0 and priority=0 for every process
	pr[i].priority=0;
}

//sorting as per arrival time

    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
	{
		if(pr[j].arrival_time>pr[j+1].arrival_time)			
		{
			temp=pr[j];
			pr[j]=pr[j+1];				
			pr[j+1]=temp;
		}
	}
}   



pr[0].execute=1;   				//process with minimum arrival time will be executed first
pr1[ta]=pr[0];
ta++;

tot_bt=pr[0].arrival_time+pr[0].burst_time;

for(i=0;i<n-1;i++)
	
	{  
		calc_prior();		
		prior_sort();
		tot_bt+=pr[0].burst_time;		
		ta++;	
	}
	
int max_bt=pr1[0].arrival_time+pr1[0].burst_time;
pr1[0].waiting_time=0;
pr1[0].turnaround=pr[i].burst_time;

	for(i=1;i<n;i++)
	{
		pr1[i].waiting_time=max_bt-pr1[i].arrival_time;			//calculating waiting time after full execution of process
		if(pr1[i].waiting_time<0)
		{
			pr1[i].waiting_time=0;
		}
		pr1[i].turnaround=pr1[i].waiting_time+pr1[i].burst_time;	//calculating turnaround time for each process
		max_bt+=pr1[i].burst_time;
	}

printf("\n________________________________________________________________________________");
printf("\n\nProcess	   Arrival_time     Burst_time    waiting time     Turnaround time\n");

for(i=0;i<n;i++)
{
	printf("\n  %s\t\t%d\t\t %d\t    %f\t     %f\n",pr1[i].pname,pr1[i].arrival_time,pr1[i].burst_time,pr1[i].waiting_time,pr1[i].turnaround);
}
printf("\n________________________________________________________________________________\n");

float Avg_turnaround=0,Avg_waiting=0;
int t=0;

for(i=0;i<n;i++)
{   //calculating Average turn around time and average waiting time of processes excluding process with burst time=0
	if(pr1[i].burst_time!=0)
	{
	t++;
	Avg_turnaround+=pr1[i].turnaround;		
	Avg_waiting+=pr1[i].waiting_time;
	}
}

Avg_turnaround/=t;
Avg_waiting/=t;

printf("\n------------------------------------------------------------------------------\n");
printf("Average Turn Around Time=%f\n",Avg_turnaround);
printf("Average Waiting time=%f\n",Avg_waiting);
printf("\n------------------------------------------------------------------------------\n");

printf("\n******************************************************************************");
printf("\nSequence of Execution:");
for(i=0;i<n;i++)
{
	printf("%s",pr1[i].pname);
	sleep(1);
	printf("-->");
	sleep(1);
}
printf("\n******************************************************************************\n");

}


