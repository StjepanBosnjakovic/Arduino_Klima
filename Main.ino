#include <IRremote.h>

IRsend irsend;
String inputString;
boolean stringComplete;
int curFan;
int curTemp;

/*
 unsigned long commandsF2[]={0x8808F07,0x8808E06,0x8808D05,0x8808C04,0x8808B03,0x8808A02,0x8808901,0x8808800,
  0x880870F,0x880860E,0x880850D,0x880840C,0x880830B};

 unsigned long commandsF3[]={0x8808F90,0x8808E9F,0x8808D9E,0x8808C9D,
 0x8808B9C,0x8808A9B,0x880899A,0x8808899,0x8808798,0x8808697,0x8808596,0x8808495,0x8808394};

 unsigned long commandsF4[]={0x8808F29,0x8808E28,0x8808D27,0x8808C26,0x8808B25,0x8808A24,0x8808923,0x8808822,0x8808721,0x8808620,
  0x880852F,0x880842E,0x880832D};

 unsigned long commandsF5[]={0x8808FA1,0x8808EA0,0x8808DAF,0x8808CAE,0x8808BAD,
  0x8808AAC,0x88089AB,0x88088AA,0x88087A9,0x88086A8,0x88085A7,0x88084A6,0x88083A5};

 unsigned long commandsF6[]={0x8808F4B,0x8808E4A,0x8808D49,0x8808C48,0x8808B47,0x8808A46,0x8808945,0x8808844,
  0x8808743,0x8808642,0x8808541,0x8808440,0x880834F};
*/



void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

    if (stringComplete) {
    //Serial.println(inputString);
    // clear the string:
    eventProcess(inputString);
    inputString = "";
    stringComplete = false;
  }

}

void eventProcess(String input){
  if(input.indexOf("off") > -1){
    irsend.sendLG((unsigned long int)0x88C0051, 28);
    Serial.println("off");
  } else if(input.indexOf("on") > -1){
    irsend.sendLG((unsigned long int)0x8800DA7, 28);
    Serial.println("on");
    curFan=4;
    curTemp=28;
  }else if(input.indexOf("temp") > -1){
    int temp = input.substring(input.indexOf(":")+1,input.length()).toInt();
    Serial.println(temp);
    findCommandos(temp, curFan);
    curTemp = temp;
    //irsend.sendLG(code, 28);
  }else if(input.indexOf("fan") > -1){
    int fan = input.substring(input.indexOf(":")+1,input.length()).toInt();
    Serial.println(fan);
    findCommandos(curTemp, fan);
    curFan = fan;
   // irsend.sendLG(code, 28);
  }
  
  
  }

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if (inChar == '$') {
      stringComplete = true;
      return;
    }
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    
  }
}

/*int findCommand(Command arr[], int temp){
 int i=0;
 for(i; i<13; i++){
    Serial.print(arr[i].key);
    Serial.print(">>>>");
    Serial.println(arr[i].command);
  if(arr[i].key == temp){
    return arr[i].command;
    }
  }
  
 return 5;
}*/

void findCommandos(int temp, int fan){
 /* temp -= 30;
  if(temp < 0 ){
    temp = abs(temp);
  }
  Serial.print(temp);
  Serial.print(">>>>");
  Serial.println(fan);
  if(fan == 2){
    return commandsF2[temp];
  }else if(fan == 3){
    return commandsF3[temp];
  }else if(fan == 4){
    return commandsF4[temp];
  }else if(fan == 5){
    return commandsF5[temp];
  }else if(fan == 6){
    return commandsF6[temp];
  }else {
    irsend.sendLG(0;
  }*/
  switch (temp) {
    case 30:    
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        case 0:         irsend.sendLG(0x‭8808F5C,28);         case 1
        irsend.sendLG(0x8808F07,28);
        break;
        case 2:
        irsend.sendLG(0x8808F90,28);
        break;
        case 3:
        irsend.sendLG(0x8808F29,28);
        break;
        case 4:
        irsend.sendLG(0x8808FA1,28);
        break;
        case 5,:
        irsend.sendLG(0x8808F4B,28);
        break;
      }
      break;
    case 29:   
      switch (fan) {
        case 0:         
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x8808E06,28);
        break;
        case 2:
        irsend.sendLG(0x8808E9F,28);
        break;
        case 3:
        irsend.sendLG(0x8808E28,28);
        break;
        case 4:
        irsend.sendLG(0x8808EA0,28);
        break;
        case 5:
        irsend.sendLG(0x8808E4A,28);
        break;
      }
      break;
    case 28: 
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x8808D05,28);
        break;
        case 2:
        irsend.sendLG(0x8808D9E,28);
        break;
        case 3:
        irsend.sendLG(0x8808D27,28);
        break;
        case 4:
        irsend.sendLG(0x8808DAF,28);
        break;
        case 5:
        irsend.sendLG(0x8808D49,28);
        break;
      }
      break;
    case 27:  
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x8808C04,28);
        break;
        case 2:
        irsend.sendLG(0x8808C9D,28);
        break;
        case 3:
        irsend.sendLG(0x8808C26,28);
        break;
        case 4:
        irsend.sendLG(0x8808CAE,28);
        break;
        case 5:
        irsend.sendLG(0x8808C48,28);
        break;
      }
      break;
    case 26:    
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x8808B03,28);
        break;
        case 2:
        irsend.sendLG(0x8808B9C,28);
        break;
        case 3:
        irsend.sendLG(0x8808B25,28);
        break;
        case 4:
        irsend.sendLG(0x8808BAD,28);
        break;
        case 5:
        irsend.sendLG(0x8808B47,28);
        break;
      }
      break;
    case 25:   
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x8808A02,28);
        break;
        case 2:
        irsend.sendLG(0x8808A9B,28);
        break;
        case 3:
        irsend.sendLG(0x8808A24,28);
        break;
        case 4:
        irsend.sendLG(0x8808AAC,28);
        break;
        case 5:
        irsend.sendLG(0x8808A46,28);
        break;
      }
      break;
    case 24:   
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        case 1:
        irsend.sendLG(0x8808901,28);
        break;
        case 2:
        irsend.sendLG(0x880899A,28);
        break;
        case 3:
        irsend.sendLG(0x8808923,28);
        break;
        case 4:
        irsend.sendLG(0x88089AB,28);
        break;
        case 5:
        irsend.sendLG(0x8808945,28);
        break;
      }
      break;
    case 23:  
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x8808800,28);
        break;
        case 2:
        irsend.sendLG(0x8808899,28);
        break;
        case 3:
        irsend.sendLG(0x8808822,28);
        break;
        case 4:
        irsend.sendLG(0x88088AA,28);
        break;
        case 5:
        irsend.sendLG(0x8808844,28);
        break;
      }
      break;
    case 22:    
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x880870F,28);
        break;
        case 2:
        irsend.sendLG(0x8808798,28);
        break;
        case 3:
        irsend.sendLG(0x8808721,28);
        break;
        case 4:
        irsend.sendLG(0x88087A9,28);
        break;
        case 5:
        irsend.sendLG(0x8808743,28);
        break;
      }
      break;
    case 21:   
      switch (fan) {
        case 0:
        irsend.sendLG(0x880860E,28);
        break;
        case 2:
        irsend.sendLG(0x8808697,28);
        break;
        case 3:
        irsend.sendLG(0x8808620,28);
        break;
        case 4:
        irsend.sendLG(0x88086A8,28);
        break;
        case 5:
        irsend.sendLG(0x8808642,28);
        break;
      };
      break;
    case 20:   
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x880850D,28);
        break;
        case 2:
        irsend.sendLG(0x8808596,28);
        break;
        case 3:
        irsend.sendLG(0x880852F,28);
        break;
        case 4:
        irsend.sendLG(0x88085A7,28);
        break;
        case 5:
        irsend.sendLG(0x8808541,28);
        break;
      }
      break;
    case 19:  
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
        irsend.sendLG(0x880840C,28);
        break;
        case 2:
        irsend.sendLG(0x8808495,28);
        break;
        case 3:
        irsend.sendLG(0x880842E,28);
        break;
        case 4:
        irsend.sendLG(0x88084A6,28);
        break;
        case 5:
        irsend.sendLG(0x8808440,28);
        break;
      }
      break;
    case 18:    
      switch (fan) {
        case 0:
        irsend.sendLG(0x‭8808F5C,28);
        break;
        case 1:
//        irsend.sendLG(0x880830B,28);
        break;
        case 2:
        irsend.sendLG(0x8808394,28);
        break;
        case 3:
        irsend.sendLG(0x880832D,28);
        break;
        case 4:
        irsend.sendLG(0x88083A5,28);
        break;
        case 5:
        irsend.sendLG(0x880834F,28);
        break;
      }
      break;
  }


  
}
