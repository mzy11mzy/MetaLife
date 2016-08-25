#include <NewPing.h>

const int sensor_num = 6, max_distance = 100;
int trigger_pins[6] = {30, 31, 32, 33, 34, 35}, 
    echo_pins[6] = {A0, A1, A2, A3, A4, A5},
    out_pins[6] = {38, 39, 40, 41, 42, 43},
    count = 0,
    pinnum = 0,
    flag = 0;
    
NewPing *sonar[6];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(38,OUTPUT);
  pinMode(39,OUTPUT);
  pinMode(40,OUTPUT);
  pinMode(41,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(43,OUTPUT);
  for (int i = 0; i < sensor_num; ++i)
    sonar[i] = new NewPing(trigger_pins[i], echo_pins[i], max_distance);
  for (int i=0;i<sensor_num;++i)
    {
        digitalWrite(out_pins[i],HIGH);
    }  
}
  

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  for (int i = 0; i < sensor_num; ++i)
  {
    Serial.print("#");
    Serial.print(i);
    Serial.print(sonar[i]->ping_cm());
    Serial.println("cm");
    if (sonar[i]->ping_cm() <= 30 && sonar[i]->ping_cm() != 0)
    {
      flag = 1;
      clean();
      //delay(500);
      break;
    }
  }
  if (flag == 1)
    {
      clean();
      flag = 0;
    }
    else work();
}

void work()
{
  if (count<20)
    { digitalWrite(out_pins[pinnum],LOW);
      delay(2);
      count++;    
    }
  else 
    { count = 0;
      digitalWrite(out_pins[pinnum],HIGH);
      pinnum = random(0,4);  
    }
}

void clean()
{ 
  for(int i=0;i<sensor_num;i++)
{
  digitalWrite(out_pins[i],HIGH);
  delay(10);
}
}


