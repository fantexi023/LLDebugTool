//
//  LLTitleCellModel.m
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

#import "LLTitleCellModel.h"
#import "LLTitleSwitchCell.h"
#import "LLDetailTitleSelectorCell.h"
#import "LLTitleSliderCell.h"
#import "LLDetailTitleCell.h"
#import "LLConst.h"

@implementation LLTitleCellModel

- (instancetype)initWithTitle:(NSString *)title flag:(BOOL)flag {
    if (self = [super init]) {
        _title = [title copy];
        _flag = flag;
        _cellClass = NSStringFromClass(LLTitleSwitchCell.class);
        _separatorInsets = UIEdgeInsetsMake(0, kLLGeneralMargin, 0, 0);
    }
    return self;
}

- (instancetype)initWithTitle:(NSString *)title detailTitle:(NSString *)detailTitle {
    if (self = [super init]) {
        _title = [title copy];
        _detailTitle = [detailTitle copy];
        _cellClass = NSStringFromClass(LLDetailTitleCell.class);
        _separatorInsets = UIEdgeInsetsMake(0, kLLGeneralMargin, 0, 0);
    }
    return self;
}

- (instancetype)initWithTitle:(NSString *)title detailTitleSelector:(NSString *)detailTitle {
    if (self = [super init]) {
        _title = [title copy];
        _detailTitle = [detailTitle copy];
        _cellClass = NSStringFromClass(LLDetailTitleSelectorCell.class);
        _separatorInsets = UIEdgeInsetsMake(0, kLLGeneralMargin, 0, 0);
    }
    return self;
}

- (instancetype)initWithTitle:(NSString *)title value:(CGFloat)value minValue:(CGFloat)minValue maxValue:(CGFloat)maxValue {
    if (self = [super init]) {
        _title = [title copy];
        _value = value;
        _minValue = minValue;
        _maxValue = maxValue;
        _cellClass = NSStringFromClass(LLTitleSliderCell.class);
        _separatorInsets = UIEdgeInsetsMake(0, kLLGeneralMargin, 0, 0);
    }
    return self;
}

@end
