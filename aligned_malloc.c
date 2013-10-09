/* FILE aligned_malloc.c
 *    An implementation of aligned malloc.
 * Author: Samuel(Tzu-Yao) Chien
   Date: November 2012
 */

#include <stdio.h>
#include <stdlib.h>

/*************************************************
 Name	 :- aligned_malloc
 Parameters:- size of the user malloc request and aligment segment
 Return :- NULL on error
 valid pointer on success
 
 Idea: allocate a set of memory that user request on the aligned boundary line.
 
 Purpose: If the memory is on the aligned boundary, CPU doesn't need to fetch both memory block that both save part of data, rather it only need to fetch one block of aligned memory which is much more efficient.
 
 Ex.
 aligned_malloc(100,512);
 This will allocate 100 bytes size of memory with
 starting address multiple of 512. REMEMBER! alignment must be a power of 2.
 
 *************************************************/

void * aligned_malloc(size_t size, size_t alignment)
{
    /* First of all, we can not have alignment of 0 or smaller since there is no address that's multiple of 0.
        Secondly, size that's smaller than 0 is also not valid because we need to return an address that points of the boundary line.
    */
    if (alignment <= 0 || size < 0) return NULL;
    
    /*
     alignment must be a power of 2. So first check if alignment is power of 2.
     */
    int temp = alignment;
    int temp2;
    int binaryOneCount = 0;
    while(temp !=0){
        temp2 = temp|1;
        if (temp == temp2){
            binaryOneCount++;}
        temp = temp>>1;
    }
    if(binaryOneCount != 1) return NULL;
    
    // Define pointers that are needed for this malloc assignments.
    void *startingMallocPointer ,*alignedBoundryPointer;

    /* First allocate memory of size + alignment + sizeof(size_t) Then check if malloc is successful. if not return null. size is the block of memory user requests. allocate alignment is so we know doesn't matter where the alignment boundary lies, we can always have size of bytes users request after it. Last but not least, sizeof(size_t) is the size of each pointer on different machine for saving a memory address. This allocation is for a memory address that stores where the allocation starts. This is for the free alignment purpose. 
     */
    if((startingMallocPointer =(void *) malloc(size + alignment + sizeof(size_t)))==NULL)
        return NULL;
    
    /*	To find the alignment address point, we first need to know how large the last box of the memory is. So we can % it and find where the closest alignment point is in front of the allocated memory box.
     */
    size_t maximumAllocateCompacity=(size_t)startingMallocPointer+alignment+sizeof(size_t);
    
    // Find the alignedBoundryPoint using the size of allocation - allocation%alignment.
    alignedBoundryPointer=(void *)(maximumAllocateCompacity - (maximumAllocateCompacity%alignment));
    
    /*	Last step is storing the pointer address in front of alignedBoundaryPoint, so if 
        user wants to free the memory, it can just roll back one step of size_t to obtain where
        aligned memory starts. Since when we malloc orignally, we has also include the size of the 
        address. So there must be rooms in front of the boundary line.
     */
    *((size_t *)alignedBoundryPointer-1)=(size_t)startingMallocPointer;
    
    return alignedBoundryPointer;
}

/************************************************
 Name	 :- aligned_free
 Arguments	:- ALIGNED pointer to be freed
 Returns	 :- Nothing
 
 *************************************************/

void aligned_free(void * ptr)
{
    /*	Since the address root of each aligned_malloc address is store 1 size_t bytes of memory before the pointer. So roll back to the root memory and free the memory like usual.
     */
    free((void *)(*((size_t *) ptr-1)));
}


/************************************************
 Name	 :- main
 Arguments	:- none
 Returns	 :- 0 if successful
 
 Purpose: Check if aligned_malloc can actually malloc a certain bytes starting from certain multiple address such as 128. We check by divid the memory address by its alignment and if we get 0 then it's an aligned memory.
 
 *************************************************/

int main( void )
{
    // char type memory data.
    char* randomMemory = 0;
    
    // run the memory allocation of 50 bytes and set 128 byte boundry
    randomMemory = aligned_malloc(50,128);
    
    // if malloc is successful then we check if its memory address is actually multiple of alignment.
    if( randomMemory != NULL )
    {
        if (((int)randomMemory)%128 == 0)
            printf("This is actually aligned memory!!!!!!!!!!!!\n");
        else
            printf("The memory is actually not aligned!!!\n");
        
        // free the alocated memory
        aligned_free( randomMemory );
    }
    
    return 0;
}