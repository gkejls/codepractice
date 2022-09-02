#include <Keypad.h>
#include <pitches.h>
//0902
//analog 출력 9번 핀 전압 0V 설정
analogWrite(9, 0);
//9번 핀 전압 5V로 설정
analogWrite(9, 255);
analogWrite(9, 127);//약 2.5V
//digital 출력 13번 핀에 디지털 신호 내보내지 않는다
digitalWrite(13, LOW);
//13번 핀에 디지털 신호 내보낸다.
digitalWrite(13, HIGH);
//디지털 신호 입력 받기
int a; //디지털 신호 입력 값 저장 변수
//13번 핀에 디지털 신호 입력 값을 받음
digitalRead(13);
//상수 HIGH와 LOW를 이용해 입력 값 확인
if (a == HIGH) {//전압 HIGH인 경우}
else {//전압이 LOW인 경우}






















//핀번호 배정
    int datapin = A1;   // 74HC595의 data(DS) 핀을 연결
    int latchpin = A2;  // 74HC595의 latch(ST_CP) 핀을 연결
    int clockpin = A3;  // 74HC595의 clock(SH_CP) 핀을 연결
    int switch_r = A4;  //right
    int switch_l = A5;  //left
    int pinLED_r = 12;
    int pinLED_g = 13;

    const byte ROWS = 4;    // 행(rows) 개수
    const byte COLS = 4;    // 열(columns) 개수
    byte rowPins[ROWS] = { 6, 7, 8, 9 };   // R1, R2, R3, R4 단자가 연결된 아두이노 핀 번호
    byte colPins[COLS] = { 5, 4, 3, 2 };   // C1, C2, C3, C4 단자가 연결된 아두이노 핀 번호

    //스위치와 FND 변수
    int number = 0;
    int select = 0;

    byte digits[] = { 0x03,0x9F,0x25,0x0D,0x99,0x49,0x41,0x1B,0x01,0x09 };


    //키패드 변수
    int tru = 0; // 비밀번호가 맞는지 확인
    int count = 0;
    int pwc = 0;

    char plane[13] = { '8','7','B','7','8','8','8','7','7','7','8','8','8' }; //연주 순서
    char urs[19] = { 'B','B','B','B','B','8','C','C','8','B','C','C','8','C','C','8','B','B','B' };
    char bell[11] = { '6','6','6','6','6','6','6','7','4','5','6' };
    char star[14] = { 'B','B','C','C','*','*','C','9','9','8','8','7','7','B' };
    char butter[] = {};
    char rabbit[] = {};
    char PW[] = {};



    char keys[ROWS][COLS] = {
      {'1','2','3','A'},
      {'4','5','6','B'},
      {'7','8','9','C'},
      {'*','0','#','D'}
    };




    void setup()
    {
        Serial.begin(9600);
        pinMode(latchpin, OUTPUT);
        pinMode(clockpin, OUTPUT);
        pinMode(datapin, OUTPUT);
        pinMode(switch_r, INPUT_PULLUP);
        pinMode(switch_l, INPUT_PULLUP);
        pinMode(pinLED_r, OUTPUT);
        pinMode(pinLED_g, OUTPUT);
    }

    void loop()
    {

        digitalWrite(latchpin, LOW);
        shiftOut(datapin, clockpin, LSBFIRST, digits[number]);
        digitalWrite(latchpin, HIGH);
        delay(500);

        if (digitalRead(switch_l) == LOW) {
            if (number == 9) {
                number = 0;
            }
            else {
                number++;
            }
        }

        if (digitalRead(switch_r) == LOW) {
            select = number;
            Serial.print("select=");
            Serial.println(select);
            switch (select) {
            case 1://plane
                pwc = 13;
                Serial.print("pwc=");
                Serial.println(pwc);
                for (int i = 0; i < 14; i++) {
                    PW[i] = plane[i];
                }
                for (int j = 0; j < 14; j++) {
                    Serial.println(PW[j]);
                }
                break;
            case 2: //urs
                pwc = 19;
                Serial.print("pwc=");
                Serial.println(pwc);
                for (int i = 0; i < 20; i++) {
                    PW[i] = urs[i];
                }
                for (int j = 0; j < 20; j++) {
                    Serial.println(PW[j]);
                }
                break;
            case 3://bell
                pwc = 11;
                Serial.print("pwc=");
                Serial.println(pwc);
                for (int i = 0; i < 12; i++) {
                    PW[i] = bell[i];
                }
                for (int j = 0; j < 12; j++) {
                    Serial.println(PW[j]);
                }
                break;
            case 4://star
                pwc = 14;
                Serial.print("pwc=");
                Serial.println(pwc);
                for (int i = 0; i < 15; i++) {
                    PW[i] = star[i];
                }
                for (int j = 0; j < 15; j++) {
                    Serial.println(PW[j]);
                }
                break;
            }
        }



        //키패드 음계    
        Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
        char key = keypad.getKey();

        if (key) {

            if (key == PW[count]) //입력번호와 비밀번호가 맞을시 count,tru++
            {
                count++;
                tru++;
                Serial.print("tru=");
                Serial.println(tru);
                Serial.print("count=");
                Serial.println(count);
            }
            else if (key != PW[count])//입력번호와 비밀번호가 틀릴시 count만 ++
            {
                count++;
                Serial.print("tru=");
                Serial.println(tru);
                Serial.print("count=");
                Serial.println(count);
            }

            if (count == pwc)//count개수가 비밀번호 개수와 같을 시
            {
                if (tru == pwc)
                {
                    tone(11, NOTE_C6, 500); delay(600), noTone(6); //성공
                    tone(11, NOTE_E6, 500); delay(600), noTone(6);
                    tone(11, NOTE_G6, 500); delay(600), noTone(6);
                    tone(11, NOTE_C7, 500); delay(600), noTone(6);

                    digitalWrite(pinLED_g, HIGH);
                    delay(500);
                    digitalWrite(pinLED_g, LOW);
                    delay(500);

                    tru = 0;
                    count = 0;
                }

                else {
                    tone(11, NOTE_D2, 300); delay(501), noTone(6);//실패

                    digitalWrite(pinLED_r, HIGH);
                    delay(500);
                    digitalWrite(pinLED_r, LOW);
                    delay(500);

                    tru = 0;
                    count = 0;
                    number = 0;
                }
            }

            switch (key) {
            case '1':
                tone(11, NOTE_C4, 500); delay(501), noTone(6);
                break;
            case '2':
                tone(11, NOTE_D4, 500); delay(501), noTone(6);
                break;
            case '3':
                tone(11, NOTE_E4, 500); delay(501), noTone(6);
                break;
            case 'A':
                tone(11, NOTE_F4, 500); delay(501), noTone(6);
                break;

            case '4':
                tone(11, NOTE_G4, 500); delay(501), noTone(6);
                break;
            case '5':
                tone(11, NOTE_A4, 500); delay(501), noTone(6);
                break;
            case '6':
                tone(11, NOTE_B4, 500); delay(501), noTone(6);
                break;
            case 'B':
                tone(11, NOTE_C5, 500); delay(501), noTone(6);
                break;

            case '7':
                tone(11, NOTE_D5, 500); delay(501), noTone(6);
                break;
            case '8':
                tone(11, NOTE_E5, 500); delay(501), noTone(6);
                break;
            case '9':
                tone(11, NOTE_F5, 500); delay(501), noTone(6);
                break;
            case 'C':
                tone(11, NOTE_G5, 500); delay(501), noTone(6);
                break;

            case '*':
                tone(11, NOTE_A5, 500); delay(501), noTone(6);
                break;
            case '0':
                tone(11, NOTE_B5, 500); delay(501), noTone(6);
                break;
            case '#':
                tone(11, NOTE_C6, 500); delay(501), noTone(6);
                break;
            case 'D':
                tone(11, NOTE_D6, 500); delay(501), noTone(6);
                break;
            }

        }
    }