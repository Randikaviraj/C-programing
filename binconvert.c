include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[]){
	
switch(argv[1]){
case '-B':
switch(argv[2]){
case '-H':
   //Binary to hexa converting

int val[8]={};

for(int i=0;i<4;i++){
	
val[0]=val[0]+(argv[3][i]-'0')*pow(2,3-i);	
	
	}


for(int i=4;i<8;i++){
	
val[1]=val[1]+(argv[3][i]-'0')*pow(2,7-i);	
	
	}

for(int i=8;i<12;i++){
	
val[2]=val[2]+(argv[3][i]-'0')*pow(2,11-i);	
	
	}	
	

for(int i=12;i<16;i++){
	
val[3]=val[3]+(argv[3][i]-'0')*pow(2,15-i);	
	
	}	


for(int i=16;i<20;i++){
	
val[4]=val[4]+(argv[3][i]-'0')*pow(2,19-i);	
	
	}
	

for(int i=20;i<24;i++){
	
val[5]=val[5]+(argv[3][i]-'0')*pow(2,23-i);	
	
	}	
	

for(int i=24;i<28;i++){
	
val[6]=val[6]+(argv[3][i]-'0')*pow(2,27-i);	
	
	}	
	

for(int i=28;i<32;i++){
	
val[7]=val[7]+(argv[3][i]-'0')*pow(2,(31-i));	
	//printf("%d",argv[1][i]-'0');
	}	


printf("0x");
for(int i=0;i<8;i++){
	
if(val[i]>9){
switch(val[i]){
case 10:	
printf("A");
break;
case 11:	
printf("B");
break;
case 12:	
printf("C");
break;
case 13:	
printf("D");
break;
case 14:	
printf("E");
break;
case 15:	
printf("F");
break;	
}	}	
	
else printf("%d",val[i]);	
	
}

break;
	
case '-I':

int expo=0,e=0;
float m;
float dec;	
//Binary to decimal converting	
for(int i=1;i<9;i++){
  expo=expo+(argv[3][i]-'0')*pow(2,(8-i));
  
}

 e=expo-127;	


for(int i=9;i<32;i++){
	 m=m+(argv[3][i]-'0')*pow(2,(8-i));  
}	

if(argv[3][0]=='1'){
dec=-(1+m)*pow(2,e);}
else{
dec=(1+m)*pow(2,e);	
}

printf("%d",dec);
break;

case '-F':
int expo=0,e=0;
float m;
float dec;	
//Binary to decimal converting	
for(int i=1;i<9;i++){
  expo=expo+(argv[3][i]-'0')*pow(2,(8-i));
  
}

 e=expo-127;	


for(int i=9;i<32;i++){
	 m=m+(argv[3][i]-'0')*pow(2,(8-i));  
}	

if(argv[3][0]=='1'){
dec=-(1+m)*pow(2,e);}
else{
dec=(1+m)*pow(2,e);	
}

printf("%f",dec);
break;
}
break;



case '-H':

switch(argv[2]){
case '-B':

//Hexadecimal to binarray converting
int y;
int valu[4]={};

for(int i=0;i<8;i++){


switch(argv[3][i]){
case 'A':
printf("1010");
break;	
case 'B':
printf("1011");
break;		
case 'C':
printf("1100");
break;		
case 'D':
printf("1101");
break;	
case 'E':
printf("1110");
break;	
case 'F':
printf("1111");
break;	
case '0':
printf("0000");
break;	
case '1':
printf("0001");
break;	
case '2':
printf("0010");
break;	
case '3':
printf("0011");
break;	
case '4':
printf("0100");
break;	
case '5':
printf("0101");
break;	
case '6':
printf("0110");
break;	
case '7':
printf("0111");
break;
case '8':
printf("1000");
break;		
case '9':
printf("1001");
break;	

}	
	
}
break;	

//case '-I':

//case '-F':

}
break;

case '-I':
switch(argv[2]){
case '-B'
//Decimal to binary converting


int k,j,number=atoi(argv[3]);
float fnumber;
int array1[]={},array2[32]={},binarray[32]={},expo=0;

if(number<0){
	binarray[0]=1;
	number=number*(-1);
	fnumber=(atof(argv[3])-atoi(argv[3]))*-1;
}
else{
	binarray[0]=0;
	fnumber=atof(argv[3])-atoi(argv[3]);
}

for(j=0;j>=0;j++){
	
array1[j]=number%2;
number=number/2;
if(number==0) break;
	
}



for(int i=0;i<32;i++){

array2[i]=fnumber*2;	
fnumber=fnumber*2;
if(array2[i]==1)fnumber=fnumber-1;
if(fnumber==0) break;
}


if(atoi(argv[3])>=1||atoi(argv[3])<=-1){
expo=j+127;

for(int i=1;i<9;i++){
	binarray[9-i]=expo%2;
	expo=expo/2;
}
for(int i=9;i<32;i++){
	binarray[i]=array1[j];
	j--;
	k=i;
	if(j==0) break;
}
int m=0;
for(k=k+1;k<32;k++){
	
	binarray[k]=array2[m];
m=m+1;
}




}
else{
	k=0;
	while(array2[k]==0){
	k=k+1;	}
expo=127-(k+1);
for(int i=1;i<9;i++){
	binarray[i]=expo%2;
	expo=expo/2;
}
for(int i=0;i<32;i++){
	binarray[i+9]=array2[k+1];
	k=k+1;
}
}

for(int i=0;i<32;i++){
	printf("%d",binarray[i]);
}
break;
//case '-H'
case  '-F'
printf("%f",(flaot)argv[3]);
	break;
}
break;

case '-F':
switch(argv[2]){
case '-B':
//Decimal to binary converting


int k,j,number=atoi(argv[3]);
float fnumber;
int array1[]={},array2[32]={},binarray[32]={},expo=0;

if(number<0){
	binarray[0]=1;
	number=number*(-1);
	fnumber=(atof(argv[3])-atoi(argv[3]))*-1;
}
else{
	binarray[0]=0;
	fnumber=atof(argv[3])-atoi(argv[3]);
}

for(j=0;j>=0;j++){
	
array1[j]=number%2;
number=number/2;
if(number==0) break;
	
}



for(int i=0;i<32;i++){

array2[i]=fnumber*2;	
fnumber=fnumber*2;
if(array2[i]==1)fnumber=fnumber-1;
if(fnumber==0) break;
}


if(atoi(argv[3])>=1||atoi(argv[3])<=-1){
expo=j+127;

for(int i=1;i<9;i++){
	binarray[9-i]=expo%2;
	expo=expo/2;
}
for(int i=9;i<32;i++){
	binarray[i]=array1[j];
	j--;
	k=i;
	if(j==0) break;
}
int m=0;
for(k=k+1;k<32;k++){
	
	binarray[k]=array2[m];
m=m+1;
}




}
else{
	k=0;
	while(array2[k]==0){
	k=k+1;	}
expo=127-(k+1);
for(int i=1;i<9;i++){
	binarray[i]=expo%2;
	expo=expo/2;
}
for(int i=0;i<32;i++){
	binarray[i+9]=array2[k+1];
	k=k+1;
}
}

for(int i=0;i<32;i++){
	printf("%d",binarray[i]);
}
break;

//case '-H':
case   '-I':
printf("%d",(int)(argv[3]-'0'));
break;
}
break;



	
	
	
	
}	
	
	
	
	
	
	
}	
	
	
	
	