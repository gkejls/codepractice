//0914
void setup() {
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT); //초음파 센서 에코 트리그
}

void loop() {
	analogWrite(11, 0);
	analogWrite(10, 0);
	analogWrite(9, 0); //3색 led 색 꺼주기 위함

	digitalWrite(2, LOW); //혹시나 trig 전압이 기존에 high일 수 있어 low로 처음 설정
	delayMicroseconds(2);
	digitalWrite(2, HIGH); //trig에서 초음파 발사 
	delayMicroseconds(10); //충분히 발사되도록 멈춤
	digitalWrite(2, LOW);

	long duaration = pulseln(3, HIGH); //발사된 초음파가 에코부분으로 돌아올 때까지 시간을 잼

}
