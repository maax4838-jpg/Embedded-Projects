/******************************************************************************

Max  
Embedded Basics :)

Creating a register
Bitwise operations
Pointers 
BitMasking
Structs  needs work rn :(

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>

void printBYTE(uint8_t byte)  //  prints a byte in binary form
{
    for(int i = 7; i >= 0; i--)  //  uses a for loop to isolate each bit MSB -> LSB
    {    
        printf("%d", (byte >> i) & 1);  // uses the & operation to see if bit is 1 or 0 
    }
    printf("\n");
}

uint8_t setBit(uint8_t byte, int bitNum)  //  sets a desired bit
{
    byte |= (1 << bitNum);  //  | operator is used as a set
    return byte;
}

uint8_t resetBit(uint8_t byte, int bitNum)  //  resets desired bit
{
    byte &= ~(1 << bitNum);  //  ~ operator creates a mask that inverts all the bits 
    return byte;  //  using with & operator resets desired bit
}

uint8_t toggleBit(uint8_t byte, int bitNum)  //  toggles desired bit
{
    byte ^= (1 << bitNum);  //  ^ operator will XOR the bit 
    return byte;
}


void writePort(uint8_t *portAddress, uint8_t newValue)  //  updates register to desired mask
{
    *portAddress = newValue;
}

struct myByte
{
    uint8_t byte; 
};// will use later 
int main()
{
    uint8_t REG1 = 0b11111111;  //  not a real register just a reference for future projects 
    // 8 bit register created 
    uint8_t *PORTA = &REG1;  //  pointing to address of REG1
    printBYTE(*PORTA);  //  00000000
    //Set bit
    *PORTA = setBit(*PORTA,7);
    printBYTE(*PORTA);  //  10000000
    //Reset bit
    *PORTA = resetBit(*PORTA,7);
    printBYTE(*PORTA);  //  00000000
    // Toggle bit
    *PORTA = toggleBit(*PORTA,7);
    printBYTE(*PORTA);  //  10000000
    
    printf("%p = %p\n%d\n", PORTA, &REG1, *PORTA);  //  PORTA holds the address *PORTA is the value of the data thats getting pointed to
    //********************************************************************************************************************************************
    //these are for PIC18F47 :(
   // ANSELC = 0b11111111; //  1 sets to analog 0 sets digital
    //TRISC = 0b11111110;  //  1 sets input 0 sets output 
    return 0;
}



/* 
Other Notes: 
number systems 
decimal 128 binary 0b10000000 Hex 0x80
Bit Masks:
A number paired with a bitwise operator used to get a desired outcome for example resetBit function
*/