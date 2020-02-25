

void setup() 
{
  Serial.begin(9600); // start the serial port
}
void loop() 
{
 delay(1000); // slow down serial port 

//---------------------------------------------------------------------------------------------DISTANS
  #define sensor A0 // Sharp IR GP2Y0A41SK0F (4-30cm, analog)
  float volts = analogRead(sensor)*0.0048828125;  // value from sensor * (5/1024)
  float distance = 13*pow(volts, -1); // worked out from datasheet graph
  Serial.print("Avstånd;"); 
  Serial.print(distance);   
  
//----------------------------------------------------------------------------------------------- TID

unsigned long timer = 0;
static int sec1 = 0;
static int sec10 = 0;
static int min1 = 0;
static int min10 = 0;
static int hrs1 = 0;
static int hrs10 = 0;

timer = millis();
if (timer >= 1000) {
  sec1 = sec1 + 1;
  timer = 0;
}
if (sec1 == 10) {
  sec10 = sec10 + 1 ;
  sec1 = 0;
}
if (sec10 == 6) {
  min1 = min1 + 1;
  sec10 = 0;
}
if (min1 == 10) {
  min10 = min10 + 1;
  min1 = 0;
}
if (min10 == 6) {
  hrs1 = hrs1 + 1;
  min10 = 0;
}
if (hrs1 == 10) {
  hrs10 = hrs10 + 1;
  hrs1 = 0;
}
Serial.print(";Tid;");  
Serial.print(hrs10); Serial.print(hrs1); Serial.print(":");
Serial.print(min10); Serial.print(min1); Serial.print(":");
Serial.print(sec10); Serial.print(sec1);

//--------------------------------------------------------------------------------------------- TEMP

 #define sensorA1 A1 // 

 float reading = analogRead(sensorA1);       //getting the voltage reading from the temperature sensor
 float voltage = reading * 5.0;              // converting that reading to voltage, for 3.3v arduino use 3.3
 voltage /= 1024.0; 
  
 float temperatureC = (voltage - 0.5) * 100; 
 Serial.print(";Temperatur;");                                      
 Serial.print(temperatureC);
 Serial.println("");
  
 delay(1000); // slow down serial port 

}


  
