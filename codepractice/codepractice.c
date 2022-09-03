void setup() {
	//put your setup code here, to run once!
	pinMode(13, OUTPUT);
	//the setup function runs once when you press reset or power the board
	//initialize digital pin 13 as an output.
}

void loop() {
	//put your main code here, to run repeatedly
	digitalWrite(13, HIGH);         //turn the LED on (HIGH is the voltage level)
	delay(1000);                    //wait for a second
	digitalWrite(13, LOW);          //turn the LED off by making the voltage LOW
	delay(1000);
	//the loop function runs over and over again forever
}
