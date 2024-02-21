//Variable declarations
unsigned char functionState = 0;
unsigned int functionResult = 0;


//Function prototypes
int function1(int x);
int function2(int y);
int function3(int z);


//Function Pointer Declarations and Initialization
// An array of function pointers is declared and the array will contain three
// addresses for function1, function2, and function3.  The array is initialized
// with the addresses of these functions.  This array will point to functions that
// are passed one int parameter and return one int parameter.
int (*funPtr[3])(int a) = { &function1, &function2, &function3 };


//Place function pointers in program memory
int (* const funPtrFlash[3])(int a) = { &function1, &function2, &function3 };

//*******************************************************************************
//Could place the function pointers in flash if desired.  Uncomment this declaration and comment 
// out the existing declaration for funPtr[ ]
//int (*funPtr[3])(int a) __attribute__((space(prog))) = { &function1, &function2, &function3};
//*******************************************************************************


//Main routine
int main(void)
{
//The functionState variable is incremented after each indirect function call so that
// the succeeding function is called next.  In each function call, a value of 2 is passed
// to the function
    while(1)
    {
//Calls function1        
        functionState = 0;
        functionResult = funPtr[functionState](2);

//Calls function 2
        functionState++;
        functionResult = funPtr[functionState](2);

//Calls function 3
        functionState++;
        functionResult = funPtr[functionState](2);
        
        functionState = 0;
        
        
//Now use function pointers in program memory

//Calls function1        
        functionState = 0;
        functionResult = funPtrFlash[functionState](2);

//Calls function 2
        functionState++;
        functionResult = funPtrFlash[functionState](2);

//Calls function 3
        functionState++;
        functionResult = funPtrFlash[functionState](2);
        
        functionState = 0;        
    }
}


//Returns the value passed to the function
int function1(int x)
{
    return x;
}

//Returns the square of the value passed to the function
int function2(int y)
{
    return y * y;
}

//Returns the cube of the value passed to the function
int function3(int z)
{
    return z * z * z;
}


