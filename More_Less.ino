/* COPYRIGHT MICHEL CHATMAJIAN 2016*/
/* COPYRIGHT MICHEL CHATMAJIAN 2016*/
/* COPYRIGHT MICHEL CHATMAJIAN 2016*/
/* COPYRIGHT MICHEL CHATMAJIAN 2016*/
/* COPYRIGHT MICHEL CHATMAJIAN 2016*/
/* COPYRIGHT MICHEL CHATMAJIAN 2016*/
const int led = 12;
const int more = 13;
const int less = 11;
boolean new_ = true;
int AI_number = 0;
boolean good = true;
int lights[] = {more,led,less};

void setup() {
  // put your setup code here, to run once:
pinMode(led,OUTPUT);
pinMode(more,OUTPUT);
pinMode(less,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:  
Serial.println("Guess what number I'm thinking of ! (Integer from 1 to 15)");
if(new_){
AI_number = random(1,15);
}
while(Serial.available() == 0){
}
int answer = Serial.readString().toInt();
if(answer > AI_number){
less_();
new_ = false;
}
else if(answer < AI_number){
  more_();
  new_=false;
}
else if (answer == AI_number){
  Serial.println("Correct!");
  new_ = true;
  flicker();
}

}

void checker(int n){
  if(n > 15 || n < 1){
    Serial.println("Your guess was not between 1 and 15 please try again!");
    good = false;
  }
}

int rand(){
return random(1,15);    
}

void more_(){
   Serial.println("MORE!");  
   digitalWrite(lights[0],HIGH);
   delay(1000);
   digitalWrite(more,LOW);
}

void less_(){
   Serial.println("LESS!");  
   digitalWrite(less,HIGH);
   delay(1000);
   digitalWrite(less,LOW);
}

void flicker(){
  for(int j = 0;j < 3;j ++){
for(int i = 0; i <= 2; i++){
  digitalWrite(lights[i],HIGH);
  delay(400);
}
for(int i = 0; i <= 2; i++){
  digitalWrite(lights[i],LOW);
  delay(400);
}
  }


  
}

