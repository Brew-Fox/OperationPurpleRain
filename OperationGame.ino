int Touch = 2;
int Disarm = 3;
int Challenge = A0;
int relayPin1 = 4; 
int relayPin2 = 5;
int relayPin3 = 6; 
int relayPin4 = 7;
int relayPin5 = 8; 
int relayPin6 = 9; 
int relayPin7 = 10;
int relayPin8 = 11;

const int necessary_delay=10; //in milliseconds
int isTouching = 0; //Note how it is declared outside the loop
unsigned long countStart;

// timers
int kill = 0;
int timer = 0;
int wait = 0;

int lightON1 = 1;
int lightON2 = 1;
int lightON3 = 1;
int lightON4 = 0;
int buzzON = 0;


void setup()
{
 /*Not always necessary with some boards with pin 13 automatically connected to led, but shouldn't harm. Also, LED could be changed later. */
 
 pinMode(Touch, INPUT_PULLUP);
 pinMode(Disarm, INPUT_PULLUP);
 pinMode(Challenge, INPUT);
 
  // AC lights
 pinMode(relayPin1, OUTPUT);      // sets the digital pin as output
 pinMode(relayPin2, OUTPUT);      // sets the digital pin as output
 pinMode(relayPin3, OUTPUT);      // sets the digital pin as output
  // AC Red lamp
 pinMode(relayPin4, OUTPUT);      // sets the digital pin as output
 
 pinMode(relayPin5, OUTPUT);      // sets the digital pin as output
 pinMode(relayPin6, OUTPUT);      // sets the digital pin as output
 pinMode(relayPin7, OUTPUT);      // sets the digital pin as output
 // DC Buzzers
 pinMode(relayPin8, OUTPUT);      // sets the digital pin as output
 
 // AC lights
 digitalWrite(relayPin1, LOW);       // lamps on at start
 digitalWrite(relayPin2, LOW);       // lamps on at start 
 digitalWrite(relayPin3, LOW);       // lamps on at start
 // AC Red lamp
 digitalWrite(relayPin4, HIGH);        // Red off at startup
 
 digitalWrite(relayPin5, HIGH);        // Prevents relays from starting up engaged
 digitalWrite(relayPin6, HIGH);        // Prevents relays from starting up engaged
 digitalWrite(relayPin7, HIGH);        // Prevents relays from starting up engaged
 digitalWrite(relayPin8, HIGH);        // Prevents relays from starting up engaged
 
} 

void loop() {
  //Serial.print("analog = ");
  //Serial.println(digitalRead(Touch));
  //Serial.print("relay = ");
  //Serial.println(lightON1);
  Serial.print("sensitivity = ");
  Serial.println(analogRead(Challenge));

  int canFire = 0;
  
if(digitalRead(Touch) == 0 && kill == 0) {
  Serial.println("-------hit----------");
  int s = analogRead(Challenge);
  if (s <= 100){
    if (wait < 1){
      canFire = 1;
    }else{
      canFire = 0;
      wait++;
    }
  }
  if (s > 100 && s <= 300){
    if (wait == 4 ){
      canFire = 1;
    }else{
      canFire = 0;
      wait++;
    }
  }
  if (s > 300 && s <= 600){
    if (wait == 8){
      canFire = 1;
    }else{
      canFire = 0;
      wait++;
    }
  }
  if (s > 600 && s <= 900){
    if (wait == 12){
      canFire = 1;
    }else{
      canFire = 0;
      wait++;
    }
  }
  if (s > 900 ){
    if (wait > 16){
      canFire = 1;
    }else{
      canFire = 0;
      wait++;
    }
  }
  
  
  if (canFire == 1){
    wait = 0;
    isTouching = 1;
    // reset to delay sequence for continued contact
    if (timer > 80){
     timer = 0;
    }
  }
 }
  
 if (timer > 100 && digitalRead(Touch) == 1){
  kill = 0;
  wait = 0;
  isTouching = 0;
 }
 
 if(digitalRead(Disarm) == 0) {
    Serial.println("-------dismiss----------");
    if (isTouching == 1) {
      Serial.println("-------reset----------");
      digitalWrite(relayPin1, LOW);
      digitalWrite(relayPin2, LOW);
      digitalWrite(relayPin3, LOW);
      digitalWrite(relayPin4, HIGH);
      digitalWrite(relayPin8, HIGH);
    }
    isTouching = 0;
    wait = 0;
 }

 // -------lamp 1----------------
 if (isTouching == 1){
       if (timer <= 10 ) {
            if (lightON1 == 1){
              digitalWrite(relayPin1, HIGH);  
              Serial.println("Light 1 = ON 1");
              lightON1 = 0;
           }
      } else if (timer >= 20 && timer < 30) {
            if (lightON1 == 1){
              digitalWrite(relayPin1, HIGH);  
              Serial.println("Light 1 = ON 1");
              lightON1 = 0;
            }
      } else if (timer >= 50 && timer <70) {
              if (lightON1 == 1){
                  digitalWrite(relayPin1, HIGH);  
                  Serial.println("Light 1 = ON 1");
                  lightON1 = 0;
            }
      } else {
        if (lightON1 == 0){
              digitalWrite(relayPin1, LOW);  
              Serial.println("Light 1 = OFF");
              lightON1 = 1;
        }
      }
 }

 
 // -------lamp 2----------------

 
 if (isTouching == 1){
       if (timer <= 5 ) {
            if (lightON2 == 1){
              digitalWrite(relayPin2, HIGH);  
              Serial.println("Light 2 = ON 1");
              lightON2 = 0;
           }
      } else if (timer >= 15 && timer < 25) {
            if (lightON2 == 1){
              digitalWrite(relayPin2, HIGH);  
              Serial.println("Light 2 = ON 1");
              lightON2 = 0;
            }
      } else if (timer >= 30 && timer <65) {
              if (lightON2 == 1){
                  digitalWrite(relayPin2, HIGH);  
                  Serial.println("Light 2 = ON 1");
                  lightON2 = 0;
            }
      } else {
        if (lightON2 == 0){
              digitalWrite(relayPin2, LOW);  
              Serial.println("Light 2 = OFF");
              lightON2 = 1;
        }
      }
 }
 // -------lamp 3----------------
 if (isTouching == 1){
       if (timer <= 15 ) {
            if (lightON3 == 1){
              digitalWrite(relayPin3, HIGH);  
              Serial.println("Light 3 = ON 1");
              lightON3 = 0;
           }
      } else if (timer >= 35 && timer < 45) {
            if (lightON3 == 1){
              digitalWrite(relayPin3, HIGH);  
              Serial.println("Light 3 = ON 1");
              lightON3 = 0;
            }
      } else if (timer >= 60 && timer <75) {
              if (lightON3 == 1){
                  digitalWrite(relayPin3, HIGH);  
                  Serial.println("Light 3 = ON 1");
                  lightON3 = 0;
            }
      } else {
        if (lightON3 == 0){
              digitalWrite(relayPin3, LOW);  
              Serial.println("Light 3 = OFF");
              lightON3 = 1;
        }
      }
 }

 if (isTouching == 1){
       if (timer <= 80 ) {
            if (lightON4 == 0){
              digitalWrite(relayPin4, LOW);  
              Serial.println("Light 4 = ON 1");
              lightON4 = 1;
           }
      } else {
        if (lightON4 == 1){
              digitalWrite(relayPin4, HIGH);  
              Serial.println("Light 4 = OFF");
              lightON4 = 0;
        }
      }
 }

 if (isTouching == 1){
       if (timer <= 40 ) {
            if (buzzON == 0){
              digitalWrite(relayPin8, LOW);  
              Serial.println("buzzON = ON 1");
              buzzON = 1;
           }
      } else {
        if (buzzON == 1){
              digitalWrite(relayPin8, HIGH);  
              Serial.println("buzzON = OFF");
              buzzON = 0;
        }
      }
 }
 timer++;
 delay(40);
  // do any other things necessary as in normal loop, 'coz loop_touching does not introduce delays
}



