#include <Servo.h>
char buffer[21];
Servo servo1; // Create a servo object
Servo servo2;
Servo servo3;
Servo servo4;
void setup()
{
servo1.attach(11); // Attaches the servo on pin 11 to the servo1; object
servo2.attach(10);
servo3.attach(9);
servo4.attach(8);
Serial.begin(9600);
while(Serial.available())
Serial.read();
servo1.write(90); // Put servo1 at home position
servo2.write(90);
servo3.write(90);
servo4.write(90);
Serial.println("STARTING...");
}
void loop()
{
if (Serial.available() > 0) { // Check if data has been entered
int index=0;
delay(100); // Let the buffer fill up
int numChar = Serial.available(); // Find the string
//length
if (numChar>20) {
numChar=20;
}
while (numChar--) {
// Fill the buffer with the string
buffer[index++] = Serial.read();
}
buffer[index]='\0';
splitString(buffer); // Run splitString function
}
}
void splitString(char* data) {
Serial.print("Data entered: ");
Serial.println(data);
char* parameter;
parameter = strtok (data, " ,"); //String to token
while (parameter != NULL) { // If we haven't reached the end
//of the string...
setServo(parameter); // ...run the setServo function
parameter = strtok (NULL, " ,");
}
while(Serial.available())
Serial.read();
}
void setServo(char* data) {
if ((data[0] == 'A') || (data[0] == 'a')) {
int firstVal = strtol(data+1, NULL, 10); // String to
//long integer;
firstVal = constrain(firstVal,0,180);
// Constrain values
servo1.write(firstVal);
Serial.print("Servo1 is set to: ");
Serial.println(firstVal);
}
if ((data[0] == 'B') || (data[0] == 'b')) {
int secondVal = strtol(data+1, NULL, 10); // String to 
//long integer;
secondVal = constrain(secondVal,0,255); //Constrain the values
servo2.write(secondVal);
Serial.print("Servo2 is set to: ");
Serial.println(secondVal);
}
if ((data[0] == 'C') || (data[0] == 'c')) {
int thirdVal = strtol(data+1, NULL, 10); // String to
//long integer;
thirdVal = constrain(thirdVal,0,180);
// Constrain values
servo3.write(thirdVal);
Serial.print("Servo3 is set to: ");
Serial.println(thirdVal);
}
if ((data[0] == 'D') || (data[0] == 'd')) {
int forthVal = strtol(data+1, NULL, 10); // String to
//long integer;
forthVal = constrain(forthVal,0,180);
// Constrain values
servo4.write(forthVal);
Serial.print("Servo4 is set to: ");
Serial.println(forthVal);
}
}
