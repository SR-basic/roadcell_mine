void loadcell_ver1(){
  int value;

  scale.set_scale(calibration_factor);
  scale.tare(); //영점잡기. 현재 측정값을 0으로 둔다.

  while(1) {
    value = (int)scale.get_units(10);
    if (value < -5){
      value = abs(value);
    }
    Serial.print(value);
    Serial.println(" g");

    delay(2000);
      
    if (value >= 25) break;   // 25g 넘으면 쓰레기통 닫겠습니다. (+미구연 쓰레기통이 10초 넘게 열려있으면)
  }
}