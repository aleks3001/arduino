#include <Servo.h>
#define coef 5
#define min_zone 6
#define max_zone 44
#define Trig 12 //Trig сенсор дальномера
#define Echo 13 //Echo сенсор дальномера
#define servoPin 11
Servo myservo;

void setup() {
  pinMode (Trig, OUTPUT); //инициируем как выход
  pinMode (Echo, INPUT); //инициируем как вход
  myservo.attach (servoPin);
  myservo.write (0);
  //Serial.begin (9600);
}
unsigned int impulseTime = 0;
unsigned int distance_sm = 0;

void loop() {
  digitalWrite (Trig, HIGH); /* Подаем импульс на вход trig дальномера */
  delayMicroseconds (10); // равный 10 микросекундам
  digitalWrite (Trig, LOW); // Отключаем
  impulseTime = pulseIn(Echo, HIGH); // Замеряем длину импульса
  distance_sm = impulseTime / 58; // Пересчитываем в сантиметры
  if (distance_sm >= min_zone && distance_sm <= max_zone)
    //если замеряемая длинна больше 4см и меньше 22см
  {
    myservo.write (coef * (distance_sm - min_zone));
    // поворачиваем сервопривод на значение: 10*(замеряемая длина - 4см )
  }
  else if (distance_sm < min_zone)
    //иначе, если дистанция менее 4 см, сервопривод в положении ноль градусов
  {
    myservo.write(0);
  }
  else //иначе
  {
    myservo.write(180); //сервопривод в положении 180 градусов
  }
  //Serial.println(distance_sm);
  delay (100); /* ждем 0.1 секунды */
}
