
#include <Servo.h> //Servo library that is built into Arduino only supports servos on pin 9 and 10, not others

int pin = 9;  //WARNING: servos only operate on pin NINE and TEN
int y;  //The scaled range I created was from -100 to 100, where each extremes are the maximum speed that the servo can rotate in one direction or another. When y=0, the servo stops spinning, where z is equal to 1500 Microseconds.  
int z;  //This variable represents the number of microseconds sent to the Servo and tells it how fast and in what direction to spin.
int percent(int y){
   z=(5*y)+1500;  //The range that the servo operates from is 1000 Microseconds to 2000 Microseconds. So from the range I created from -100 to 100, this function converts each respective number to its equivalent between 1000 and 2000. 
} //This function can be altered based on what you want the scale to be, such as -50 to 50. 


Servo servo;

void setup() {
  servo.attach(pin); //This is letting the Arduino know that the Arduino is attached to pin 9. "pin" is set above as a global variable to always be equivalent to 9.
  Serial.begin(9600); //The 9600 tells the Arduino that it is communicating information at 9600 bauds, which is a rate that information is being transferred. 
  servo.write(90); //When writing for the servo to be 90, it means the servo will not move and is starting at its "starting point." Also, when the code is written as "servo.write," the input is in degrees of an angle, while "servo.writeMicroseconds," input is in Microseconds.
}

void loop() {
    for (int i=-100; i <= 100; i++){ //This for loop I have created will continue to run the code between the curly brackets until the parameters set within the parentheses are no longer true. The function starts at -100 and adds up in increments of 10 until it reaches 100, then it stops running the loop.
      Serial.println(i); //This prints the numbers from -100 to 100, letting me check that the correct numbers are being inputted into the servo. 
      percent(i); //This inputs the number "i," which is number on the smaller range from -100 to 100, into the function an dhas it output the number in Microseconds. 
      servo.writeMicroseconds(z); //This command transmits to the servo in which direction to spin and how quickly.
      Serial.print(z);
      Serial.println(" Microseconds");
      delay(125); //The delay makes each increment in which "i" is increased to last one eight of a second, or 125 milliseconds. This number can be changed and in turn, will change how quickly or slowly the speed of the servo's horn changes. The horn is the piece of equipment attached to the gears.
    }
    for (int i=100; i >= -100; i--){
      Serial.println(i);
      percent(i);
      Serial.print(z);
      Serial.println(" Microseconds");
      servo.writeMicroseconds(z); 
      delay(125);
    }
}
