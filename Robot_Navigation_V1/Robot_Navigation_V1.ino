/*
 * Jose De Jesus Alarcon
 * Creating our Robot
 */

const int trig = 12; // This here means that the variable being declared is a pointer, pointing to a constant integer, this would indicate that the value wont change once it is declared.
const int echo = 11;
const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

int duration = 0;// This would indicate a time that represents the a count
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);// Using the pin Trig, and the rest in the library above, would show the output pins. 
  pinMode(echo , INPUT);
  pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig , HIGH); // I used digitalWrite for the pins of a value of HIGH/LOW.
  delayMicroseconds(1000);// Here is delaying the time in 1000 of a second. This means one second.
  digitalWrite(trig, LOW);

  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5;
  Serial.println(distance);

  if ( distance < 20 )
  {
    digitalWrite(leftForward , LOW);
    digitalWrite(leftBackward , HIGH);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
    delay(100);
  }
  else
  {
    digitalWrite(leftForward , HIGH);
    digitalWrite(leftBackward , LOW);
    digitalWrite(rightForward , HIGH);
    digitalWrite(rightBackward , LOW);
  }

}
