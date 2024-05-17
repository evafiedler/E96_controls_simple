#include <Arduino.h>

// Motor controller constants
const int ENA_right;
const int IN1_right;
const int IN2_right;

const int ENA_left;
const int IN1_left;
const int IN2_left;

const int ENA_front;
const int IN1_front;
const int IN2_front;

const int ENA_back;
const int IN1_back;
const int IN2_back;

// Joystick constants
const int XINPUT_right = A0;
const int YINPUT_right = A1;

const int XINPUT_left = A2;
const int YINPUT_left = A3;

const int XINPUT_front = A4;
const int YINPUT_front = A5;

const int XINPUT_back = A6;
const int YINPUT_back = A7;

// Threshold constants
const int forward_direction_th; // ~500
const int backward_direction_th; // ~500

int translateForward (int position);
int translateBackward (int position);

void setup() {
  pinMode(ENA_right, OUTPUT);
  pinMode(IN1_right, OUTPUT);
  pinMode(IN2_right, OUTPUT);

  pinMode(ENA_left, OUTPUT);
  pinMode(IN1_left, OUTPUT);
  pinMode(IN2_left, OUTPUT);

  pinMode(ENA_front, OUTPUT);
  pinMode(IN1_front, OUTPUT);
  pinMode(IN2_front, OUTPUT);

  pinMode(ENA_back, OUTPUT);
  pinMode(IN1_back, OUTPUT);
  pinMode(IN2_back, OUTPUT);
}

void loop() {
  int right_reading = analogRead(XINPUT_right);
  int left_reading = analogRead(XINPUT_left);
  int front_reading = analogRead(XINPUT_front);
  int back_reading = analogRead(XINPUT_back);

  // Right motor
  if (right_reading > forward_direction_th) {
    digitalWrite(IN1_right, HIGH);
    digitalWrite(IN2_right, LOW);
    analogWrite(ENA_right, translateForward(XINPUT_right));
  } else if (right_reading < backward_direction_th) {
    digitalWrite(IN1_right, LOW);
    digitalWrite(IN2_right, HIGH);
    analogWrite(ENA_right, translateBackward(XINPUT_right));
  } else {
    digitalWrite(IN1_right, LOW);
    digitalWrite(IN2_right, LOW);
    analogWrite(ENA_right, 0);
  }

  // Left motor
  if (left_reading > forward_direction_th) {
    digitalWrite(IN1_left, HIGH);
    digitalWrite(IN2_left, LOW);
    analogWrite(ENA_left, translateForward(XINPUT_left));
  } else if (left_reading < backward_direction_th) {
    digitalWrite(IN1_left, LOW);
    digitalWrite(IN2_left, HIGH);
    analogWrite(ENA_left, translateBackward(XINPUT_left));
  } else {
    digitalWrite(IN1_left, LOW);
    digitalWrite(IN2_left, LOW);
    analogWrite(ENA_left, 0);
  }

  // Front motor
  if (front_reading > forward_direction_th) {
    digitalWrite(IN1_front, HIGH);
    digitalWrite(IN2_front, LOW);
    analogWrite(ENA_front, translateForward(XINPUT_front));
  } else if (front_reading < backward_direction_th) {
    digitalWrite(IN1_front, LOW);
    digitalWrite(IN2_front, HIGH);
    analogWrite(ENA_front, translateBackward(XINPUT_front));
  } else {
    digitalWrite(IN1_front, LOW);
    digitalWrite(IN2_front, LOW);
    analogWrite(ENA_front, 0);
  }

  // Back motor
  if (back_reading > forward_direction_th) {
    digitalWrite(IN1_back, HIGH);
    digitalWrite(IN2_back, LOW);
    analogWrite(ENA_back, translateForward(XINPUT_back));
  } else if (back_reading < backward_direction_th) {
    digitalWrite(IN1_back, LOW);
    digitalWrite(IN2_back, HIGH);
    analogWrite(ENA_back, translateBackward(XINPUT_back));
  } else {
    digitalWrite(IN1_back, LOW);
    digitalWrite(IN2_back, LOW);
    analogWrite(ENA_back, 0);
  }
}

int translateForward(int position) {
  return (position - 511) / 2;
}

int translateBackward(int position) {
  return 255 - (position / 2); 
}