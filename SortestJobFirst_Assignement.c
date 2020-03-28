#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 

int main() 
{ 
 //Variable declaration , 
  int count,i,j,m=0,n,y=0,time,remain=0,min,flag=0; 
  int wait_time=0,turn_a_time=0,a_time[10],b_time[10],p[10],z[10];
  float k=0,x=0; 
  printf("Enter number of Process : "); 
  scanf("%d",&n); 
  printf("\nWARNINGS : \nArrival time should be greater than 2 as CPU remains idle for first 3 secs.");
  printf("\nBurst time should be less tha 10\n\n");
  for(count=0;count<n;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for  Process Number %d :",count+1); 
    scanf("%d",&a_time[count]); 
    scanf("%d",&b_time[count]);  
  } 

//Constraints checking
for(i=0;i<n;i++)
{
	if(a_time[i]==0 )
	{
		printf("\nS INVALID ARRIVAL TIME\n");
		getch();
		exit(1);
	}
	if(b_time[i]>10){
		printf("\nBurst time should be less than 10");
		getch();
		exit(1);
	}
}
for(i=0;i<n;i++)
{
	if(a_time[i]<3)
	{
		printf("\nS INVALID Arrival Time it should be greater than 3\n");
		getch();
		exit(1);
	}
}
  printf("\n\n\tProcess\t|Turnaround Time|Waiting Time\n\n"); 
  printf("\t===========================================\n");
  
for(i=0;i<n;i++)
{
	m=m+b_time[i];
}
min=m;
time=m;

//Take the minimum burst time in time variable
for(i=0;i<n;i++)
{
	if(a_time[i]<time)
	{
		time=a_time[i];  
	}
	
}
//Now the time variable has the lowest burst time in all the process
for(i=time;i<=m;i=i+b_time[j])
{
	min=m;
	remain=0;  //Remaining burst time of the process
	flag=0;

	for(count=0;count<n;count++)
	{
		//Arrival time of the process is less than time then 
		if(a_time[count]<=i)
		{

			if(b_time[count]<min)
			{
				//If the burst time is less than the min burst time then process will execute completally and fleg = 1
				min = b_time[count];
				j=count;		//J will tell that which process is executed now
				flag=1;
			}
			remain=1;	 
		}
	}
	if(flag==1&&remain==1)
	{
		//Print the data for the process j whihc is executed successfully
		wait_time=i-a_time[j];
		turn_a_time=wait_time+b_time[j];
		printf("\tP[%d]\t|\t%d\t|\t%d\n",j+1,turn_a_time,wait_time); 
		k=k+wait_time;			//Variable for storing the waiting time of the processes
		x=x+turn_a_time;		//X is for storing the turn around time of the process
	
		a_time[j]=m+1;
		p[y]=j+1;
		z[y]=i;
		y++;
	}
}

//Print the average eaiting time & turn around time
printf("\n\nAverage Waiting Time= %.2f\n",k/n); 
printf("Avg Turnaround Time = %.2f",x/n); 
printf("\n\n\nTotal time taken by processor to complete all the jobs : %d",m);  
printf("\n\nQueue  for order of execution:\n");

// Print the order of execution of the processes
printf("\n\nProcess		");
for(i=0;i<n;i++)
{
	printf(" P[%d]   ",p[i]);
	if(i==(n-1))
	{
		printf("End");
	}
}
  return 0; 
}
