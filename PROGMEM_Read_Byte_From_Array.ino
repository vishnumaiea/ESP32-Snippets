//=================================================================//
//                                                                 //
//  A small program to demonstrate how to store arrays in PROGMEM  //
//  of ESP32 and retrieve them to SRAM. Each alphabet is read      //
//  using memcpy_P function to a char pointer and printed to       //
//  console. The const pointer of string residing in PROGMEM is    //
//  added with a counter to read the next value.                   //
//                                                                 //
//  Author : Vishnu M Aiea                                         //
//  GitHub : https://github.com/vishnumaiea                        //
//  Date created : IST 6:46 PM 30-10-2017, Monday                  //
//                                                                 //
//=================================================================//


const uint8_t alphabets[] PROGMEM = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                                     'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                     'W', 'X', 'Y', 'Z', 0x00};
                                     
uint8_t* alphaPointer = new uint8_t; //a single char pointer

void setup() {
  Serial.begin(115200);
  Serial.println();
  memcpy_P(alphaPointer, alphabets, 1); //determine the address of const string on PROGMEM
 }

int counter = 0;
uint8_t* alphaPointerBackup = alphaPointer; //take a backup of the const pointer

void loop() {
  memcpy_P(alphaPointer, alphabets + counter, 1); //read each byte by adding the counter value to const pointer
  Serial.println((char) *alphaPointer); //print the read byte as char
  counter++; //increment counter

  if(counter == 25) { //reset and start reading from the beginning again
    counter = 0;
    alphaPointer = alphaPointerBackup; //restore the pointer
  }
  delay(1000);
}
