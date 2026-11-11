// pins are temp for now, i don;t feel like getting all of them right now
// if a,b=0,0 break; a,b=1,0 forward; a,b=0,1 reverse; a,b=1,1 coast (neutral)
const int LEFT_MOTOR_a_PIN = 1;
const int LEFT_MOTOR_b_PIN = 2;
const int LEFT_MOTOR_DUTY_PIN = 3;

const int RIGHT_MOTOR_A_PIN = 4;
const int RIGHT_MOTOR_B_PIN = 5;
const int RIGHT_MOTOR_DUTY_PIN = 6;

const int frequency = 15000;
const int ledcResolution = 10; // 0-1023

int leftDuty = 0;
int rightDuty = 0;

int[2] LEFT_MOTOR_STATE = {1,1};
int[2] RIGHT_MOTOR_STATE = {1,1};

void setup() {
  // for the motors use ledcWrite
  // left motor would be ledcWrite(0, dutyCycle);
  // right ledcWrite(1, dutyCycle);

  Serial.begin(115200);

  ledcAttach(LEFT_MOTOR_DUTY_PIN, frequency, ledcResolution);
  pinMode(LEFT_MOTOR_a_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_b_PIN, OUTPUT);

  ledcAttach(RIGHT_MOTOR_DUTY_PIN, frequency, ledcResolution);
  pinMode(RIGHT_MOTOR_A_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_B_PIN, OUTPUT);
  setMotorState();
}

void loop() {

}

void motorForw(int m, int duty) {
  if ( m == 0 ) { //left
    LEFT_MOTOR_STATE = {1,0};
    leftDuty = duty;
    setMotorState();
  } else if ( m == 1 ) {
    RIGHT_MOTOR_STATE = {1,0};
    rightDuty = duty;
    setMotorState();
  }
  pwmWrite();
}

void motorBack(int m, int duty) {
  if ( m == 0 ) { //left
    LEFT_MOTOR_STATE = {0,1};
    leftDuty = duty;
    setMotorState();
  } else if ( m == 1 ) {
    RIGHT_MOTOR_STATE = {0,1};
    rightDuty = duty;
    setMotorState();
  }
  pwmWrite();
}

void motorBreak(int m) {
  if ( m == 0 ) { //left
    LEFT_MOTOR_STATE = {0,0};
    leftDuty = 0;
    setMotorState();
  } else if ( m == 1 ) {
    RIGHT_MOTOR_STATE = {0,0};
    rightDuty = 0;
    setMotorState();
  }
  pwmWrite();
}

void motorCoast(int m ){
  if ( m == 0 ) { //left
    LEFT_MOTOR_STATE = {1,1};
    leftDuty = 0;
    setMotorState();
  } else if ( m == 1 ) {
    RIGHT_MOTOR_STATE = {1,1};
    rightDuty = 0;
    setMotorState();
  }
  pwmWrite();
}

void setMotorState() {
  digtalWrite(LEFT_MOTOR_a_PIN, LEFT_MOTOR_STATE[0]);
  digitalWrite(LEFT_MOTOR_b_PIN, LEFT_MOTOR_STATE[1]);
  digtalWrite(RIGHT_MOTOR_A_PIN, RIGHT_MOTOR_STATE[0]);
  digitalWrite(RIGHT_MOTOR_B_PIN, RIGHT_MOTOR_STATE[1]);
}

void setMotorZero(int m){
  if (m == 0){
    leftDuty = 0;
  }  else if (m == 1){
    rightDuty = 0;
  }
  pwmWrite();  
}

void pwmWrite(){
  ledcWrite(LEFT_MOTOR_DUTY_PIN, leftDuty);
  ledcWrite(RIGHT_MOTOR_DUTY_PIN, rightDuty);
}

int voltage(float volt){
  return (int)(volt / 12.0 * (pow(2.0, (float(ledcResolution)) - 1.0));
}
