#include <stdio.h>

int main(){
  double x, y;
  int a, b, c;
  
  .
  .
  .
  .

}

sizeof(int)    = 4  ====> It means if you enter integer variables, addresses would increase 4 bytes by 4 bytes
sizeof(double) = 8  ====> It means if you enter double variables, addresses would increase 8 bytes by 8 bytes

Then we have:
                                                          ------------
                                                    a    | 0x0012ff6c |
                                                          ------------
                                                          ------------
                                                    b    | 0x0012ff68 |
                                                          ------------
                                                          ------------
                                                    c    | 0x0012ff64 |
                a is 4 bytes after b                      ------------
                                                          ------------
                                                    x    | 0x0012ff78 |
                x is 8 bytes after y                     ------------
                                                          ------------
                                                    y    | 0x0012ff70 |
                                                          ------------
                                                          
More detailed in graphical mode:
                              IN MEMORY:(whole memory)
                              LE = Little Endian
                              BE = Big Endian
                                                          ------------------
                                            0x00000000   |                  | ?
                                                          ------------------
                                                .                .
                                                .                .
                                                .                .
                                                    
                                                          -----------------
                                            0x0012ff64   | 00(LE)   00(BE) |  c              if c = 256 (base10)
                                                          -----------------                     c = 0x00000100
                                                          -----------------
                                            0x0012ff65   | 01(LE)   00(BE) |  c   0x0012ff64 points to c variable
                                                          -----------------       0x0012ff64 is a pointer
                                                          -----------------
                                            0x0012ff66   | 00(LE)   01(BE) |  c
                                                          -----------------
                                                          -----------------
                                            0x0012ff67   | 00(LE)   00(BE) |  c
                                                          -----------------
                                                          -----------------
                                            0x0012ff68   |                 |  b
                                                          -----------------
                                                                 .
                                                                 .
                                                                 .
                                                          -----------------
                                            0x0012ff6c   |                 |  a
                                                          -----------------
                                                                 .
                                                                 .
                                                                 .
                                                          -----------------
                                            0x0012ff70   |                 |  y
                                                          -----------------
                                                          -----------------
                                            0x0012ff71   |                 |  y
                                                          -----------------  
                                                          -----------------
                                            0x0012ff72   |                 |  y
                                                          -----------------
                                                          -----------------
                                            0x0012ff73   |                 |  y
                                                          -----------------
                                                          -----------------
                                            0x0012ff74   |                 |  y
                                                          -----------------
                                                          -----------------
                                            0x0012ff75   |                 |  y
                                                          -----------------
                                                          -----------------
                                            0x0012ff76   |                 |  y
                                                          -----------------
                                                          -----------------
                                            0x0012ff77   |                 |  y
                                                          -----------------
                                                                .
                                                                .
                                                                .
                                                          -----------------
                                            0x0012ff78   |                 |  x
                                                          -----------------
                                                                .
                                                                .
                                                                .
                                                          -----------------
                                            0xfffffffff  |                 |  ?
                                                          -----------------
                                                        
                                                        
                                                        
