int d1=7,d2=8,d3=9,d4=10,d5=11,d6=12,d7=13;
   
#define E_D LOW //Enable Digit
#define D_D HIGH //Disable Digit

#define E_S HIGH //ENABLE Segment
#define D_S LOW //Disable Segment

void setup() {
  // put your setup code here, to run once:
  DDRD=0xff; // all pins 0-7 OUTPUTs
  DDRB=0xff; // all pins 8-13 OUTPUTs even though we only use pins 8-12
  
  PORTD=B10000000; // make pins 0-6 LOWs, and pin 7 HIGH (Disabled)
  PORTB=B00111111; // make pins 8-13 HIGH (Disabled) 
}

int message = 0;
int counter = 0;
void loop() {
  // put your main code here, to run repeatedly:
  counter += 1;
  if(counter >= 200){
    counter = 0;
    if(message < 3){
      message +=1;
    } else {
      message = 0;
    }
  }
  if(message == 0){
    writeLetter('H', d1);
    writeLetter('A', d2);
    writeLetter('P', d3);
    writeLetter('P', d4);
    writeLetter('Y', d5);
    writeLetter('-', d6);
  } else if(message == 1){
    writeLetter('H', d1);
    writeLetter('A', d2);
    writeLetter('L', d3);
    writeLetter('L', d4);
    writeLetter('O', d5);
    writeLetter('S', d6);
  } else if(message == 3){
    writeLetter('-', d1);
    writeLetter('-', d2);
    writeLetter('E', d3);
    writeLetter('V', d4);
    writeLetter('E', d5);
    writeLetter('-', d6);
  }
}

void writeLetter(char letter, int digit){
  switch(letter){
    case 'H':
        PORTD=B11110110;
        break;
    case 'A':
        PORTD=B11110111;
        break;
    case 'P':
        PORTD=B11110011;
        break;
    case 'Y':
        PORTD=B11101110;
        break;
    case 'L':
        PORTD=B10111000;
        break;
    case 'O':
        PORTD=B10111111;
        break;
    case 'S':
        PORTD=B11101101;
        break;
    case 'E':
        PORTD=B11111001;
        break;
    case 'V':
        PORTD=B10111110;
        break;
    case '-':
        PORTD=B10000000;
        break;
  }
  digitalWrite(digit, E_D);
  delay(2);
  digitalWrite(digit, D_D);
}

