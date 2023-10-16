#include "standarLibrary.h"

void pausa () {
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore();
}

void timeStop(int Milsec) {
    Sleep(static_cast<DWORD>(Milsec));
}

void limpiaBuffer (void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void gotoxy (int x,int y) {
    printf("%c[%d;%df",0x1B,y,x);
}

void setborder (int altura, int anchura) {
    int columnaX, FilaY;
    for (columnaX = 1; columnaX <= anchura; columnaX++) {
        gotoxy(columnaX, 0);
        putchar(char(223));
        gotoxy(columnaX, altura);
        putchar(char(220));
    }
    for (FilaY = 1; FilaY <= altura; FilaY++) {
        gotoxy(0, FilaY);
        putchar(char(219));
        gotoxy(anchura, FilaY);
        putchar(char(219));
    }
}

void AltEnter() {
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
    return;
}