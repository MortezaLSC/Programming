#include <iostream>
using namespace std;
//Write a program to solve this puzzle:
//Do we have a number that has 5 digits with the following conditions?
// 1) Sum of all digits is 30
// 2) Second gigit plus third digit is 10
// 3) Sum of Third digit and fifth digit is 14
// 4) First digit is 2*(second digit) - 1
// 5) fourth digit is second digit plus

int main(){
  int x1, x2, x3, x4, x5;
  
  for(x1=1 ; x1<10; x1++)
    for(x2=0 ; x2<10; x2++){
      if(x1!=2*x2-1)
	continue;
      for(x3=0 ; x3<10; x3++){
	if(x2+x3!=10)
	  continue;
	for(x4=0 ; x4<10; x4++){
	  if(x4!=x2+1)
	    continue;
	  for(x5=0 ; x5<10; x5++){
	    if(x5+x3!=14)
	      continue;
	    if(x1+x2+x3+x4+x5!=30)
	      continue;
	    cout << "ans: " << x1 << x2 << x3 << x4 << x5
		 << endl;
	  }
	}
      }
    }
}
