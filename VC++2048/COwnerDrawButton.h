/**
 * \file OwnerDrawButton.h
 *
 * \brief 自绘按钮的实现类
 *
 * \author
 */

#pragma once
#include "framework.h"
#include <iostream>
class COwnerDrawButton
{
public:
	COwnerDrawButton(LPCWSTR,);
	~COwnerDrawButton(void);
private:
	COwnerDrawButton(const COwnerDrawButton& OtherOwnerDrawButton);
	COwnerDrawButton& operator=(const COwnerDrawButton& OtherOwnerDrawButton);
public:
	/**
	 * \brief 刷新控件
	 */
	bool InvalidataCtrl();
public:
	/**
	 * \brief 创建按钮
	 * \param lpszCaption 参数，为按钮的显示文本
	 * \param lpszImage 参数，为按钮的位图路径
	 * \param rect 参数，为按钮的坐标
	 * \param hParentWnd 参数，为按钮的父窗口句柄
	 * \param nID 参数，为按钮的控件ID
	 * \param lpszImage 参数，为按钮控件一般状态位图路径
	 */
	BOOL Create(LPCSTR lpszCaption, const RECT& rect, HWND hParentWnd, \
		UINT nID, LPCWSTR lpszImage, HINSTANCE hInstance);
	/**
	 * \brief 绘制按钮
	 * \param hDC 参数，为按钮的绘制用DC句柄
	 */
	void Draw(HDC hDC);
	void DrawFocusRect(HDC hDC, RECT& rcWnd);
	/**
	 * \brief 设置按钮
	 * \param fEnable 参数，为设置按钮是否可用
	 */
	void EnableButton(bool fEnable);

	void OnLbuttonDown(WPARAM wParam, LPARAM lParam);
	void OnLbuttonUp(WPARAM wParam, LPARAM lParam);
	void OnLbuttonDBClick(WPARAM wParam, LPARAM lParam);
	void OnMouseMove(WPARAM wParam, LPARAM lParam);
	void OnMouseLeave(WPARAM wParam, LPARAM lParam);
private:
	/**
	 * \brief 按钮消息回调函数
	 */
	static LRESULT CALLBACK ButtonProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	enum STATE
	{
		STATE_UP,
		STATE_DOWN,
		STATE_FOCUS,
		STATE_DISABLE
	};
	WNDPROC     m_OldProc;//!按钮的默认消息回调函数
	HWND        m_hWnd;      //!此按钮的句柄
	void   ShowButton();
	void   HideButton();
private:
	HBITMAP     m_hFourStateBitmap; //!按钮的普通四状态位图
	BOOL        m_fRoundButton;  //!当前控件类型，TRUE为按钮类型，FALSE为一般的显示位图控件
	BOOL        m_fTrackMouse;
	int         m_nButtonState;//!按钮的当前状态
	HFONT       m_hFont;//!控件字体
	LPCWSTR     className;

};


