#include<stdio.h>
#include<stdlib.h>
void main(){
int n;
printf("enter the number of processes\n");
scanf("%d",&n);

int * sum;
sum=(int *) malloc(n*sizeof(int));
printf("enter the burst time of processes\n");
for(int i=0;i<n;i++){
scanf("%d",sum+i);
}

int * waitT;
waitT=(int *) malloc(n*sizeof(int));
int * tat;
tat=(int *) malloc(n*sizeof(int));
int * arrivT;
arrivT=(int *) malloc(n*sizeof(int));
int * finT;
finT=(int *) malloc(n*sizeof(int));

finT[0]=sum[0];

for(int p=1;p<n;p++){

finT[p]=finT[p-1]+sum[p];


}

for(int g=0;g<n;g++){
arrivT[g]=g;

}

for(int z=0;z<n;z++){
tat[z]=finT[z]-arrivT[z];
}

for(int y=0;y<n;y++){
waitT[y]=tat[y]-sum[y];
}
for(int k=0;k<n;k++){
int st =k;
printf("For process %d, the wait time is %d, and the T.A.T is %d\n",st+1,waitT[k],tat[k]);
}

free (sum);

printf("NOTE: In this program,it is assumed that the first program arrives at 0th sec and the last program at nth-1 sec\n");
}
