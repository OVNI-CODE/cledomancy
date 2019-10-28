// volume set low to test
//>>>>>>>>>>>>>>>>> MP3 PLAYER

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

// Create the mp3 module object, 
//   Arduino Pin 2 is connected to TX of the JQ6500
//   Arduino Pin 4 is connected to one end of a  1k resistor, 
//     the other end of the 1k resistor is connected to RX of the JQ6500
//   If your Arduino is 3v3 powered, you can omit the 1k series resistor
JQ6500_Serial mp3(2,4);

unsigned int numFiles; // Total number of files on media (autodetected in setup())
byte mediaType;        // Media type (autodetected in setup())




//SETUP>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void setup() {
randomSeed(analogRead(A0) + analogRead(A3) + analogRead(A2));
  // Begin the connection, reset the device, and set volume to a reasonable level
  mp3.begin(9600);
  while(numFiles == 0)
  {
    mp3.reset();  
    
    mp3.setVolume(30);
    mp3.setLoopMode(MP3_LOOP_NONE);
   
    // Try to get the number of files on the SD Card
    numFiles = mp3.countFiles(MP3_SRC_SDCARD);
  
    if(numFiles)
    {
      // If there are SD Card files, make sure we have selected that source    
      mp3.setSource(MP3_SRC_SDCARD);    
      mediaType = MP3_SRC_SDCARD;
    }    
    if(!numFiles)
    {
      delay(3000);
    }
  }
}
//MAIN LOOP >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void loop() {
   
   pinMode(A1, INPUT);
  int CoinOp = digitalRead(A1);
if(CoinOp == HIGH){
 selectfile(); //call the randonplay function
}}
  





//PLAY FILE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 
void selectfile() {
    //  ** NOTE: Checking for STOPPED doesn't work with the builtin memory 
  //      because in that case the devie appears to only return PAUSED, not STOPPED  
byte stat = mp3.getStatus();
 if(stat != MP3_STATUS_PLAYING) 
  {
    // pick a random file, numbered 1 to numFiles (NB: random() returns up to but not including the highest number, hence why we add 1)
    // if the file is the same as the one which was just played, pick a different one
    unsigned int pick;
     unsigned int pick1;
      unsigned int pick2;
      int delaytime = 6000; //millisecs between each repeat
      
     unsigned int PickStart;
  
       PickStart = random(numFiles-13);
       //PickStart below replaces the number 1 as the starting point of the files
     int countPlay = 1;
     int playLimit = 2;
     
     

// >>>>>START PLAYLOOP   
   while (countPlay < playLimit)
   {
 pick = random(1,numFiles+1);
       pick1 = random(1,numFiles+1);
        pick2 = random(1,numFiles+1);
    
   pick == mp3.currentFileIndexNumber(mediaType);
   
    // and play it
    mp3.playFileByIndexNumber(pick);
    mp3.play();
    
  delay(delaytime); // DELAY AND THEN play it again sam
   // and play it
    mp3.playFileByIndexNumber(pick1);
    mp3.play();
    
  delay(delaytime); // DELAY AND THEN play it again sam
   // and play it
    mp3.playFileByIndexNumber(pick2);
    mp3.play();

    
    int CoinOp = digitalRead(A1);
if(CoinOp == LOW){//check if coin timer on other arduino is still running
    break;
  Resetup(); // if not -go back to start
}
    
    
  delay(delaytime); // DELAY AND THEN play it again sam
     mp3.playFileByIndexNumber(pick);
    mp3.play();
    
  delay(delaytime); // DELAY AND THEN play it again sam
   // and play it
    mp3.playFileByIndexNumber(pick1);
    mp3.play();
    
  delay(delaytime); // DELAY AND THEN play it again sam
   // and play it
    mp3.playFileByIndexNumber(pick2);
    mp3.play();

  CoinOp = digitalRead(A1);
if(CoinOp == LOW){//check if coin timer on other arduino is still running
   break;
  Resetup(); // if not -go back to start
}


countPlay++; 
}///end looop>>>>>>>>>>>>>>>
Resetup(); // CODE TO START RESET UP AFTER EACH TRACK
    }}






//RESET UP THE MP3 PLAYER>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void Resetup() {
 //FUNCTION KEPT HERE IN CASE MP3 PLAYER NEEDS TO BE RESTARTED
   randomSeed(analogRead(A0) + analogRead(A1) + analogRead(A2));
  // Begin the connection, reset the device, and set volume to a reasonable level
  mp3.begin(9600);
  while(numFiles == 0)
  {
    mp3.reset();  
    
    mp3.setVolume(20);
    mp3.setLoopMode(MP3_LOOP_NONE);
   
    // Try to get the number of files on the SD Card
    numFiles = mp3.countFiles(MP3_SRC_SDCARD);
  
    if(numFiles)
    {
      // If there are SD Card files, make sure we have selected that source    
      mp3.setSource(MP3_SRC_SDCARD);    
      mediaType = MP3_SRC_SDCARD;
    }    
    if(!numFiles)
    {
      delay(3000);
    }
  }
  //loop(); //return to loop mode
  gamelantone();
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void gamelantone()
{
  // read the sensor:
//int sensorReading = analogRead(A1);
  // map the analog input range (in this case, 400 - 1000 from the photoresistor)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving:
//int thisPitch = map(sensorReading, 200, 1000, 120, 1500);

 int CountCoin = 1;
 int timer = 13;  //AMOUNT OF TIMES TO REPEAT THE RANDOM SELECTION
 int octave = 23;
 int timing = 222; //milliseconds between notes
  
  while(CountCoin < timer){
   //int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
int notelength = random(200,400);//length of note
   int PinOut = 8; //pin to use for output
 int randomnumber1 = random(8);
  int gamTone = 0; 
   int gam0 = 204.40;
   int gam1 = 408.81;
   int gam2 = 433.51;
   int gam3 = 597.81;
   int gam4 = 648.19;
   int gam5 = 820.33;
   int gam6 = 872.61;
   int gam7 = 1110.62;
   int gam8 = 1198.57;


 
   // do something different depending on the
  // randomnumber1 value:


  
  switch (randomnumber1) {
    case 0:    // your hand is on the sensor
  gamTone = gam0;
      break;
    case 1:    // your hand is close to the sensor
  gamTone = gam1;
      break;
    case 2:    // your hand is a few inches from the sensor
  gamTone = gam2;
      break;
    case 3:    // your hand is nowhere near the sensor
    gamTone = gam3;
      break;
       case 4:    // your hand is nowhere near the sensor
     gamTone = gam4;
      break;
       case 5:    // your hand is nowhere near the sensor
   gamTone = gam5;
      break;
        case 6:    // your hand is nowhere near the sensor
  gamTone = gam6;
      break;
        case 7:    // your hand is nowhere near the sensor
    gamTone = gam7;
      break;
         case 8:   
    gamTone = gam8;
      break;
     
  }
  
  //divide the gamtone for lower octaves
   tone(PinOut, gamTone / random(4,octave), notelength);
  
 
  delay(timing);        // delay  between each note
  noTone(PinOut);

CountCoin++;
  }
  
  
 //loop();
  tone2(); //call second tone 
  //windGen(); //call wind sound
  //updateControl();
  
  }




//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>TONE2
  void tone2()

{

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is


  // declare pin x to be an output:
  pinMode(led, OUTPUT);

// the loop routine 
 int CountCoin2 = 1;
 int timer2 = 47;  //AMOUNT OF TIMES TO REPEAT THE TONE BELOW

 //>>>>>>>START TONE LOOP
  while(CountCoin2 < timer2)
  {

    int fadeAmount = random(13,93);    // how many points to fade the LED by
int timing2 = random(13,93); //milliseconds between notes


  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  
  CountCoin2++;
  // wait for 30 milliseconds to see the dimming effect
  delay(timing2);
}
  // declare pin x to be an input:
  pinMode(led, INPUT);
loop();

}

