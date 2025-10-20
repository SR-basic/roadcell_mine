int get_distance(){
  int cm = check_error_duration(5);
  if(cm != 0)  {
    // Serial.print(cm);
    // Serial.println("cm");
    delay(10);
  }
  return cm;
}

int get_duration(){
  int duration = 0;
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);

  return pulseIn(echo, HIGH);
}

int check_error_duration(int cnt){
  int hap = 0;
  int distance[5];
  for(int i = 0 ; i < cnt ; i++){
    duration = get_duration();
    cm = duration/58;
    delay(10);
    hap = hap + cm;
    distance[i]=cm; 
  }
  int avg = hap / cnt;
  
  
  for(int i = 0 ; i < cnt; i++){
    if(abs(avg-distance[i])>error){
      return 0;
    }
  }
  return avg;
}
