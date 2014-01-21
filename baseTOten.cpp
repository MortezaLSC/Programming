//This program is written by "MortezaLSC" on Tuesday, 21 January 2014 at 11:25 PM

#include <iostream>
#include <typeinfo>

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
  powers=1,
  flag2=1;

  cout << "Enter num base 2: ";
  cin >> base2;

  digits = base2;
  
  while(digits){ 
    parts = digits % 10;

    if(parts > 1 || base2 < 0){
      cout << "The number you have entered is not base 2 !!!\n";
      flag2=0;
      break;
    }

    digits /= 10;
    base10 += powers * parts;
    powers *= 2;	
}
  
  if(flag2){
    cout << " \"base2\":\t" << base2  << "\n" 
	 << "\"base10\":\t" << base10 << endl;
  }
}


///////////////////////////////////////////
/*   FUNCTION: CONVERTING BASE 8 TO 10   */
///////////////////////////////////////////
int base8to10(int num){
  int base8,
    digit,
    base10=0,
    part,
    power=1,
    flag8=1;

  cout << "Enter num base 8: ";
  cin >> base8;

  digit = base8;

  while(digit){
    part = digit % 10;
    if(part > 7 || base8 < 0){
      cout << "The number you have entered is not base 8 !!!\n";
      flag8=0;
      break;
    }
    
    digit /= 10;
    base10 += power * part;
    power *= 8;
  }
  if(flag8){
    cout << "\"base8\":\t"   << base8  << "\n" 
	 << "\"base10\":\t"  << base10 << endl;
  }
}


//////////////////////////////////////////
/*           FUNCTION: MAIN             */
//////////////////////////////////////////
int main(){
  int num,nums,a ,b,ans;

  //  cout << "What base you want to convert?\n"
  cout << "*******************************************************\n"
       << "*            BASE TWO:                2               *\n"
       << "*            BASE EIGHT:              8               *\n"
       << "*            BOTH BASE TWO AND EIGHT: 28              *\n"
       << "*            BOTH BASE EIGHT AND TWO: 82              *\n"
       << "*******************************************************\n";

  cout << "What base you want to convert? ";
  cin >> ans;
  
  if(ans != 2 && ans != 8 && ans != 28 && ans !=82){
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

  else if(ans == 82){
    cout << "*********************************************\n"
	 << "*     YOU'VE CHOSEN BOTH BASE 8 AND 2       *\n"
	 << "*********************************************\n";
    base8to10(b);
    base2to10(a);
  }
 
  return 0;
}
