#include "mfc.h"

MyApp app;//ȫ��Ӧ�ó���������ҽ���һ��

BOOL MyApp::InitInstance(){

	//��������
	MyFrame  *frame = new MyFrame();

	//��ʾ�͸���
	frame->ShowWindow(SW_SHOWNORMAL);
	frame->UpdateWindow();

	//����ָ��Ӧ�ô��ڵ�ָ��,���Զ����frameע���windowsָ��.����->����->MFC��ʹ��->�ڹ��� DLL ��ʹ�� MFC
	m_pMainWnd = frame;

	return TRUE;//����������ʼ��
}

//�ֽ��
BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
	//��Ϣ��
	ON_WM_LBUTTONDOWN() //����������
	ON_WM_CHAR() //����
	ON_WM_PAINT() //��ͼ��

END_MESSAGE_MAP()


//���캯��
MyFrame::MyFrame(){

	Create(NULL,TEXT("mfc"));
}

void MyFrame::OnLButtonDown(UINT, CPoint point){

	/*TCHAR buf[1024];//��mfc�е��ַ�����
	wsprintf(buf,TEXT("x=%d,y=%d"),point.x,point.y);

	MessageBox(buf);*/

	//mfc�е��ַ���, CString

	CString str;
	str.Format(TEXT("x=%d,,,,y=%d"),point.x,point.y);
	MessageBox(str);
}

void MyFrame::OnChar(UINT key, UINT, UINT){
	CString str;
	str.Format(TEXT("������%c��"),key);
	MessageBox(str);
}

void  MyFrame::OnPaint(){
	CPaintDC dc(this);//������,���ĵ�CDC���������ܻ���ͼ��
	dc.TextOutW(100,200,TEXT("������С����"));

	//����Բ
	dc.Ellipse(10,10,100,100);
}