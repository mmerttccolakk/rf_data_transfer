char data[] = "740,660,1440,661,740,660,739,1361,740,660,1437,663,739,660,739,1361,741,658,741,661,738,662,740,659,1439,1362,1439,1361,739,661,1438,1363,738,660,738,661,739,1362,738,662,739,662,738,660,1440,661,739,660,";//it data with delay every cycle chance 0>1
unsigned int indexID = 0; //indexID
char *microDelaydata[500]; //microDelaydata
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
     
  for (int n = 0; n < 10; n++){
    for (int n = 0; n < indexID; n++){
          digitalWrite(transmitPin, !digitalRead(transmitPin));
          int delayseconsishere= String(microDelaydata[n]).toInt();
          delayMicroseconds(delayseconsishere);
        }
  }

}
