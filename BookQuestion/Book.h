//
//  Book.h
//  Book
//
//  Created by Samuel Chien on 2012-11-17.
//  Copyright (c) 2012 Samuel Chien. All rights reserved.
//

// import foundation to write objective c code
#import <Foundation/Foundation.h>

// define the interface book
@interface Book : NSObject
{
    // string variable
    NSString *title;
    NSString *author;
    NSString *date;
}

// Designated initializer
-(id)initWithTitleAndAuthorAndDate: (NSString*)title: (NSString*)author :(NSString*)date;
-(id)initWithTitleAndAuthor: (NSString*)title: (NSString*)author;
-(id)init;

// property for each variable, so it could be synthesize.
@property NSString *title, *author, *date;

@end
