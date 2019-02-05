boolean bdct = false ; //ball detect
boolean gs = false ;//game start
const int echo = 38 ;
const int trig = 39 ;
int score = 0 ;
/*---------------------------------------------------------------------------------------------------------------- display method -------------------------------------------------------------------------------------*/
void displa(int x , int i ) { //x = digit to code , i = position of the digit
  int pinA , pinB , pinC , pinD , pinE , pinF, pinG;
  pinA = 7 * i + 2;
  pinB = 7 * i + 3;
  pinC = 7 * i + 4;
  pinD = 7 * i + 5;
  pinE = 7 * i + 6;
  pinF = 7 * i + 7;
  pinG = 7 * i + 8;

  if ( x = 0) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1);               // wait for a second
  }
  if (x = 1) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1);               // wait for a second
  }
  if (x = 2) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    delay(1);               // wait for a second

  }
  if (x = 3) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
    delay(1);               // wait for a second

  }
  if (x = 4) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1);               // wait for a second
  }
  if (x = 5) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1);               // wait for a second
  }
  if (x = 6) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1000);               // wait for a second
  }
  if (x = 7) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(1000);               // wait for a second
  }
  if (x = 8) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1000);               // wait for a second

  }
  if (x = 9) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1000);               // wait for a second
  }
}

/*---------------------------------------------------------------------------------------------------------------- split it  -------------------------------------------------------------------------------------*/
int spliter(int x , int score ){ // x = time 
  int tab [4] ;
  int both = (30 - x)*100 + score ;
  for(int i = 3 ; i > -1 ; i--){
      tab[i] = both % 10 ;
      both = both / 10 ;
  }
}

/*---------------------------------------------------------------------------------------------------------------- game_main -------------------------------------------------------------------------------------*/

boolean sensor() {
  float duration = 0;
  float distance = 0 ;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) * 0.0343;
  if (distance >= 2 && distance < 16) {
    return true ;
  }
  else {
    return false ;
  }



}

/*---------------------------------------------------------------------------------------------------------------- setup ----------------------------------------------------------------------------------------*/

void setup() {
  // 4 7 segments are plugged from pin 2 to pin 36
  for (int i = 0 ; i < 34 ; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  unsigned long time ;


}

void loop() {
  unsigned long time = 0 ;
  int splited;
  if (sensor == true) {
    score++ ;
    gs = true ;
  }
  if (gs == true) {
    time = millis() / 1000;
    while (time < 30) {
      if (sensor == true) {
        score++;
      }
      splited = spliter(time , score);
      for(int i = 0 ; i < 4 ; i++){
        displa(splited[3-i],i);
      }
    }
    time = 0 ;
  }


}
