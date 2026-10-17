const int button =2;
volatile int dem=0;
unsigned long quakhu=0;


void setup() {
  Serial.begin(9600);
  pinMode (button,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button),check,FALLING);
}
void check(){
  unsigned long hientai=millis ();
  if (hientai-quakhu>=200){
    dem++;
    quakhu=hientai;
  }
}
int k=0;
void loop() {
 if (dem>k){
  Serial.println(dem);
  k=dem;
 }

}
