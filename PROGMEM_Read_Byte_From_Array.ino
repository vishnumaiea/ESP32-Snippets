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


const size_t lenAlpha  = 27;
const uint8_t alphabets[] PROGMEM = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                                     'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                                     'W', 'X', 'Y', 'Z', 0x00};
                                     
uint8_t* alphaBuffer = new uint8_t; //a single char pointer

void setup() {
     Serial.begin(115200); Serial.println();
     memcpy_P(alphaBuffer, alphabets, 1); //determine the address of the string
 }

int counter = 0;
uint8_t* alphaBufferBackup = alphaBuffer; //take a bakcup of the const pointer

void loop() {
  memcpy_P(alphaBuffer, alphabets + counter, 1); //read each byte by adding the counter value (alphabets++ won't work)
  Serial.println((char)*alphaBuffer); //print the read byte as char
  counter++;

  if(counter == 25) { //reset and start reading from the beginning again
    counter = 0;
    alphaBuffer = alphaBufferBackup; //restore the pointer
  }
  delay(1000);
}
