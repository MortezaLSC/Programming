#include <iostream>
using namespace std;


int base2toten(int nums);
int base8toten(int num);

////////////////////////////////////////////
/*   FUNCTION: CONVERTING BASE 2 TO 10   */
////////////////////////////////////////////
int base2to10(int nums){
int base2,
    digits,
    base10=0,
    parts,
    powers=1;

  cout << "Enter num base 2: ";
  cin >> base2;

  digits = base2;
  
  while(digits){ 
    parts = digits % 10;
    digits /= 10;
    base10 += powers * parts;
    powers *= 2;	
}
  cout << " \"base2\"" << "\t\t\"base10\"\n"
       << "  " << base2 << "\t\t  " << base10 << endl;
}


///////////////////////////////////////////
/*   FUNCTION: CONVERTING BASE 8 TO 10   */
///////////////////////////////////////////
int base8to10(int num){
  int base8,
    digit,
    base10=0,
    part,
    power=1;

  cout << "Enter num base 8: ";
  cin >> base8;

  digit = base8;

  while(digit){
    part = digit % 10;
    digit /= 10;
    base10 += power * part;
    power *= 8;
  }
  cout << "\"base8\"" << "\t\t\"base10\"\n"
       << "  " << base8 << "\t\t  " << base10 << endl;
}


//////////////////////////////////////////
/*           FUNCTION: MAIN             */
//////////////////////////////////////////
int main(){
  int num,nums,a ,b,ans;

  cout << "*******************************************************\n"
       << "*            BASE TWO:                2               *\n"
       << "*            BASE EIGHT:              8               *\n"
       << "*            BOTH BASE TWO AND EIGHT: 28              *\n"
       << "*******************************************************\n";

  cout << "What base you want to convert? ";
  cin >> ans;
  
  if(ans != 2 && ans != 8 && ans != 28){
    cout << "Your answer in not acceptable!!!\n";
  }
  
  else if(ans == 2){
    cout << "**********************************\n"
         << "*     YOU'VE CHOSEN BASE 2       *\n"
         << "**********************************\n";
    base2to10(a);  
  }

  else if(ans == 8){
    cout << "**********************************\n"
	 << "*     YOU'VE CHOSEN BASE 8       *\n"
	 << "**********************************\n";
    base8to10(b);
  }
  
  else if(ans == 28){
    cout << "*********************************************\n"
	 << "*     YOU'VE CHOSEN BOTH BASE 2 AND 8       *\n"
	 << "*********************************************\n";
    base2to10(a);
    base8to10(b);
  }
 
  return 0;
}
