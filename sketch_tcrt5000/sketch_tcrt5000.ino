#define trackingPin1 9 //the tracking module attach to pin 2
#define trackingPin2 8 //the tracking module attach to pin 2
#define trackingPin3 7 //the tracking module attach to pin 2
void setup()
{
  Serial.begin(9600);
  pinMode(trackingPin1, INPUT); // set trackingPin as INPUT
  //pinMode(ledPin, OUTPUT); //set ledPin as OUTPUT
}
void loop()
{
  int val = digitalRead(trackingPin1); // read the value of tracking module
  Serial.println(val) ;
  val = digitalRead(trackingPin2); // read the value of tracking module
  Serial.println(val) ;
  val = digitalRead(trackingPin3); // read the value of tracking module
  Serial.println(val) ;
  Serial.println("end read") ;
  //if (val == HIGH) //if it is HiGH
  //{
    //digitalWrite(ledPin, LOW); //turn off the led
  //  Serial.println("tracking 1 = HiGH" ) ;
  //}
  //else
  //{
  //  Serial.println("tracking 1 = not hight" ) ;
  //}

  //val = digitalRead(trackingPin2); // read the value of tracking module
  //if (val == HIGH) //if it is HiGH
  //{
    //digitalWrite(ledPin, LOW); //turn off the led
  //  Serial.println("tracking 2 = HiGH" ) ;
  //}
  //else
  //{
  //  Serial.println("tracking 2 = not hight" ) ;
    //digitalWrite(ledPin, HIGH); //turn on the led
  //}//digitalWrite(ledPin, HIGH); //turn on the led


  //val = digitalRead(trackingPin3); // read the value of tracking module
  //if (val == HIGH) //if it is HiGH
  //{
  //  //digitalWrite(ledPin, LOW); //turn off the led
  //  Serial.println("tracking 3 = HiGH" ) ;
  //}
  //else
  //{
  //  Serial.println("tracking 3 = not hight" ) ;
    //digitalWrite(ledPin, HIGH); //turn on the led
  //}//digitalWrite(ledPin, HIGH); //turn on the led



  delay (1000); /* ждем 0.1 секунды */
}
