
//Create an array of pointers and initialize 4 different strings.  These strings are programmed
// into flash during programming because the 'const' keyword is used to make the pointers point
// to flash memory.  Also, create some generic variables used for the loops.
const char *p[4] = {"ALARM", "FAULT", "SENSOR", "UNLOCK"};
const char **pp = &p[0];
unsigned char y;


//Function prototype
void string_access(const char **message_pointer);


int main(int argc, char** argv) 
{
    
//Step through the following code and watch the 'y' variable.  This code will separately access each
// string in the array.  This code will pass the pointer address to the strings to the function.  It will 
// increment the double pointer to point to the next string.  This method demonstrates how to pass the 
// pointer to the function.    
   while(1)
   {
//Access "ALARM"       
       pp = &p[0];
       string_access(&*pp);

//Access "FAULT"
       pp++;
       string_access(&*pp);

//Access "SENSOR"       
       pp++;
       string_access(&*pp);

//Access "UNLOCK"       
       pp++;
       string_access(&*pp);

      while(1);
   }
}


//This function receives the address of the array pointer to the text strings.  The
// double pointer allows us to pass the address of pointers to functions.  The function
// will access each character in the string until the NULL character is reached.
void string_access(const char **message_pointer)
{
    unsigned char i;
    
    i = 0;
    do{
        y = *(*message_pointer + i);
        i++;
    } while(y != '\0');
}