int speed_cube=4;
int latchPin=13;
int count=0;
int level=0;
int clockPin=12;
int dataPin=11;
int mosfet[8]={10,9,8,7,6,5,4,3};
int start=1;
bool face[8][8][8];

bool present[8][8]={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};


void initialise(int x){
for(int i=0;i<8;i++){
  for(int j=0;j<8;j++){
    for(int k=0;k<8;k++){
      if((((j==x || j==7-x) && (i==x || i==7-x)) || ((i==x || i==7-x) && (k==(6-x) || k==(x+7)%8)) || ((j==x || j==7-x) && (k==(6-x) || k==(x+7)%8))) && (i>=x && j>=x && i<=(7-x) && j<=(7-x))){
        if(x==0 || (x==1 && k>=0 && k<=5) || (x==2 && k>=1 && k<=4) || (x==3 && k>=2 && k<=3)){
        face[i][j][k]=0;
        }
        else face[i][j][k]=1;
      }
      else face[i][j][k]=1;
    }
  }
}
}


void displayleds(int m){
  for(int temp=0;temp<8;temp++){
    for(int temp2=0;temp2<8;temp2++){
      present[temp][temp2]=face[temp][temp2][m];
    }
  }
  //digitalWrite(latchPin,LOW);
  updateShiftRegister();
  //digitalWrite(latchPin,HIGH);
  
  for(int temp=0;temp<8;temp++){
    for(int temp2=0;temp2<8;temp2++){
      present[temp][temp2]=1;
    } 
  }
  
  
}



void controlmosfet(int current){
  for(int foo=0;foo<8;foo++){
    digitalWrite(mosfet[foo],LOW);
  }
  digitalWrite(mosfet[current],HIGH);
}





void updateShiftRegister(){
  for(int i=0;i<8;i++){
    for (int j=0;j<8;j++){
      digitalWrite(clockPin,LOW);
      digitalWrite(dataPin,present[i][j]);
      digitalWrite(clockPin,HIGH);
    }
  }
}





void setup() {
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  for(int i=0;i<8;i++){
    pinMode(mosfet[i],OUTPUT);
  }
  // put your setup code here, to run once:

}







char serialListener;
char serialListener_temp;

void loop() {
  //char serialListener=32;
  //char serialListener_temp;
  if(count%(8*speed_cube) == 0){
    int a=(count/(8*speed_cube))%4;
    initialise(a);
  }
  
  //level=7-((int(count/(speed_cube)))%8);
  for(int m=0;m<8;m++){
    digitalWrite(latchPin,LOW);
    controlmosfet(m);
    displayleds(m);
    delay(1);
    digitalWrite(latchPin,HIGH);
  }
  
  
  count=count+1;
  // put your main code here, to run repeatedly:

}






/*void loop() {
 /* if(Serial.available()>0){
  char serialListener=Serial.read();
  if(serialListener=='0'){
    initialise(0);
  }
  if(serialListener=='1'){
    initialise(1);
  }
  if(serialListener=='2'){
    initialise(2);
  }
  if(serialListener=='3'){
    initialise(3);
  }
  if(start=1){
    initialise(3);
  }
  start=0;
  }
  
  if(start==1){
    initialise(1);
  }
  start=0;
  count=count+1;
  level=(int(count/10))%8;
  //level=0;
  for(int m=0;m<8;m++){
    digitalWrite(latchPin,LOW);
    controlmosfet(m);
    displayleds(m,level);
    
    delay(1);
    digitalWrite(latchPin,HIGH);
  }
  
  
  
  // put your main code here, to run repeatedly:

}*/
