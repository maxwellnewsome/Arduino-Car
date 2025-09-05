
//Car code

#include <IRremote.hpp>

const int RemotePin = 8;

// Motor driver pins
int in1 = 3;
int in2 = 5;
int in3 = 6;
int in4 = 9;

void setup() {
  IrReceiver.begin(RemotePin, ENABLE_LED_FEEDBACK);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    unsigned long code = IrReceiver.decodedIRData.command;

    //Functions called correlate to direction of car
    
    if (code == 0x9) {         // Forward button
      Forward();
    }
    else if (code == 0xD) {    // Backward button
      Backward();
    }
    else if (code == 0xC) {    // Left button
      Left();                  
    }
    else if (code == 0xE) {    // Right button
      Right();
    }
    else if (code == 0x1) {    // Stop button
      Stop();
    }

    IrReceiver.resume();
  }
}

// ================== MOTOR CONTROL ==================

void Forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Backward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void Right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
