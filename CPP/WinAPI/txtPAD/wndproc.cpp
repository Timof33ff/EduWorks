#include "main.h"

LONG WINAPI WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{                  // handle to device context 
    TEXTMETRIC tm;             // structure for text metrics 
    static DWORD dwCharX;      // average width of characters 
    static DWORD dwCharY;      // height of characters 
    static DWORD dwClientX;    // width of client area 
    static DWORD dwClientY;    // height of client area 
    static DWORD dwLineLen;    // line length 
    static DWORD dwLines;      // text lines in client area 
    static int nCaretPosX = 0; // horizontal position of caret 
    static int nCaretPosY = 0; // vertical position of caret 
    static int nCharWidth = 0; // width of a character 
    static int cch = 0;        // characters in buffer 
    static int nCurChar = 0;   // index of current character 
    static PTCHAR pchInputBuf; // input buffer 
    int i, j;                  // loop counters 
    int cCR = 0;               // count of carriage returns 
    int nCRIndex = 0;          // index of last carriage return 
    int nVirtKey;              // virtual-key code 
    TCHAR szBuf[128];          // temporary buffer 
    TCHAR ch;                  // current character  
    RECT rc;                   // output rectangle for DrawText 
    SIZE sz;                   // string dimensions 
    COLORREF crPrevText;       // previous text color 
    COLORREF crPrevBk;         // previous background color
    size_t* pcch = nullptr;
    //HRESULT hResult;

    switch (msg)
    {
    case WM_CREATE:

        // Get the metrics of the current font. 

        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        ReleaseDC(hwnd, hdc);

        // Save the average character width and height. 

        dwCharX = tm.tmAveCharWidth;
        dwCharY = tm.tmHeight;

        // Allocate a buffer to store keyboard input. 

        pchInputBuf = (LPTSTR)GlobalAlloc(GPTR,
            BUFSIZE * sizeof(TCHAR));
        return 0;

    case WM_SIZE:

        // Save the new width and height of the client area. 

        dwClientX = LOWORD(lParam);
        dwClientY = HIWORD(lParam);

        // Calculate the maximum width of a line and the 
        // maximum number of lines in the client area. 

        dwLineLen = dwClientX - dwCharX;
        dwLines = dwClientY / dwCharY;
        break;


    case WM_SETFOCUS:

        // Create, position, and display the caret when the 
        // window receives the keyboard focus. 

        CreateCaret(hwnd, (HBITMAP)1, 0, dwCharY);
        SetCaretPos(nCaretPosX, nCaretPosY * dwCharY);
        ShowCaret(hwnd);
        break;

    case WM_KILLFOCUS:

        // Hide and destroy the caret when the window loses the 
        // keyboard focus. 

        HideCaret(hwnd);
        DestroyCaret();
        break;

    case WM_CHAR:
        // check if current location is close enough to the
        // end of the buffer that a buffer overflow may
        // occur. If so, add null and display contents. 
        if (cch > BUFSIZE - 5)
        {
            pchInputBuf[cch] = 0x00;
            SendMessage(hwnd, WM_PAINT, 0, 0);
        }
        switch (wParam)
        {
        case 0x08:  // backspace 
            pchInputBuf[cch] = NULL;
            return 0;
        case 0x0A:  // linefeed 
        case 0x1B:  // escape 
            MessageBeep((UINT)-1);
            return 0;

        case 0x09:  // tab 

            // Convert tabs to four consecutive spaces. 

            for (i = 0; i < 4; i++)
                SendMessage(hwnd, WM_CHAR, 0x20, 0);
            return 0;

        case 0x0D:  // carriage return 

            // Record the carriage return and position the 
            // caret at the beginning of the new line.

            pchInputBuf[cch++] = 0x0D;
            nCaretPosX = 0;
            nCaretPosY += 1;
            break;

        default:    // displayable character 

            ch = (TCHAR)wParam;
            HideCaret(hwnd);

            // Retrieve the character's width and output 
            // the character. 

            hdc = GetDC(hwnd);
            GetCharWidth32(hdc, (UINT)wParam, (UINT)wParam,
                &nCharWidth);
            TextOut(hdc, nCaretPosX, nCaretPosY * dwCharY,
                &ch, 1);
            ReleaseDC(hwnd, hdc);

            // Store the character in the buffer.

            pchInputBuf[cch++] = ch;

            // Calculate the new horizontal position of the 
            // caret. If the position exceeds the maximum, 
            // insert a carriage return and move the caret 
            // to the beginning of the next line. 

            nCaretPosX += nCharWidth;
            if ((DWORD)nCaretPosX > dwLineLen)
            {
                nCaretPosX = 0;
                pchInputBuf[cch++] = 0x0D;
                ++nCaretPosY;
            }
            nCurChar = cch;
            ShowCaret(hwnd);
            break;
        }
        SetCaretPos(nCaretPosX, nCaretPosY * dwCharY);
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:   // LEFT ARROW 

            // The caret can move only to the beginning of 
            // the current line. 

            if (nCaretPosX > 0)
            {
                HideCaret(hwnd);

                // Retrieve the character to the left of 
                // the caret, calculate the character's 
                // width, then subtract the width from the 
                // current horizontal position of the caret 
                // to obtain the new position. 

                ch = pchInputBuf[--nCurChar];
                hdc = GetDC(hwnd);
                GetCharWidth32(hdc, ch, ch, &nCharWidth);
                ReleaseDC(hwnd, hdc);
                nCaretPosX = max(nCaretPosX - nCharWidth,
                    0);
                ShowCaret(hwnd);
            }
            break;

        case VK_RIGHT:  // RIGHT ARROW 

            // Caret moves to the right or, when a carriage 
            // return is encountered, to the beginning of 
            // the next line. 

            if (nCurChar < cch)
            {
                HideCaret(hwnd);

                // Retrieve the character to the right of 
                // the caret. If it's a carriage return, 
                // position the caret at the beginning of 
                // the next line. 

                ch = pchInputBuf[nCurChar];
                if (ch == 0x0D)
                {
                    nCaretPosX = 0;
                    nCaretPosY++;
                }

                // If the character isn't a carriage 
                // return, check to see whether the SHIFT 
                // key is down. If it is, invert the text 
                // colors and output the character. 

                else
                {
                    hdc = GetDC(hwnd);
                    nVirtKey = GetKeyState(VK_SHIFT);
                    if (nVirtKey & SHIFTED)
                    {
                        crPrevText = SetTextColor(hdc,
                            RGB(255, 255, 255));
                        crPrevBk = SetBkColor(hdc,
                            RGB(0, 0, 0));
                        TextOut(hdc, nCaretPosX,
                            nCaretPosY * dwCharY,
                            &ch, 1);
                        SetTextColor(hdc, crPrevText);
                        SetBkColor(hdc, crPrevBk);
                    }

                    // Get the width of the character and 
                    // calculate the new horizontal 
                    // position of the caret. 

                    GetCharWidth32(hdc, ch, ch, &nCharWidth);
                    ReleaseDC(hwnd, hdc);
                    nCaretPosX = nCaretPosX + nCharWidth;
                }
                nCurChar++;
                ShowCaret(hwnd);
                break;
            }
            break;

        case VK_UP:
            nCaretPosX = 0;
            nCaretPosY -= 1;
            break;
        case VK_DOWN:   // DOWN ARROW 
            MessageBeep((UINT)-1);
            return 0;

        case VK_HOME:   // HOME 

            // Set the caret's position to the upper left 
            // corner of the client area. 

            nCaretPosX = nCaretPosY = 0;
            nCurChar = 0;
            break;

        case VK_END:    // END  

            // Move the caret to the end of the text. 

            for (i = 0; i < cch; i++)
            {
                // Count the carriage returns and save the 
                // index of the last one. 

                if (pchInputBuf[i] == 0x0D)
                {
                    cCR++;
                    nCRIndex = i + 1;
                }
            }
            nCaretPosY = cCR;

            // Copy all text between the last carriage 
            // return and the end of the keyboard input 
            // buffer to a temporary buffer. 

            for (i = nCRIndex, j = 0; i < cch; i++, j++)
                szBuf[j] = pchInputBuf[i];
            szBuf[j] = TEXT('\0');

            // Retrieve the text extent and use it 
            // to set the horizontal position of the 
            // caret. 

            hdc = GetDC(hwnd);
            //hResult = StringCchLength(szBuf, 128, pcch);
            //if (FAILED(hResult))
            //{
            //    // TODO: write error handler
            //}
            GetTextExtentPoint32(hdc, szBuf, *pcch, &sz);
            nCaretPosX = sz.cx;
            ReleaseDC(hwnd, hdc);
            nCurChar = cch;
            break;

        default:
            break;
        }
        SetCaretPos(nCaretPosX, nCaretPosY * dwCharY);
        break;

    case WM_PAINT:
        if (cch == 0)       // nothing in input buffer 
            break;

        hdc = BeginPaint(hwnd, &ps);
        HideCaret(hwnd);

        // Set the clipping rectangle, and then draw the text 
        // into it. 

        SetRect(&rc, 0, 0, dwLineLen, dwClientY);
        DrawText(hdc, pchInputBuf, -1, &rc, DT_LEFT);

        ShowCaret(hwnd);
        EndPaint(hwnd, &ps);
        break;

        // Process other messages. 

    case WM_DESTROY:
        PostQuitMessage(0);

        // Free the input buffer. 

        GlobalFree((HGLOBAL)pchInputBuf);
        UnregisterHotKey(hwnd, 0xAAAA);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return NULL;
}