#include "mfc.h"

MyApp app;//全局应用程序对象，有且仅有一个

BOOL MyApp::InitInstance(){

	//创建窗口
	MyFrame  *frame = new MyFrame();

	//显示和更新
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	//保存指向应用窗口的指针,将自定义的frame注册进windows指针.属性->常规->MFC的使用->在共享 DLL 中使用 MFC
	m_pMainWnd = frame;

	return TRUE;//返回正常初始化
}

//分界宏
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	//消息宏
	ON_WM_LBUTTONDOWN() //鼠标左键按下
	ON_WM_CHAR() //键盘
	ON_WM_PAINT() //绘图宏

END_MESSAGE_MAP()


//构造函数
MyFrame::MyFrame(){

	Create(NULL,TEXT("mfc"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point){

	/*TCHAR buf[1024];//在mfc中的字符数组
	wsprintf(buf,TEXT("x=%d,y=%d"),point.x,point.y);

	MessageBox(buf);*/

	//mfc中的字符串, CString

	CString str;
	str.Format(TEXT("x=%d,,,,y=%d"),point.x,point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT){
	CString str;
	str.Format(TEXT("按下了%c键"),key);
	MessageBox(str);
}

void  MyFrame::OnPaint(){
	CPaintDC dc(this);//画家类,在文档CDC里找其他能画的图形
	dc.TextOutW(100,200,TEXT("蓝蓝的小火苗"));

	//画椭圆
	dc.Ellipse(10,10,100,100);

	//多字节转为宽字节,加个L
	//TEXT会自动适应编码的转换
	//TCHAR 自适应编码的转换
	//MessageBox(L"aaaa");

	//统计字符串长度
	int num = 0;
	char *p = "aaaaa";
	num = strlen(p);

	//统计宽字节
	wchar_t * p2 = L"bbbb";
	num = wcslen(p2);

	//char * 和CString之间的转换
	//char* -> CString
	char *p3 = "ccc";
	CString str = CString(p3);

	//CString -> char *
	CStringA tmp;
	tmp = str;
	char * pp = tmp.GetBuffer();

	//CString转c++ string是无法直接转换的,需要char作为中间转换
}

//老外1字符对应1字节和多字节
//中文 1字符对应多个字节 宽字节 Unicode utf-8 3个 GBK 2个
