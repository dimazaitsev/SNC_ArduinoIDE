// Conceptual disign of Embedded System based on Finite Automaton
// Example: Vending Machine selling chocolate bars - milk and dark
//
// VM = (X,Q,Y,Q_INIT)
// X - inputs; Q - states; Y -outputs; Q_INIT - initial state
// X: none, coin, chocolate, return
// Q: 0 coin, 1 coin, 2 coin, 3 coin
// Y: none, coin, milk chocolate, dark chocolate, 
// Cost: mill chocolate = 2 coins, dark chocolate = 3 coins
//
// Debug: https://wokwi.com/projects/396320866049857537

int d=0; // debug mode if d>0

// finite autonaton 
// can be generated on FA state diagram and included as
// #include "fa.h"
#define NX 4 // number of input symbols
#define NQ 4 // number of states
#define NY 4 // number of output symbols
#define Q_INIT 0 // initial state
static int qt[NQ][NX]={
  {0,1,0,0},
  {1,2,1,0},
  {2,3,0,1},
  {3,3,0,2}
}; // input matrix NQ x NX, range NQ
static int yt[NQ][NX]={
  {0,0,0,0},
  {0,0,0,1},
  {0,0,2,1},
  {0,1,3,1}
}; // output matrix NQ x NX, range NY
static int q=Q_INIT,y=0;
static volatile int x=0;
// end of finite autonaton 

// pin mapping 
// can be generated on FA state diagram annotation and included as
// #include "pin_map.h"
static int in_pins[NX]={-1,15,14,13};
static int out_pins[NY]={-1,16,17,18};
void IR_Read1() { x=1; }
void IR_Read2() { x=2; }
void IR_Read3() { x=3; }
void Init_IR()
{
  attachInterrupt(digitalPinToInterrupt(in_pins[1]), IR_Read1, RISING);
  attachInterrupt(digitalPinToInterrupt(in_pins[2]), IR_Read2, RISING);
  attachInterrupt(digitalPinToInterrupt(in_pins[3]), IR_Read3, RISING);
}
// end of pin mapping

void setup() {
  int i;
  for(i=1;i<NX;i++) {
      pinMode(in_pins[i], INPUT_PULLUP);
  }
  delay(100);
  Init_IR();
  for(i=1;i<NY;i++) {
      pinMode(out_pins[i], OUTPUT);
      digitalWrite(out_pins[i],LOW);
  }
  if(d>0) {
    Serial1.begin(115200);
    Serial1.println("Hello from FA");
  }
  x=0;
}

void Trans()
{
  y=yt[q][x];
  q=qt[q][x];
}

void WriteSym()
{
  if( (out_pins[y]>=0)) {
    digitalWrite(out_pins[y],HIGH);
    delay(1000);
    digitalWrite(out_pins[y],LOW);
  }
}

void loop() {
  if( x>0 ) {
if(d>0) Serial1.println("input "+String(x));
    Trans();
if(d>0) Serial1.println("state "+String(q));
    WriteSym();
if(d>0) Serial1.println("output "+String(y));
    x=0;
  }
}
