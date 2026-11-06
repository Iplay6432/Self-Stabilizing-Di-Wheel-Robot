// pins are temp for now, i don;t feel like getting all of them right now
// if a,b=0,0 break; a,b=1,0 forward; a,b=0,1 reverse; a,b=1,1 coast (neutral)

const int LEFT_MOTOR_a = 1;
const int LEFT_MOTOR_b = 2;
const int LEFT_MOTOR_PWM = 3;

const int RIGHT_MOTOR_A = 4;
const int RIGHT_MOTOR_A = 5;
const int RIGHT_MOTOR_PWM = 6; 

const int frequency = 15000;
const int ledcResolution = 10; // 0-1023
const double dutyRatio = 0.500; //idk what will be best and why yet, this is just temp
const int dutyCycle = int( double(1023) * dutyRatio); 

void setup() {
  // for the motors use ledcWrite
  // left motor would be ledcWrite(0, dutyCycle);
  // right ledcWrite(1, dutyCycle);
  
  ledcSetup(0, frequency, ledcResolution);
  ledcAttachPin(LEFT_MOTOR_PWM, dutyCycle);

  ledcSetup(1, frequency, ledcResolution);
  ledcAttachPin(RIGHT_MOTOR_PWM, dutyCycle);
}

void loop() {

}
