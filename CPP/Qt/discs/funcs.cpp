#include<funcs.h>

/*****************************************************************
*
* Вызов нижереализованной функции возвращает строку, содержащую подробную
* информацию обо всех обнаруженных на устройстве дисках.
* DiscsInfo() опишет для каждого обнаруженного диска его тип, количество
* свободного диского пространства, название диска, его серийный номер,
* максимальный размер имени файлов и каталогов и т.п.
*
******************************************************************/

string DiscsInfo()
{
    stringstream ans;
    const DWORD nBufferLength = 256;
    CHAR Buff[nBufferLength];


    DWORD k = 0;
    LPCSTR driveType;
    DWORD type;

    const DWORD res = GetLogicalDriveStringsA(nBufferLength, Buff);

    if (res == 0) cout << "Error!" << endl;
    else if (res > nBufferLength) cout << "Buff length is`t enough!" << endl;
    else cout << res/4 << " disks found." << endl;

    CHAR buf[4];

    //for getDiskFreeSpaceEx(...);
    ULARGE_INTEGER lpFreeBytesAvailableToCaller;
    ULARGE_INTEGER lpTotalNumberOfBytes;
    ULARGE_INTEGER lpTotalNumberOfFreeBytes;

    //for getVolumeInformation(...);

    CHAR NameBuffer[256];
    CHAR SysNameBuffer[256];
    DWORD VSNumber;
    DWORD MCLength;

    /*                            */
    /*     End of initialize      */
    /*                            */

    ans << " Drives names :\n";
    for (DWORD i = 0; i < res; i += 4)
    {
        ans << "{";
        for (DWORD j = i; j < (i + 4); j++)
        {
            ans << char(Buff[j]);
            buf[k++] = Buff[j];
        }

        type = GetDriveTypeA(buf);        // Получаем тип диска
        driveType = catchDriveType(type);

            if (GetDiskFreeSpaceExA(      // Получаем информацию о свободном пространстве на диске
                buf,
                &lpFreeBytesAvailableToCaller,
                &lpTotalNumberOfBytes,
                &lpTotalNumberOfFreeBytes
                ))
            {
            ans << "}\t||\t" << driveType << "\t||\n"
                << "\tFree drive`s space for this app :\t"
                << lpFreeBytesAvailableToCaller.QuadPart / 1073741824 << "\tgigabytes\n"

                << "\tTotal drive`s space :\t"
                << lpTotalNumberOfBytes.QuadPart / 1073741824 << "\tgigabytes\n"

                << "\tFree drive`s space :\t"
                << lpTotalNumberOfFreeBytes.QuadPart / 1073741824 << "\tgigabytes\n"
                << "\n";
            }

            if (GetVolumeInformationA( // Получаем информацию о диске
                buf,
                NameBuffer,
                sizeof(NameBuffer),
                &VSNumber,
                &MCLength,
                NULL,
                SysNameBuffer,
                sizeof(SysNameBuffer)
                ))
            {
            ans << "\tDrive`s name :\t" << NameBuffer << "\n"
                << "\tFilesystem name :\t" << SysNameBuffer << "\n"
                << "\tSerial volume number :\t" << VSNumber << "\n"
                << "\tMax filename size :\t" << MCLength << "\n\n";
            }
        k = 0;
    }
    return ans.str();
}

LPCSTR catchDriveType(DWORD type)
{
    for (DWORD i = 0; i < 8; i++)
    {
        if (type == DriveTypeFlags[i].type)
        {
            //cout << DriveTypeFlags[i].name << endl;
            return DriveTypeFlags[i].name;
        }
    }
    return NULL;
}
