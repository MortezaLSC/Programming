#include <stdio.h>

int main(){
  double x, y;
  int a, b, c;
  int *p;
  .
  .
  .
    p = &c;  // It means p = 0x0012ff64  ,,, we see &p = 0x0012ff60
    a = c    // a = 256
    a = *p  //  at first p is address of c, it goes to memory and put values of p indide eachother
            //  which is 0x0012ff64 so it points to that address and put the value of that address to a
            //  so again we have : a = 256
  .
  .
  .
  .

      }

sizeof(int)    = 4  ====> It means if you enter integer variables, addresses would increase 4 bytes by 4 bytes
sizeof(double) = 8  ====> It means if you enter double variables, addresses would increase 8 bytes by 8 bytes

  Then we have:
                                                          ------------------
                                            0x0012ff6c   |                  | a
                                                          ------------------
                                                          ------------------
                                            0x0012ff68   |                  | b
                                                          ------------------
                                                          ------------------
                                            0x0012ff64   |                  | c
                a is 4 bytes after b                      ------------------
                                                          ------------------
                                            0x0012ff78   |                  | x
                x is 8 bytes after y                      ------------------
                                                          ------------------
                                            0x0012ff70   |                  | y
                                                          ------------------
                                                          
  More detailed in graphical mode:
  IN MEMORY:(whole memory)
  LE = Little Endian  (INTEL)
  BE = Big Endian     (MIPS)
                                                          ------------------
                                            0x00000000   |                  | ?
                                                          ------------------
                                                 .                 .
                                                 .                 .
                                                 .                 .
                                                          ------------------
                                            0x0012ff60   |  64(LE)  00(BE)  | 
                                                          ------------------
                                                          ------------------
                                            0x0012ff61   |  ff(LE)  12(BE)  | 
                                                          ------------------
                                                          ------------------
                                            0x0012ff62   |  12(LE)  ff(BE)  | 
                                                          ------------------
                                                          ------------------
                                            0x0012ff63   |  00(LE)  64(BE)  | 
                                                          ------------------
                                                    
                                                          ------------------
                                            0x0012ff64   | 00(LE)   00(BE)  |  c         if c = 256        (base10)
                                                          ------------------                c = 0x00000100 (base16)
                                                          ------------------
                                            0x0012ff65   | 01(LE)   00(BE)  |  c   0x0012ff64 points to c variable
                                                          ------------------       0x0012ff64 is a pointer
                                                          ------------------
                                            0x0012ff66   | 00(LE)   01(BE)  |  c
                                                          ------------------
                                                          ------------------
                                            0x0012ff67   | 00(LE)   00(BE)  |  c 
                                                          ------------------
                                                          ------------------
                                            0x0012ff68   |                  |  b
                                                          ------------------
                                                                   .
                                                                   .
                                                                   .
                                                          ------------------
                                            0x0012ff6c   |                  |  a
                                                          ------------------
                                                                   .
                                                                   .
                                                                   .
                                                          ------------------
                                            0x0012ff70   |                  |  y
                                                          ------------------
                                                          ------------------
                                            0x0012ff71   |                  |  y
                                                          ------------------  
                                                          ------------------
                                            0x0012ff72   |                  |  y
                                                          ------------------
                                                          ------------------
                                            0x0012ff73   |                  |  y
                                                          ------------------
                                                          ------------------
                                            0x0012ff74   |                  |  y
                                                          ------------------
                                                          ------------------
                                            0x0012ff75   |                  |  y
                                                          ------------------
                                                          ------------------
                                            0x0012ff76   |                  |  y
                                                          ------------------
                                                          ------------------
                                            0x0012ff77   |                  |  y
                                                          ------------------
                                                                  .
                                                                  .
                                                                  .
                                                          ------------------
                                            0x0012ff78   |                  |  x
                                                          ------------------
                                                                  .
                                                                  .
                                                                  .
                                                          ------------------
                                            0xfffffffff  |                  |  ?
                                                          ------------------
                                                        
                                                        
                                                        
