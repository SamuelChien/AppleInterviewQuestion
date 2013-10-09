//
//  main.m
//  Book
//
//  Created by Samuel Chien on 2012-11-17.
//  Copyright (c) 2012 Samuel Chien. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Book.h"

/******************************************************************************
 *  main                                                                      *
 ******************************************************************************/

/* FUNCTION main
 *    Run the the small test of the initializer and accessor of Book implementation.
 * Parameters and preconditions:  int argc, const char * argv[]
 * Return value:  0 as successful program
 * Side-effects:  program is executed and memory is allocate and drained by autoreleasepool block.
 *
 */

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        Book *bestBook = [[Book alloc]initWithTitleAndAuthorAndDate:@"World's Seven Wonders" :@"Samuel" :@"1993"];
        bestBook.title = @"World's Seven Wonders~NOT!";
        NSLog(@"\nThis book is called: %@\nThe book is written by the author: %@ who publish it in %@", bestBook.title, bestBook.author, bestBook.date);
        
    }
    return 0;
    
}

