/*	Write a C program to simulate the non-preemptive CPU scheduling algorithms to find
turnaround time and waiting time for shortest job first scheduling	*/

#include<stdio.h>
int main()
{
	int time,bt[10],at[10],sum_bt=0,smallest,n,i,gc[10],temp[10];
	int sumt=0,sumw=0,k=0;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time for process P%d : ",i+1);
		scanf("%d",&at[i]);
		printf("Enter the burst time for process P%d : ",i+1);
		scanf("%d",&bt[i]);
		sum_bt+=bt[i];
	}
	bt[9]=9999;
	printf("Process\t|\tTAT\t|\tWT\t\n");
	for(time=0;time<sum_bt;)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
			smallest=i;
		}
	printf("P[%d]\t|\t%d\t|\t%d\n",smallest+1,time+bt[smallest]-at[smallest],time-at[smallest]);
	if(1)
	{
		temp[k]=smallest+1;	
		gc[k]=time+bt[smallest];
		k++;
	}
	sumt+=time+bt[smallest]-at[smallest];
	sumw+=time-at[smallest];
	time+=bt[smallest];
	bt[smallest]=0;
	}
	printf("\nGantt Chart:\n");
	for(i=0;i<n;i++)
		printf("|\tP%d\t|",temp[i]);
	printf("\n0\t\t");
	for(i=0;i<n;i++)
		printf("%d\t\t",gc[i]);
	printf("\n");

	printf("\n\n average waiting time = %f",sumw*1.0/n);
	printf("\n\n average turnaround time = %f\n",sumt*1.0/n);
	return 0;
}
