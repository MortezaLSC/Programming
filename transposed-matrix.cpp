//This program is written by "MortezaLSC" on Thursday, 23 January 2014 at 11:43 PM

#include <iostream>
using namespace std;

int main(){
  int i, j, n=1, m=2;
  int a[n][m], b[m][n];
  
  cout << "----                           ----\n"
       << "| a[1,1]   a[1,2]   . . .  a[1,n] |\n"
       << "| a[2,1]   a[2,2]   . . .  a[2,n] |\n"
       << "|  .        .    .          .     |\n"
       << "|  .        .      .        .     |\n"
       << "|  .        .        .      .     |\n"
       << "| a[m,1]   a[m,2]   . . .  a[m,n] |\n"
       << "----                           ----\n";
  
  cout << "ENTER MATRIX nXm ";
  cin >> n >> m;

  cout << "ENTER MATRIX VALUES:\n";
  
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      cin >> a[i][j];
    }
  }
  
  cout << "MATTRIX " << n << "X" << m << " is:\n";
  for(i=0; i<n; i++){
    for(j=0; j<m; j++){
      cout << a[i][j] << "\t";
    }
    cout << endl;
  }
  
  cout << "TRANSPOSED MATRIX(" <<  n << "X" << m << ")=" << m << "X" << n << " is:\n";
  for(j=0; j<m; j++){
    for(i=0; i<n; i++){
      cout << a[i][j] << "\t";
      b[j][i] = a[i][j];
    }
    cout << endl;
  }
}
