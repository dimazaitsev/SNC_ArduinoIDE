// SN pin map
#define MI 3
#define MO 3
static int in_places[MI]={4,5,6};
static int in_pins[MI]={15,14,13};
volatile static int in_mu[MI]={0,0,0};
static int out_places[MO]={7,8,9};
static int out_pins[MO]={16,17,18};
void IR_Read0() { in_mu[0]=1; go=1; }
void IR_Read1() { in_mu[1]=1; go=1; }
void IR_Read2() { in_mu[2]=1; go=1; }
void Init_pins_IR()
{
  int i;
  for(i=0;i<MI;i++)
    pinMode(in_pins[i], INPUT_PULLUP);
  for(i=0;i<MO;i++){
    pinMode(out_pins[i], OUTPUT);
    digitalWrite(out_pins[i],LOW);
  }
  attachInterrupt(digitalPinToInterrupt(in_pins[0]), IR_Read0, RISING);
  attachInterrupt(digitalPinToInterrupt(in_pins[1]), IR_Read1, RISING);
  attachInterrupt(digitalPinToInterrupt(in_pins[2]), IR_Read2, RISING);
}
void ReadIn()
{
  int pi;
  for(pi=0;pi<MI;pi++)
    if(in_mu[pi]>0)
    {
      mu[in_places[pi]]=in_mu[pi];
      in_mu[pi]=0;
    } 
}
void WriteOut()
{
  int po;
  for(po=0;po<MO;po++)
    if(mu[out_places[po]]>0)
    {
      digitalWrite(out_pins[po],HIGH);
      delay(1000);
      digitalWrite(out_pins[po],LOW);
      mu[out_places[po]]=0;
    }
}
// end of SN pin map
