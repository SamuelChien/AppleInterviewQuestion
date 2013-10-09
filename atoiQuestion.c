/* FILE atoiQuestion.c
 *    An implementation of atoi. Try to mimic the c library's atoi function. 
 * Author: Samuel(Tzu-Yao) Chien
   Date: November 2012
 */


#include <stdio.h>
#include <stdlib.h>

/*
 Atoi Behavior Observation:
    - disregard all beginning spaces and 0's
    - ignore anything after the first non integer character 
    - return 0 when it'empty
    - return -1 if integer is not transferable to an int
    - every 10 integer character, it automatically turn 10 int into int and put it back to saving array. 
    - jump back to 0 when it hits 2^32 aka 4294967296
    - if 10 characters give a result of longer than 10 character and it can not further be reduced to 1 character, then, return -1;
*/



/******************************************************************************
 *  Functions.                                                                *
 ******************************************************************************/




/* FUNCTION atoiSamuelVersion
 *    A mimic version of Atoi. Try to handle all input the same way as atoi function.
 * Parameters and preconditions: a char pointer which can not be NULL. Else segmentation fault in both atoi and atoiSamuelVersion.
 * Return value: int
 * Side-effects: none
 */

int atoiSamuelVersion(const char * str){
    // define an int 10 character int array to save value. Since the 10 int turned into one integer, so there isn't the issue of out of bound.
    int result [10];
    int negative = 1;
    
    // j is where the non-space, 0's starts. i is looping index for the string
    int i = 0;
    int j = 0;
    int index = 0;
    
    // disregard any space or 0's in the beginning
    while (*(str+j) == ' ' || *(str+j) == '0') {
        j++;
    }
    
    // handling negative value.
    if (*(str+i +j) == '-') {
        negative = -1;
        i++;
    }
    
    // if the character is '0' ~ '9' continue looping
    while (*(str+i +j) - '0' >= 0 && *(str+i + j) - '0' <= 9) {
        // when int array is full, turn 10 character into one int and insert back to array.
        if (index== 10){
            // temp = combined int result
            int temp = addNumber(result, 10);
            
            // to prevent the case is 0, since 0 is count as 1 digit too.
            int temp2 = temp/10;
            int totalDigit = 1;
            
            // To get the total amount of digit. TotalDigit.
            while (temp2 != 0) {
                temp2/=10;
                totalDigit++;
            }
            
            // if the combined int still have more than 10 digit. Then we have an overflow, which returns -1
            if (totalDigit> 9) return -1;
            
            // obtain a zeros so we can insert the digit from left to right.
            int k = 0;
            int zeros = 1;
            for (k; k< totalDigit-1; k++){zeros*=10;}
            
            // insert the int back to array. And set index to number of digit.
            index = 0;
            for(index; index<totalDigit; index++){
                result[index] = temp/zeros;
                zeros/=10;
            }
            
        }
        
        // continue reading the string and insert it into the array
        result[index] = *(str+i + j) - '0';
        i++;
        index++;
        
        
    }
    

    // after reading all digit. return the combined value int times if it's negative
    return addNumber(result, index) * negative;
    
}


/* FUNCTION addNumber
 *    Combined the array numbers up to the given index
 * Parameters and preconditions:
 *    max and array can not be null
 * Return value:  int
 * Side-effects:
 *    array[] is address, so any modification of the code might change the array.
 */


int addNumber(int array[], int max){
    int value = 0;
    int k = 0;
    int z = 0;
    int zeros = 1;
    for (k; k< max-1; k++){zeros*=10;}
    
    for (z; z< max; z++){
        value += (array[z] * zeros);
        zeros/=10;
    }
    
    return value;

}


/******************************************************************************
 *  Test Suite.                                                                *
 ******************************************************************************/



/* FUNCTION atoiTestSuiteOutput()
 *    In Charge of the printing the test result on screen.
 * Parameters and preconditions:
 *    none
 * Return value:  none
 * Side-effects:
 *   some test such as test1 might crash the program since NULL is not a valid input
 */

void atoiTestSuiteOutput(){
    //    // Test 1: handling null ----> segmentation fault
    //    printf ("The value is %d \n",atoi(NULL));
    //    printf ("The value is %d \n",atoiSamuelVersion(NULL));
    
    //Test 2: Combine 11 character -1 handling
    printf("ATOI: The value is %d \n",atoi("2294967297022949672970"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("2294967297022949672970"));
    
    // Test 3: handing character----> 1234
    printf("ATOI: The value is %d \n",atoi("1234hahaha"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("1234hahaha"));
    
    // Test 4: empty string ----> 0
    printf("ATOI: The value is %d \n",atoi(""));
    printf("MINE: The value is %d \n",atoiSamuelVersion(""));
    
    //Test 5: Handling normal input ---> 1234
    printf("ATOI: The value is %d \n",atoi("1234"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("1234"));
    
    //Test 6: handling signs ---> 12
    printf("ATOI: The value is %d \n",atoi("12^32"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("12^32"));
    
    // Test7: White Space
    printf("ATOI: The value is %d \n",atoi("1     2^32"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("1      2^32"));
    
    
    //Test 8: begin with white space
    printf("ATOI: The value is %d \n",atoi("    12^32"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("    12^32"));
    
    //Test 9: begin with 0's overflow
    printf("ATOI: The value is %d \n",atoi("0000000000000000000000000000000001"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("0000000000000000000000000000000001"));
    
    //Test 10: Combine 10 character
    printf("ATOI: The value is %d \n",atoi("42949672970"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("42949672970"));
    
    //Test 11: negative handling
    printf("ATOI: The value is %d \n",atoi("-4294967293"));
    printf("MINE: The value is %d \n",atoiSamuelVersion("-4294967293"));
    
}


/* FUNCTION atoiTestSuite
    This function counts the successful test and print out the output of each test.
 * Parameters and preconditions: none
 * Return value:  none
 * Side-effects:none
 */

void atoiTestSuite(){
    int trueCount = 0;
    int totalTest = 10;
    
    if(atoi("2294967297022949672970") == atoiSamuelVersion("2294967297022949672970"))trueCount++;
    
    if(atoi("1234hahaha") == atoiSamuelVersion("1234hahaha"))trueCount++;
    
    if(atoi("") == atoiSamuelVersion(""))trueCount++;
    
    if(atoi("1234") == atoiSamuelVersion("1234"))trueCount++;
    
    if(atoi("12^32") == atoiSamuelVersion("12^32"))trueCount++;
    
    if(atoi("1     2^32") == atoiSamuelVersion("1     2^32"))trueCount++;
    
    //    if(atoi(NULL) == atoiSamuelVersion(NULL))trueCount++;
    
    if(atoi("    12^32") == atoiSamuelVersion("    12^32"))trueCount++;
    
    if(atoi("42949672970") == atoiSamuelVersion("42949672970"))trueCount++;
    
    if(atoi("00000000001") == atoiSamuelVersion("00000000001"))trueCount++;
    
    if(atoi("-4294967293") == atoiSamuelVersion("-4294967293"))trueCount++;
    
    printf("In Total of %d Test Cases %d Success and %d Fails!\n", totalTest, trueCount, totalTest-trueCount);
    
    atoiTestSuiteOutput();
}


/******************************************************************************
 *  main                                                                      *
 ******************************************************************************/

/* FUNCTION main
 *    Run the atoiTestSuite.
 * Parameters and preconditions:  none
 * Return value:  0 as successful program
 * Side-effects:  program is executed
 */



int main ()
{
    atoiTestSuite();
    return 0;
}