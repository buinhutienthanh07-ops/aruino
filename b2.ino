unsigned long quakhudo=0;
unsigned long quakhuvang=0;
int ddo=13;
int vang=12;
int tim=11;
int nut=A4;
int bien=A5;
int trangthaido=LOW;
int trangthaivang=LOW;
int k=0;

void setup() {
  Serial.begin(9600);
  Serial.print("bat dau nhap");
  pinMode (ddo,OUTPUT);
  pinMode (vang,OUTPUT);
  pinMode (tim,OUTPUT);
  pinMode (nut,INPUT);
  pinMode (bien,OUTPUT);
  digitalWrite(ddo,LOW);
  digitalWrite(vang,LOW);
  digitalWrite(tim,LOW);

}

void loop() {
  unsigned long hientai=millis();
  if (Serial.available()>0){
    int z=Serial.parseInt ();
    if (z>=800&&z<=1500){
      k=z;
    }
    else k=0;
  }
  if (k>0){
    if (hientai-quakhudo>=k){
      quakhudo=hientai;
      if (trangthaido==LOW) trangthaido=HIGH;
      else trangthaido=LOW;
      digitalWrite(ddo,trangthaido);
    }
  }
  else digitalWrite(ddo,LOW);
  if (digitalRead(nut)==LOW){
    if (hientai-quakhuvang>=800){
      quakhuvang=hientai;
      if (trangthaivang==LOW) trangthaivang=HIGH;
      else trangthaivang=LOW;
      digitalWrite(vang,trangthaivang);
    }
  }
  else digitalWrite(vang,LOW);
  int g=analogRead(bien);
  analogWrite (tim,g/4);
}
