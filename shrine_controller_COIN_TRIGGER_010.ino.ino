// PIN9 TRIGGERS THE MP3 DIVINATION DEVICE
//RELAYS ON PINS 2,3,4,5 CONTROL NEONS (WIRED IN PAIRS)
// RELAY ON PIN 6 UNUSED

void setup() {

  randomSeed(analogRead(A0) + analogRead(A1) + analogRead(A2));
    

  
//int CountCoin = 0;


}

void loop() {

//coin in pin -SET HIGH TO STOP
    pinMode(7, INPUT);
    digitalWrite(7, HIGH);

    //TRIGGER MP3 PLAYER pin -SET LOW TO STOP mp3
    pinMode(9, OUTPUT);
    digitalWrite(9, LOW);

// relay pins STOP RELAYS
    pinMode(2, INPUT);
      pinMode(3, INPUT);
        pinMode(4, INPUT);
          pinMode(5, INPUT);
          //COMPUTER LEDS OFF
            pinMode(6, INPUT);
            //OTHER 3 RELAYS
           pinMode(10, INPUT);
      pinMode(11, INPUT);
        pinMode(12, INPUT);
        
          
  int CoinOp = digitalRead(7);



if(CoinOp == LOW)
// switch is pressed - pullup keeps pin high normally
{
   delay(100); // delay to debounce switch
//TURN ON MP3
 digitalWrite(9, HIGH);
  

RunNeons();
}}//END LOOP



//>>>>>>>>>>>>>>>>>>>>>>SELECT RELAY/NEON FUNCTION
void RunNeons()
{
    //turn on lights on white board
    pinMode(6, OUTPUT);
   
 
 int CountCoin = 1;
 int cycle = random(6,12); 
int timer = cycle;  //AMOUNT OF TIMES TO REPEAT THE neon rotation
int tempo = 600; //miliseconds delay between each CYCLE
int OnTime= 400; //how long each neon on

//>>>>>>WHILE LOOP
  while(CountCoin < timer){
 // loop from the lowest pin to the highest:
  for (int thisPin = 2; thisPin < 6; thisPin++) {
     // turn the pin on:FOR NEON LIGHTS
    pinMode(thisPin, OUTPUT); 
    //DELAY BETWEEN SELECTIONS
    delay(OnTime);
    // turn the pin off:
      pinMode(thisPin, INPUT); 
CountCoin++;


    
delay(tempo);        // delay in between reads for stability
  }//END FOR LOOP
  }//END WHILE LOOP

//>>>>>>>>>>>>>>>>>>>>>
    //TURN NEONS OFF
  // relay pins STOP RELAYS
    pinMode(2, INPUT);
      pinMode(3, INPUT);
        pinMode(4, INPUT);
          pinMode(5, INPUT);
         
            //OTHER 3 RELAYS
           pinMode(10, INPUT);
      pinMode(11, INPUT);
        pinMode(12, INPUT);
        
           //turn OFF lights on white board
    pinMode(6, INPUT);
  //start radio voices
  SelectRadio();
 }//END LOOP








//>>>>>>>>>>>>>>>>>>>>>>SELECT RADIO/NEON FUNCTION
void SelectRadio()
{     //  the radio relays 10,11,12  
  
  //turn on lights on white board
    pinMode(6, OUTPUT);
    
 
 //TURN ON THE PIN9 TO START MP3 PLAYER
pinMode(9, OUTPUT);
   
    int CountCoin2 = 1;
    int cycle = random(2,6); 
int timer2 = cycle; //AMOUNT OF TIMES TO REPEAT THE CYCLE
  
int tempo = 3000; //RADIO OFF TIME miliseconds delay between each cycle
int TimeOn = 5000; //0[time for radio to stay on
//>>>>>>WHILE LOOP
  while(CountCoin2 < timer2){

 // loop from the lowest pin to the highest FOR RADIO RELAYS 9,10,11
  for (int thisPin = 10; thisPin < 13; thisPin++) {
   
      // next decide if radio1 is on or off
pinMode(thisPin, OUTPUT); 

if(timer2 > 3){  //turn on lights on white board after 3 cycles
    pinMode(6, OUTPUT);}
    
    //TIME ON DELAY
    delay(TimeOn);
    // turn the pin off:
      pinMode(thisPin, INPUT);       
CountCoin2++;
delay(tempo);        // delay in between reads for stability
  }
  }//END WHILE LOOP
   //TURN OFF THE PIN9 TO STOP MP3 PLAYER
    pinMode(9, INPUT);
 //run the fast neons at end
  RunNeonsEnd();
 }//END LOOP



//>>>>>>>>>>>>>>>>>>>>>>SELECT RELAY/NEON FUNCTION
void RunNeonsEnd()
{
    //turn off lights on white board
    pinMode(6, INPUT);
     //TURN OFF THE PIN9 TO STOP MP3 PLAYER
    pinMode(9, INPUT);
 
 int CountCoin = 1;
 int cycle = random(6,12); 
int timer = cycle;  //AMOUNT OF TIMES TO REPEAT THE neon rotation
int tempo = 400; //miliseconds delay between each CYCLE
int OnTime= 200; //how long each neon on

//>>>>>>WHILE LOOP
  while(CountCoin < timer){
 // loop from the lowest pin to the highest:
  for (int thisPin = 2; thisPin < 6; thisPin++) {
     // turn the pin on:FOR NEON LIGHTS
    pinMode(thisPin, OUTPUT); 
    //DELAY BETWEEN SELECTIONS
    delay(OnTime);
    // turn the pin off:
      pinMode(thisPin, INPUT); 
CountCoin++;


    
delay(tempo);        // delay in between reads for stability
  }//END FOR LOOP
  }//END WHILE LOOP

//>>>>>>>>>>>>>>>>>>>>>
    //TURN NEONS OFF
  // relay pins STOP RELAYS
    pinMode(2, INPUT);
      pinMode(3, INPUT);
        pinMode(4, INPUT);
          pinMode(5, INPUT);
         
            //OTHER 3 RELAYS
           pinMode(10, INPUT);
      pinMode(11, INPUT);
        pinMode(12, INPUT);
        
           
 //GO BACK TO LOOP AND WAIT FOR A NEW COIN
  loop();
 }//END LOOP


