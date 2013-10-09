//
//  Book.m
//  Book
//
//  Created by Samuel Chien on 2012-11-17.
//  Copyright (c) 2012 Samuel Chien. All rights reserved.
//

//import book.h which contains the interface book
#import "Book.h"

@implementation Book

// synthesize the variable to make variable getter and setter 
@synthesize title, author, date;

// ==========================
// = Designated initializer =
// ==========================

/* FUNCTION initWithTitleAndAuthorAndDate
 *    initialized when it's given 3 parameter
 * Parameters and preconditions:
 *    it must be string
 * Return value:  the initialized object
 * Side-effects:
 *    doesn't output errors when super class didn't initialize correctly
 */
-(id)initWithTitleAndAuthorAndDate: (NSString*)inTitle: (NSString*)inAuthor: (NSString*)inDate
{
    // if the super class init correctly, set the title, author, and date accordingly
    if (self = [super init])
    {
        self.title = inTitle;
        self.author = inAuthor;
        self.date = inDate;
    }
    return self;
}

/* FUNCTION initWithTitleAndAuthor
 *    initialized when it's given 2 parameter
 * Parameters and preconditions:
 *    it must be string
 * Return value:  the initialized object
 * Side-effects:
 *    doesn't output errors when super class didn't initialize correctly
 */
-(id)initWithTitleAndAuthor: (NSString*)inTitle: (NSString*)inAuthor
{
    if (self = [super init])
    {
        self.title = inTitle;
        self.author = inAuthor;
        self.date = @"Unknown";
    }
    return self;
}

/* FUNCTION init
 *    initialized when it's given none parameter
 * Parameters and preconditions:
 *    it must be string
 * Return value:  0 if successful
 * Side-effects:
 *    doesn't output errors when super class didn't initialize correctly
 */
-(id)init{
    if (self = [super init]){
        self.title = @"No-Title";
        self.author = @"Unknown";
        self.date = @"Unknown";
        
    }
    return self;
}

@end
