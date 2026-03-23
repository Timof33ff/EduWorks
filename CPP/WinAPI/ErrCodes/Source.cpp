#include "Header.h"

int Err;

LPCWSTR fn_lpcwstr[4]{
				L"FileNotFound.txt",
				L"Path\\PathNotFound.txt"
};

const char fn_FNF[32] = "FileNotFound.txt";
const char fn_PNF[32] = "Path\\PathNotFound.txt";

void WinAPIStyle()
{
	LPWSTR errmsg;
	HANDLE H;

	cout << " WinAPI style open file: " << endl;

	SetLastError(0);
	H = CreateFile(	fn_lpcwstr[0], GENERIC_READ,
					FILE_SHARE_READ, 0,
					OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
					NULL); // открываем файл
	Err = GetLastError();  // получаем код ошибки

	errmsg = getErrCode(Err);


	CloseHandle(H);
}

void CStyle()
{
	LPWSTR errmsg;
	FILE* F;

	cout << " C style open file: " << endl;

	SetLastError(0);
	fopen_s(&F, fn_FNF, "rt"); // открываем файл
	Err = GetLastError();      // получаем код ошибки

	errmsg = getErrCode(Err);

	_fcloseall();
}

void CPPStyle()
{
	LPWSTR errmsg;

	cout << " CPP style open file: " << endl;

	SetLastError(0);

	fstream F;
	F.open(fn_FNF); // открываем файл 
	Err = GetLastError(); // получаем код ошибки

	errmsg = getErrCode(Err);

	F.close();
}


