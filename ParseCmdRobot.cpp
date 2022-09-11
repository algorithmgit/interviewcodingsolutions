/*
We have a simple robot that can only take a few actions.
The commands are sent one byte at a time over a serial link as command packets. These packets have the following format:
Header (4 bytes)
Header = "ZOOX", ASCII

Length (1 byte)
1 ASCII decimal digit character, so between '0' and '9' (inclusive).
Length = command length + repeat length (excludes header, length, checksum)

Command (Length-1 bytes)
ASCII, one of: "LEFT", "RIGHT", "FORWARD", "BEEP"

Repeat (1 byte)
1 ASCII decimal digit character, so between '0' and '9' (inclusive).
Number of times to repeat the command

Checksum (1 byte)
1 ASCII uppercase alphabetic character, so between 'A' and 'Z' (inclusive).
Simple computation to check content for bit errors
Calculated over the following section: [Length, Command, Repeat] (excludes header, checksum)

Assignment
Using the provided code, implement the parse(c) function to identify and execute each command packet.
The parse(c) function takes one byte at a time because that is how the data will arrive for the simple robot.
Feel free to add more functions and definitions, but do not change main().
execute_packet_command(...) has been provided to assist with the test output.
A few example inputs -> outputs for the complete system:
ZOOX6RIGHT3X -> Cmd: RRR
ZOOX5LEFT2QZOOX5BEEP3C -> Cmd: LL!!!
If there are multiple complete packets, they should all get called as parameters to execute_packet_command(...).

This simple robot lives in a harsh world. These packets are coming in over a bad link. There may be lots of bit errors, random erroneous bytes, and all kinds of data loss. We need this code to silently drop all the junk data, but output packets that pass the checksum. For example, this means we could have the following inputs -> outputs:
abcZOOX6RIGHT2Wabc -> Cmd: RR
abcZOOX6lmnopRIGHT3Xabc -> Cmd:
ZOOX6RIGHT3abc -> Cmd:
(notice the checksum byte is lost on that last one)
If your parser identifies bytes as belonging to a complete packet, those bytes will not be used for any later packets.

Code development workflow
Please use the provided in-browser RemoteInterview coding environment. It records your progress. This way the person reviewing your submission will be able to review your development and debugging process. Having a clean and clear process will earn you the appreciation of the person reviewing your code.

Grading
A variety of test inputs will be checked automatically and output formatting is very specific. For this reason, all answers must start with "Cmd: " and this is provided in main(). Your parse(c) function need only call execute_packet_command(...) when appropriate.

Timing
Basic command parsing should be achievable within the time limit. Covering all the possible edge cases is bonus.

Starter Code
In case you need to restore any of the starter code, here's a copy.
/************************************************

Do not modify this starter code. * *
Your code should be added at the bottom. * *
   * Thank you and good luck! *           *
************************************************/
/*
#include
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
// Review problem description for more info
unsigned char checksum(string input) {
unsigned char accumulated = 0;
for(char& c : input) {
accumulated += c;
}
return (accumulated % 26) + 'A';
}

// Required output format
const string MSG_HEADER = "ZOOX";

const string MSG_LEFT = "LEFT";
const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";
const string MSG_BEEP = "BEEP";

const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
for (int i = 0; i < repeat; i++) {
cout << cmd;
}
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {
if (cmd.compare(MSG_LEFT) == 0) {
execute_command(OUTPUT_LEFT, repeat);
}
if (cmd.compare(MSG_RIGHT) == 0) {
execute_command(OUTPUT_RIGHT, repeat);
}
if (cmd.compare(MSG_FORWARD) == 0) {
execute_command(OUTPUT_FORWARD, repeat);
}
if (cmd.compare(MSG_BEEP) == 0) {
execute_command(OUTPUT_BEEP, repeat);
}
}

// Required prototype and main
void parse(char c);
int main() {
string input;
cin >> input;
cout << "Cmd: ";
for(char& c : input) {
parse(c);
}
return 0;
}

/************************************************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------
/************************************************/

/************************************************

Do not modify this starter code. * *
Your code should be added at the bottom. * *
   * Thank you and good luck! *           *
************************************************/
/*
#include
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
// Review problem description for more info

unsigned char checksum(string input) {

unsigned char accumulated = 0;

for(char& c : input) {

accumulated += c;
}

return (accumulated % 26) + 'A';

}

// Required output format
const string MSG_HEADER = "ZOOX";
const string MSG_LEFT = "LEFT";

const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";

const string MSG_BEEP = "BEEP";
const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";
// You should not need to call this function
// Util used by execute_packet_command(...)

void execute_command(string cmd, int repeat) {
for (int i = 0; i < repeat; i++) {
cout << cmd;
}
}
// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.

// cmd should be the command string from the packet

// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {

if (cmd.compare(MSG_LEFT) == 0) {

execute_command(OUTPUT_LEFT, repeat);
}

if (cmd.compare(MSG_RIGHT) == 0) {
execute_command(OUTPUT_RIGHT, repeat);
}
if (cmd.compare(MSG_FORWARD) == 0) {
execute_command(OUTPUT_FORWARD, repeat);
}
if (cmd.compare(MSG_BEEP) == 0) {
execute_command(OUTPUT_BEEP, repeat);
}
}

// Required prototype and main

void parse(char c);

int main() {
string input;
cin >> input;
cout << "Cmd: ";
for(char& c : input) {

parse(c);
}
return 0;
}
*/
/************************************************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------

/************************************************/
/*
void parse(char c)
{

}*/

/************************************************
*    * Do not modify this starter code. *       *
* * Your code should be added at the bottom. *  *
*        * Thank you and good luck! *           *
************************************************/

#include <iostream>
using namespace std;


struct packet { 
  char header[4];
  char length;
  char cmd[7];
  char repeat;
  char checksum;
} received_packet;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
//           Review problem description for more info
unsigned char checksum(string input) {
  unsigned char accumulated = 0;
  for(char& c : input) {
    accumulated += c;
  }
  return (accumulated % 26) + 'A';
}

// Required output format
const string MSG_HEADER = "ZOOX";

const string MSG_LEFT = "LEFT";
const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";
const string MSG_BEEP = "BEEP";

const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
  for (int i = 0; i < repeat; i++) {
    cout << cmd;
  }
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {
  if (cmd.compare(MSG_LEFT) == 0) {
    execute_command(OUTPUT_LEFT, repeat);
  }
  if (cmd.compare(MSG_RIGHT) == 0) {
    execute_command(OUTPUT_RIGHT, repeat);
  }
  if (cmd.compare(MSG_FORWARD) == 0) {
    execute_command(OUTPUT_FORWARD, repeat);
  }
  if (cmd.compare(MSG_BEEP) == 0) {
    execute_command(OUTPUT_BEEP, repeat);
  }
}

// Required prototype and main
void parse(char c);
int main() {
  string input;
  cin >> input;
  cout << "Cmd: ";
  for(char& c : input) {
    parse(c);
  }
  return 0;
}

/************************************************/
// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------
/************************************************/
bool parse_header(char c, int *i){
  if (c >= 'A' && c <= 'Z'){
    received_packet.header[*i] = c;
    *i = *i + 1;
  }
  else{
    *i = 0;
  }

  if (*i == 4){
    if(MSG_HEADER.compare(received_packet.header) == 0) {
      return true;
    }
  }

  return false;
}

bool parse_length(char c, int *i) {
  
  if (c >= '0' && c <= '9'){
    received_packet.length = c;
    *i = *i + 1;
    return true;
  }
  else {
    *i = 0;  
  }

  return false;
}

bool parse_repeat(char c, int *i){
  
  if (c >= '0' && c <= '9'){
    received_packet.repeat = c;
    *i = *i + 1;
    //cout << "i = " << *i << " Building repeat = " << received_packet.repeat << endl;
    return true;
  }
  else {
    *i = 0;  
  }
  
  return false;
}

bool parse_cmd(char c, int *i){
  if (c >= 'A' && c <= 'Z'){
    received_packet.cmd[*i] = c;
    //cout << "i = " << i << " Building Cmd = " << received_packet.cmd << endl;
    *i = *i + 1;
  }
  else{
      *i = 0;
  }

  if (*i <= 7){
    //cout << "i = " << i << " CMD Found = " << received_packet.cmd << endl;
    if((MSG_LEFT.compare(0, 4, received_packet.cmd)    == 0)   || 
       (MSG_RIGHT.compare(0, 5, received_packet.cmd)   == 0)   ||
       (MSG_FORWARD.compare(0, 7, received_packet.cmd) == 0)   || 
       (MSG_BEEP.compare(0, 4, received_packet.cmd)    == 0)
      ){
      return true;
    }
  }

  return false;
}


bool parse_checksum(char c){
  
  received_packet.checksum = c;
  return true;
}

int header_length = 0;
int length_length = 0;
int cmd_length    = 0;
int repeat_length = 0;

void build_packet(char c)
{
  static int i = 0;
  static bool header_done   = false;
  static bool length_done   = false;
  static bool cmd_done      = false;
  static bool repeat_done   = false;
  static bool checksum_done = false;
  
  
  if (header_done == false){
    header_done = parse_header(c, &header_length);
  }
  
  if(header_done == true && header_length == 4){
        i++;
        //cout << " i = " << i << "parsed Header = " << received_packet.header << endl;
        header_length = 0;
        return;
  }
    
  if (header_done == true && length_done == false){
    length_done = parse_length(c, &length_length);
  }
  
  if(length_done == true && length_length == 1){
        i++;
        //cout << " i = " << i << "parsed length = " << received_packet.length << endl;
        length_length = 0;
        return;
  }  
  
  if (length_done == true && cmd_done == false){
    cmd_done = parse_cmd(c, &cmd_length);
    //cout << "cmd_length = " << cmd_length << " received_packet.length " << received_packet.length << endl;
  }
  
  //if(length_done == true && cmd_done == true) { 
  // cout << "cmd_length = " << cmd_length << endl;
  // cout << "received_packet.length - 1 = " << (received_packet.length - '0' - 1) << endl;
  //}
  
  if((cmd_done == true) && (cmd_length == (received_packet.length - '0' - 1) )){
        i++;
        //cout << " i = " << i << "parsed cmd = " << received_packet.cmd << endl;
        cmd_length = 0;
        return;
  }
      
  if (cmd_done == true && repeat_done == false){
    repeat_done = parse_repeat(c, &repeat_length);
    //cout << "repeat_length = " << repeat_length << " received_packet.repeat = " << received_packet.repeat << endl;
  }
  
  if(repeat_done == true && repeat_length == 1 ){
    i++;
    //cout << " i = " << i << "parsed repeat = " << received_packet.repeat << endl;
    repeat_length = 0;
    return;
  }
  
  if (repeat_done == true && checksum_done == false){
    checksum_done = parse_checksum(c);
    
    //string pkt(received_packet.header);
    string pkt;
    pkt.append(1, received_packet.length);
    pkt.append(received_packet.cmd);
    pkt.append(1, received_packet.repeat);
    //pkt.append(received_packet.checksum);
    
    char cs = checksum(pkt);
    
    //cout << " CS = " << cs << endl;
    //cout << " Received_packet.checksum = " << received_packet.checksum << endl;
    if (cs == received_packet.checksum){
      i++;
    }
  }
  
  if( i == 5 ){
    string cmd(received_packet.cmd);
    int repeat = received_packet.repeat - '0';
    
    execute_packet_command(cmd, repeat);
    i = 0;
    header_done   = false;
    length_done   = false;
    cmd_done      = false;
    repeat_done   = false;
    checksum_done = false;
    header_length = 0;
    length_length = 0;
    cmd_length    = 0;
    repeat_length = 0;
  }
  
  return ; 
}

void parse(char c){
  build_packet(c);
}

