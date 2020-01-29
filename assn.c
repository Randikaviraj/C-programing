#include <stdio.h>


int *inttoBinary(char argv[]);
int *hexatoBinary(char argv[]);
double binarytoSingp(char argv[]);
double binarytoDoubp(char argv[]);
int binarytoInt(char argv[]);
char *binarytoHex(char argv[]);
void singptoBinary(char argv[]);
void doubptoBinary(char argv[]);
double atof(char argv[]);
double pow(double base,int power);
void singptoHexa(char argv[]);
void doubptoHexa(char argv[]);
void hexatoDoubleprici(char argv[]);

int main(int argc,char *argv[]){
int *intarray,k,integerno,a=0,size;	
char *hexarray,binarray[32];

if(argc!=4) {fprintf(stderr,"ERROR: The number of arguments is wrong. "); return 1;} //check the number of arguments

if(argv[1][1]=='B'){}
else if(argv[1][1]=='H'){}
else if(argv[1][1]=='I'){}
else if(argv[1][1]=='D'){}
else if(argv[1][1]=='F'){}
else{fprintf(stderr,"ERROR: The input argument is wrong."); return 1;} //check the input  arguments

if(argv[2][1]=='B'){}
else if(argv[2][1]=='H'){}
else if(argv[2][1]=='I'){}
else if(argv[2][1]=='D'){}
else if(argv[2][1]=='F') {}
else {fprintf(stderr,"ERROR: The output argument is wrong."); return 1; }//check the output arguments


if(argv[1][1]=='B') //when input type is binary number
{ 
	
   for(k=0;k>=0;k++)//check the number of elements
   {	if(argv[3][k]=='\0') break;
    }

   if(k==32|| k==64){}
   else{fprintf(stderr,"ERROR: The input size is wrong. "); return 1;} //if wrong input size 
   if(k==32){size=32;}
   else{size=64;}
   for(k=0;k<size;k++) //check the elements are 0 or 1
   {	if(argv[3][k]=='0'){}
        else if(argv[3][k]=='1'){}
		else { fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}
   }


   if(argv[2][1]=='H') //when the output type is hexadecimal
   {  
     for(size=0;size>=0;size++)
     {
	  if(argv[size]=='\0') break;
     }
   
      fprintf(stdout,"0x");
	  hexarray=binarytoHex(argv[3]);
	  for(int j=0;j<size/4;j++)
      {
	  fprintf(stdout,"%c",*(hexarray+j));
      }
   }
   else if(argv[2][1]=='I') //when the output type is integer
   {   if(k==64){fprintf(stderr,"ERROR: The input size is wrong. "); return 1;}
	   integerno=binarytoInt(argv[3]);
	   fprintf(stdout,"%d",integerno);
   }
   else if(argv[2][1]=='B') //when output type is binary
   {
	   for(int j=0;j>=0;j++)
      {
	    if(argv[3][j]=='\0') break;
	    fprintf(stdout,"%c",argv[3][j]);
      }
   }   
   else if(argv[2][1]=='F')//when the output type is single precision no
   {
	    
	    fprintf(stdout,"%.2f",(float)binarytoSingp(argv[3]));
   }
   else if(argv[2][1]=='D') // when output type is double precision
   {
	   
	   fprintf(stdout,"%lf",binarytoDoubp(argv[3]));
   }


}
else if(argv[1][1]=='H') //when input type is hexadecimal
{
    for(k=0;k>=0;k++)//check the number of elements
   {	if(argv[3][k]=='\0') break;
    }
	
	if(k==8||k==16){} 
	else{fprintf(stderr,"ERROR: The input size is wrong. "); return 1; }//if wrong input size 
    if(k==8){size=8;}
    else{size=16;}
    
   for(k=0;k<size;k++) //check the elements are correct
   {
     if(argv[3][k]=='A'){}
     else if(argv[3][k]=='B'){}
     else if(argv[3][k]=='C'){}
     else if(argv[3][k]=='D'){}
     else if(argv[3][k]=='E'){}
     else if(argv[3][k]=='F'){}
     else if(argv[3][k]=='0'){}
     else if(argv[3][k]=='1'){}
     else if(argv[3][k]=='2'){}
	 else if(argv[3][k]=='3'){}
     else if(argv[3][k]=='4'){}
     else if(argv[3][k]=='5'){}
     else if(argv[3][k]=='6'){}
	 else if(argv[3][k]=='7'){}
     else if(argv[3][k]=='8'){}
     else if(argv[3][k]=='9'){}
     else  {fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}
   }
   
   
   if(argv[2][1]=='B')//when output is binary number
   { 
    for(size=0;size>=0;size++)
    {
	if(argv[3][size]=='\0') break;
    }
	  
	  
	  intarray=hexatoBinary(argv[3]);
      for(int j=0;j<4*size;j++)
     {
	  fprintf(stdout,"%d",*(intarray+j));
     }
   }   
   
   else if(argv[2][1]=='I') //when output is unsigned integer
   { 
     if(k==16){fprintf(stderr,"ERROR: This conversion is not possible."); return 1;}
	 intarray=hexatoBinary(argv[3]);
      for(int j=0;j<32;j++)
     {
	  binarray[j]=*(intarray+j)+'0';
	  
     }

     integerno=binarytoInt(binarray);
	 fprintf(stdout,"%d",integerno);	 
    }   
    else if(argv[2][1]=='F') //when output is single precision no
	{
	  intarray=hexatoBinary(argv[3]);
      for(int j=0;j<32;j++)
      {
	   binarray[j]=*(intarray+j)+'0';
      }

 
	 fprintf(stdout,"%.2f",binarytoSingp(binarray));	 
	}
    else if(argv[2][1]=='D')
	{

	   hexatoDoubleprici(argv[3]);
      	 
	}
	else if(argv[2][1]=='H') //when output type is hexadecimal
   {    fprintf(stdout,"0x");
	    for(int j=0;j>=0;j++)
      {
	    if(argv[3][j]=='\0') break;
	    fprintf(stdout,"%c",argv[3][j]);
      }
   }   


}

else if(argv[1][1]=='I') //when input type is  integer
{
	
    for(k=0;k>=0;k++) //check the elements are correct
    {
	if(argv[3][k]=='\0') break;
	
	 if(argv[3][k]=='0'){}
	 else if(argv[3][k]=='-'){if(argv[3][0]!='-'){fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}}
	 else if(argv[3][k]=='1'){}
     else if(argv[3][k]=='2'){}
	 else if(argv[3][k]=='3'){}
     else if(argv[3][k]=='4'){}
     else if(argv[3][k]=='5'){}
     else if(argv[3][k]=='6'){}
	 else if(argv[3][k]=='7'){}
     else if(argv[3][k]=='8'){}
     else if(argv[3][k]=='9'){} 
	 else {fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}
    
	}
    
	
	if(atof(argv[3])>=-2147483647&&atof(argv[3])<2147483648){}
    else {fprintf(stderr,"ERROR: The input size is wrong. "); return 1; }//if wrong input size
	
	if(argv[2][1]=='B')//when output type is binary
    {
		intarray=inttoBinary(argv[3]);
		 for(int j=0;j<32;j++)
        {
	      fprintf(stdout,"%d",*(intarray+j));
        }
	}
	else if(argv[2][1]=='H') //when output type is hexadecimal
	{
		intarray=inttoBinary(argv[3]);
		 for(int j=0;j<32;j++)
        {
	      binarray[j]=*(intarray+j)+'0';
        }
	    
	  hexarray=binarytoHex(binarray);
	  fprintf(stdout,"0x");
	  for(int j=0;j<16;j++)
      {
	  fprintf(stdout,"%c",*(hexarray+j));
      }
	}	
    
	else if(argv[2][1]=='F') fprintf(stdout,"%.2f",(float)atof(argv[3])); //when output type is float
		
    else if(argv[2][1]=='D') fprintf(stderr,"ERROR: This conversion is not possible."); //when output type is double
	else if(argv[2][1]=='I') //when output type is integer
   {
	   
	    for(int j=0;j>=0;j++)
      {
	    if(argv[3][j]=='\0') break;
	    fprintf(stdout,"%c",argv[3][j]);
      }
   }   	
}

else if(argv[1][1]=='F') //when input type is float
{
    
    
	for(k=0;k>=0;k++) //check the elements are correct
    { 
	 if(argv[3][k]=='\0') break;
	
     if(argv[3][k]=='0'){}
	 else if(argv[3][k]=='-'){if(argv[3][0]!='-'){fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}}
	 else if(argv[3][k]=='1'){}
     else if(argv[3][k]=='2'){}
	 else if(argv[3][k]=='3'){}
     else if(argv[3][k]=='4'){}
     else if(argv[3][k]=='5'){}
     else if(argv[3][k]=='6'){}
	 else if(argv[3][k]=='7'){}
     else if(argv[3][k]=='8'){}
     else if(argv[3][k]=='9'){}
     else if(argv[3][k]=='.')
	 {
		 a=a+1;
		 if(a==2){ fprintf(stderr,"ERROR: Input format error at location %d. ",k+1); return 1;}
	 }	 
	 else { fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}
     
	}
	
	
	
      
	  if(argv[2][1]=='B') singptoBinary(argv[3]);//float to binary
      else if(argv[2][1]=='H')
	  {
        singptoHexa(argv[3]);
	  }
      else if(argv[2][1]=='I') //float to integer
	  {
	   for(k=0;k>=0;k++)
	   {
		   if(argv[3][k]=='.')break;
	   }
	   if(k>10)
       {
	   fprintf(stderr,"ERROR: This conversion is not possible."); return 1;
	   }
	   else
	   {
	   if(argv[3][0]>2){fprintf(stderr,"ERROR: This conversion is not possible."); return 1;}
	   fprintf(stderr,"WARNING: There is a possibility for a precision loss.\n");
       fprintf(stdout,"%d",(int)atof(argv[3])); 
	   }
	  }
      
	  
	  else if(argv[2][1]=='D') fprintf(stderr,"ERROR: This conversion is not possible.");
	 
      else if(argv[2][1]=='F') //when output type is float
      {
	   
	    for(int j=0;j>=0;j++)
      {
	    if(argv[3][j]=='\0') break;
	    fprintf(stdout,"%c",argv[3][j]);
      }
      }   
}

else //when input is double
{

    
    
	for(k=0;k>=0;k++) //check the elements are correct
    {if(argv[3][k]=='\0') break;
	
     if(argv[3][k]=='0'){}
	 else if(argv[3][k]=='-'){if(argv[3][0]!='-'){fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;}}
	 else if(argv[3][k]=='1'){}
     else if(argv[3][k]=='2'){}
	 else if(argv[3][k]=='3'){}
     else if(argv[3][k]=='4'){}
     else if(argv[3][k]=='5'){}
     else if(argv[3][k]=='6'){}
	 else if(argv[3][k]=='7'){}
     else if(argv[3][k]=='8'){}
     else if(argv[3][k]=='9'){}
     else if(argv[3][k]=='.')
	 {
		a=a+1;
		if(a==2){ fprintf(stderr,"ERROR: Input format error at location %d. ",k); return 1;} 
	 }	 
	 else { fprintf(stderr,"ERROR: Input format error at location %d. ",k+1); return 1;}
	}
	
	
	
	
	
	
	
	if(argv[2][1]=='B') doubptoBinary(argv[3]);//output is double
	else if(argv[2][1]=='H') {doubptoHexa(argv[3]);}
    else if(argv[2][1]=='I') //output is integer
	{	
	 fprintf(stderr,"ERROR: This conversion is not possible.");
	 
	}
    else if(argv[2][1]=='F') //output is float
	{	
    
     fprintf(stderr,"ERROR: This conversion is not possible.");
	 }
	

     else if(argv[2][1]=='D') //when output type is double
    {
	   
	    for(int j=0;j>=0;j++)
      {
	    if(argv[3][j]=='\0') break;
	    fprintf(stdout,"%c",argv[3][j]);
      }
    }   


}



return 0;



}


//function to convert integer to binary
int *inttoBinary(char argv[]){
double value=0;
int i,intvalue;	
int val[100]={},Binary[100]={};	
static int Bin[32];
	
if(argv[0]=='-')
{ 
  Bin[0]=1;
	for( i=0;i>=0;i++)
 {   
    
	if(argv[i+1]=='\0') break;
	val[i]=argv[i+1]-'0';//get characters and store as integer array
 }
}
else
{	
 Bin[0]=0;
 for( i=0;i>=0;i++)
 {   
    
	if(argv[i]=='\0') break;
	val[i]=argv[i]-'0';//get characters and store as integer array
 }
}




for(int j=0;j<i;j++)
{
	value=value+(val[j]*pow(10,i-j-1));//get the real intiger value
}


intvalue=(int)value;


for(int j=0;j>=0;j++)
{
   Binary[j]=intvalue%2;//geting the binary number of value
   intvalue=intvalue/2;
   
if(intvalue==0) break;   
}



	


for(int j=0;j<31;j++)
{
Bin[j+1]=Binary[30-j];
}

if(Bin[0]==0){ }
else
{
  for(int j=1;j<32;j++)
  {
	  if(Bin[j]==0) 
	  {Bin[j]=1;}
	  else {Bin[j]=0;}
  }	
  
  for(int j=31;j>0;j--)
  {
	  if(Bin[j]==0) 
	  {	  Bin[j]=1;
          break; 
      }
      else
	  {Bin[j]=0;}	  
  }

 }	
return Bin;
}




//convert hexadecimal to binary

int *hexatoBinary(char argv[]){
	
	
int val,k=-1,kk,num;	
static int Bin[64],Binary[64];	
	
for(num=0;num>=0;num++)
{
	if(argv[num]=='\0') break;
}
	
	//geting the decimal number
for(int i=num-1;i>=0;i--)	
{
  if(argv[i]=='A')
  {
   val=10;
  }
  else if(argv[i]=='B')
  {
   val=11;
  }
  else if(argv[i]=='C')
  {
   val=12;
  } 
  else if(argv[i]=='D')
  {val=13;
  }
  else if(argv[i]=='E')
  {
   val=14;
  }
  else if(argv[i]=='F')
  {
   val=15;
  }
  else
  {
	  val=argv[i]-'0';
  }	  
  kk=0;

  for(k=k+1;k<4*num;k++)
  {  
      kk=kk+1;
	  Binary[k]=val%2;
	  val=val/2;
	  if(kk==4)break;
	   
  }  
  
 
}

 for(int i=0;i<4*num;i++)
 {
	 Bin[i]=Binary[4*num-1-i];

 }

	return Bin;
}


//Binary number to single precision number  converting
double binarytoSingp(char argv[]){
int expo=0,e=0;
double m;
double dec;	
//Binary to decimal converting	
for(int i=1;i<9;i++)
{
  expo=expo+(argv[i]-'0')*pow(2,(8-i));
  }

 e=expo-127;	


for(int i=9;i<32;i++)
{
 m=m+(argv[i]-'0')*pow(2,(8-i));  
}	


if(argv[0]=='1')
{
dec=-(1+m)*pow(2,e);
}
else
{
dec=(1+m)*pow(2,e);	
}

	
	
return dec;	
}



//double precision number to float converting
double binarytoDoubp(char argv[]){
int expo=0,e=0;
double m;
double dec;	
//Binary to decimal converting	
for(int i=1;i<12;i++)
{
  expo=expo+(argv[i]-'0')*pow(2,(11-i));
  }

 e=expo-127;	


for(int i=12;i<64;i++)
{
 m=m+(argv[i]-'0')*pow(2,(11-i));  
}	


if(argv[0]=='1')
{
dec=-(1+m)*pow(2,e);
}
else
{
dec=(1+m)*pow(2,e);	
}

	
	
return dec;	
}


//Convert binary number to integer
int binarytoInt(char argv[]){
double N=0,value=0;	
int j;

if(argv[0]=='0')
{	
  for(int i=0;i<31;i++)
  {
    value=value+(argv[i+1]-'0')*pow(2,30-i);

   }
}   
else
{	
  for( j=0;j>=0;j++)
  {
	if(argv[j]=='0') break;
  }	


   for(int i=j;i<31;i++)
  {
    N=N+(argv[i]-'0')*pow(2,30-i);

   }	

   value=-1*(pow(2,32-j)-N);
}


return (int)value;	
}


//Convert binary number to hexadecimal
char *binarytoHex(char argv[]){
	float value;
	int j,size,intvalue,k=-1;
	static char hexarray[8]={};
	
	for(size=0;size>=0;size++)
   {
	if(argv[size]=='\0') break;
   }
	
for(int i=0;i<size/4;i++)
{    
     j=0;
	 value=0;
    
	for(k=k+1;k<size;k++)
	{
	value=value+(argv[k]-'0')*pow(2,3-j);
    j=j+1;
    if(j==4) break;	
	}	
	intvalue=(int)value;
	
	
	if(intvalue==10) hexarray[i]='A';
	else if(intvalue==11) hexarray[i]='B';
	else if(intvalue==12) hexarray[i]='C';
	else if(intvalue==13) hexarray[i]='D';
	else if(intvalue==14) hexarray[i]='E';
	else if(intvalue==15) hexarray[i]='F';
	else{
		hexarray[i]=intvalue+'0';
		
	}
}
return hexarray;
}





//Decimal to double precision floating binary converting

void doubptoBinary(char argv[]){
int k,j,number=(int)atof(argv);
float fnumber;
int array1[]={},array2[64]={0},binarray[64]={},expo=0;

if(atof(argv)<0){
	binarray[0]=1;
	number=number*(-1);
	fnumber=(atof(argv)-(int)atof(argv))*-1;
	
}
else{
	binarray[0]=0;
	fnumber=atof(argv)-(int)atof(argv);
	
}

for(j=0;j>=0;j++){
	
array1[j]=number%2;
number=number/2;
if(number==0) break;
	
}



for(int i=0;i<64;i++){

array2[i]=fnumber*2;	
fnumber=fnumber*2;

if(array2[i]==1)fnumber=fnumber-1;

if(fnumber==0.000000 ) {break;}
	
}


if((int)atof(argv)>=1||(int)atof(argv)<=-1){
expo=j+1023;

for(int i=1;i<12;i++){
	binarray[12-i]=expo%2;
	expo=expo/2;

}
j=j-1;
for(int i=12;i<64;i++){
	binarray[i]=array1[j];
	if(j==0) break;
	j--;
	k=i;

	
}
int m=0;
for(k=k+1;k<64;k++){
	
	binarray[k]=array2[m];
m=m+1;
}




}
else{
	k=0;
	while(array2[k]==0){
	k=k+1;	}
expo=1023-(k+1);

for(int i=1;i<12;i++){
	binarray[i]=expo%2;
	expo=expo/2;
}
for(int i=0;i<53;i++){
	binarray[i+12]=array2[k+1];
	k=k+1;
}
}

for(int i=0;i<64;i++){
	fprintf(stdout,"%d",binarray[i]);
}
return;
}


//Decimal number converting to single precision number
void singptoBinary(char argv[]){
int k,j,number=(int)atof(argv);
float fnumber;
int array1[]={},array2[32]={},binarray[32]={},expo=0;

if(atof(argv)<0){
	binarray[0]=1;
	number=number*(-1);
	fnumber=(atof(argv)-(int)atof(argv))*-1;
	
}
else{
	binarray[0]=0;
	fnumber=atof(argv)-(int)atof(argv);
	
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


if((int)atof(argv)>=1||(int)atof(argv)<=-1){
expo=j+127;

for(int i=1;i<9;i++){
	binarray[9-i]=expo%2;
	expo=expo/2;

}
j=j-1;
for(int i=9;i<32;i++){
	
	binarray[i]=array1[j];
	if(j==0) break;
	j--;
	k=i;

	
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
	fprintf(stdout,"%d",binarray[i]);
}
return;
}


//Function for convert char value to double
double atof(char argv[]){
int array1[]={};
int array2[]={};
int i,j,tell=0;;
double value=0;

if(argv[0]=='-'){


for(i=0;i>=0;i++) //get the non decimal part to array1
{
  if(argv[i+1]=='.') break;
  else if(argv[i+1]=='\0'){
	tell=1; //check whether there is decimal
    break;
  }

array1[i]=argv[i+1]-'0';
} 

for(int k=0;k<i;k++) // convert non decimal part to floating number
{
value=value+array1[i-1-k]*pow(10,k);
}




     
i=i+1;
}

else{


for(i=0;i>=0;i++) //get the non decimal part to array1
{
  if(argv[i]=='.') break;
  else if(argv[i]=='\0'){
	tell=1; //check whether there is decimal
    break;
  }

array1[i]=argv[i]-'0';
}      


for(int k=0;k<i;k++) // convert non decimal part to floating number
{
value=value+array1[i-1-k]*pow(10,k);
}

}




for(j=0;j>=0;j++) //get decimal part to a array2
{
  if(tell==1)break;
  if(argv[i+1+j]=='\0') break;
  
  array2[j]=argv[i+1+j]-'0';
}



for(int k=0;k<j;k++)  //covert decimal part floating number;
{
   if(tell==1)break;	
  value=value+array2[k]*pow(10,-(k+1));
}

if(argv[0]=='-') return -1*value;
else return value;

}

//function for getting power 
double pow(double base,int power){

double value;
value=1.0;
if(power==0) //check wheather power=0
{
	value=value;
}	
else if(power>0)  //check wheather power>0
{	
   for(int i=1;i<=power;i++)
   {
    value=value*base;
   }
}
else 
{
	for(int i=1;i<=-1*power;i++) //when power<0
	{
		value=value*base;
	}
    value=1/value;	
}	

return value;
}

//single precision number to hexadecimal converting
void singptoHexa(char argv[]){
int k,j,number=(int)atof(argv);
float fnumber;
int array1[]={},array2[32]={},binarray[32]={},expo=0;
char charray[32],*hexarray;
if(atof(argv)<0){
	binarray[0]=1;
	number=number*(-1);
	fnumber=(atof(argv)-(int)atof(argv))*-1;
	
}
else{
	binarray[0]=0;
	fnumber=atof(argv)-(int)atof(argv);
	
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


if((int)atof(argv)>=1||(int)atof(argv)<=-1){
expo=j+127;

for(int i=1;i<9;i++){
	binarray[9-i]=expo%2;
	expo=expo/2;

}
j=j-1;
for(int i=9;i<32;i++){
	
	binarray[i]=array1[j];
	if(j==0) break;
	j--;
	k=i;

	
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
	charray[i]=binarray[i]+'0';
}

     hexarray=binarytoHex(charray);
	  fprintf(stdout,"0x");
	  for(int j=0;j<16;j++)
      {
	  fprintf(stdout,"%c",*(hexarray+j));
      }


return;

}

//converting double precision number to hexadecimal
void doubptoHexa(char argv[]){
int intvalue,k,j,number=(int)atof(argv);
float fnumber,value;
int array1[]={},array2[64]={0},binarray[64]={},expo=0;
char hexarray[16]={};
if(atof(argv)<0){
	binarray[0]=1;
	number=number*(-1);
	fnumber=(atof(argv)-(int)atof(argv))*-1;
	
}
else{
	binarray[0]=0;
	fnumber=atof(argv)-(int)atof(argv);
	
}

for(j=0;j>=0;j++){
	
array1[j]=number%2;
number=number/2;
if(number==0) break;
	
}



for(int i=0;i<64;i++){

array2[i]=fnumber*2;	
fnumber=fnumber*2;

if(array2[i]==1)fnumber=fnumber-1;

if(fnumber==0.000000 ) {break;}
	
}


if((int)atof(argv)>=1||(int)atof(argv)<=-1){
expo=j+1023;

for(int i=1;i<12;i++){
	binarray[12-i]=expo%2;
	expo=expo/2;

}
j=j-1;
for(int i=12;i<64;i++){
	binarray[i]=array1[j];
	if(j==0) break;
	j--;
	k=i;

	
}
int m=0;
for(k=k+1;k<64;k++){
	
	binarray[k]=array2[m];
m=m+1;
}




}
else{
	k=0;
	while(array2[k]==0){
	k=k+1;	}
expo=1023-(k+1);

for(int i=1;i<12;i++){
	binarray[i]=expo%2;
	expo=expo/2;
}
for(int i=0;i<53;i++){
	binarray[i+12]=array2[k+1];
	k=k+1;
}
}

k=-1;
for(int i=0;i<8;i++)
{    
     j=0;
	 value=0;
    
	for(k=k+1;k<64;k++)
	{
	value=value+(binarray[i])*pow(2,3-j);
    j=j+1;
    if(j==4) break;	
	}	
	intvalue=(int)value;
	
	
	if(intvalue==10) hexarray[i]='A';
	else if(intvalue==11) hexarray[i]='B';
	else if(intvalue==12) hexarray[i]='C';
	else if(intvalue==13) hexarray[i]='D';
	else if(intvalue==14) hexarray[i]='E';
	else if(intvalue==15) hexarray[i]='F';
	else{
		hexarray[i]=intvalue+'0';
		
	}
}




fprintf(stdout,"0x");
for(int i=0;i<16;i++){
	fprintf(stdout,"%c",hexarray[i]);
}
return;
}

//converting hexadecimal number to double precision float
void hexatoDoubleprici(char argv[]){

int val,k=-1,kk, Binary[64];	
char Bin[64];	
	
	//geting the decimal number
for(int i=15;i>=0;i--)	
{
  if(argv[i]=='A')
  {
   val=10;
  }
  else if(argv[i]=='B')
  {
   val=11;
  }
  else if(argv[i]=='C')
  {
   val=12;
  } 
  else if(argv[i]=='D')
  {val=13;
  }
  else if(argv[i]=='E')
  {
   val=14;
  }
  else if(argv[i]=='F')
  {
   val=15;
  }
  else
  {
	  val=argv[i]-'0';
  }	  
  kk=0;

  for(k=k+1;k<64;k++)
  {  
      kk=kk+1;
	  Binary[k]=val%2;
	  val=val/2;
	  if(kk==4)break;
	  
  }  
  
  
}

 for(int i=0;i<64;i++)
 {
	 Bin[i]=Binary[63-i]+'0';
 }

	
fprintf(stdout,"%lf",binarytoDoubp(Bin));	
	
	return ;
}
