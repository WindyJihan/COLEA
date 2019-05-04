 int totalSensor = 5;
 char sensorNumber;

int sensor[][5]={
  //S0,S1,S2,S3,Outpin
  {22,23,24,25,26},//Sensor 1
  {27,28,29,30,31},//Sensor 2
  {32,33,34,35,36},//Sensor 3
  {37,38,39,40,41},//Sensor 4
};

// Stores frequency read by the photodiodes
float redFrequency = 0;float greenFrequency = 0;float blueFrequency = 0;float clearFrequency=0;
int persentaseMerah=0;int persentaseHijau=0;int persentaseBiru=0;

void setup(){

  for (int j=0;j<totalSensor;j++){
    pinMode(sensor[j][0],OUTPUT);
    pinMode(sensor[j][1],OUTPUT);
    pinMode(sensor[j][2],OUTPUT);
    pinMode(sensor[j][3],OUTPUT);
    pinMode(sensor[j][4],INPUT);
    digitalWrite(sensor[j][0],HIGH);
    digitalWrite(sensor[j][1],LOW);
  }
    Serial.begin(9600);
    delay(100);
}
void loop() {
  if (Serial.available()>0){
    sensorNumber=Serial.read();
    Serial.println(sensorNumber);

    if (sensorNumber=='1'){
        int i=0;
        redFilter(i);
        greenFilter(i);
        blueFilter(i);
        clearFilter(i);
        calculateColorPresentation();
        warna(persentaseMerah,persentaseHijau,persentaseBiru);
    }
     else if (sensorNumber=='2'){
        int n=1;
        redFilter(n);
        greenFilter(n);
        blueFilter(n);
        clearFilter(n);
        calculateColorPresentation();
        warna(persentaseMerah,persentaseHijau,persentaseBiru);
     }
     else if (sensorNumber=='3'){
        int p=2;
        redFilter(p);
        greenFilter(p);
        blueFilter(p);
        clearFilter(p);
        calculateColorPresentation();
        warna(persentaseMerah,persentaseHijau,persentaseBiru);
     }
     else if (sensorNumber=='4'){
        int k=3;
        redFilter(k);
        greenFilter(k);
        blueFilter(k);
        clearFilter(k);
        calculateColorPresentation();
        warna(persentaseMerah,persentaseHijau,persentaseBiru);
     }
  }
}

//FUNCTION

void redFilter(int i){
    // Setting RED (R) filtered photodiodes to be read
  digitalWrite(sensor[i][2],LOW);
  digitalWrite(sensor[i][3],LOW);
  // Reading the output frequency
  redFrequency = float(pulseIn(sensor[i][4], LOW));
  delay(100);
}

void greenFilter(int i){
    // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(sensor[i][2],HIGH);
  digitalWrite(sensor[i][3],HIGH);
  // Reading the output frequency
  greenFrequency = float(pulseIn(sensor[i][4], LOW));
  delay(100);
}

void blueFilter(int i){
    // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(sensor[i][2],LOW);
  digitalWrite(sensor[i][3],HIGH);
  // Reading the output frequency
  blueFrequency = float(pulseIn(sensor[i][4], LOW));
  delay(100);
}

void clearFilter(int i){
  digitalWrite(sensor[i][2],HIGH);
  digitalWrite(sensor[i][3],LOW);
  clearFrequency = float(pulseIn(sensor[i][4],LOW));
  delay(100);
}

void calculateColorPresentation(){
  persentaseMerah=int((clearFrequency/redFrequency)*100);
  persentaseHijau=int((clearFrequency/greenFrequency)*100);
  persentaseBiru=int((clearFrequency/blueFrequency)*100);
}
