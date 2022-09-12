void setup() {
	// put your setup code here, to run once:
	// 아날로그라 설정할 거 없음
	Serial.begin(9600);
}

void loop() {
	// put your main code here, to run repeatedly:
	int light = analogRead(A0);
	int ledLight = map(light, 0, 1023, 255, 0);
	analogWrite(9, ledLight);
	Serial.print("light is ");
	Serial.println(ledLight);
	delay(300);
} //again//