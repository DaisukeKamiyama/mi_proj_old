/*
     File: NSStringExtras.m 
 Abstract: Some convenience methods defined as a
 category of the NSString class.  Primairly, these methods provide
 simple conversions between JavaScriptCore strings and the NSString
 class.  These methods are used again and again in the sample
 whereever such string conversions are required. 
  Version: 1.1 
  
 Disclaimer: IMPORTANT:  This Apple software is supplied to you by Apple 
 Inc. ("Apple") in consideration of your agreement to the following 
 terms, and your use, installation, modification or redistribution of 
 this Apple software constitutes acceptance of these terms.  If you do 
 not agree with these terms, please do not use, install, modify or 
 redistribute this Apple software. 
  
 In consideration of your agreement to abide by the following terms, and 
 subject to these terms, Apple grants you a personal, non-exclusive 
 license, under Apple's copyrights in this original Apple software (the 
 "Apple Software"), to use, reproduce, modify and redistribute the Apple 
 Software, with or without modifications, in source and/or binary forms; 
 provided that if you redistribute the Apple Software in its entirety and 
 without modifications, you must retain this notice and the following 
 text and disclaimers in all such redistributions of the Apple Software. 
 Neither the name, trademarks, service marks or logos of Apple Inc. may 
 be used to endorse or promote products derived from the Apple Software 
 without specific prior written permission from Apple.  Except as 
 expressly stated in this notice, no other rights or licenses, express or 
 implied, are granted by Apple herein, including but not limited to any 
 patent rights that may be infringed by your derivative works or by other 
 works in which the Apple Software may be incorporated. 
  
 The Apple Software is provided by Apple on an "AS IS" basis.  APPLE 
 MAKES NO WARRANTIES, EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION 
 THE IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS 
 FOR A PARTICULAR PURPOSE, REGARDING THE APPLE SOFTWARE OR ITS USE AND 
 OPERATION ALONE OR IN COMBINATION WITH YOUR PRODUCTS. 
  
 IN NO EVENT SHALL APPLE BE LIABLE FOR ANY SPECIAL, INDIRECT, INCIDENTAL 
 OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 INTERRUPTION) ARISING IN ANY WAY OUT OF THE USE, REPRODUCTION, 
 MODIFICATION AND/OR DISTRIBUTION OF THE APPLE SOFTWARE, HOWEVER CAUSED 
 AND WHETHER UNDER THEORY OF CONTRACT, TORT (INCLUDING NEGLIGENCE), 
 STRICT LIABILITY OR OTHERWISE, EVEN IF APPLE HAS BEEN ADVISED OF THE 
 POSSIBILITY OF SUCH DAMAGE. 
  
 Copyright (C) 2011 Apple Inc. All Rights Reserved. 
  
 */

#import "NSStringExtras.h"


@implementation NSString (JavaScriptConversion)



	/* convert a JavaScriptCore string into a NSString */
+ (NSString *)stringWithJSString:(JSStringRef)jsStringValue {

		/* as a class method we return an autoreleased NSString. */
	return [ ( (NSString *) JSStringCopyCFString( kCFAllocatorDefault, jsStringValue ) ) autorelease ];
}


	/* return a new JavaScriptCore string value for the string */
- (JSStringRef)jsStringValue {
	return JSStringCreateWithCFString( (CFStringRef) self );
}


	/* convert a JavaScriptCore value in a JavaScriptCore context into a NSString. */
+ (NSString *)stringWithJSValue:(JSValueRef)jsValue fromContext:(JSContextRef)ctx {
	NSString* theResult = nil;
	
		/* attempt to copy the value to a JavaScriptCore string. */
	JSStringRef stringValue = JSValueToStringCopy( ctx, jsValue, NULL );
	if ( stringValue != NULL ) {
	
			/* if the copy succeeds, convert the returned JavaScriptCore
			string into an NSString. */
		theResult = [NSString stringWithJSString: stringValue];
		
			/* done with the JavaScriptCore string. */
		JSStringRelease( stringValue );
	}
	return theResult;
}



@end
