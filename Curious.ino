#include <NewPing.h>

const int sensor_num = 8, max_distance = 100;
int trigger_pins[8] = {30, 31, 32, 33, 34, 35, 36, 37},
    echo_pins[8] = {A0, A1, A2, A3, A4, A5, A6, A7}, 
    out_pins[8] = {38, 39, 40, 41, 42, 43, 44, 45},
    pin_num,
    pin_num_last = 9;

NewPing *sonar[8];

void setup() 
{
  Serial.begin(115200);
  pinMode(38,OUTPUT);
  pinMode(39,OUTPUT);
  pinMode(40,OUTPUT);
  pinMode(41,OUTPUT);
  pinMode(42,OUTPUT);
  pinMode(43,OUTPUT);
  pinMode(44,OUTPUT);
  pinMode(45,OUTPUT);
  for (int i = 0; i < sensor_num; ++i)
    {
        sonar[i] = new NewPing(trigger_pins[i], echo_pins[i], max_distance);
    }
  for (int i=0;i<sensor_num;i++)
    {
        digitalWrite(out_pins[i],HIGH);
    }   
}
  
void loop() {
  int dist0 =sonar[0]->ping_cm();
  Serial.print("1#");
  Serial.println(dist0);
  int dist1 =sonar[1]->ping_cm();
  Serial.print("2#");
  Serial.println(dist1);
  int dist2 =sonar[2]->ping_cm();
  Serial.print("3#");
  Serial.println(dist2);
  int dist3 =sonar[3]->ping_cm();
  Serial.print("4#");
  Serial.println(dist3);
  int dist4 =sonar[4]->ping_cm();
  Serial.print("5#");
  Serial.println(dist4);
  int dist5 =sonar[5]->ping_cm();
  Serial.print("6#");
  Serial.println(dist5);
  int dist6 =sonar[6]->ping_cm();
  Serial.print("7#");
  Serial.println(dist6);
  int dist7 =sonar[7]->ping_cm();
  Serial.print("8#");
  Serial.println(dist7);
  int dist[ ]={dist0,dist1,dist2,dist3,dist4,dist5,dist6,dist7};
  int dis_num=30;
  for(int i=0;i<8;i++)
    {
        if(dist[i]<dis_num && dist[i]!=0)
            { 
                dis_num=dist[i];
                pin_num=i; 
            }
    }
  if (pin_num_last != pin_num)
    {
      digitalWrite(out_pins[pin_num_last],HIGH);
      digitalWrite(out_pins[pin_num],LOW);
      pin_num_last = pin_num;
    }
  else 
      digitalWrite(out_pins[pin_num],LOW);
  if (dis_num==30)
    {
      for (int i=0;i<sensor_num;i++)
          {
              digitalWrite(out_pins[i],HIGH);
          }
     }
  delay(2000);
}




