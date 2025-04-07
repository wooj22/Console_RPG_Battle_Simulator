#include "ConsoleRenderer.h"
#include <stdio.h>

namespace ConsoleRenderer
{
    HANDLE hConsoleHandle;      // 초기 콘솔 창의 핸들

    int nScreenWidth = 60;       // 콘솔 창의 너비
    int nScreenHeight = 60;      // 콘솔 창의 높이
    int nScreenBufferSize = nScreenWidth * nScreenHeight;  // 콘솔 창의 스크린 버퍼 크기 (너비 * 높이)
    int nScreenBufferIndex = 0;  // 현재 사용 중인 스크린 버퍼의 인덱스 (0 또는 1)
    HANDLE hScreenBuffer[2];     // 콘솔 창에서 사용할 더블 버퍼링 스크린 버퍼 (2개)

    ///  콘솔 화면 초기화 (더블 버퍼링 설정)
    void ScreenInit()
    {
        // 현재 콘솔 핸들 get
        hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        // 콘솔창 크기 set
        COORD bufferSize = { nScreenWidth, nScreenHeight };
        SMALL_RECT windowSize = { 0, 0, nScreenWidth - 1, nScreenHeight - 1 };

        SetConsoleScreenBufferSize(hConsoleHandle, bufferSize);
        SetConsoleWindowInfo(hConsoleHandle, TRUE, &windowSize);

        // 더블 버퍼 생성
        hScreenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        hScreenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        // 더블 버퍼 사이즈 set
        SetConsoleScreenBufferSize(hScreenBuffer[0], bufferSize);
        SetConsoleScreenBufferSize(hScreenBuffer[1], bufferSize);
        SetConsoleWindowInfo(hScreenBuffer[0], TRUE, &windowSize);
        SetConsoleWindowInfo(hScreenBuffer[1], TRUE, &windowSize);

        // 기본 콘솔 및 생성된 스크린 버퍼의 커서를 숨김
        CONSOLE_CURSOR_INFO cursorInfo = { 0, };
        cursorInfo.bVisible = FALSE;
        cursorInfo.dwSize = 1;

        SetConsoleCursorInfo(hConsoleHandle, &cursorInfo);
        SetConsoleCursorInfo(hScreenBuffer[0], &cursorInfo);
        SetConsoleCursorInfo(hScreenBuffer[1], &cursorInfo);
    }

    /// 화면 전환 (더블 버퍼링을 이용한 화면 갱신)
    void ScreenFlipping()
    {
        SetConsoleActiveScreenBuffer(hScreenBuffer[nScreenBufferIndex]);
        nScreenBufferIndex = (nScreenBufferIndex + 1) % 2;
    }

    /// brief 현재 사용 중인 버퍼를 공백 문자(' ')로 채워 화면을 지움
    void ScreenClear()
    {
        COORD Coor = { 0, 0 };
        DWORD dw;
        FillConsoleOutputCharacter(hScreenBuffer[nScreenBufferIndex], ' ', nScreenBufferSize, Coor, &dw);
    }

    /// 콘솔 스크린 버퍼 해제 (프로그램 종료 시 호출)
    void ScreenRelease()
    {
        CloseHandle(hScreenBuffer[0]);
        CloseHandle(hScreenBuffer[1]);
    }

    /// 문자(char) 출력
    bool ScreenDrawChar(int x, int y, char ch, WORD attr)
    {
        COORD cdPos;
        BOOL bRval = FALSE;
        DWORD dwCharsWritten;

        cdPos.X = x;
        cdPos.Y = y;

        bRval = FillConsoleOutputCharacterA(hScreenBuffer[nScreenBufferIndex], ch, 1, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputCharacter()\n");

        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, 1, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputAttribute()\n");

        return bRval;
    }

    /// 문자열(char*) 출력
    bool ScreenDrawString(int x, int y, const char* pStr, WORD attr)
    {
        COORD cdPos;
        BOOL bRval = FALSE;
        DWORD dwCharsWritten;

        cdPos.X = x;
        cdPos.Y = y;

        DWORD nNumberOfBytesToWrite = (DWORD)strlen(pStr);

        // 문자열 출력
        WriteConsoleOutputCharacterA(hScreenBuffer[nScreenBufferIndex], pStr, nNumberOfBytesToWrite, cdPos, &dwCharsWritten);

        // 문자열 속성 설정
        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, nNumberOfBytesToWrite, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputAttribute()\n");

        return bRval;
    }

    // 문자(wchar_t) 출력
    bool ScreenDrawChar(int x, int y, wchar_t ch, WORD attr)
    {
        COORD	cdPos;
        BOOL	bRval = FALSE;
        DWORD	dwCharsWritten;
        cdPos.X = x;
        cdPos.Y = y;

        bRval = FillConsoleOutputCharacterW(hScreenBuffer[nScreenBufferIndex], ch, 1, cdPos, &dwCharsWritten);
        if (bRval == false) OutputDebugStringA("Error, FillConsoleOutputCharacter()\n");

        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, 1, cdPos, &dwCharsWritten);
        if (bRval == false) OutputDebugStringA("Error, FillConsoleOutputAttribute()\n");
        return bRval;
    }

    // 문자열(wchar_t*) 출력
    bool ScreenDrawStringW(int x, int y, const wchar_t* pStr, WORD attr)
    {
        COORD cdPos;
        BOOL bRval = FALSE;
        DWORD dwCharsWritten;

        cdPos.X = x;
        cdPos.Y = y;

        DWORD nNumberOfCharsToWrite = (DWORD)wcslen(pStr);

        WriteConsoleOutputCharacterW(hScreenBuffer[nScreenBufferIndex], pStr, nNumberOfCharsToWrite, cdPos, &dwCharsWritten);

        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, nNumberOfCharsToWrite * 2, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputAttribute()\n");

        return bRval;
    }

    /// 콘솔 전체 문자 속성 변경
    bool ScreenSetAttributes(WORD attr)
    {
        COORD cdPos = { 0, 0 };
        bool bRval = FALSE;
        DWORD dwCharsWritten;

        // 콘솔 전체 속성 변경
        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, nScreenBufferSize, cdPos, &dwCharsWritten);
        if (!bRval)
        {
            printf("Error, FillConsoleOutputCharacter()\n");
        }

        return bRval;
    }

    /// 현재 콘솔 너비 반환
    int ScreenWidth()
    {
        return nScreenWidth;
    }

    /// 현재 콘솔 높이 반환
    int ScreenHeight()
    {
        return nScreenHeight;
    }
};