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

AView_TextViewHSeparator

*/

#pragma once

#include "../../AbsFramework/Frame.h"
#include "ATypes.h"

#pragma mark ===========================
#pragma mark [クラス]AView_TextViewHSeparator

/**
分割線ビュー
*/
class AView_TextViewHSeparator : public AView
{
	//コンストラクタ、デストラクタ
  public:
	AView_TextViewHSeparator( const AWindowID inWindowID, const AControlID inID );
	virtual ~AView_TextViewHSeparator();
  private:
	void					NVIDO_Init();//#92
	void					NVIDO_DoDeleted();//#92
	
	//<インターフェイス>
	
	//情報取得
  private:
	AViewType				NVIDO_GetViewType() const {return kViewType_TextViewHSeparator;}
	
	//<イベント処理>
  private:
	ABool					EVTDO_DoMouseDown( const ALocalPoint& inLocalPoint, const AModifierKeys inModifierKeys, const ANumber inClickCount );
	ABool					EVTDO_DoMouseMoved( const ALocalPoint& inLocalPoint, const AModifierKeys inModifierKeys );
	void					EVTDO_DoMouseLeft( const ALocalPoint& inLocalPoint );
	void					EVTDO_DoDraw();
	void					EVTDO_DoMouseWheel( const AFloatNumber inDeltaX, const AFloatNumber inDeltaY, const AModifierKeys inModifierKeys, const ALocalPoint inLocalPoint ) {}//win 080706
	ABool					EVTDO_DoTextInput( const AText& inText, //#688 const AOSKeyEvent& inOSKeyEvent, 
							const AKeyBindKey inKeyBindKey, const AModifierKeys inModifierKeys, const AKeyBindAction inKeyBindAction,
							ABool& outUpdateMenu ) {return false;}
	ACursorType				EVTDO_GetCursorType( const ALocalPoint& inLocalPoint, const AModifierKeys inModifierKeys ) {return kCursorType_ResizeUpDown;}
	
	void					DoMouseTrack( const ALocalPoint& inLocalPoint );
//#688 #if IMPLEMENTATION_FOR_WINDOWS
	void					EVTDO_DoMouseTracking( const ALocalPoint& inLocalPoint, const AModifierKeys inModifierKeys );
	void					EVTDO_DoMouseTrackEnd( const ALocalPoint& inLocalPoint, const AModifierKeys inModifierKeys );
//#688 #endif
	
	//Drag通知先ウインドウ設定
  public:
	void					SPI_SetTargetWindowID( const AWindowID inTargetWindowID ) { mTargetWindowID = inTargetWindowID; }
  private:
	AWindowID							mTargetWindowID;
	
	//線の位置
  public:
	void					SPI_SetLinePosition( const ASeparatorLinePosition inPosition );
  private:
	ASeparatorLinePosition				mLinePosition;
	ANumber					GetLineOffset() const;
	
	//
	AMouseTrackingMode		mMouseTrackingMode;
	//#688 ABool					mMouseTrackByLoop;
	AGlobalPoint			mPreviousMouseGlobalPoint;
	ABool					mHover;
};

