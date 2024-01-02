// Swap MSB of each nibble in a byte. 

#include <iostream>

unsigned char swapMSBOfNibbles(unsigned char byte) {
    // Extract MSB of each nibble
    unsigned char msb1 = (byte & 0x80) >> 4;  // MSB of the first nibble
    unsigned char msb2 = (byte & 0x08) << 4;  // MSB of the second nibble

    // Clear MSBs in the original byte
    byte &= 0x77;

    // Set swapped MSBs
    byte |= msb1 | msb2;

    return byte;
}

int main() {
    unsigned char byte = 0xA3; // Example byte

    std::cout << "Original Byte: 0x" << std::hex << (int)byte << std::endl;

    unsigned char result = swapMSBOfNibbles(byte);

    std::cout << "Modified Byte: 0x" << std::hex << (int)result << std::endl;

    return 0;
}

/* Output :

Original Byte: 0xa3
Modified Byte: 0x2b

*/
