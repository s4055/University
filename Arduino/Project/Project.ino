#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

int a[26][4] = { { 0, 1, 2, 2 }, { 1, 0, 0, 0 }, { 1, 0, 1, 0 }, { 1, 0, 0, 2 }, { 0, 2, 2, 2 }, { 0, 0, 1, 0 }, { 1, 1, 0, 2 },//A~G
      { 0, 0, 0, 0 }, { 0, 0, 2, 2 }, { 0, 1, 1, 1 }, { 1, 0, 1, 2 }, { 0, 1, 0, 0 }, { 1, 1, 2, 2 }, { 1, 0, 2, 2 }, { 1, 1, 1, 2 },//H~O
      { 0, 1, 1, 0 }, { 1, 1, 0, 1 }, { 0, 1, 0, 2 }, { 0, 0, 0, 2 }, { 1, 2, 2, 2 }, { 0, 0, 1, 2 }, { 0, 0, 0, 1 }, { 0, 1, 1, 2 },//P~W
      { 1, 0, 0, 1 }, { 1, 0, 1, 1 }, { 1, 1, 0, 0 } };//X~Z
int number[10][5] = { { 1, 1, 1, 1, 1 }, { 0, 1, 1, 1, 1 }, { 0, 0, 1, 1, 1 }, { 0, 0, 0, 1, 1 }, { 0, 0, 0, 0, 1 },//0~4
      { 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0 }, { 1, 1, 0, 0, 0 }, { 1, 1, 1, 0, 0 }, { 1, 1, 1, 1, 0 } };//5~9

int l=0;//lcd판에 값을 표시할 위치를 위한 변수

void setup() {
  pinMode(2,INPUT);//짧 *,0
  pinMode(4,INPUT);//긴 -,1
  pinMode(7,OUTPUT);//스피커
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  int mos[16];//버튼으로 입력한 값을 저장하는 배열
  int i=0;
  
  while(1){
    if(Serial.available()){
      char ch = Serial.read();
      if(ch=='q'){
        Size(mos, i);//입력한 배열크기를 조사하기 위해
        i=0;
        Serial.println();
        break;
      }
      else if(ch=='r'){
        Serial.println();
        Serial.println();
        i=0;
        l=0;
        lcd.clear();
      }
    }
    delay(150);
    if(digitalRead(2)==0){
      tone(7,4186,100);
      Serial.print('*');
      mos[i]=0;
      i++;
    }
    delay(150);
    if(digitalRead(4)==0){
      tone(7,4186,300);
      Serial.print('-');
      mos[i]=1;
      i++;
    }
  }
}

void Size(int m[], int turn){
  if(turn==5){//숫자는 한 행당 배열 크기가 5이므로 
    compare_num(m, turn, l);
    l++;
  }
  //알파벳은 한 행당 배열 크기가 5보다 작으므로 임의로 배열크기를 맞추기 위해 기준을 4로 해서 나머지 빈칸을 2로 채움
  else if(turn<5){
    for(int i=turn;i<4;i++){
      m[i]=2;
    }
    compare_a(m,turn,l);
    l++;
  }
}

void compare_a(int m[], int turn, int l){//알파벳
  int i,j,count;

  lcd.setCursor(l,0);
  
  //비교
  for(i=0;i<26;i++){
    count=0;
    for(j=0;j<4;j++){
      if(m[j]==a[i][j]){//if에 조건이 성립할 때마다 count를 세기
        count++;
      }
    }
    if(count==4 && i==0){
      lcd.print('A');
    }
    else if(count==4 && i==1){
      lcd.print('B');
    }
    else if(count==4 && i==2){
      lcd.print('C');
    }
    else if(count==4 && i==3){
      lcd.print('D');
    }
    else if(count==4 && i==4){
      lcd.print('E');
    }
    else if(count==4 && i==5){
      lcd.print('F');
    }
    else if(count==4 && i==6){
      lcd.print('G');
    }
    else if(count==4 && i==7){
      lcd.print('H');
    }
    else if(count==4 && i==8){
      lcd.print('I');
    }
    else if(count==4 && i==9){
      lcd.print('J');
    }
    else if(count==4 && i==10){
      lcd.print('K');
    }
    else if(count==4 && i==11){
      lcd.print('L');
    }
    else if(count==4 && i==12){
      lcd.print('M');
    }
    else if(count==4 && i==13){
      lcd.print('N');
    }
    else if(count==4 && i==14){
      lcd.print('O');
    }
    else if(count==4 && i==15){
      lcd.print('P');
    }
    else if(count==4 && i==16){
      lcd.print('Q');
    }
    else if(count==4 && i==17){
      lcd.print('R');
    }
    else if(count==4 && i==18){
      lcd.print('S');
    }
    else if(count==4 && i==19){
      lcd.print('T');
    }
    else if(count==4 && i==20){
      lcd.print('U');
    }
    else if(count==4 && i==21){
      lcd.print('V');
    }
    else if(count==4 && i==22){
      lcd.print('W');
    }
    else if(count==4 && i==23){
      lcd.print('X');
    }
    else if(count==4 && i==24){
      lcd.print('Y');
    }
    else if(count==4 && i==25){
      lcd.print('Z');
    }
  }
}

void compare_num(int m[],int turn, int l){//숫자
  int i,j,count;

  lcd.setCursor(l,0);

  for(i=0;i<10;i++){
    count=0;
    for(j=0;j<5;j++){
      if(m[j]==number[i][j]){
        count++;
      }
    }
    if(count==5){
      lcd.print(i);
    }
  }
}

