/*

Copyright (C) 2018  Daisuke Kamiyama (https://www.mimikaki.net)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
/*

CocoaContextualMenuController

*/

#import "CocoaContextualMenuController.h"
#include "../AbsBase/Cocoa.h"

@implementation CocoaContextualMenuController

#pragma mark ===========================
#pragma mark [クラス]CocoaContextualMenuController
#pragma mark ===========================

/**
初期設定
*/
- (id)initWithNibName:(NSString*)inIBName
{
	//contextualMenuはnib内で設定する。nib loadにより、contextualMenuが設定される。
	contextualMenu = nil;
	
	self = [super init];
	if( self != nil )
	{
		//指定nib nameのnibを読み込み(ownerは自分)
		if( [NSBundle loadNibNamed:inIBName owner:self] == NO )
		{
			_ACError("nib menu not found",NULL);
		}
	}
	return self;
}

/**
コンテキストメニュー取得
*/
- (NSMenu*)getContextualMenu
{
	return contextualMenu;
}

@end

