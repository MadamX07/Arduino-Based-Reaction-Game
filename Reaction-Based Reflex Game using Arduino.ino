#include <Servo.h>

Servo servos[10];  // Array of Servo objects
const int buttonPin = 2;  // Push button pin to start the game
int buttonState = 0;
int lastButtonState = 0;
bool gameStarted = false;  // Track if the game has started

int servoPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  // 10 servo pin numbers
Servo* servoArray[10];  // Array to hold servo object pointers

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with pull-up resistor

    for (int i = 0; i < 10; i++) {
        servos[i].attach(servoPins[i]);
        servoArray[i] = &servos[i];
        servos[i].write(0);  // Set to initial position
    }
}

void loop() {
    buttonState = digitalRead(buttonPin);

    // Start game on button press if not already started
    if (buttonState == LOW && lastButtonState == HIGH && !gameStarted) {
        gameStarted = true;
        delay(10000);  // Initial delay before starting

        shuffleServos();

        for (int i = 0; i < 10; i++) {
            servoArray[i]->write(90);  // Activate
            delay(1000);               // Hold for 1s
            delay(10000);              // Wait before next
        }
    }
    // Reset on next button press
    else if (buttonState == LOW && lastButtonState == HIGH && gameStarted) {
        for (int i = 0; i < 10; i++) {
            servos[i].write(0);  // Reset all servos
        }
        gameStarted = false;
    }

    lastButtonState = buttonState;
}

void shuffleServos() {
    for (int i = 0; i < 10; i++) {
        int j = random(i, 10);
        Servo* temp = servoArray[i];
        servoArray[i] = servoArray[j];
        servoArray[j] = temp;
    }
}
