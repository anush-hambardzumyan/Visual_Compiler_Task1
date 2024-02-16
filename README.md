# Visual_Compiler_Task1
The program will receive a text.txt file as input, which will contain all simple type declarations.

**text.txt**
````cpp
int Integer; double Double; char Character; float Float; short Short; bool Boolean;
unsigned int integerNumber = 10; Double; double doubleNumber = 3.14159; unsigned
char character = 'A'; unsigned float floatNumber = 2.71828f; unsigned short shortNumber
 = 1000; doubleNumber; unsigned bool boolean = true;  long long int result; long int sum;
const int constantValue = 11;   constantValue;   otherValue;
```` 

Names that do not have types should be considered output values, and declarations that are not valued will contain GARBAGE.

The program should create two files, result.txt and typeInfo.txt. As a result, display the types and values specified in the text.txt file as output values in the result.txt file. In addition, display information about the row and position, and display all simple type declarations in the typeInfo.txt file.
<br>
<br>

**result.txt** 
````
Type          Value                       Name                      Line           Position     

 d            GARBAGE                    Double                      0                1
 d            3.14159                   doubleNumber                 1                2
ci             11                      constantInteger               4                0
 -              -                        otherValue                  4                2
````

<br>
<br>

**typeInfo.txt**
`````cpp
int Integer;
double Double;
char Character;
float Float;
short  Short;
bool Boolean;
unsigned int integerNumber = 10; 
double doubleNumber = 3.14159; 
unsigned char character = 'A'; 
unsigned float floatNumber = 2.71828f; 
unsigned short  shortNumber = 1000; 
unsigned bool boolean = true; 
long long int result;
long int sum;
const int constantValue = 11;
`````

---------
**How to use this program** <br>
* Clone the repository to your local PC.
* Write the code you want to analyze in ``"text.txt"``.
* Compile the ``parser.cpp`` file and execute ``./a.out``.
* TaDaam!! all required results are stored in appropriate files.
