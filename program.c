#include<stdio.h>
int main(){
	
	void swap(int *xp, int *yp) 
	{ 
 	   	int temp = *xp; 
    		*xp = *yp; 
    		*yp = temp; 
	} 
	// A function to implement bubble sort 
	void sortBtime(int arr[], int n) 
	{ 
   		int i, j; 
  	 	for (i = 0; i < n-1; i++){       
       			// Last i elements are already in place    
       			for (j = 0; j < n-i-1; j++){  
        	   		if (arr[j] > arr[j+1]) 
              				swap(&arr[j], &arr[j+1]);
			} 
		}
	}
	int noOfProcess;
	int i;
	int wa_time=0,ta_time=0;

	printf("Enter the no of process :");
	scanf("%d",&noOfProcess);
	int at[noOfProcess],bt[noOfProcess],rt[noOfProcess],process[noOfProcess];
	printf("Enter the Arrival time of all the process :\n");
	for(i = 0; i<noOfProcess; i++){
		printf("process%d:",i+1);
        	scanf("%d",&bt[i]);
        	process[i]=i+1;
	}
	printf("Enter the Brust time of each process :\n");
	for(i = 0; i < noOfProcess; i++){
		printf("process%d:",i+1);
        	scanf("%d",&bt[i]);
        	process[i]=i+1;
	}
	int size = sizeof(bt)/sizeof(int);
	sortBtime(bt,size);			//Now this bt array is sorted 	
	int j;
	for(j = 0; j<size; j++){
		printf("process%d :%d\n",j,bt[j]);
	}	
	
}