//连接前先将电机调整至正中央,连接烧写程序后在启动电机电源

#define EN        8       //步进电机使能端，低电平有效
#define X_DIR     5       //X轴 步进电机方向控制
#define Y_DIR     6       //y轴 步进电机方向控制
#define Z_DIR     7       //z轴 步进电机方向控制
#define X_STP     2       //x轴 步进控制
#define Y_STP     3       //y轴 步进控制
#define Z_STP     4       //z轴 步进控制

void step(boolean dir, byte dirPin1, byte stepperPin1, byte dirPin2, byte stepperPin2, byte dirPin3, byte stepperPin3, int steps)
{
  digitalWrite(dirPin1, dir);
  digitalWrite(dirPin2, dir);
  digitalWrite(dirPin3, dir);
  delay(50);
  for (int i = 0; i < steps; i++) 
  {
    digitalWrite(stepperPin1, HIGH);
    digitalWrite(stepperPin2, HIGH);
    digitalWrite(stepperPin3, HIGH);
    delayMicroseconds(400);  //调整速度
    digitalWrite(stepperPin1, LOW);
    digitalWrite(stepperPin2, LOW);
    digitalWrite(stepperPin3, LOW);
    delayMicroseconds(400);  //调整速度
  }
  
}
void setup()
{
  Serial.begin(9600);
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
}
void loop()
{
  step(false, X_DIR, X_STP, Y_DIR, Y_STP, Z_DIR, Z_STP, 6400);//调整距离
  delay(1000);
  step(true, X_DIR, X_STP, Y_DIR, Y_STP, Z_DIR, Z_STP, 6400);
  delay(1000);
}
