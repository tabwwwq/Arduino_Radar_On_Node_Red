#include <Servo.h>

Servo s;               

int trigPin = 10;       // отправка 
int echoPin = 11;       // приём
long duration;          // время
int distance;           // расстояние

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);    

  Serial.begin(9600);       
  s.attach(12);   // сервопривод            
}

void loop() {

// прокрутка вперед
  for (int angle = 180; angle >= 0; angle--)
   {
    s.write(angle);
    delay(120);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance > 40)
    {
      distance = 40;
    }

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }

//обратно
  for (int angle = 0; angle <= 180; angle++)
  {
    s.write(angle);
    delay(120);

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if (distance > 40)
    {
      distance = 40;
    }
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}
