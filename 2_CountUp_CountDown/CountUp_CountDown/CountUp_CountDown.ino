#define SEG_A 7
#define SEG_B 6
#define SEG_C 5
#define SEG_D 4
#define SEG_E 3
#define SEG_F 2
#define SEG_G 1
#define SEG_P 0
#define D1 A0
#define D2 A1
#define D3 A2
#define D4 A3
#define SWITCH1 8
#define SWITCH2 9

#define DELAY_5MS 5

int n = 0;
int IncrementSwitchState = 0;
int DecrementSwitchState = 0;
int prevIncrementSwitchState = 0;
int prevDecrementSwitchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);
  pinMode(SEG_P, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(SWITCH1, INPUT);
  pinMode(SWITCH2, INPUT);
}

void loop() {
  // Read State of push button
  IncrementSwitchState = digitalRead(SWITCH1);
  DecrementSwitchState = digitalRead(SWITCH2);

  if (IncrementSwitchState == LOW && prevIncrementSwitchState == HIGH) 
  {
    n++;

    if (n > 9999)
    {
      n = 9999;
    }
  }
  else if (DecrementSwitchState == LOW && prevDecrementSwitchState == HIGH)
  {
    n--;

    if (n < 0) 
    {
      n = 0;
    }
  }

  prevIncrementSwitchState = IncrementSwitchState;
  prevDecrementSwitchState = DecrementSwitchState;
  
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber((int)n/1000);// get the value of thousand
  delay(DELAY_5MS);

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d1
  pickNumber(((int)n%1000)/100);// get the value of thousand
  delay(DELAY_5MS);

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d1
  pickNumber(((int)n%100)/10);// get the value of thousand
  delay(DELAY_5MS);

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d1
  pickNumber((int)n%10);// get the value of thousand
  delay(DELAY_5MS);
}

void pickDigit(int x) //light up a 7-segment display
{
  //The 7-segment LED display is a common-cathode one. So also use digitalWrite to  set d1 as high and the LED will go out
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);

  switch(x)
  {
    case 0: 
    digitalWrite(D1, HIGH);//Light d1 up 
    break;
    case 1: 
    digitalWrite(D2, HIGH); //Light d2 up 
    break;
    case 2: 
    digitalWrite(D3, HIGH); //Light d3 up 
    break;
    default: 
    digitalWrite(D4, HIGH); //Light d4 up 
    break;
  }
}

void pickNumber(int x)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    break;
  }
} 

void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
  digitalWrite(SEG_P, HIGH);
}

void zero()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, HIGH);
}

void one()
{
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
}

void two()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, LOW);
}
void three()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, LOW);
}

void four()
{
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
}

void five()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
}

void six()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
}

void seven()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, HIGH);
  digitalWrite(SEG_G, HIGH);
}

void eight()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
}

void nine()
{
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, HIGH);
  digitalWrite(SEG_F, LOW);
  digitalWrite(SEG_G, LOW);
}
