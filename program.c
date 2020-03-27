#include<stdio.h>
#include<conio.h>
# define max 30
int main(){

    int i,j,n,temp,time,remaining,count;
    int process[max],bt[max],at[max],wt[max],tat[max],rt[max];
    float awt = 0;
    float atat = 0;
    int flag=0;
    int queue[100];
    //For average waiting & turn around time calculation
    int totalWt=0,totalTat = 0;
    //clrscr();

    //code
    printf("Enter the number of process : \n");
    scanf("%d",&n);
    remaining = n;
    printf("Enter the arrival time of process :\n");
    for(i = 0; i < n; i++){
        scanf("%d",&process[i]);
    }

    printf("Enter the burst time of Process :\n");
    for(i = 0; i < n; i++){
        scanf("%d",&bt[i]);
    }

    //Sorting of Burst time using Bubble Sort
    
    for(i = 0; i<n; i++){
        for(j = 0; j<n-i-1; j++){
            if(bt[j]>bt[j+1]){
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }

    printf("\tprocess \t Burst time \t waiting time \t turn around time\n");
    
    for(i = 0; i<n; i++){
        wt[i]=0;
        tat[i]=0;

	    //To check if the process is of less than the time limit 10 unit
	    if(rt[count]<=10 && rt[count]>0) 	
	    { 
		//Add the remaining time of that process in time because this process is executed fully
	      time+=rt[count]; 
	      rt[count]=0; 
	      flag=1;
	      queue[count] = process[count]; 
	    } 
	    //If remaining time is more than 10 unit time then 10 sec of process will be executed
	    else if(rt[count]>0) 
	    { 
	      rt[count]-=10; 
	      time+=10; 
	    }
	    
        for(j=0; j<i; j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i] = wt[i]+bt[i];
        
        totalWt = totalWt+wt[i];
	totalTat = totalTat+tat[i];
        printf("\t%d\t %d\t\t %d\t\t %d\n",process[i],bt[i],wt[i],tat[i]);
    }
    
    //Printing average time calculation
    awt = (float)totalWt/(float)n;
    atat = (float)totalTat/(float)n;
    printf(" \n\nAverage Waiting time is %.2f",awt);
    printf("\n\nAverage Turn around time is %.2f",atat);
    
    return 0;
}
