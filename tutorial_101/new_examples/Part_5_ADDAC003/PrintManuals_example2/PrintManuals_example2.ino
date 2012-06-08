#include <StandardCplusplus.h>
#include <vector>

#include <ADDAC.h>

ADDAC VCC; 

//#define DEBUG       // Just comment this line if you are not debugging

void setup(){
  VCC.setup();

#ifdef DEBUG
  Serial.begin(115200);
#endif

}

void loop(){
  VCC.update(); 

  if(VCC.MODE==0){ 
    if(VCC.SUBMODE==0){ 
      //program to preset in MODE “0”, SUBMODE “0”.
      //Generate voltage in VCC output 1 controlled by Manual POT 1 
      VCC.WriteChannel(1, VCC.ReadManual(A,1));
    }

    else if(VCC.SUBMODE==1){ 
      //program to preset in MODE “0”, SUBMODE “1”.
      for(int i=0;i<6;i++){
        //generate voltage in the first 6 output controlled by the 6 Manual POTS
        VCC.WriteChannel(i, VCC.ReadManual(A,i));
      }
    }
  }

#ifdef DEBUG
  Serial.println();
  delay(10);
#endif
}

