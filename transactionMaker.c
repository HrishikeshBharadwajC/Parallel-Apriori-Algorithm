/*this file is used to produce input transaction files.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

FILE *f = fopen("input.txt","w");
if(f == NULL){
	printf("error opening file !");
	exit(1);
}

int i,j;
int n;
printf("Enter the number of Items: ");
scanf("%d",&n);
int t;
printf("Enter the number of Transactions: ");
scanf("%d",&t);
int count;	//no of items per transaction
int r;
float prob;
char buffer[1000];

int arr[n];
for(i=1;i<=n;i++)
	arr[i-1] = i;

char space[] = " ";
char end[] = "-1\n";
char temp[5];

printf("Completed");
for(i=0;i<t;i++){
	count = 0;
	buffer[0] = '\0';
	for(j=0;j<n;j++){
		r = rand();
		prob = ((float)r)/RAND_MAX;

		if(prob > 0.5){
			sprintf(temp,"%d",arr[j]);
			strcat(buffer,temp);		
			strcat(buffer,space);				
			count++;		
		}	
	}
	if(count==0)
		continue;
	strcat(buffer,end);
	fprintf(f,"%s",buffer);	
}
return 0;
}
