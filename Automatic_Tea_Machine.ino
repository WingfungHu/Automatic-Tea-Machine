/* 
 *  Automatic Tea Machine
 *  Created by: Wingfung Hu
 *  Start date: 2021/10/12 (YYYY/MM/DD)
 *  
 *  The purpose of this project is to create a tea brewing station with:
 *  - A seven segment display
 *  - A potentiometer
 *  - A push button
 *  - An LED
 *  - Two servo motors
 *  - Arduino microcontroller
 *  - A breadboard
 *  - Wires and resistors as needed
 *  
 */
#include <Servo.h> // Adds the library for the Servo to operate.
#include "pitches.h" // Adds the tab I've created for certain pitches and notes for the buzzer to play when called.
Servo servoOne; // All of these variables are for the usage of the tea brewing program.
Servo servoTwo;
int sensorValue = 0;
int minuteTimer = 0;
int counter = 0;
int welcome = 0;
int i = 0;
int buttonStateOne = 1;
int a = 2; // a-g are the variables for the 7 segment.
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int buttonOne = 11; 
const int led = 13; 
int buzzer = 12; // Buzzer not attached to pin 11 due to the tone and analogWrite() both having the same built in timer in both pins 3 and 11. Can create weird sound if put on either pins.
int melody[] = {
  NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_B4, NOTE_D5, NOTE_A4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_A3, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_A3, 
  NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_B4, NOTE_D5, NOTE_A4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_A3, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_E4, NOTE_A3,
  NOTE_B3, NOTE_A3, NOTE_B3, NOTE_CS4, NOTE_D4, NOTE_A3, NOTE_FS4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, REST
};
int durations[] = {
  6, 14, 6, 14, 4, 4, 4, 4, 4, 4, 6, 14, 6, 14, 6, 14, 6, 14, 6, 14, 6, 14, 4, 4, 6, 14, 6, 14, 4, 4, 4, 4, 4, 4, 6, 14, 6, 14, 6, 14, 6, 14, 6, 14, 6, 14, 4, 4, 
  6, 14, 6, 14, 4, 6, 14, 24, 24, 24, 24, 14, 6, 14, 2, 4, 4
};
int songLength = sizeof(melody)/sizeof(melody[0]);

void setup() // Sets up each pin, the serial monitor, and the servos for usage.
{
  pinMode(A0,INPUT);
  pinMode(buttonOne,INPUT_PULLUP);
  Serial.begin(9600);
  servoOne.attach(9);
  servoTwo.attach(10);
  pinMode(led,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
}

void clearAll() // Resets the 7 segment.
{
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void digitOne() // Creates the number 1 on the 7 segment.
{
  clearAll();
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}

void digitTwo() // Creates the number 2 on the 7 segment.
{
  clearAll();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void digitThree() // Creates the number 3 on the 7 segment.
{
  clearAll();
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
}

void digitFour() // Creates the number 4 on the 7 segment.
{
  clearAll();
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void digitFive() // Creates the number 5 on the 7 segment.
{
  clearAll();
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}

void ledBlink() // The method that controls the LED, sets up the servos to stay for a certain amount of time, 
// and displays what is happening and when the process will end in the serial monitor.
{
  if(minuteTimer == 1)
  {
    counter = 60;
    Serial.println("The tea is brewing!");
    for(int i = 0; i < 30; i++)
    {
      Serial.println(counter);
      counter--;
      digitalWrite(led, HIGH);
      delay(1000);
      Serial.println(counter);
      counter--;
      digitalWrite(led, LOW);
      delay(1000);
    }
    digitalWrite(led, HIGH);
  }
  else if(minuteTimer == 2)
  {
    counter = 120;
    Serial.println("The tea is brewing!");
    for(int i = 0; i < 60; i++)
    {
      Serial.println(counter);
      counter--;
      digitalWrite(led, HIGH);
      delay(1000);
      Serial.println(counter);
      counter--;
      digitalWrite(led, LOW);
      delay(1000);
    }
    digitalWrite(led, HIGH);
  }
  else if(minuteTimer == 3)
  {
    counter = 180;
    Serial.println("The tea is brewing!");
    for(int i = 0; i < 90; i++)
    {
      Serial.println(counter);
      counter--;
      digitalWrite(led, HIGH);
      delay(1000);
      Serial.println(counter);
      counter--;
      digitalWrite(led, LOW);
      delay(1000);
    }
    digitalWrite(led, HIGH);
  }
  else if(minuteTimer == 4)
  {
    counter = 240;
    Serial.println("The tea is brewing!");
    for(int i = 0; i < 120; i++)
    {
      Serial.println(counter);
      counter--;
      digitalWrite(led, HIGH);
      delay(1000);
      Serial.println(counter);
      counter--;
      digitalWrite(led, LOW);
      delay(1000);
    }
    digitalWrite(led, HIGH);
  }
  else if(minuteTimer == 5)
  {
    counter = 300;
    Serial.println("The tea is brewing!");
    for(int i = 0; i < 150; i++)
    {
      Serial.println(counter);
      counter--;
      digitalWrite(led, HIGH);
      delay(1000);
      Serial.println(counter);
      counter--;
      digitalWrite(led, LOW);
      delay(1000);
    }
    digitalWrite(led, HIGH);
  }
}

void teaTime() // Moves the servos to place the tea bag in the mug slowly.
{
  if(minuteTimer > 0)
  {
    // sweep the servo from 0 to 180 degrees in steps
    // of 1 degrees
    for (i = 0; i <= 40; i += 1) 
    {
      // tell servo to go to position in variable 'i'
      servoOne.write(i);
      // wait 15 ms for servo to reach the position
      delay(50); // Wait for 15 millisecond(s)
    }
    for (i = 60; i >= 25; i -= 1) 
    {
      // tell servo to go to position in variable 'i'
      servoTwo.write(i);
      // wait 15 ms for servo to reach the position
      delay(50); // Wait for 15 millisecond(s)
    }
  }
}

void startingPos() // Moves the servos to their loading/starting position for the process.
{
  servoOne.write(0);
  delay(15);
  servoTwo.write(60);
  delay(15);
}

void returnPos() // Moves the servos slowly back.
{
  for (i = 25; i <= 60; i += 1) {
    // tell servo to go to position in variable 'i'
    servoTwo.write(i);
    // wait 15 ms for servo to reach the position
    delay(50); // Wait for 15 millisecond(s)
  }
  for (i = 40; i >= 0; i -= 1) {
    // tell servo to go to position in variable 'i'
    servoOne.write(i);
    // wait 15 ms for servo to reach the position
    delay(50); // Wait for 15 millisecond(s)
  }
}

void buzzerTune() // The tune that is played through the buzzer when the tea making process is completed.
{
  for (int thisNote = 0; thisNote < songLength; thisNote++){
    // determine the duration of the notes that the computer understands
    // divide 1000 by the value, so the first note lasts for 1000/8 milliseconds
    int duration = 1000/ durations[thisNote];
    tone(12, melody[thisNote], duration);
    // pause between notes
    int pause = duration * 2;
    delay(pause);
    // stop the tone
    noTone(12);
  }
}

void welcomeMessage() // The welcome message that's displayed to the user when the program is started or goes back to the start.
{
  Serial.println("Hello and welcome to the tea brewing station!");
  Serial.println("Please set up the amount of time (1-5 minutes) you would like your tea to be brewed.");
  Serial.println("(Set the time by turning the potentiometer, the time will be displayed on the seven segment.");
  Serial.println("Once you have set the time, please push the button in order to start the process.");
  Serial.println("A tune will play when the tea is ready, or you can watch the countdown on the serial monitor if you're bored.");
  Serial.println("Once the tea is ready, simply pick-up the mug and you're good to go. You're welcome to repeat the process after everything is done!");
  Serial.println("Enjoy!");
  welcome++;
}

// The main code where everything happens.
void loop() 
{
  // As a back-up/cautionary measure so that the servos are correctly set up.
  startingPos();
  // The welcome message whenever the program starts, or once everything is done and it's prepared for another run.
  if(welcome == 0)
  {
    welcomeMessage();
  }
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  delay(10); // Delay a little bit to improve simulation performance
  // Controls 7 segment with potentiometer to set up how long the tea should be brewed.
  if(sensorValue <= 203)
  {
    digitOne();
    delay(20);
    minuteTimer = 0;
    minuteTimer = minuteTimer + 1;
  }
  if(sensorValue >= 204 && sensorValue <= 407)
  {
    digitTwo();
    delay(20);
    minuteTimer = 0;
    minuteTimer = minuteTimer + 2;
  }
  if(sensorValue >= 408 && sensorValue <= 611)
  {
    digitThree();
    delay(20);
    minuteTimer = 0;
    minuteTimer = minuteTimer + 3;
  }
  if(sensorValue >= 612 && sensorValue <= 815)
  {
    digitFour();
    delay(20);
    minuteTimer = 0;
    minuteTimer = minuteTimer + 4;
  }
  if(sensorValue >= 816 && sensorValue <= 1023)
  {
    digitFive();
    delay(20);
    minuteTimer = 0;
    minuteTimer = minuteTimer + 5;
  }
  buttonStateOne = digitalRead(buttonOne); // Reads when the button is pushed.
  delay(25); // Delay to improve simulation process.
  if(buttonStateOne == 0) // Starts the actual tea brewing if the button is pushed.
  {
    teaTime();
    ledBlink();
    returnPos();
    buzzerTune();
    digitalWrite(led, LOW);
    Serial.println("The tea is ready! Bonappetit!");
    buttonStateOne = 1;
    welcome--;
  }
}
