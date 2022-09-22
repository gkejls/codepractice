void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, INPUT);
}

void loop() {
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(9, 0);

    digitalWirte(2, LOW);
    delayMicroseconds(2);
    digitalWirte(2, HIGH);
    delayMicroseconds(10);
    digitalWirte(2, LOW);

    long duration = pulseIn(3, HIGH);

    if (duration == 0) {
        return;
    }

    long distance = duration / 58.2;

    if (distance < 10) {
        analogWrite(11, 255);
    }
    else if (distance)
}
