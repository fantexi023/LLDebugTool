//
//  LLHtmlConfigViewController.m
//  LLDebugToolDemo
//
//  Created by admin10000 on 2019/10/11.
//  Copyright © 2019 li. All rights reserved.
//

#import "LLHtmlConfigViewController.h"
#import "LLTitleCellCategoryModel.h"
#import "LLSettingManager.h"
#import "LLFactory.h"
#import "LLMacros.h"
#import "LLConst.h"
#import "UIView+LL_Utils.h"
#import "LLThemeManager.h"
#import "LLToastUtils.h"
#import "LLHtmlViewController.h"
#import "LLHtmlUIWebViewController.h"
#import "LLHtmlWkWebViewController.h"
#import "LLConfig.h"
#import <WebKit/WebKit.h>

@interface LLHtmlConfigViewController () <UITextFieldDelegate>

@property (nonatomic, copy) NSString *webViewClass;

@property (nonatomic, strong) UIView *headerView;

@property (nonatomic, strong) UITextField *headerTextField;

@end

@implementation LLHtmlConfigViewController

#pragma mark - Life cycle
- (void)viewDidLoad {
    [super viewDidLoad];
    [self setUpUI];
    [self loadData];
}

- (void)viewWillDisappear:(BOOL)animated {
    if ([self.headerTextField isFirstResponder]) {
        [self.headerTextField resignFirstResponder];
    }
}

#pragma mark - Over write
- (void)rightItemClick:(UIButton *)sender {
    NSString *urlString = [self currentUrlString];
    if (!urlString) {
        [[LLToastUtils shared] toastMessage:@"Empty URL"];
        return;
    }
    if (![urlString.lowercaseString hasPrefix:@"https://"] && ![urlString.lowercaseString hasPrefix:@"http://"]) {
        [[LLToastUtils shared] toastMessage:@"URL must has prefix with https:// or http://"];
        return;
    }
    Class cls = NSClassFromString(self.webViewClass);
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    if (cls != [UIWebView class] && cls != [WKWebView class]) {
#pragma clang diagnostic pop
        [[LLToastUtils shared] toastMessage:@"Invalid webView class"];
        return;
    }
    
    [LLSettingManager shared].lastWebViewUrl = urlString;
    
    LLHtmlViewController *vc = nil;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    if (cls == [UIWebView class]) {
#pragma clang diagnostic pop
        vc = [[LLHtmlUIWebViewController alloc] init];
    } else {
        vc = [[LLHtmlWkWebViewController alloc] init];
    }
    vc.webViewClass = self.webViewClass;
    vc.urlString = [self currentUrlString];
    [self.navigationController pushViewController:vc animated:YES];
}

#pragma mark - UITextFieldDelegate
- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return YES;
}

#pragma mark - Primary
- (void)setUpUI {
    self.title = @"WebView Config";
    [self initNavigationItemWithTitle:@"Go" imageName:nil isLeft:NO];
    
    self.webViewClass = [LLSettingManager shared].webViewClass ?: NSStringFromClass([WKWebView class]);
    
    self.tableView.tableHeaderView = self.headerView;
}

- (void)loadData {
    NSMutableArray *settings = [[NSMutableArray alloc] init];
    
    // Short Cut
    [settings addObject:[self getWebViewStyleModel]];
    LLTitleCellCategoryModel *category0 = [[LLTitleCellCategoryModel alloc] initWithTitle:nil items:settings];
    [settings removeAllObjects];
    
    [self.dataArray removeAllObjects];
    [self.dataArray addObjectsFromArray:@[category0]];
    [self.tableView reloadData];
}

- (LLTitleCellModel *)getWebViewStyleModel {
    LLTitleCellModel *model = [[LLTitleCellModel alloc] initWithTitle:@"Style" detailTitleSelector:self.webViewClass];
    __weak typeof(self) weakSelf = self;
    model.block = ^{
        [weakSelf showWebViewClassAlert];
    };
    return model;
}

- (void)showWebViewClassAlert {
    __block NSMutableArray *actions = [[NSMutableArray alloc] init];
    [actions addObject:NSStringFromClass([WKWebView class])];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
    [actions addObject:NSStringFromClass([UIWebView class])];
#pragma clang diagnostic pop
    __weak typeof(self) weakSelf = self;
    [self showActionSheetWithTitle:@"Web View Style" actions:actions currentAction:self.webViewClass completion:^(NSInteger index) {
        [weakSelf setNewWebViewClass:actions[index]];
    }];
}

- (void)setNewWebViewClass:(NSString *)aClass {
    self.webViewClass = aClass;
    [LLSettingManager shared].webViewClass = aClass;
    [self loadData];
}

- (NSString *)currentUrlString {
    NSString *text = self.headerTextField.text;
    text = [text stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    if (!text || text.length == 0) {
        return nil;
    }
    return text;
}

#pragma mark - Getters and setters
- (UIView *)headerView {
    if (!_headerView) {
        _headerView = [LLFactory getView];
        _headerView.frame = CGRectMake(0, 0, LL_SCREEN_WIDTH, 60);
        [_headerView addSubview:self.headerTextField];
        self.headerTextField.frame = CGRectMake(kLLGeneralMargin, kLLGeneralMargin, _headerView.LL_width - kLLGeneralMargin * 2, _headerView.LL_height - kLLGeneralMargin * 2);
    }
    return _headerView;
}

- (UITextField *)headerTextField {
    if (!_headerTextField) {
        _headerTextField = [LLFactory getTextField];
        _headerTextField.tintColor = [LLThemeManager shared].primaryColor;
        _headerTextField.backgroundColor = [LLThemeManager shared].backgroundColor;
        [_headerTextField LL_setBorderColor:[LLThemeManager shared].primaryColor borderWidth:1];
        [_headerTextField LL_setCornerRadius:5];
        _headerTextField.font = [UIFont systemFontOfSize:14];
        _headerTextField.textColor = [LLThemeManager shared].primaryColor;
        _headerTextField.delegate = self;
        _headerTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
        _headerTextField.attributedPlaceholder = [[NSAttributedString alloc] initWithString:@"Pleace input url" attributes:@{NSForegroundColorAttributeName : [LLThemeManager shared].placeHolderColor}];
        _headerTextField.text = [LLSettingManager shared].lastWebViewUrl ?: ([LLConfig shared].defaultHtmlUrl ?: @"https://");
        UIView *leftView = [LLFactory getView];
        leftView.frame = CGRectMake(0, 0, 10, 1);
        _headerTextField.leftView = leftView;
        _headerTextField.leftViewMode = UITextFieldViewModeAlways;
    }
    return _headerTextField;
}

@end
