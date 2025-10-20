#include "HX711.h"
#define calibration_factor -1080    //캘리브레이션 값 (음수값이 나올 수 있음)
                                    // 절대값 기준으로 원래 무게보다 더 나가면 값을 추가
                                    // 절대값 기준으로 원래 무게보다 덜 나가면 값을 감소

const int DOUT_PIN = 2;
const int SCK_PIN = 3;

HX711 scale;

int value;

void setup() {
    Serial.begin(9600);  
    scale.begin(DOUT_PIN,SCK_PIN);
    scale.set_scale(calibration_factor);
    scale.tare(); //영점잡기. 현재 측정값을 0으로 둔다.
}
void loop() {
    value = (int)scale.get_units(10);
    Serial.print(value);
    Serial.println(" g");

    delay(2000);
}