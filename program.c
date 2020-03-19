
#include<stdio.h>
#include<conio.h>
# define max 30
int main(){
    int i,j,n,temp,process[max],bt[max],at[max],wt[max],tat[max];
    float awt = 0;
    float atat = 0;

//    clrscr();

    //code
    printf("Enter the number of process : \n");
    scanf("%d",&n);

    printf("Enter the ID of process :\n");
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

    printf("process \t Burst time \t waiting time \t turn around time\n");

    for(i = 0; i<n; i++){
        wt[i]=0;
        tat[i]=0;

        for(j=0; j<i; j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i] = wt[i]+bt[i];

        printf("\t%d\t %d\t\t %d\t\t %d\n",process[i],bt[i],wt[i],tat[i]);
    }
    return 0;
}
