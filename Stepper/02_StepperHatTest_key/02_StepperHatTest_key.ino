/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/


#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
//Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

int move_mode = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  //AFMS.begin();  // create with the default frequency 1.6KHz
  AFMS.begin();
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  myMotor->setSpeed(100);  // 10 rpm   
}

void loop() {
  

  if(move_mode==1)
  {
    Serial.println("Single coil steps (FORWARD)");
    myMotor->step(500, FORWARD, SINGLE); 
    move_mode = 0;
  }

  else if(move_mode==2)
  {
    Serial.println("Single coil steps (BACKWARD)");
    myMotor->step(500, BACKWARD, SINGLE); 
    move_mode = 0;
  }

  else if(move_mode==3)
  {
    Serial.println("DOUBLE coil steps (FORWARD)");
    myMotor->step(500, FORWARD, DOUBLE); 
    move_mode = 0;
  }

  else if(move_mode==4)
  {
    Serial.println("DOUBLE coil steps (BACKWARD)");
    myMotor->step(500, BACKWARD, DOUBLE); 
    move_mode = 0;
  }

  else if(move_mode==5)
  {
    Serial.println("DOUBLE coil steps (FORWARD)");
    myMotor->step(100, FORWARD, DOUBLE); 
    move_mode = 0;
  }

  else if(move_mode==6)
  {
    Serial.println("DOUBLE coil steps (BACKWARD)");
    myMotor->step(100, BACKWARD, DOUBLE); 
    move_mode = 0;
  }

  else if(move_mode==7)
  {
    Serial.println("DOUBLE coil steps (FORWARD)");
    myMotor->step(10, FORWARD, DOUBLE); 
    move_mode = 0;
  }

  else if(move_mode==8)
  {
    Serial.println("DOUBLE coil steps (BACKWARD)");
    myMotor->step(10, BACKWARD, DOUBLE); 
    move_mode = 0;
  }
  
  delay(100);
}



void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    
    if (inChar == '1') {
      move_mode = 1;
    }
    else if (inChar == '2') {
      move_mode = 2;
    }
    else if (inChar == '3') {
      move_mode = 3;
    }
    else if (inChar == '4') {
      move_mode = 4;
    }

    else if (inChar == '5' || inChar=='a') {
      move_mode = 5;
    }
    else if (inChar == '6' || inChar=='d') {
      move_mode = 6;
    }

    else if (inChar == '7' || inChar=='z') {
      move_mode = 7;
    }
    else if (inChar == '8' || inChar=='c') {
      move_mode = 8;
    }
    
    
  }
}
