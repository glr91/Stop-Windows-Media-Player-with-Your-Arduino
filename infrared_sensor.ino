// Infrared Sensor

int receiverpin=11; // pin 11 of IR receiver to Arduino 
                    // digital pin 11
#include <IRremote.h> // use the library                  
#include <IRremoteInt.h>
IRrecv irrecv(receiverpin); // create instance of irrecv
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); // start the IR receiver
}

void loop(){
  if(irrecv.decode(&results)){
    // have we received an IR signal?
    Serial.print(results.value,HEX); // display IR code on the
                                     // Serial Monitor
    Serial.print(" ");
    irrecv.resume(); // receive the next value
  }
}
