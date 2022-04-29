//Fisierul header "mouseg.h" pentru lucrul cu mouse-ul in modul grafic
//--------------------------------------------------------------------

// Strctura REGPACK (din <dos.h>) contine mai multe campuri ce reprezinta valorile pasate sau returnate de un
// apel al functiei intr() (aceasta functie se afla tot in <dos.h>). Fiecare camp reprezinta unuldin registrii
// microprocesorului. Functia intr() permite apelul de intreruperi DOS pentru procesoarele 80x86. Inrudite cu
// intr() sunt int86 si in 86x, acestea lucrand cu reuniuni REGS.

// Structura REGPACK este:

// The structure of the values passed to and returned by the intr function call

// struct REGPACK
// {
//   unsigned r_ax, r_bx, r_cs, r_dx;
//   unsigned r_bp, r_si, r_di;
//   unsigned r_ds, r_es, r_flags
// };

#include<dos.h>

//Functia aceasta foloseste structura predefinita in <dos.h> cu numele REGPACK.
void MOUSE(int &ax, int &bx, int&cx, int &dx, int&bp, int &si, int &di, int &ds, int &es, int &flags)
{
    struct REGPACK regs;
    regs.r_ax=ax; regs.r_bx=bx; regs.r_cx=cx; regs.r_dx=dx;
    regs.r_bp=bp; regs.r_si=si; regs.r_di=di;
    regs.r_ds=ds; regs.r_es=es; regs.r_flags=flags;
    intr(0x33, &regs);

    ax=regs.r_ax;
    bx=regs.r_bx;
    cx=regs.r_cx;
    dx=regs.r_dx;

    bp=regs.r_bp;
    si=regs.r_si;
    di=regs.r_di;

    ds=regs.r_ds;
    es=regs.r_es;
    flags=regs.r_flags;
}

// Functie de initializare a flagului de vizibilitate a cursorului (implicit -1). Aceasta functie incrementeaza flagul de vizibilitate
void MouseInit()
{
    int ax=1,bx,cx,dx,bp,si,di,ds,es,flags;
    MOUSE(ax,bx,cx,dx,bp,si,di,ds,es,flags);
}

// Aceasta functie
