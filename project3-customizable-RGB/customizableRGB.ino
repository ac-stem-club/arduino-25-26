// the following 3 global variables represent the digital pins that the RGB LED's leads are plugged into
// the keyword "const" tells the compiler that we are making a variable that is constant--its value should never change!
const int redPin = 7;
const int greenPin = 6;
const int bluePin = 5;

// the following 3 global variables represent the analog pins that the potentiometers (variable resistance knobs) are plugged into
const int rPotPin = A0;
const int gPotPin = A1;
const int bPotPin = A2;

/* the following 3 global variables store the resistance value of the potentiometers.
   We could have defined these in loop(){...}, but putting them here means that the ATMega328p CPU does not have to waste time
   redefining variables each time the loop() function is executed. 
*/
int r = 0; // notice that we don't use const here because we want to let these variables change
int g = 0;
int b = 0;

/* setColor is something called a Function. It is a piece of code that we intend to use over and over again.
   Instead of having to write lines 33, 34, and 35 each time we want to change the color of an LED, we can make 
   our lives so much easier and bundle those 3 steps into the setColor function.

   Notice:
   - the keyword "void" means that this function does not need to send back or "return" a value when it is executed.
     If the function were to send back a value that was an int, we would have wrote "int setColor..."
   - (int redValue, int greenValue, int blueValue) are the 3 inputs to this function! 
     When the compiler reads line 32, it makes 3 variables to be used inside this function. They are deleted from memory when the function is done running.
   - to use our function, we have to "call" it. To call the function, we just have to write setColor(r, g, b); where r g and b are replaced with ints!
     for example: setColor(0, 0, 255); will set the color of the RGB LED to Blue. 

*/
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setup() {
  // The RGB LED leads will be our 3 ouputs so that we can write red, blue, or green values as ints 0-255 to them.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // The resistance value of the potentiometers (also called 'pots') will serve as our input. 
  pinMode(rPotPin, INPUT);
  pinMode(gPotPin, INPUT);
  pinMode(bPotPin, INPUT);
}

void loop() {
  // first we get the resistance values of the 4 pots, then we send them to the RGB LED.
  /* 
    - Pots store resistance values as 10-bit data. That means that the highest number that we can read is 1111111111 in binary which is 1023 in decimal.
    - But RGB LEDs store red gree and blue values as 8-bit data. That means that the highest number we can output is 11111111 in binary which is 255 in decimal.
    - So dividing by 4 will map any 10-bit value to its equivalent 8-bit value. Observe: 1024/4 = 256
    - In C++, we can do math using +, -, *, and /. To divide we use the slash!
  */
  r = analogRead(rPotPin) / 4;
  g = analogRead(gPotPin) / 4;
  b = analogRead(bPotPin) / 4;

  setColor(r, g, b);
}
