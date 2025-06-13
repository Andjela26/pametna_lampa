const int LED_PIN = GREEN_LED;   //pin crvene LED
const int PIR_PIN = 28;        //pin PIR modula
const int LIGHT_PIN = 24; // pin senzora osvetljenja
const int RELAY_PIN = 26;   //pin releja

int ON_VALUE = 0;   //granicna vrednost za ukljucivanje releja
int OFF_VALUE = 0;  //granicna vrednost za iskljucivanje releja

const int N = 10; // duzina niza ocitanih vrednosti senzora osvetljenja
int citanje[N];  // niz poslednjih N ocitanih vrednosti 
int k = 0;        // indeks tekuceg ocitavanja
int suma = 0;    // suma svih ocitavanja
int sr_vr = 0;      // srednja vrednost vrednosti u nizu readings
int svetlost = 0;  // tekuca vrednost intenziteta svetla
int x=0;
int y=290;
int z=0;
int a=0;

int relayState = LOW;    //tekuce stanje releja
int analogValue = 0;     //tekuca vrednost analognog ulaza

void setup()
{
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);    
  pinMode(RELAY_PIN,OUTPUT);              
  // inicijalizacija niza readings: 
  for (int i = 0; i < N; i++)
    citanje[i] = 0;   
  
  Serial.begin(9600);  
}


void loop() {
  
  svetlost = analogRead(LIGHT_PIN); 
  suma= suma - citanje[k];         
  citanje[k] = svetlost; 
  suma= suma + svetlost;       
  k = k + 1;                    
  if (k >= N)              
    k = 0;                           
  sr_vr = suma / N; 
  if(a==1)
    y = sr_vr+2;
  if(a==0)
    y=289;  
    
  if(sr_vr > y){
    z=1; 
    digitalWrite(LED_PIN,LOW); 
    relayState = LOW;
  }
  else if(sr_vr < y){
    if(digitalRead(PIR_PIN)==HIGH){
      digitalWrite(LED_PIN,HIGH);
      relayState = HIGH;
      a=1;
    }
    
    else if(digitalRead(PIR_PIN)==LOW){
      digitalWrite(LED_PIN,LOW);
      relayState = LOW;
      a=0;
      
    }
    
  }

  Serial.print("Srednja vrednost: ");
  Serial.println(sr_vr);
  digitalWrite(RELAY_PIN, relayState); //pobuda releja
  Serial.print("PIR_PIN: ");
  Serial.println(digitalRead(PIR_PIN));

  Serial.println(y);
}
