#include "main.h"


int main(void) // ������� main() ���������� � ����� ��������� ������� � ������� ��� ������� �������
{
    hin = hInst;		 // ���������� ����������� ���������� ����������
    winclass();  	// ����������� ������ ���� ����������
    HWND winhandler = makeWin(); 	//�������� �������� ����
    ShowWindow(winhandler, SW_SHOW); 	// ����������� ���������� ����
    messageprocess();				//������ ����� ��������� ���������
    return 0;
}