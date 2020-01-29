#include <stdio.h>
#include <stdlib.h>

void bubblesort(int number,int *point);

int main(){
int number;	

printf("Enter the number:" );//Geting the no of numbers	
scanf("%d",&number);

int *point = (int *) malloc(number * sizeof (int));//allocating memory space
if (point == NULL) 
{
printf("There is no memory allocation\n");
}
else{
  for (int i = 0; i <number; ++i)
  {
	*(point+i)=rand();
	
  }
}

bubblesort(number,point);

for(int i=0;i<number;i++) //printing
{
	printf("%d  ",*(point+i) );
}
return 0;

}


void bubblesort(int number,int *point){
int temp,move=1;
while(move)
{ 
	move=0;//checking if there is swap
	for(int i=0;i<number-1;i++)
	{
      if(*(point+i)>*(point+i+1))
      {
      	temp = *(point+i);        
      	*(point+i) = *(point+i+1);        
      	*(point+i+1) = temp;
      	move=1;//when there is swap
      }
	}
}
return;
}



