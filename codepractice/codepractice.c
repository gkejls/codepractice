
const char trigpin = 13;
const char echopin = 12;

//펄스 폭과 거리 변수 설정
int pulseWidth;
int distance;
int distanceOld;

void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	//트리거 핀의 초기값을 LOW로 설정
	digitalWrite(trigPin, LOW);
}
