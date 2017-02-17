////////////////////////////////////////
// COSC 130, Lab 2 Template File
// Modify the functions below
//
////////////////////////////////////////

String decimal_to_bin(int input)
{
  String output;

  // Write the binary value of input into
  // the string output
  for(int i = 31;i>=0;i--){
    int bit = input & (1 << i);
    if(bit == 0){
      output+='0';
    } else {
      output+='1';
    }
  }
  
  return output;
}

String decimal_to_hex(int input)
{
  String output;

  // Write the hex value of input into
  // the string output
  for(int i = 7;i>=0;i--){
    int bit = (input >> (i*4)) & 15;
    char char_value;
    if(bit >= 10){
      char_value = (bit - 10) + 'a';
      output+= char_value;
    } else {
      char_value = bit + '0';
      output+= char_value;
    }
  }
  

  return output;
}

String decimal_to_oct(int input)
{
  String output;

  // Write the octal value of input into
  // the string output

  int bit = (input >> 30) & 3;
  char char_value = bit + '0';
  output += char_value;
    
  for(int i = 10;i>=0;i--){
    bit = (input >> (i*3)) & 7;
    char_value = bit + '0';
    output += char_value;
  }

  return output;
}

////////////////////////////////////////
//
// DO NOT MODIFY ANY FUNCTIONS BELOW
//
////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial && (Serial.available() > 0)) {
    String input = Serial.readString();
    int i_input = input.toInt();

    Serial.println("Dec: " + input);
    Serial.println("Bin: " + decimal_to_bin(i_input));
    Serial.println("Oct: " + decimal_to_oct(i_input));
    Serial.println("Hex: " + decimal_to_hex(i_input));
    Serial.print("\n");
    
  }
  else {
    delay(115);
  }
}

