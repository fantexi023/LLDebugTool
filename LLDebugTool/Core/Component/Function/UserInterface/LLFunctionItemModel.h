//
//  LLFunctionItemModel.h
//
//  Copyright (c) 2018 LLDebugTool Software Foundation (https://github.com/HDB-Li/LLDebugTool)
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import "LLBaseModel.h"
#import "LLComponent.h"
#import "LLDebugTool.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The model of LLFunctionCell.
 */
@interface LLFunctionItemModel : LLBaseModel

/**
 The name of the display image.
 */
@property (nonatomic, copy, readonly) NSString *imageName;

/**
 The title to display.
 */
@property (nonatomic, copy, readonly) NSString *title;

/**
 Specified action.
 */
@property (nonatomic, assign, readonly) LLDebugToolAction action;

/**
 Action component.
 */
@property (nonatomic, strong, readonly) LLComponent *component;

/**
 Specifies the init method.

 @param action Specified action.
 @return Instance object.
 */
- (instancetype _Nonnull)initWithAction:(LLDebugToolAction)action;

@end

NS_ASSUME_NONNULL_END
