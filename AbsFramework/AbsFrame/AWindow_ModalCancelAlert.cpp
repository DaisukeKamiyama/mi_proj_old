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

AWindow_ModalCancelAlert

*/

#include "stdafx.h"

#include "AWindow_ModalCancelAlert.h"

const AControlID	kOKButton		= 10001;
const AControlID	kCancelButton	= 10002;
const AControlID	kMessage1		= 10003;
const AControlID	kMessage2		= 10004;

#pragma mark ===========================
#pragma mark [クラス]AWindow_ModalCancelAlert
#pragma mark ===========================
//OKCancel子ウインドウ

/**
コンストラクタ
*/
AWindow_ModalCancelAlert::AWindow_ModalCancelAlert() : AWindow(), mCanceled(false)
{
}

/**
デストラクタ
*/
AWindow_ModalCancelAlert::~AWindow_ModalCancelAlert()
{
}

/**
ウインドウ生成
*/
void	AWindow_ModalCancelAlert::NVIDO_Create( const ADocumentID inDocumentID )
{
	NVI_SetFixTitle(true);
	NVM_CreateWindow("AbsFrameworkCommonResource/ModalCancelAlert");
	NVI_SetDefaultOKButton(kOKButton);
	NVI_SetDefaultCancelButton(kOKButton);
	NVI_RegisterToFocusGroup(kOKButton,true);//#353
}

/**
設定＋ウインドウ表示
*/
ABool	AWindow_ModalCancelAlert::SPNVI_Show( const AText& inMessage1, const AText& inMessage2, const AText& inOKButtonText, const AText& inCancelButtonText )
{
	//
	mCanceled = false;
	//
	NVI_SetDefaultTitle(inMessage1);
	NVI_SetControlText(kMessage1,inMessage1);
	NVI_SetControlText(kMessage2,inMessage2);
	NVI_SetControlText(kOKButton,inOKButtonText);
	NVI_SetControlText(kCancelButton,inCancelButtonText);
	NVI_Show();
	//モーダル開始（モーダル終了までブロックする）
	NVI_RunModalWindow();
	//ウインドウを閉じる
	NVI_Close();
	//
	return (mCanceled==false);
}

/**
コントロールのクリック時のコールバック
*/
ABool	AWindow_ModalCancelAlert::EVTDO_Clicked( const AControlID inID, const AModifierKeys inModifierKeys )
{
	ABool	result = false;
	switch(inID)
	{
	  case kOKButton:
		{
			NVI_StopModalSession();
			result = true;
			break;
		}
	  case kCancelButton:
		{
			NVI_StopModalSession();
			result = true;
			mCanceled = true;
			break;
		}
	}
	return result;
}

/**
ウインドウ閉じるボタン
*/
void	AWindow_ModalCancelAlert::EVTDO_DoCloseButton()
{
	NVI_StopModalSession();
}


