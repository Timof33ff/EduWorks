#include "main.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    hin = hInst;		 // ���������� ����������� ���������� ����������
    winclass();  	// ����������� ������ ���� ����������
    HWND winhandler = makeWin(); 	//�������� �������� ����
    ShowWindow(winhandler, SW_SHOW); 	// ����������� ���������� ����
    UpdateWindow(winhandler);
    messageprocess();				//������ ����� ��������� ���������
    return 0;
}


