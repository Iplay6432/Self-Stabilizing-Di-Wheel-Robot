// pins are temp for now, i don;t feel like getting all of them right now
// if a,b=0,0 break; a,b=1,0 forward; a,b=0,1 reverse; a,b=1,1 coast (neutral)
const int LEFT_MOTOR_a_PIN = 1;
const int LEFT_MOTOR_b_PIN = 2;
const int LEFT_MOTOR_PWM_PIN = 3;

const int RIGHT_MOTOR_A_PIN = 4;
const int RIGHT_MOTOR_B_PIN = 5;
const int RIGHT_MOTOR_PWM_PIN = 6; 

const int frequency = 15000;
const int ledcResolution = 10; // 0-1023
const double dutyRatio = 0.500; //idk what will be best and why yet, this is just temp
const int dutyCycle = int( double(1023) * dutyRatio); 

int LEFT_MOTOR_PWM = 0;
int RIGHT_MOTOR_PWM = 0;

int[2] LEFT_MOTOR_STATE = {1,1};
int[2] RIGHT_MOTOR_STATE = {1,1};

void setup() {
  // for the motors use ledcWrite
  // left motor would be ledcWrite(0, dutyCycle);
  // right ledcWrite(1, dutyCycle);

  Serial.begin(115200);

  ledcSetup(0, frequency, ledcResolution);
  ledcAttachPin(LEFT_MOTOR_PWM, dutyCycle);
  pinMode(LEFT_MOTOR_a_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_b_PIN, OUTPUT);
  digtalWrite(LEFT_MOTOR_a_PIN, LEFT_MOTOR_STATE[0]);
  digitalWrite(LEFT_MOTOR_b_PIN, LEFT_MOTOR_STATE[1]);

  ledcSetup(1, frequency, ledcResolution);
  ledcAttachPin(RIGHT_MOTOR_PWM, dutyCycle);
  pinMode(RIGHT_MOTOR_A_PIN, OUTPUT);
  pinMode(RIGHT_MOTOR_B_PIN, OUTPUT);
  digtalWrite(RIGHT_MOTOR_A_PIN, RIGHT_MOTOR_STATE[0]);
  digitalWrite(RIGHT_MOTOR_B_PIN, RIGHT_MOTOR_STATE[1]);
}

void loop() {

}

