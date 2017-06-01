
// Working of All alphabets..
int speed_cube=4;
int latchPin=13;
int count=0;
int level=0;
int clockPin=12;
int dataPin=11;
int mosfet[8]={10,9,8,7,6,5,4,3};
bool present[8][8]={{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1}};

bool a[8][8]={{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,0,0,0,0,0,1},{1,0,1,1,1,1,0,1},{1,1,0,1,1,0,1,1},{1,1,1,0,0,1,1,1},{1,1,1,1,1,1,1,1},{1,0,1,1,1,1,0,1}};
bool b[8][8]={{1,0,1,1,1,0,1,1},{1,0,1,1,1,0,1,1},{1,0,0,0,0,1,1,1},{1,0,1,1,1,0,1,1},{1,0,1,1,1,0,1,1},{1,0,0,0,0,1,1,1},{1,1,1,1,1,1,1,1},{1,0,0,0,0,1,1,1}};
bool c[8][8]={{1,1,0,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,1,0,0,0,0,1},{1,1,1,0,0,0,0,1}};
bool d[8][8]={{1,0,1,1,1,0,1,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,0,1,1},{1,0,0,0,0,1,1,1},{1,0,0,0,0,1,1,1}};
bool e[8][8]={{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,0,0,0,0,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,0,0,0,0,1,1},{1,1,1,1,1,1,1,1},{1,0,0,0,0,0,1,1}};
bool f[8][8]={{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,0,0,0,0,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,0,0,0,0,0,1},{1,0,1,1,1,1,1,1}};
bool g[8][8]={{1,0,1,1,1,1,0,1},{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,1,0,0,0,0,0,0},{1,1,0,0,0,0,1,1}};
bool h[8][8]={{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,0,0,0,0,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,1}};
bool i[8][8]={{1,1,1,1,0,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,0,1,1,1},{1,1,0,0,0,0,0,1},{1,1,0,0,0,0,0,1}};
bool j[8][8]={{1,0,1,1,1,0,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,0,1,1},{1,1,1,0,0,0,0,0},{1,1,0,0,0,1,1,1}};
bool k[8][8]={{1,1,0,1,1,0,1,1},{1,1,0,1,0,1,1,1},{1,1,0,0,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,0,0,1,1,1,1},{1,1,0,1,0,1,1,1},{1,1,0,1,1,0,1,1},{1,1,1,1,1,1,1,1}};
bool l[8][8]={{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,0,0,0,0,1,1}};
bool m_1[8][8]={{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,0,1,1,0,1},{0,1,0,1,0,1,0,1},{0,0,1,1,1,0,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1}};
bool n[8][8]={{0,1,1,1,1,1,0,0},{0,1,1,1,1,0,1,0},{0,1,1,1,0,1,1,0},{0,1,1,0,1,1,1,0},{0,1,0,1,1,1,1,0},{0,0,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0}};
bool o[8][8]={{1,0,1,1,1,1,0,1},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{1,0,1,1,1,1,0,1},{1,1,0,0,0,0,1,1},{1,1,0,0,0,0,1,1}};
bool p[8][8]={{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,0,0,0,0,1,1,1},{1,0,1,1,1,0,1,1},{1,0,1,1,1,0,1,1},{1,0,0,0,0,1,1,1},{1,0,1,1,1,1,1,1}};
bool q[8][8]={{1,1,1,1,1,1,0,1},{1,1,0,0,0,0,1,1},{1,0,1,1,0,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,0,1,1,1,1,0,1},{1,1,0,0,0,0,1,1},{1,1,1,1,1,1,1,0}};
bool r[8][8]={{1,0,1,1,0,1,1,1},{1,0,1,0,1,1,1,1},{1,0,0,1,1,1,1,1},{1,0,0,0,0,1,1,1},{1,0,1,1,1,0,1,1},{1,0,1,1,1,0,1,1},{1,0,0,0,0,1,1,1},{1,0,1,1,1,0,1,1}};
bool s[8][8]={{1,0,0,0,0,0,1,1},{1,1,1,1,1,1,0,1},{1,1,1,1,1,1,0,1},{1,1,0,0,0,0,1,1},{1,0,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,1,0,0,0,0,0,1},{1,1,1,1,1,1,1,1}};
bool t[8][8]={{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{0,0,0,0,0,0,0,1},{1,1,1,0,1,1,1,1}};
bool u[8][8]={{1,1,0,1,1,1,0,1},{1,0,1,1,1,1,1,0},{1,0,1,1,1,1,1,0},{1,0,1,1,1,1,1,0},{1,0,1,1,1,1,1,0},{1,0,1,1,1,1,1,0},{1,0,1,1,1,1,1,0},{1,1,1,0,0,0,1,1}};
bool v[8][8]={{1,1,0,1,0,1,1,1},{1,0,1,1,1,0,1,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{1,1,1,0,1,1,1,1}};
bool w[8][8]={{1,0,1,0,1,0,1,1},{0,1,1,0,1,1,0,1},{0,1,1,0,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{0,1,1,1,1,1,0,1},{1,1,0,1,0,1,1,1}};
bool x[8][8]={{0,1,1,1,1,1,0,1},{1,0,1,1,1,0,1,1},{1,1,0,1,0,1,1,1},{1,1,1,0,1,1,1,1},{1,1,0,1,0,1,1,1},{1,0,1,1,1,0,1,1},{0,1,1,1,1,1,0,1},{1,1,1,1,1,1,1,1}};
bool y[8][8]={{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,0,1,0,1,1,1},{1,0,1,1,1,0,1,1},{0,1,1,1,1,1,0,1},{1,1,1,0,1,1,1,1}};
bool z[8][8]={{1,0,1,1,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,1,0,1,1,1},{1,1,1,1,1,0,1,1},{1,1,1,1,1,1,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};


void controlmosfet(int current){
  for(int foo=0;foo<8;foo++){
    digitalWrite(mosfet[foo],LOW);
  }
  digitalWrite(mosfet[current],HIGH);
}


void displayleds(int m,int level,int letter){
  for(int temp=0;temp<8;temp++){
    if(letter=='a' || letter=='A'){
    present[level][temp]=a[m][temp];
    }
    if(letter=='b' || letter=='B'){
    present[level][temp]=b[m][temp];
    }
    if(letter=='c' || letter=='C'){
    present[level][temp]=c[m][temp];
    }
    if(letter=='d' || letter=='D'){
    present[level][temp]=d[m][temp];
    }
    if(letter=='e' || letter=='E'){
    present[level][temp]=e[m][temp];
    }
    if(letter=='f' || letter=='F'){
    present[level][temp]=f[m][temp];
    }
    if(letter=='g' || letter=='G'){
    present[level][temp]=g[m][temp];
    }
    if(letter=='h' || letter=='H'){
    present[level][temp]=h[m][temp];
    }
    if(letter=='i' || letter=='I'){
    present[level][temp]=i[m][temp];
    }
    if(letter=='j' || letter=='J'){
    present[level][temp]=j[m][temp];
    }
    if(letter=='k' || letter=='K'){
    present[level][temp]=k[m][temp];
    }
    if(letter=='l' || letter=='L'){
    present[level][temp]=l[m][temp];
    }
    if(letter=='m' || letter=='M'){
    present[level][temp]=m_1[m][temp];
    }
    if(letter=='n' || letter=='N'){
    present[level][temp]=n[m][temp];
    }
    if(letter=='o' || letter=='O'){
    present[level][temp]=o[m][temp];
    }
    if(letter=='p' || letter=='P'){
    present[level][temp]=p[m][temp];
    }
    if(letter=='q' || letter=='Q'){
    present[level][temp]=q[m][temp];
    }
    if(letter=='r' || letter=='R'){
    present[level][temp]=r[m][temp];
    }
    if(letter=='s' || letter=='S'){
    present[level][temp]=s[m][temp];
    }
    if(letter=='t' || letter=='T'){
    present[level][temp]=t[m][temp];
    }
    if(letter=='u' || letter=='U'){
    present[level][temp]=u[m][temp];
    }
    if(letter=='v' || letter=='V'){
    present[level][temp]=v[m][temp];
    }
    if(letter=='w' || letter=='W'){
    present[level][temp]=w[m][temp];
    }
    if(letter=='x' || letter=='X'){
    present[level][temp]=x[m][temp];
    }
    if(letter=='y' || letter=='Y'){
    present[level][temp]=y[m][temp];
    }
    if(letter=='z' || letter=='Z'){
    present[level][temp]=z[m][temp];
    }
  }
  //digitalWrite(latchPin,LOW);
  updateShiftRegister();
  //digitalWrite(latchPin,HIGH);
  
  for(int temp=0;temp<8;temp++){
    present[level][temp]=1;
  }
  
  
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
    if(Serial.available()>0){
      serialListener_temp=Serial.read();
      if((serialListener_temp>=65 && serialListener_temp<=90) || (serialListener_temp>=97 && serialListener_temp<=122) || serialListener_temp==32){
        serialListener=serialListener_temp;
      }
    }
  }
  int y=int(count/(8*speed_cube))%2;
  level=7*y + pow(-1,y)*((int(count/(speed_cube)))%8);
  for(int m=0;m<8;m++){
    digitalWrite(latchPin,LOW);
    controlmosfet(m);
    displayleds(m,level,serialListener);
    delay(1);
    digitalWrite(latchPin,HIGH);
  }
    
  count=count+1;
  // put your main code here, to run repeatedly:

}
