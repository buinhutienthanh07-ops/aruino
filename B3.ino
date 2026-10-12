int nut =2;
unsigned long quakhu=0;
int chuky=20;
int trangthai=LOW;
int dem=0;
void setup() {
 pinMode (nut,INPUT);
}
void loop() {
  unsigned long hientai=millis();
  if ( hientai-quakhu>=1){
    quakhu=hientai;
    int read_nut=digitalWrite(nut);
    if (read_nut==HIGH){
      if (dem<chuky){
        ++dem;
      }
      if (dem==chuky){
        trangthai=HIGH;
        ++dem;
      }
    }
    else {
      dem=0;
      trangthai=LOW;
    }
  }
  
}
