/* Write a C program to simulate the preemptive CPU scheduling algorithms to find
turnaround time and waiting time for Round Robin Scheduling for a given Quantum	*/

#include<stdio.h>
struct process
{
	//char name;
	int no,at,bt,wt,tt,rt,completed;
}p[10];
	int n;
	int q[15];  //queue
	int front=-1,rear=-1;
void enqueue(int i)
{
	if(rear==15)
	printf("overflow");
	rear++;
	q[rear]=i;
	if(front==-1)
	front=0;
}

int dequeue()
{
	if(front==-1)
	printf("underflow");
	int temp=q[front];
	if(front==rear)
	front=rear=-1;
	else
	front++;
	return temp;
}
int isInQueue(int i)
{
	int k;
	for(k=front;k<=rear;k++)
	{
	if(q[k]==i)
	return 1;
	}
	return 0;
}
void sortByArrival()
{
	struct process temp;
	int i,j;
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
	if(p[i].at>p[j].at)
	{
	temp=p[i];
	p[i]=p[j];
	p[j]=temp;
	}
	}
}

void main()
{
	int i,j,time=0,sum_bt=0,tq,temp[50],k=0;
	char c;
	temp[k]=0;k++;
        float avgwt=0,avgtt=0;
	printf("Enter no of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	 p[i].no=i+1;
	 printf("\nEnter the arrival time of process %d: ",p[i].no);
	 scanf("%d",&p[i].at);
	 printf("Enter the burst time of process %d: ",p[i].no);
	 scanf("%d",&p[i].bt);
	 p[i].rt=p[i].bt;
	 p[i].completed=0;
	 sum_bt+=p[i].bt; 
	}
	printf("\nEnter the time quantum:");	
	scanf("%d",&tq);

	sortByArrival();
	enqueue(0);          // enqueue the first process
	printf("\nGantt Chart:\n");
	for(time=p[0].at;time<sum_bt;)       // run until the total burst time reached
	{   i=dequeue();

	if(p[i].rt<=tq)
	{                          /* for processes having remaining time with less than or  equal  to time quantum  */
                      
	time+=p[i].rt;
	temp[k]=time;
	k++;
	p[i].rt=0;
	p[i].completed=1;         
	printf("|\tP%d\t|",p[i].no);
          p[i].wt=time-p[i].at-p[i].bt;
            p[i].tt=time-p[i].at;      
            for(j=0;j<n;j++)                /*enqueue the processes which have come while scheduling */
            {
            if(p[j].at<=time && p[j].completed!=1&& isInQueue(j)!=1)
            {
            enqueue(j);
           
            }
           }
        }
    else               // more than time quantum
    {
    time+=tq;
    p[i].rt-=tq;
    temp[k]=time;
    k++;
    printf("|\tP%d\t|",p[i].no);
    for(j=0;j<n;j++)    /*first enqueue the processes which have come while scheduling */
            {
            if(p[j].at<=time && p[j].completed!=1&&i!=j&& isInQueue(j)!=1)
             {
            enqueue(j);
             }
            }
           enqueue(i);   // then enqueue the uncompleted process          
    }

}
	printf("\n");
	for(i=0;i<k;i++)
	printf("%d\t\t",temp[i]);
	printf("\n\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time");
	for(i=0;i<n;i++)
	{
	avgwt+=p[i].wt;
	avgtt+=p[i].tt;
	printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i].no,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	}
	printf("\nAverage waiting time:%f",avgwt/n);
	printf("\nAverage turnaround time:%f\n",avgtt/n);
}
