#include<afxwin.h> //mfc头文件

class MyApp:public CWinApp //CWinapp应用程序类
{
public:
	virtual BOOL InitInstance();//程序入口

};


class MyFrame:public CFrameWnd //窗口框架类
{
public:
	MyFrame();//构造函数

	//声明宏， 提供消息映射机制
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT,CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();

private:

};