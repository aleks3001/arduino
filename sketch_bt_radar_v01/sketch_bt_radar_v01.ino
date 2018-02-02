#include <SoftwareSerial.h>
#define coef 5
#define min_zone 6
#define max_zone 44
#define Trig 12 //Trig сенсор дальномера
#define Echo 13 //Echo сенсор дальномера
SoftwareSerial BT(0, 1);
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
int servopin = 11; // select digital pin 9 for servomotor signal line
int myangle;// initialize angle variable
int pulsewidth;// initialize width variable
int val_servo = 0;
int val_servo_ang = 0;
int val_inc = 1;
int val_servo_pause = 0;
unsigned int impulseTime = 0;
unsigned int distance_sm = 0;

void servopulse(int servopin, int myangle) // define a servo pulse function
{
  pulsewidth = (myangle * 11) + 500; // convert angle to 500-2480 pulse width
  digitalWrite(servopin, HIGH); // set the level of servo pin as “high”
  delayMicroseconds(pulsewidth);// delay microsecond of pulse width
  digitalWrite(servopin, LOW); // set the level of servo pin as “low”
  delay(20 - pulsewidth / 1000);
}

void servomove()
{
  
    //val_servo_ang = val_servo * (180 / 5); // convert number to angle
    for (int i = 0; i <= 50; i++) // giving the servo time to rotate to commanded position
    {
      servopulse(servopin, val_servo_ang); // use the pulse function
    }
    if (val_inc == 1)
    {
      val_servo_ang = val_servo_ang + 90;
    }
    else
    {
      val_servo_ang = val_servo_ang - 90;
    }
    if (val_servo_ang == 180)
    {
      val_inc = 0;
    }
    if (val_servo_ang == 0)
    {
      val_inc = 1;
    }

    digitalWrite (Trig, HIGH); /* Подаем импульс на вход trig дальномера */
    delayMicroseconds (10); // равный 10 микросекундам
    digitalWrite (Trig, LOW); // Отключаем
    impulseTime = pulseIn(Echo, HIGH); // Замеряем длину импульса
    distance_sm = impulseTime / 58; // Пересчитываем в сантиметры
    //if (BT.available()) // if text arrived in from BT serial...
    //{
    delay(5);
      BT.print("S: ");
      BT.println(distance_sm);
      BT.print("A: ");
      BT.println(val_servo_ang);
      delay(5);
    //}

}
void setup()
{
  pinMode (Trig, OUTPUT); //инициируем как выход
  pinMode (Echo, INPUT); //инициируем как вход
  BT.begin(9600);// Send test message to other device
  BT.println("Hello from Arduino");
  pinMode(servopin, OUTPUT); // set servo pin as “output”
}
char a; // stores incoming character from other device


void loop()
{
  if (BT.available())
    // if text arrived in from BT serial...
  {
    a = (BT.read());
    if (a == '1')
    {
      //digitalWrite(13, HIGH);
      BT.println("LED on");
    }
    if (a == '2')
    {
      //digitalWrite(13, LOW);
      BT.println("LED off");
    }
    if (a == '?')
    {
      BT.println("Send '1' to turn LED on");
      BT.println("Send '2' to turn LED on");
    }


    // you can add more "if" statements with other characters to add more commands
  }

  servomove();

  //delay (50); /* ждем 0.1 секунды */

}
