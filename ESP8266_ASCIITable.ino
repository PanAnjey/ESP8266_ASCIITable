/*
  ASCII table
 
 Prints out byte values in all possible formats:  
 * as raw binary values
 * as ASCII-encoded decimal, hex, octal, and binary values
 
 For more on ASCII, see http://www.asciitable.com and http://en.wikipedia.org/wiki/ASCII
 
 The circuit:  No external hardware needed.
 
 created 2006
 by Nicholas Zambetti 
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.

 <http://www.zambetti.com> 
 
 */
#define PORTOUT Serial1
#define RE_PIN D6
//#define DE_PIN A7
void setup() { 
 //Initialize serial and wait for port to open:
//  Serial1.begin(9600); 
    PORTOUT.begin(9600); 
	PORTOUT.swap();
	digitalWrite(RE_PIN, HIGH);
	//digitalWrite(DE_PIN, HIGH);
	delay(20);
//  while (!PORTOUT) {
 //   ; // wait for serial port to connect. Needed for Leonardo only
 // }
  
  // prints title with ending line break 
//  Serial1.println("ASCII Table ~ Character Map"); 
    PORTOUT.println("ASCII Table ~ Character Map"); 
} 

// first visible ASCIIcharacter '!' is number 33:
int thisByte = 33; 

void loop() { 
  PORTOUT.write(thisByte);    
    PORTOUT.print(", dec: "); 
    PORTOUT.print(thisByte);   
    PORTOUT.print(", hex: "); 
  PORTOUT.print(thisByte, HEX); 
    PORTOUT.print(", oct: "); 
  PORTOUT.print(thisByte, OCT);   
    PORTOUT.print(", bin: "); 
    PORTOUT.println(thisByte, BIN);   
  if(thisByte == 126)
  {     // you could also use if (thisByte == '~') {
	  thisByte = 33;
  } 
  thisByte++;  
} 
