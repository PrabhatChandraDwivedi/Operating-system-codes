#include<stdio.h>
#include <stdlib.h>
int main()
{
int max[10][10], need[10][10], allocation[10][10], available[10], compl[10], safeseq[10];
int p, r,i,j,process,count=0;
printf("enter the no of processes : ");
scanf("%d",&p);
for(i=0;i<p;i++)
compl[i]=0;
printf("Enter the no instances of resources : ");
scanf("%d",&r);
printf("Enter the maximum matrix for each process :\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
scanf("%d",&max[i][j]);
}
}
printf("Enter the allocation for each process :\n");
 for(i=0;i<p;i++)
 {
 for(j=0;j<r;j++)
 {
 scanf("%d",&allocation[i][j]);
 }
 }
printf("Enter the current available resources with os :\n");
for(i=0;i<r;i++)
scanf("%d",&available[i]);
for(i=0;i<p;i++)
for(j=0;j<r;j++)
need[i][j]=max[i][j]-allocation[i][j];
do
{
printf("Max matrix:\tAllocation matrix:\n");
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
printf("%d ",max[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf(" %d",allocation[i][j]);
printf("\n");
}
process = -1;
for(i=0;i<p;i++)
{
if(compl[i]==0)
{
process = i;
for(j=0;j<r;j++)
{
if(available[j]<need[i][j])
{
process = -1;
break;
}
}
}
if(process != -1)
break;
}
if(process != -1)
{
printf("Process %d is now completed!\n",process+1);
safeseq[count]=process+1;
count++;
for(j=0;j<r;j++)
{
available[j]+=allocation[process][j];
allocation[process][j] = 0;
max[process][j]=0;
compl[process]=1;
}
}
}
while(count != p && process != -1);
if(count == p)
{
printf("The system is in a safe state!!\n");
printf("safe sequesnce : < ");
for(i=0;i<p;i++)
printf("%d ",safeseq[i]);
printf(">\n");
}
else printf("\nThe system is in an unsafe state!!");
}
