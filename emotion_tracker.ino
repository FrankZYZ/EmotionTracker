#include <Arduino_MKRIoTCarrier.h>
MKRIoTCarrier carrier;
//Define few parameters needed for the system logic
unsigned long buttonPressStartTime[5] = {0,0,0,0,0};
unsigned long buttonPressDuration[5] = {0,0,0,0,0};
int buttonPressCount[5] = {0,0,0,0,0};
bool plus_now[5]={0,0,0,0,0};
int recording_status[5]={0,0,0,0,0};

//Define emotions
char emotions[][10]={
  "Joy",
  "Anger",
  "Sad",
  "Fear",
  "Disgust"
};

//Define color of each emotion
unsigned int colors[5]={
  ST77XX_YELLOW,
  ST77XX_RED,
  ST77XX_BLUE,
  ST77XX_MAGENTA,
  ST77XX_GREEN
};

//Setup
void setup() {
  delay(1500);
  Serial.begin(9600);
  CARRIER_CASE = false;
  carrier.begin();
}

void loop() {
  // Updates state of all buttons
  carrier.Buttons.update();
  //--------------------------------------------------------
  //Button 0 - Joy
  if (carrier.Button0.getTouch()) {
    plus_now[0]=1;
    buttonPressDuration[0] = millis() - buttonPressStartTime[0];
    if (buttonPressDuration[0] >= 1500 ) {
      if (recording_status[0]==0 && check_other_if_recording(recording_status)==0) {//no other recording at the time.
        recording_status[0]=1;
        play_beep(1,0);
        show(0,0,0);
      }else if (recording_status[0]==1 && check_other_if_recording(recording_status)==1){//only this emotion is recording
        recording_status[0]=0;
        play_beep(0,0);
        show(0,0,1);
      }
      reset_time(0);
    }
  }else if(!carrier.Button0.getTouch()) {
    buttonPressStartTime[0] = millis();
    if (plus_now[0]==1 && recording_status[0]==1 && check_other_if_recording(recording_status)==1) {
      buttonPressCount[0]++;
      carrier.Buzzer.beep(1400,50);
      show(0,1,0);
      plus_now[0]=0;
    }
  }

  //--------------------------------------------------------
  //Button 1 - Anger
  if (carrier.Button1.getTouch()) {
    plus_now[1]=1;
    buttonPressDuration[1] = millis() - buttonPressStartTime[1];
    if (buttonPressDuration[1] >= 1500) {
      if (recording_status[1]==0 && check_other_if_recording(recording_status)==0) {
        recording_status[1]=1;
        play_beep(1,1);
        show(1,0,0);
      }else if (recording_status[1]==1 && check_other_if_recording(recording_status)==1){
        recording_status[1]=0;
        play_beep(0,1);
        show(1,0,1);
      }
      reset_time(1);
    }
  }else if(!carrier.Button1.getTouch()) {
    buttonPressStartTime[1] = millis();
    if (plus_now[1]==1 && recording_status[1]==1 && check_other_if_recording(recording_status)) {
      buttonPressCount[1]++;
      carrier.Buzzer.beep(1400,50);
      show(1,1,0);
      plus_now[1]=0;
    }
  }
  
  //--------------------------------------------------------
  //Button 2 - Sad
  if (carrier.Button2.getTouch()) {
    plus_now[2]=1;
    buttonPressDuration[2] = millis() - buttonPressStartTime[2];
    if (buttonPressDuration[2] >= 1500) {
      if (recording_status[2]==0 && check_other_if_recording(recording_status)==0) {
        recording_status[2]=1;
        play_beep(1,2);
        show(2,0,0);
      }else if (recording_status[2]==1 && check_other_if_recording(recording_status)==1){
        recording_status[2]=0;
        play_beep(0,2);
        show(2,0,1);
      }
      reset_time(2);
    }
  }else if(!carrier.Button2.getTouch()) {
    buttonPressStartTime[2] = millis();
    if (plus_now[2]==1 && recording_status[2]==1 && check_other_if_recording(recording_status)) {
      buttonPressCount[2]++;
      carrier.Buzzer.beep(1400,50);
      show(2,1,0);
      plus_now[2]=0;
    }
  }
  
  //--------------------------------------------------------
  //Button 3 - Fear
  if (carrier.Button3.getTouch()) {
    plus_now[3]=1;
    buttonPressDuration[3] = millis() - buttonPressStartTime[3];
    if (buttonPressDuration[3] >= 1500) {
      if (recording_status[3]==0 && check_other_if_recording(recording_status)==0) {
        recording_status[3]=1;
        play_beep(1,3);
        show(3,0,0);
      }else if (recording_status[3]==1 && check_other_if_recording(recording_status)==1){
        recording_status[3]=0;
        play_beep(0,3);
        show(3,0,1);
      }
      reset_time(3);
    }
  }else if(!carrier.Button3.getTouch()) {
    buttonPressStartTime[3] = millis();
    if (plus_now[3]==1 && recording_status[3]==1 && check_other_if_recording(recording_status)) {
      buttonPressCount[3]++;
      carrier.Buzzer.beep(1400,50);
      show(3,1,0);
      plus_now[3]=0;
    }
  }
  
  //--------------------------------------------------------
  //Button 4 - Disgust
  if (carrier.Button4.getTouch()) {
    plus_now[4]=1;
    buttonPressDuration[4] = millis() - buttonPressStartTime[4];
    if (buttonPressDuration[4] >= 1500) {
      if (recording_status[4]==0 && check_other_if_recording(recording_status)==0) {
        recording_status[4]=1;
        play_beep(1,4);
        show(4,0,0);
      }else if (recording_status[4]==1 && check_other_if_recording(recording_status)==1){
        recording_status[4]=0;
        play_beep(0,4);
        show(4,0,1);
      }
      reset_time(4);
    }
  }else if(!carrier.Button4.getTouch()) {
    buttonPressStartTime[4] = millis();
    if (plus_now[4]==1 && recording_status[4]==1 && check_other_if_recording(recording_status)) {
      buttonPressCount[4]++;
      carrier.Buzzer.beep(1400,50);
      show(4,1,0);
      plus_now[4]=0;
    }
  }

}

//Screen updates
int show(int emotion,bool if_print_intensity, bool if_end) {
  if (if_end) {
    carrier.display.fillScreen(ST77XX_BLACK);
    carrier.display.setTextColor(ST77XX_WHITE); // black text
    carrier.display.setTextSize(3); // large text size
    carrier.display.setCursor(20, 100); // sets position for printing (x and y)
    carrier.display.println("Recorded.");
    delay(500);
    carrier.display.fillScreen(ST77XX_BLACK);
    return 1;
  }
  //carrier.display.fillScreen(ST77XX_BLACK);
  carrier.display.fillScreen(colors[emotion]); // green background
  carrier.display.setTextColor(ST77XX_BLACK); // black text
  carrier.display.setTextSize(3); // large text size
  carrier.display.setCursor(40, 80); // sets position for printing (x and y)
  carrier.display.println(emotions[emotion]); // prints "Emotion"
  carrier.display.setCursor(40, 105); // sets position for printing (x and y)
  carrier.display.println("Intensity: "); // prints "Intensity: "
  if (if_print_intensity) {
    carrier.display.setCursor(40, 130); // sets position for printing (x and y)
    carrier.display.println(buttonPressCount[emotion]); // prints "Intensity: "
    Serial.print("Emotion: ");
    Serial.println(emotions[emotion]);
    Serial.print("Button press count: ");
    Serial.println(buttonPressCount[emotion]);
  }
  return 0;
}

//Play notification sound
int play_beep(int if_start,int emotion) {
  if (if_start==1) {
    Serial.println("Start recording!");
    carrier.Buzzer.beep(800,100);
    carrier.Buzzer.beep(1000,100);
    carrier.Buzzer.beep(1200,100);
    carrier.Buzzer.beep(1400,100);
  }else{
    Serial.print("End recording, intensity: ");
    Serial.println(buttonPressCount[emotion]);
    carrier.Buzzer.beep(1400,100);
    carrier.Buzzer.beep(1200,100);
    carrier.Buzzer.beep(1000,100);
    carrier.Buzzer.beep(800,100);
  }
  return 0;
}

//Reset the button pressed time
void reset_time(int emotion) {
  buttonPressStartTime[emotion] = millis();
  buttonPressDuration[emotion] = 0;
  buttonPressCount[emotion] = 0;
}

//Check if there is other emotion recording.
int check_other_if_recording(int* status) {
  return (status[0]+status[1]+status[2]+status[3]+status[4]);
}