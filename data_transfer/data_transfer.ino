char data[] = "5030,976,548,979,551,977,550,977,548,979,549,978,549,978,551,448,551,449,550,449,549,451,549,450,549,451,549,449,551,450,551,448,553,447,550,449,550,450,551,978,551,448,551,448,549,450,551,448,551,450,551,448,550,450,548,979,550,449,554,447,551,975,551,976,550,978,550,449,554,973,549,451,551,976,553,975,550,449,553,447";//it data with delay every cycle chance 0>1
unsigned int indexID = 0; //indexID
char *microDelaydata[2500]; //microDelaydata
char *temp_data = NULL; //temp_data
#define transmitPin D5
int transfer = LOW; //0101010100101

void setup() {
  //serial begin
  Serial.begin(115200);
  pinMode(transmitPin, OUTPUT);

  temp_data = strtok(data, ",");  // delimiter
  while (temp_data != NULL){
    microDelaydata[indexID] = temp_data;
    indexID++;
    temp_data = strtok(NULL, ",");
  }
  Serial.println("Data analyzed..");
   for (int n = 0; n < indexID; n++){
      Serial.print(n);
      Serial.print(" - ");
      Serial.println(microDelaydata[n]);
   }
}

void loop() {
       delay(1000);

  for (int n = 0; n < 10; n++){
    digitalWrite(transmitPin, HIGH);
    for (int n = 0; n < indexID; n++){
          digitalWrite(transmitPin, !digitalRead(transmitPin));
          int delayseconsishere= String(microDelaydata[n]).toInt();
          delayMicroseconds(delayseconsishere);
        }
  }
  delay(1000);
    for (int n = 0; n < 10; n++){
    digitalWrite(transmitPin, LOW);
    for (int n = 0; n < indexID; n++){
          digitalWrite(transmitPin, !digitalRead(transmitPin));
          int delayseconsishere= String(microDelaydata[n]).toInt();
          delayMicroseconds(delayseconsishere);
        }
  }
  delay(1000);

}
