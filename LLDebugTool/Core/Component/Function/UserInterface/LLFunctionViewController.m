//
//  LLFunctionViewController.m
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

#import "LLFunctionViewController.h"
#import "LLFunctionItemModel.h"
#import "LLConfig.h"
#import "LLMacros.h"
#import "LLFactory.h"
#import "LLNetworkViewController.h"
#import "LLLogViewController.h"
#import "LLCrashViewController.h"
#import "LLAppInfoViewController.h"
#import "LLSandboxViewController.h"
#import "LLFunctionItemContainerView.h"
#import "UIView+LL_Utils.h"
#import "LLThemeManager.h"
#import "LLConst.h"
#import "LLWindowManager.h"
#import "LLSettingViewController.h"

@interface LLFunctionViewController ()<LLFunctionContainerViewControllerDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;

@property (nonatomic, strong) LLFunctionItemContainerView *toolContainerView;

@property (nonatomic, strong) LLFunctionItemContainerView *shortCutContainerView;

@property (nonatomic, strong) UIButton *settingButton;

@end

@implementation LLFunctionViewController

#pragma mark - Life cycle
- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"LLDebugTool";
    
    [self.view addSubview:self.scrollView];
    [self.scrollView addSubview:self.toolContainerView];
    [self.scrollView addSubview:self.shortCutContainerView];
    [self.scrollView addSubview:self.settingButton];
    
    [self loadData];
}

- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    
    self.scrollView.frame = self.view.bounds;
        
    self.toolContainerView.frame = CGRectMake(kLLGeneralMargin, kLLGeneralMargin, self.view.LL_width - kLLGeneralMargin * 2, self.toolContainerView.LL_height);

    self.shortCutContainerView.frame = CGRectMake(self.toolContainerView.LL_left, self.toolContainerView.LL_bottom + kLLGeneralMargin, self.toolContainerView.LL_width , self.shortCutContainerView.LL_height);
    
    self.settingButton.frame = CGRectMake(self.toolContainerView.LL_left, self.shortCutContainerView.LL_bottom + 30, self.toolContainerView.LL_width, 40);
    
    
    self.scrollView.contentSize = CGSizeMake(0, self.settingButton.LL_bottom + kLLGeneralMargin);
}

#pragma mark - Over write
- (void)primaryColorChanged {
    [super primaryColorChanged];
    [self.settingButton setTitleColor:[LLThemeManager shared].primaryColor forState:UIControlStateNormal];
    self.settingButton.layer.borderColor = [LLThemeManager shared].primaryColor.CGColor;
}

#pragma mark - Primary
- (void)loadData {
    NSMutableArray *items = [[NSMutableArray alloc] init];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionNetwork]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionLog]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionCrash]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionAppInfo]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionSandbox]];
    
    self.toolContainerView.dataArray = [items copy];
    self.toolContainerView.title = @"Function";
    
    [items removeAllObjects];
    
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionScreenshot]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionHierarchy]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionMagnifier]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionRuler]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionWidgetBorder]];
    [items addObject:[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionHtml]];
    
    self.shortCutContainerView.dataArray = [items copy];
    self.shortCutContainerView.title = @"Short Cut";
}

#pragma mark - LLFunctionContainerViewDelegate
- (void)LLFunctionContainerView:(LLFunctionItemContainerView *)view didSelectAt:(LLFunctionItemModel *)model {
    LLComponent *component = model.component;
    [component componentDidLoad:nil];
}

#pragma mark - Event response
- (void)settingButtonClicked:(UIButton *)sender {
    [[[LLFunctionItemModel alloc] initWithAction:LLDebugToolActionSetting].component componentDidLoad:nil];
}

#pragma mark - Getters and setters
- (UIScrollView *)scrollView {
    if (!_scrollView) {
        _scrollView = [LLFactory getScrollView];
    }
    return _scrollView;
}

- (LLFunctionItemContainerView *)toolContainerView {
    if (!_toolContainerView) {
        _toolContainerView = [[LLFunctionItemContainerView alloc] initWithFrame:CGRectZero];
        _toolContainerView.delegate = self;
    }
    return _toolContainerView;
}

- (LLFunctionItemContainerView *)shortCutContainerView {
    if (!_shortCutContainerView) {
        _shortCutContainerView = [[LLFunctionItemContainerView alloc] initWithFrame:CGRectZero];
        _shortCutContainerView.delegate = self;
    }
    return _shortCutContainerView;
}

- (UIButton *)settingButton {
    if (!_settingButton) {
        _settingButton = [LLFactory getButton:nil frame:CGRectZero target:self action:@selector(settingButtonClicked:)];
        [_settingButton LL_setCornerRadius:5];
        [_settingButton setTitle:@"Settings" forState:UIControlStateNormal];
        [_settingButton setTitleColor:[LLThemeManager shared].primaryColor forState:UIControlStateNormal];
        [_settingButton LL_setBorderColor:[LLThemeManager shared].primaryColor borderWidth:1];
    }
    return _settingButton;
}

@end
