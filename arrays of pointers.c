//Generic loop variables are declared
unsigned char i = 0, j = 0, y;

//Create an array of pointers and initialize 4 different strings.  These strings are programmed
// into flash during programming. The pointer is also placed in program memory. 
char *const p[4] = {"a01", "b02", "c03", "d04"};

//Create an array of pointers that reside in data memory
const char *q[4] = {"e01", "f02", "g03", "h04"};

//Let the linker place the variables and strings in flash (same as using const pointer)
//const char *r[4] __attribute__((space(prog))) = {"i01", "j02", "k03", "l04"};

int main(int argc, char** argv) {

    //Step through the following code and watch the 'y' variable.  This code will step through each of the strings.
    // When a NULL character is found, the next string is pointed to.  The 'y' variable will contain the character
    // being pointed to. 

    //The first pass through the loop, the pointer points to the "a01" string.  When a NULL character is found, the 
    // pointer is incremented and points to the "b02" string.  It will follow the same format for the third and fourth 
    // strings.  When the loop counter is equal to 4, the next loop using the q[ ] array of pointers is accessed.  Finally, 
    // the r[ ] array of pointers is accessed after the q[ ] pointer loop has executed four times.    
    while (1) {
        //Step through p[ ] pointer       
        for (i = 0; i < 4; i++, j = 0) {
            do {
                y = *(p[i] + j);
                j++;
            } while (y != '\0');
        }

        //Step through q[ ] pointer      
        for (i = 0; i < 4; i++, j = 0) {
            do {
                y = *(q[i] + j);
                j++;
            } while (y != '\0');
        }

        //Step through r[ ]pointer      
        //      for(i = 0; i < 4; i++, j=0)
        //      {
        //         do{
        //             y = *(r[i] + j);
        //             j++;
        //         } while(y != '\0');
        //      }
        //
        //      
        //      while(1);
        //   }
    }
}

