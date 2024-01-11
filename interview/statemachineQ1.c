// Identifier (ID) in networks
// A unique ID is given for each endpoint in the network, and can be of 2 different lengths

//                  +   Reader +--------+
//                  |          |        |
//                  |          |  93    |
//                  |          |        |
//   Unique ID      |          +--------+
//                  |
//   Type1          |   Card
//                  |                    +---------------------------+
//   4 bytes        |                    |      |      |      |      |
//                  |                    | UID0 | UID1 | UID2 | UID3 |
//                  |                    |      |      |      |      |
//                  |                    +---------------------------+
//                  |
//                  +
//


//
//                  +   Reader +--------+                                  +-------+
//                  |          |        |                                  |       |
//                  |          |  93    |                                  |  95   |
//                  |          |        |                                  |       |
//   Unique ID      |          +--------+                                  +-------+
//                  |
//   Type 2         |   card
//                  |                    +---------------------------+               +---------------------------+
//   7 bytes        |                    |      |      |      |      |               |      |      |      |      |
//                  |                    |  CT  | UID0 | UID1 | UID2 |               | UID3 | UID4 | UID5 | UID6 |
//                  |                    |      |      |      |      |               |      |      |      |      |
//                  |                    +---------------------------+               +---------------------------+
//

//      CT - Cascade tag 88
//


//Implement two tasks/functions namely - Reader() and Card(),
//Card task holds the Unique ID UIDO|UID1|UID2|UID3|... in a variable
//Reader task sends the commands according to above protocol to get complete unique ID from the above

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


volatile bool uniqueIDReceived = false;

static uint8_t readerToCardBuffer;
static uint8_t CardToReaderBuffer[4U];

#define CT 88

enum cardType {
   TYPE1,
   TYPE2,
};

enum cmdPart { 
    PART1, 
    PART2,
};


enum cardType cardTypeVar = TYPE2;
enum cmdPart cmdPartVar = PART1;

enum readerState {
   CMD_93,
   CMD_95,
   EXIT,
   INVALID,
};

void printCard(){
    for (int i = 0; i < 4; i++){
      printf("Card[%d] = %d \n", i, CardToReaderBuffer[i]); 
    }
    return;
}

static void reader(void)
{
    static enum readerState rs = CMD_93;
    
    switch(rs){
        case CMD_93:
            readerToCardBuffer = CMD_93;
            if(cardTypeVar == TYPE1)
                rs = EXIT;
            else
                rs = CMD_95;
        break;
        case CMD_95:
            readerToCardBuffer = CMD_95;
               printCard();
            rs = EXIT;
        break;
        case EXIT:
            printCard();
            readerToCardBuffer = EXIT;
            uniqueIDReceived = true;
        break;
        case INVALID:
        break;
    }
    
    return;
}


static void card(void)
{
    if(readerToCardBuffer == CMD_93){
        if(cardTypeVar == TYPE1){
            CardToReaderBuffer[0] = 0;
            CardToReaderBuffer[1] = 1;
            CardToReaderBuffer[2] = 2;
            CardToReaderBuffer[3] = 3;
        } else if (cardTypeVar == TYPE2 && cmdPartVar == PART1 ){
                    CardToReaderBuffer[0] = CT;
                    CardToReaderBuffer[1] = 1;
                    CardToReaderBuffer[2] = 2;
                    CardToReaderBuffer[3] = 3;
                    cmdPartVar = PART2;
                }
    } else if(readerToCardBuffer == CMD_95){
            if(cardTypeVar == TYPE2 && cmdPartVar == PART2){
                    CardToReaderBuffer[0] = 4;
                    CardToReaderBuffer[1] = 5;
                    CardToReaderBuffer[2] = 6;
                    CardToReaderBuffer[3] = 7;
                }
        } else if (readerToCardBuffer == EXIT){
            uniqueIDReceived = true; // do nothing
        }
    
    return;
}


int main()
{
    while(uniqueIDReceived == false)
    {
        reader();
        card();
    }
}
