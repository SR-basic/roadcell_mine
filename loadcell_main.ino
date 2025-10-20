#include <HX711.h>
#include <math.h>
#define calibration_factor 400    //캘리브레이션 값 (음수값이 나올 수 있음)
                                    // 절대값 기준으로 원래 무게보다 더 나가면 값을 추가
                                    // 절대값 기준으로 원래 무게보다 덜 나가면 값을 감소
#define error 25                    // 초음파센서의 오차범위
const int DOUT_PIN = 32;
const int SCK_PIN = 33;
const int trig = 16;
const int echo = 17;
int duration;
int cm;
float distance;
float meter;
int check_distance;

using namespace std;

HX711 scale;

void setup() {
    Serial.begin(9600);  
    scale.begin(DOUT_PIN,SCK_PIN);
    pinMode(trig, OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    pinMode(echo,INPUT);
    delay(6000);
    Serial.println("Distance");
}
void loop() {
    check_distance = get_distance();
    if(check_distance != 0 && check_distance > 5)
    {
        Serial.println("쓰레기통이 열립니다.");
        loadcell_ver1();
        Serial.println("쓰레기통이 닫힙니다.");
        delay(2000);
    }
}