# Tested motor
## NEMA-17 size - 200 steps/rev, 12V 350mA
* Bipolar winding
* 200 steps per revolution, 1.8 degrees 
    * Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 1);
* Coil #1: Red & Yellow wire pair. Coil #2 Green & Brown/Gray wire pair.

### Images 
<img src='01_StepperHatTest/screenshots/324-03.jpg' width = 400px />

<img src='01_StepperHatTest\screenshots\20210817_161345_1024.jpg' width = 400px />

* Bipolar winding

<img src='01_StepperHatTest/screenshots/bipolar_winding.png' width = 400px />

<img src='01_StepperHatTest/screenshots/bipolar_winding_direciton.png' width = 600px />

### AF_Stepper Class
step(#steps, direction, steptype)

#steps is how many steps you'd like it to take.

The direction is either FORWARD or BACKWARD

The step type is SINGLE, DOUBLE, INTERLEAVE or MICROSTEP.<br>
<ul>
<li>"Single" means single-coil activation</li>
<li>"Double" means 2 coils are activated at once (for higher torque)</li>
<li>"Interleave" means that it alternates between single and double to get twice the resolution (but of course its half the speed).</li>
<li>"Microstepping" is a method where the coils are PWM'd to create smooth motion between steps.</li>
</ul>

https://learn.adafruit.com/adafruit-motor-shield-v2-for-arduino/using-stepper-motors

### Test

<img src='assets/20211109_123929.jpg' width='512px' />


https://youtu.be/72XpgnHryAs

# References
* https://www.adafruit.com/product/324
* https://archive.is/JJWC8
