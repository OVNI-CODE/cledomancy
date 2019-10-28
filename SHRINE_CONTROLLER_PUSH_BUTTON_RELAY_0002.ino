void setup() {
  // put your setup code here, to run once:
// Serial.begin(9600);

pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
 digitalWrite(13, HIGH);//turn OFF relay
   digitalWrite(12, HIGH);//turn OFF relay
pinMode(5, OUTPUT);//POSITIVE LEAD FOR SWITCH
pinMode(7, INPUT); // TIMER SWITCH
 digitalWrite(7, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(5, LOW);

if((digitalRead(7)) == LOW)//HIGH =on/UP
 { 
  //TURN ON THE MAIN RELAY 
 digitalWrite(13, LOW);//turn on relay
 //
 //SECONDARY RELAY ON AND OFF EVERY 3 SECONDS
   digitalWrite(12, LOW);//turn OFF relay
      
  delay(17000);
    digitalWrite(13, HIGH);//turn oFF relay
      delay(3000);
   digitalWrite(12, HIGH);//turn OFF relay


  
     }
   
     
     delay(12);
}
