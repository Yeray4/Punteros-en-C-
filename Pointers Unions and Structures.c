// Pointers to Nested Unions and Structures

typedef union {
   unsigned long reg;
   struct {
      unsigned char u8rotateForwardSpeed;
      unsigned char u8rotateReverseSpeed;
      unsigned char u8speedRateChange;
      unsigned char b1rotateStatusFlags:    2;
   } member;
}LED_ROTATE_Type;

typedef union {
   unsigned long reg;
   struct {
      unsigned short u16pwmLightIntensity;
      unsigned char u8breatheSpeed;
      unsigned char b1breatheFlags:         2;
   } member;
}LED_BREATHE_Type;

typedef union {
    unsigned long reg;
    struct{
        unsigned char u8pattern[4];
    }member;
}LED_PATTERN_Type;

typedef struct{
    volatile LED_ROTATE_Type    ledRotation;
    volatile LED_PATTERN_Type   ledPattern;
    volatile LED_BREATHE_Type   ledBreathe;
}STRUCT_LEDVariables;

//create the instance of all unions and structures by ...
STRUCT_LEDVariables STRUCT_allLEDVariables;

STRUCT_LEDVariables *pSTRUCT_LEDVariables = &STRUCT_allLEDVariables;

int main(int argc, char** argv) 
{
//The while( ) loop continually loads values into each union member to 
// demonstrate indirect access using the pointer.  Operation is easy to evaluate
// when breakpoints are placed before each instruction and the instruction results
// are viewed in the Watch window after each step.    
   while(1)
   {
       pSTRUCT_LEDVariables->ledRotation.reg = 0xABCDECFF;
       pSTRUCT_LEDVariables->ledRotation.member.u8rotateForwardSpeed = 0x11;
       pSTRUCT_LEDVariables->ledRotation.member.u8rotateReverseSpeed = 0x22;
       pSTRUCT_LEDVariables->ledRotation.member.u8speedRateChange = 0x55;
       pSTRUCT_LEDVariables->ledRotation.member.b1rotateStatusFlags = 1;
       
       pSTRUCT_LEDVariables->ledPattern.reg = 0x11111111;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[0] = 0xAA;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[1] = 0xBB;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[2] = 0xCC;
       pSTRUCT_LEDVariables->ledPattern.member.u8pattern[3] = 0xDD;
       
       pSTRUCT_LEDVariables->ledBreathe.reg = 0x12345678;
       pSTRUCT_LEDVariables->ledBreathe.member.u8breatheSpeed = 0x33;
       pSTRUCT_LEDVariables->ledBreathe.member.u16pwmLightIntensity = 0xFEDC;
       pSTRUCT_LEDVariables->ledBreathe.member.b1breatheFlags = 0b11;
       
       while(1);
   }
}
