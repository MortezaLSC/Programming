//This program is written by "MortezaLSC" on 5, May 2013 at 10:30 AM
//Gets a number in current base and converts it to desiered base.

#include <stdio.h>
#include <math.h>

int CB, DB;
 void base(void)
 {
   int num2[100], i=-1,j;
   char num1[100], ch;
   long int num1=0, num2=0;

   printf("Enter your num: ");
   scanf("%c", &ch);
   
   do
     {
       i++;
       scanf("%c", &num1[i]);
     } while(num1[i]!='\n');
   
   j=i-1;
   for(i=j;i>=0;i--)
     { //converts the base to 10.                                                                                                                                 
       if(num1[i]<='9'&& num1[i]>='0')
	 {
	   num1+=((long int)pow((float)CB,(j-i)))*(((int)num1[i])-48);  //converting ascii code to num                                         
	 }
       else if(num1[i]<='Z'&&num1[i]>='A')
	 {
	   num1+=((long int)pow((float)CB,(j-i)))*(((int)num1[i])-55);
	 }
       else if(num1[i]<='z'&&num1[i]>='a')
	 {
	   num1+=((long int)pow((float)CB,(j-i)))*(((int)num1[i])-87);
	 }
     }
   
   i=0;
   while(num1>=DB)
     { //converts the base to b. (START)                                                                                                                             
       num2[i]=num1%DB;
       i++;
       num1/=DB;
     }
   
   num2[i]=num1; //converts the base to b. (END)                                                                                                                                
   printf("\nResult: \n");
   
   for(;i>=0;i--)
     { //prints the result.                                                                                                                                          
       if(num2[i]<=9&&num2[i]>=0){
	 printf("%d",num2[i]);
       }
       
       else if(num2[i]>=10&&num2[i]<=35){
	 printf("%c",(char)(num2[i]+55));
       }
     }
 }

 void main(void)
 {
   printf("Guide: You must enter \"Current Base & Desired Base\" between 2 adn 32...");
   printf("\nEnter current base: ");
   scanf("%d", &CB);
   
   printf("\nEnter desired base: ");
   scanf("%d", &DB);
   
   base();
   getchar();
   printf("\n");
   
 }
