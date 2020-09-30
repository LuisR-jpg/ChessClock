//https://playground.arduino.cc/uploads/Main/MAX72XX_Schematic.jpg
//http://www.agspecinfo.com/pdfs/G/GM45641C.PDF

#include "LedControl.h"
LedControl lc=LedControl(6,5,4,1);
long delaytime = 1;
int m1, c1, d1, u1, m2, c2, d2, u2, DG1, DG2, DG3, DG4, DG5, DG6, DG7, DG8;
signed int am1, ac1, ad1, au1, am2, ac2, ad2, au2;
int aid1, aiu1, aid2, aiu2;
int TiempoB = 700, StatusP1, StatusP2, StatusMB, Boton, Entre;
#define Buzzer 13
#define LED1 11
#define LED2 10
#define BP1 9
#define BP2 8
#define MB 7

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,15);
  lc.clearDisplay(0);  
  for( int x = 12; x > 9; x--){pinMode (x, OUTPUT );}
  for( int y = 9; y > 6; y--){pinMode (y, INPUT );}
}

void Button(){
  StatusP1 = digitalRead(BP1);
  StatusP2= digitalRead(BP2);
  StatusMB = digitalRead(MB);
  
  if(StatusP1 == HIGH){
    delay(100);
    Boton = 1;
    BZ();
  }
  if(StatusP2 == HIGH){
    delay(100);
    Boton = 2;
    BZ();
  }
  if (StatusMB == HIGH){
    delay(300);
    Boton = 3;
    BZ();
  }
}

void BZ(){
  digitalWrite(Buzzer, HIGH);
  delay(TiempoB);
  digitalWrite(Buzzer, LOW);
}

void Print(){
  lc.setChar(0, 0, m1, false);
  delay(delaytime);
  lc.setChar(0, 1, c1, true);
  delay(delaytime);
  lc.setChar(0, 2, d1, false);
  delay(delaytime);
  lc.setChar(0, 3, u1, false);
  delay(delaytime);
  lc.setChar(0, 4, m2, false);
  delay(delaytime);
  lc.setChar(0, 5, c2, true);
  delay(delaytime);
  lc.setChar(0, 6, d2, false);
  delay(delaytime);
  lc.setChar(0, 7, u2, false);
  delay(delaytime);

  delay(Entre);

  lc.setChar(0, 0, DG1, false);
  delay(delaytime);
  lc.setChar(0, 1, DG2, true);
  delay(delaytime);
  lc.setChar(0, 2, DG3, false);
  delay(delaytime);
  lc.setChar(0, 3, DG4, false);
  delay(delaytime);
  lc.setChar(0, 4, DG5, false);
  delay(delaytime);
  lc.setChar(0, 5, DG6, true);
  delay(delaytime);
  lc.setChar(0, 6, DG7, false);
  delay(delaytime);
  lc.setChar(0, 7, DG8, false);
  delay(delaytime);

  delay(Entre);

  Button();
}

void Imprimir(){
  lc.setChar(0, 0, am1, false);
  delay(delaytime);
  lc.setChar(0, 1, ac1, true);
  delay(delaytime);
  lc.setChar(0, 2, ad1, false);
  delay(delaytime);
  lc.setChar(0, 3, au1, false);
  delay(delaytime);
  lc.setChar(0, 4, am2, false);
  delay(delaytime);
  lc.setChar(0, 5, ac2, true);
  delay(delaytime);
  lc.setChar(0, 6, ad2, false);
  delay(delaytime);
  lc.setChar(0, 7, au2, false);
  delay(delaytime);
  Button();
}

void loop() {
  Entre = 500;
  BZ();
  digitalWrite (LED1, HIGH);
  digitalWrite (LED2, HIGH); 
  DG1 = 'g';
  DG2 = 'g';
  DG3 = 'g';
  DG4 = 'g';
  DG5 = 'g';
  DG6 = 'g';
  DG7 = 'g';
  DG8 = 'g';
  Boton = 0;
  TiempoB = 50;
  while(Boton != 3){
    Print();
  }
  DG3 = d1;
  DG4 = u1;
  DG5 = m2;
  DG6 = c2;
  DG7 = d2;
  DG8 = u2;
  Entre = 100;
  TiempoB = 5;
  Boton = 0;
  while(Boton != 3){
    Boton = 0;
    Button();
    if(Boton == 2){
      c1++; 
      if(c1 == 10){
        c1 = 0;
        m1++;
        if(m1 == 6){
            m1 = c1 = 0;
        }
      }
    }
    Button();
    if(Boton == 1){
      c1--;
      if(c1 < 0){
        c1 = 9;
        m1--;
        if(m1 < 0){
          m1 = 5;
        }
      }
    }
    Print();
  }
  DG1 = m1;
  DG2 = c1;
  DG3 = DG4 = 'g';
  Boton = 0;
  while(Boton != 3) {
    Boton = 0;
    Button();
    if(Boton == 1){
      u1--;
      if(u1 < 0){
        u1 = 9;
        d1--;
        if(d1 < 0){
          d1 = 5;          
        }
      }
    }
    Button();
    if(Boton == 2){
      u1++;
      if(u1 == 10){
        u1 = 0;
        d1++;
        if(d1 == 6){
          d1 = 0;
        }
      }
    }
    Print();
  }
  DG3 = d1;
  DG4 = u1;
  DG5 = DG6 = 'g';
  Boton = 0;
  while(Boton != 3) {
    Boton = 0;
    Button();
    if(Boton == 1){
      c2--;
      if(c2 < 0){
        c2 = 9;
        m2--;
        if(m2 < 0){
          m2 = 5;          
        }
      }
    }
    Button();
    if(Boton == 2){
      c2++;
      if(c2 == 10){
        c2 = 0;
        m2++;
        if(c2 == 6){
          c2 = 0;
        }
      }
    }
    Print();
  }
  DG5 = m2;
  DG6 = c2;
  DG7 = DG8 = 'g';
  Boton = 0;
  while(Boton != 3) {
    Boton = 0;
    Button();
    if(Boton == 1){
      u2--;
      if(u2 < 0){
        u2 = 9;
        d2--;
        if(d2 < 0){
          d2 = 5;          
        }
      }
    }
    Button();
    if(Boton == 2){
      u2++;
      if(u2 == 10){
        u2 = 0;
        d2++;
        if(d2 == 6){
          d2 = 0;
        }
      }
    }
    Print();
  }
  am1 = m1;
  ac1 = c1;
  ad1 = d1;
  au1 = u1;
  am2 = m2;
  ac2 = c2;
  ad2 = d2;
  au2 = u2;
  int id1, iu1, id2, iu2;
  DG1 = m1 = 'g';
  DG2 = c1 = 'g';
  DG5 = m2 = 'g';
  DG6 = c2 = 'g';
  DG7 = aid2;
  DG8 = aiu2;
  DG3 = DG4 = 'g';
  id1 = aid1;
  iu1 = aiu1;
  id2 = aid2;
  iu2 = aiu2;
  Boton = 0;
  while(Boton != 3){
    Boton = 0;
    Button();
    if(Boton == 1){
      iu1--;
      if(iu1 < 0){
        iu1 = 9;
        id1--;
        if(id1 < 0){
          id1 = 5;
        }
      }
    }
    Button();
    if(Boton == 2){
      iu1++;
      if(iu1 == 10){
        iu1 = 0;
        id1++;
        if(id1 == 6){
          id1 = 0;
        }
      }
    }
    d1 = id1;
    u1 = iu1;
    d2 = id2;
    u2 = iu2;
    Print();
  }
  DG3 = d1;
  DG4 = u1;
  DG7 = DG8 = 'g';
  Boton = 0;
  while(Boton != 3){
    Boton = 0;
    Button();
    if(Boton == 1){
      iu2--;
      if(iu2 < 0){
        iu2 = 9;
        id2--;
        if(id2 < 0){
          id2 = 5;
        }
      }
    }
    Button();
    if(Boton == 2){
      iu2++;
      if(iu2 == 10){
        iu2 = 0;
        id2++;
        if(id2 == 6){
          id2 = 0;
        }
      }
    }
    d1 = id1;
    u1 = iu1;
    d2 = id2;
    u2 = iu2;
    Print();
  }
  aid1 = id1;
  aiu1 = iu1;
  aid2 = id2;
  aiu2 = iu2;

  m1 = am1;
  c1 = ac1;
  d1 = ad1;
  u1 = au1;
  m2 = am2;
  c2 = ac2;
  d2 = ad2;
  u2 = au2;
  DG1 = m1;
  DG2 = c1;
  DG3 = d1;
  DG4 = u1;
  DG5 = m2;
  DG6 = c2;
  DG7 = d2;
  DG8 = u2;
  int aam1 = am1, aac1 = ac1, aad1 = ad1, aau1 = au1;
  int aam2 = am2, aac2 = ac2, aad2 = ad2, aau2 = au2;
  Boton = 0;
  
  while(Boton != 3){
    Print();
CICLOS:
    while(Boton == 1){
      aam2 = am2;
      aac2 = ac2;
      aad2 = ad2;
      aau2 = au2;        
      ad1 = (ad1 + id1);
      if(ad1 > 5){
        ad1 = (ad1 - 6);
        ac1++;
        if(ac1 > 9){
          ac1 = 0;
          am1++;
        }
      }
      au1 = (au1 + iu1);
      if(au1 > 9){
        au1 = (au1 - 10);
        ad1++;
        if(ad1 > 5){
          ad1 = 0;
          ac1++;
          if(ac1 > 9){
            ac1 = 0;
            am1++;
          }
        }
      }
      if((aam2 == 0) & (aac2 == 0) & (aad2 == 0) & (aau2 == 0)){
        aad2 = (aad2 + id2);
        if(aad2 > 5){
          aad2 = (aad2 - 6);
          aac2++;
          if(aac2 > 9){
            aac2 = 0;
            aam2++;
          }
        }
        aau2 = (aau2 + iu2);
        if(aau2 > 9){
          aau2 = (aau2 - 10);
          aad2++;
          if(aad2 > 5){
            aad2 = 0;
            aac2++;
            if(aac2 > 9){
              aac2 = 0;
              aam2++;
            }
          }
        }        
      }
      Imprimir();
      while(Boton == 1){
        digitalWrite (LED1, LOW);
        digitalWrite (LED2, HIGH);
        for(am2 = aam2; am2 > -1; am2--){
          for(ac2 = aac2; ac2 > -1; ac2--){
            aac2 = 9;
            for(ad2 = aad2; ad2 > -1; ad2--){
              aad2 = 5;
              for(au2 = aau2; au2 > -1; au2--){
                aau2 = 9;
                Imprimir();
                for(long MS = 0; MS < 900; MS++){
                  delay(1);
                  Button();
                  if(Boton != 1){goto CICLOS;}
                }
                if((am2 == 0) & (ac2 == 0) & (ad2 == 0) & (au2 == 0)){
                  Boton = 3;
                  goto CICLOS;
                }
              }
            }
          }
        }
      }
    }
    while(Boton == 2){
      aam1 = am1;
      aac1 = ac1;
      aad1 = ad1;
      aau1 = au1;
      ad2 = (ad2 + id2);
      if(ad2 > 5){
        ad2 = (ad2 - 6);
        ac2++;
        if(ac2 > 9){
          ac2 = 0;
          am2++;
        }
      }
      au2 = (au2 + iu2);
      if(au2 > 9){
        au2 = (au2 - 10);
        ad2++;
        if(ad2 > 5){
          ad2 = 0;
          ac2++;
          if(ac2 > 9){
            ac2 = 0;
            am2++;
          }
        }
      }
      if((aam1 == 0) & (aac1 == 0) & (aad1 == 0) & (aau1 == 0)){
        aad1 = (aad1 + id1);
        if(aad1 > 5){
          aad1 = (aad1 - 6);
          aac1++;
          if(aac1 > 9){
            aac1 = 0;
            aam1++;
          }
        }
        aau1 = (aau1 + iu1);
        if(aau1 > 9){
          aau1 = (aau1 - 10);
          aad1++;
          if(aad1 > 5){
            aad1 = 0;
            aac1++;
            if(aac1 > 9){
              aac1 = 0;
              aam1++;
            }
          }
        }        
      }
      Imprimir();
      while(Boton == 2){
        digitalWrite (LED1, HIGH);
        digitalWrite (LED2, LOW);
        for(am1 = aam1; am1 > -1; am1--){
          for(ac1 = aac1; ac1 > -1; ac1--){
            aac1 = 9;
            for(ad1 = aad1; ad1 > -1; ad1--){
              aad1 = 5;
              for(au1 = aau1; au1 > -1; au1--){
                aau1 = 9;
                Imprimir();
                for(long MS = 0; MS < 900; MS++){
                  delay(1);
                  Button();
                  if(Boton != 2){goto CICLOS;}
                }
                if((am1 == 0) & (ac1 == 0) & (ad1 == 0) & (au1 == 0)){
                  Boton = 3;
                  goto CICLOS;
                }
              }
            }
          }
        }
      }
    }
  }
  TiempoB = 300;
  BZ();
  delay(100);
  TiempoB = 500;
  BZ();
  TiempoB = 50;
  Boton = 0;
  while(Boton != 3){
    Imprimir();
    if(((am1 > 0) | (ac1 > 0) | (ad1 > 0) | (au1 > 0)) & ((am2 > 0) | (ac2 > 0) | (ad2 > 0) | (au2 > 0))){
      int Estado;
      Estado = digitalRead(LED1);
      if(Estado == HIGH){
        if(Boton == 1){goto CICLOS;}
      }
      else {
        if(Boton == 2){goto CICLOS;}
      }
    }
  }
}
