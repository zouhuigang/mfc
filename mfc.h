#include<afxwin.h> //mfcͷ�ļ�

class MyApp:public CWinApp //CWinappӦ�ó�����
{
public:
	virtual BOOL InitInstance();//�������

};


class MyFrame:public CFrameWnd //���ڿ����
{
public:
	MyFrame();//���캯��

	//�����꣬ �ṩ��Ϣӳ�����
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT,CPoint);
	afx_msg void OnChar(UINT, UINT, UINT);
	afx_msg void OnPaint();

private:

};