const int nut=12;
const int led=13;
int check =0;
void setup(){
  serial.begin(9600);
  pinMode(nut,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}
void loop(){
  check=digitalRead(nut);
  if (check=0){
    serial.println("dang bat led");
    digitalWrite(led,HIGH);
    delay(1000);
  }
  else {
    serial.println("dsng tat led");
    digitalWrite(led,LOW);
    delay(1000);
  }
}