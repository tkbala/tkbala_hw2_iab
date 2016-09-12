/*
   Copyright (c) 2016 RedBear

   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.
*/

/*
   SYSTEM_MODE:
       - AUTOMATIC: Automatically try to connect to Wi-Fi and the Particle Cloud and handle the cloud messages.
       - SEMI_AUTOMATIC: Manually connect to Wi-Fi and the Particle Cloud, but automatically handle the cloud messages.
       - MANUAL: Manually connect to Wi-Fi and the Particle Cloud and handle the cloud messages.

   SYSTEM_MODE(AUTOMATIC) does not need to be called, because it is the default state.
   However the user can invoke this method to make the mode explicit.
   Learn more about system modes: https://docs.particle.io/reference/firmware/photon/#system-modes .
*/
#if defined(ARDUINO)
SYSTEM_MODE(SEMI_AUTOMATIC);
#endif

#define NA 123

#define K1 D2
#define K2 D5
#define K3 D17
#define K4 D1
#define K5 D4
#define K6 D7
#define K7 D0
#define K8 D3
#define K9 D6
#define K10 D16
/* Keypad pins are numbered as follows
    K1 K2 K3
    K4 K5 K6
    K7 K8 K9 K10
*/

/* Status LED definitions */
#define MODE9K D12
#define SCHR D13
#define DIG D14
#define CAPS D15
#define DTIMEOUT 500 // Time delay for entering digits
#define TIMEOUT 1500 // Time delay between entering charachters
#define STIMEOUT 1000 //Time delay between switching mode using key K10
#define MAXLINKS 20 // No. of maximum connections between dots in gesture mode
#define NCHARS 56 //No. of gesture-defined characters
#define K10SAMP 4096

int k10flag = 0; // 4 for CAPS ; 3 for Entering Digits in 9-key mode; 2 for entering special characters in 9-key mode; 1 for entering 9-key mode
/* Charachter Gesture definitions */

int A[] = {K7, K4, K1, K2, K3, K6, K9, K4, K5, K6};
int B[] = {K1, K4, K7, K1, K2, K3, K6, K5, K4, K5, K6, K9, K8, K7};
int C[] = {K3, K2, K1, K4, K7, K8, K9};
int D[] = {K1, K4, K7, K1, K2, K3, K6, K9, K8, K7};
int E[] = {K1, K4, K7, K1, K2, K3, K4, K5, K6, K7, K8, K9};
int F[] = {K2, K5, K8, K2, K3, K5, K6};
int G[] = {K3, K2, K1, K4, K7, K8, K9, K6, K5};
int H[] = {K1, K4, K7, K4, K5, K6, K3, K6, K9};
int I[] = {K1, K2, K3, K2, K5, K8, K7, K8, K9};
int J[] = {K1, K2, K3, K2, K5, K8, K7};
int K[] = {K2, K5, K8, K5, K3, K5, K9};
int L[] = {K1, K4, K7, K8, K9};
int M[] = {K1, K4, K7, K1, K5, K3, K6, K9};
int N[] = {K7, K4, K1, K5, K9, K3, K6};
int O[] = {K2, K1, K4, K7, K8, K9, K6, K3, K2};
int P[] = {K2, K5, K8, K2, K3, K6, K5};
int Q[] = {K2, K1, K4, K7, K8, K9, K6, K3, K2, K5, K9};
int R[] = {K1, K4, K7, K1, K2, K3, K6, K5, K9};
int S[] = {K3, K2, K1, K4, K5, K6, K9, K8, K7};
int T[] = {K1, K2, K3, K2, K5, K8};
int U[] = {K1, K4, K7, K8, K9, K6, K3};
int V[] = {K1, K8, K3};
int W[] = {K1, K4, K7, K8, K5, K2, K5, K8, K9, K6, K3};
int X[] = {K1, K5, K9, K3, K5, K7};
int Y[] = {K1, K5, K3, K5, K8};
int Z[] = {K1, K2, K3, K5, K7, K8, K9};
int Qmark[] = {K2, K3, K6, K5, K8};
int Comma[] = {K8};
int Plus[]  = {K2, K5, K8, K4, K5, K6};
int Hyphen[] = {K4, K5};
int Uscore[] = {K7, K8};
int Emark[] = {K3, K6, K9};
int at[] = {K9, K8, K7, K4, K1, K2, K3, K6, K5};
int hash[] = {K1, K4, K7, K3, K6, K9, K1, K2, K3, K7, K8, K9};
int doll[] = {K3, K2, K1, K4, K5, K6, K9, K8, K7, K2, K5, K8};
int perc[] = {K1, K3, K5, K7, K9};
int expon[] = {K4, K2, K6};
int amb[]  = {K9, K5, K1, K2, K4, K7, K8, K6};
int star[] = {K2, K5, K8, K4, K5, K6, K1, K5, K9, K3, K5, K7};
int cbrac[] = {K3, K2, K5, K8, K9};
int icbrac[] = {K2, K3, K6, K9, K8};
int equ[] = {K1, K2, K4, K5};
int cubrac[] = {K2, K1, K5, K4, K5, K7, K8};
int icubrac[] = {K2, K3, K5, K6, K5, K9, K8};
int sbrac[] = {K2, K1, K4, K7, K8};
int isbrac[] = {K1, K2, K5, K8, K7};
int ors[] = {K1, K4, K7};
int colon[] = {K2, K8};
int scolon[] = {K2, K8, K7};
int quot[] = {K2, K4, K3, K5};
int apost[] = {K3, K5};
int flash[] = {K2, K7};
int blash[] = {K1, K8};
int fpost[] = {K1, K5};
int tild[] = {K4, K1, K2, K5, K6, K3};
int vbrac[] = {K2, K4, K8};
int ivbrac[] = {K2, K6, K8};
int* alpha[] = {&A[0], &B[0], &C[0], &D[0], &E[0], &F[0], &G[0], &H[0], &I[0], &J[0], &K[0], &L[0], &M[0], &N[0], &O[0], &P[0], &Q[0], &R[0], &S[0], &T[0], &U[0], &V[0], &W[0], &X[0], &Y[0], &Z[0], &Qmark[0], &Comma[0], &Plus[0], &Hyphen[0], &Uscore[0], &Emark[0], &at[0], &hash[0], &doll[0], &perc[0], &expon[0], &amb[0], &star[0], &cbrac[0], &icbrac[0], &equ[0], &cubrac[0], &icubrac[0], &ors[0], &sbrac[0], &isbrac[0], &colon[0], &scolon[0], &quot[0], &apost[0], &flash[0], &blash[0], &fpost[0], &tild[0], &vbrac[0], &ivbrac[0]};
int lalpha[] = {10, 14, 7, 10, 12, 7, 9, 9, 9, 7, 7, 5, 8, 7, 9, 7, 11, 9, 9, 6, 7, 3, 11, 6, 5, 7, 5, 1, 6, 2, 2, 3, 9, 12, 12, 5, 3, 8, 12, 5, 5, 4, 7, 7, 3, 5, 5, 2, 3, 4, 2, 2, 2, 2, 6, 3, 3};
//               A, B,  C,  D, E,  F, G, H, I, J, K, L, M, N, O, P,  Q, R, S, T, U, V,  W, X, Y, Z, ?, ,, +, -, _, !, @,  #,  $, %, ^, &,  *, (,),=,{,},|,[,],:,;,",',/,\,`,~,<,>
char calpha[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '?', ',', '+', '-', '_', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '=', '{', '}', '|', '[', ']', ':', ';', '"', '\'', '\\', '/', '`', '~', '<', '>'};
int kpad[10] = {K1, K2, K3, K4, K5, K6, K7, K8, K9, K10};
int modes[4] = {D12, D13, D14, D15 };
int gest[MAXLINKS];
int lgest = -1;
int prevPin = -1;
int currPin = -1;
int charID = 0;
unsigned long t0 = millis();
unsigned long t1 = millis();
void setup() {
  Serial.begin(9600);
  Serial.println("Started");
  for (int j = 0; j < 10; j++) {
    pinMode(kpad[j], INPUT_PULLDOWN);
  }
  for (int j = 0; j < 4; j++) {
    pinMode(modes[j], OUTPUT);
  }
}

void loop() {



  if (checkPins() != NA) {


    do {


      currPin = checkPins();
      if (k10flag == 3) {
        if ((millis() - t1) > DTIMEOUT) {
          t1 = millis();
          Serial.print(getNum(currPin));
        }

      }
      if (currPin == K10)
      {
        int tm = 0; // 0 if it is a single tap else takes the value of 1
        delay(STIMEOUT);
        while (readK10())
        {
          toggleK10flag();
          tm = 1;
          delay(STIMEOUT);
        }
        if (tm == 0) {
          if (k10flag == 3) {
            Serial.print('0');
          } else {
            Serial.print(" ");
          }
        }
      }
      else if (currPin != prevPin && currPin != NA) {
        t0 = millis();
        lgest++;
        gest[lgest] = currPin;
        prevPin = currPin;

      }
    } while ((millis() - t0) < TIMEOUT);
    //Serial.println(lgest + 1);
    char gen = checkAlpha(gest, lgest + 1);
    if ((int)gen < 123 && (int)gen > 65) {
      Serial.print(gen);
    }

    lgest = -1;
  }


}

char checkAlpha(int a[], int n) {
  for (int p = 0; p < NCHARS; p++) {
    if ( n == lalpha[p]) {

      if (isequal(alpha[p], a, n)) {
        if (k10flag == 4) {
          return (calpha[p]);
        } else {
          return ((char)(calpha[p] + 32));
        }
      }
    }
    //else{  Serial.print("Length Mismatch - ");Serial.print(n);Serial.print(" ");Serial.println(lalpha[p]);}
  }
}

int checkPins() {
  for (int i = 0; i < 10; i++) {
    if (digitalRead(kpad[i]) == HIGH) {
      //      Serial.print(i);
      return (kpad[i]);
    }
  }
  return (NA);
}

int isequal(int a[], int b[], int n) {

  for (int k = 0; k < n; k++) {

    //Serial.print(" <-- ");Serial.print(a[k]);Serial.println();

    if (a[k] != b[k]) {
      return (0);
    }
  }
  return (1);
}

int readK10() {
  int sm = 0;
  for (int r = 0; r < K10SAMP; r++) {
    sm += digitalRead(K10);
  }

  if (sm > 0.75 * K10SAMP) {
    return 1;
  }
  else {
    return 0;
  }
}
void toggleK10flag() {
  if (k10flag == 4) {
    k10flag = 0;
  }

  else {
    k10flag++;
  }

  for (int n = 1; n <= 4; n++) {
    if (n == k10flag) {
      digitalWrite(modes[n - 1], HIGH);
    }
    else {
      digitalWrite(modes[n - 1], LOW);
    }
  }
}
char getNum(int tmn) {
  char ret = '!';
  switch (tmn) {
    case K1: ret = '1'; break;
    case K2: ret = '2'; break;
    case K3: ret = '3'; break;
    case K4: ret = '4'; break;
    case K5: ret = '5'; break;
    case K6: ret = '6'; break;
    case K7: ret = '7'; break;
    case K8: ret = '8'; break;
    case K9: ret = '9'; break;

  }
  return (ret);
}
