// Finite automaton in Arduino IDE, debugged in Wokwi and on Raspberry Pi Pico
// https://wokwi.com/
//
// Example for chocolate vending machine:
// VM = (X,Q,Y,Q_INIT)
// X: none, chocolate, coin, return
// Q: 0, 1 coin, 2 coin, 3 coin
// Y: none, milk chocolate, coin, dark chocolate
// Cost: mill chocolate = 2 coins, dark chocolate = 3 coins
//
// To try on hardware: X <- 3 buttons; Y -> 3 LEDs

#define NX 4 // number of input symbols
#define NQ 4 // number of states
#define NY 4 // number of output symbols
#define Q_INIT 0 // initial state
static int qt[NQ][NX]={
  {0,0,1,0},
  {1,1,2,0},
  {2,0,3,1},
  {3,0,3,2}
}; // transition matrix NQ x NX, range NQ
static int yt[NQ][NX]={
  {0,0,0,0},
  {0,0,0,2},
  {0,1,0,2},
  {0,3,2,2}
}; // output matrix NQ x NX, range NY
static int q=Q_INIT,y=0;
static volatile int x=0;

static int in_pins[NX] {-1,13,15,14};

static int out_pins[NY] {-1,17,16,18};

void setup() {
  int i;
  for(i=1;i<NX;i++)
  {
      pinMode(in_pins[i], INPUT_PULLUP);
  }
  delay(100);
  attachInterrupt(digitalPinToInterrupt(in_pins[1]), IR_Read1, RISING);
  attachInterrupt(digitalPinToInterrupt(in_pins[2]), IR_Read2, RISING);
  attachInterrupt(digitalPinToInterrupt(in_pins[3]), IR_Read3, RISING);
  for(i=1;i<NY;i++)
  {
      pinMode(out_pins[i], OUTPUT);
      digitalWrite(out_pins[i],LOW);
  }
  Serial1.begin(115200);
  Serial1.println("Hello from FA");
  x=0;
}

void IR_Read1() { x=1; }
void IR_Read2() { x=2; }
void IR_Read3() { x=3; }

int Trans()
{
  y=yt[q][x];
  q=qt[q][x];
}

int WriteSym()
{
  if( (out_pins[y]>=0))
  {
    digitalWrite(out_pins[y],HIGH);
    delay(1000);
    digitalWrite(out_pins[y],LOW);
  }
}

void loop() {
  if( x>0 ) {
    Serial1.println("input "+String(x));
    Trans();
    Serial1.println("state "+String(q));
    WriteSym();
    Serial1.println("output "+String(y));
    delay(1000);
    x=0;
  }
  
}

// end of FAA, @ Dmitry Zaitsev, May 25, 2024, daze@acm.org

