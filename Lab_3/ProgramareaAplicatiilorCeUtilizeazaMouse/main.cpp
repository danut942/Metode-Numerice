// -----------------   LISTING 1 -------------------------------//

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

// Aceasta functie decrementeaza flagul de vizibilitate. Cat timp flagul este > 0, cursorul este vizibil.
// Deoarece aceasta functie decrementeaza flagul de vizibilitate, functie MouseShow()(1h) trebuie apelata de atatea ori de
// cate a fost apelata functia MouseHide()(2h)(mai putin in cazul in care se utilizeaza scurtatura de resetare, care
// reseteaza flagul de vizibilitate la -1).
// ATENTIE: Procesul invers nu este valabil (functia MouseHide()) actioneaza intotdeauna, indiferent de numarul
// anterior de apeluri ale functiei MouseShow()).

void MouseHide()
{
    int ax=2, bx, cx, dx, bp, si, di, ds, es, flags;
    MOUSE(ax, bx, cx, dx, bp, si, di, ds, es, flags);
}

// Aceasta functie este similara lui MouseInit().
void MouseShow()
{
    int ax=2, bx, cx, dx, bp, si, di, ds, es, flags;
    MOUSE(ax, bx, cx, dx, bp, si, di, ds, es, flags);
}

// Functia returneaza pozitia curenta a cursorului si starea curenta a butoanelor: bitul 0 setat pentru buton stang
// apasat, bitul 1 setat pentru buton drept apasat, iar la Logitech si Mouse Systems bitul 2 setat pentru butonul din
// mijloc apasat. A se observa apelul prin referinta al fnuctiei.

void MouseData (int& but, int& x, int& y)
{
    int ax=3, bx, cx, dx, bp, si, di, ds, es, flags;
    MOUSE(ax, bx, cx, dx, bp, si, di, ds, es, flags);
    but=bx; x=cx; y=dx;
}

void MouseMove(int x, int y)
{
    int ax=4,bx,cx=x,dx=y,bp,si,di,ds,es,flags;
    MOUSE(ax, bx, cx, dx, bp, si, di, ds, es, flags);
}

void MouseCursSet()
{
    int ax=9,bx,cx,dx=1,bp,si,di,ds,es,flags;
    MOUSE(ax, bx, cx, dx, bp, si, di, ds, es, flags);
}

// -----------------   LISTING 2 -------------------------------//

clrscr();
init_graph();

maxx=getmaxx();
maxy=getmaxy();

setcolor(getmaxcolor());
setfillpattern(pattern, getmaxcolor());

bar(0,0,maxx,maxy); // genereaza o pata alba la extrema dreapta a primului cursor superior

MouseInit();


MouseHide();

setbkcolor(1);

afis_ecran();

MouseShow();
activ();

// -----------------   LISTING 3 -------------------------------//

void activ()
{
    mesaj_screen();
    reia:
        if(kbhit()) goto out; // iesire prin apasarea unei taste
        f=0;

        MouseData(b,x,y);
        if((x>(x0bar)) && (x<x0bar+10) && (y>y0bar) && (y<y1bar) && (b==1))
            f=0;

        MouseData(b,x,y);
        if(b==0) goto reia;
        else if(b==1) {
            tstbuton();
            if(b==2) goto out;
        }
        else {
            MouseData(b,x,y);
            if (b==2) goto out;
        }
        loop:
            MouseData(b,x,y);
            param_cursor();
            if(b==0) goto reia;
            else goto loop;
            out:
                ;
}

// -----------------   LISTING 4 -------------------------------//

// Testul butoanelor
int tstbuton();
{

    int b=0,x,y;
    MouseData(b,x,y);
    if(f==0)
    {
        if(b==1)
        {
            if ((y>ymin1) && (y<ymax1))
            {
                if((x>x1min) && (x<x1max){
                   proced_1();
                }
                if((x>x2min) && (x<x2max){
                   proced_2();
                }
                if((x>x3min) && (x<x3max){
                   proced_3();
                }
                if((x>x4min) && (x<x4max){
                   proced_4();
                }
                if((x>x5min) && (x<x5max){
                   proced_5();
                }
                if((x>x6min) && (x<x6max){
                   proced_6();
                }
                if((x>x7min) && (x<x7max){
                   proced_7();
                }
                if((x>x8min) && (x<x8max){
                   proced_8();
                }
            }
            if((y>ymin0) && (y<ymax0)
        }
    }
}

// -----------------   LISTING 5 -------------------------------//

// Parametri cursoarelor
// ---------------------
void param_cursor()
{
    i1s=48;
    char *ch;
    setcolor(0);
    outtextxy(116,3,ch);
    setcolor(15);
    i1s+=t;
    *ch=i1s;
    outtextxy(116,3,ch);
}
void cursor_activ();
{
    cursor();
iar:
    agata();
    if(kbhit()) goto pas;
    MouseData(b,x,y);
    if((x<x0bar-10) || (x>x0bar+10) || (y<y0bar) || (y>y1bar)) goto pas;
    param_cursor();
    xtmp=x;
    goto iar;
    pas:
        ;
}

// -----------------   LISTING 6 -------------------------------//

// Randul 1 de butoane

void proced_1()
{
    MouseHide();
    delbuton1();
    buton_1_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
    }
    delbuton1();
    buton_1_1();
    cadru_screen_no_del(); //Rutina Efectiva
    MouseShow();
}

void proced_2()
{
    MouseHide();
    delbuton2();
    buton_2_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
    }
    delbuton2();
    buton_2_1();
    test_afisare_screen(); // Rutina efectiva
    MouseShow();
}

void proced_3()
{
    MouseHide();
    delbuton3();
    buton_3_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
        display();
    }
    delbuton3();
    buton_3_1();
    // display(); // Rutina efectiva
    MouseShow();
}

void proced_4()
{
    MouseHide();
    delbuton4();
    buton_4_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
    }
    delbuton4();
    buton_4_1();
    afis_a(); // Rutina efectiva
    MouseShow();
}

void proced_5()
{
    MouseHide();
    delbuton5();
    buton_5_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
    }
    delbuton5();
    buton_5_1();
    sterg_tot; // Rutina efectiva
    MouseShow();
}

void proced_6()
{
    MouseHide();
    delbuton6();
    buton_6_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
        no_display();
    }
    delbuton6();
    buton_6_1();
    //no_displaay(); // Rutina efectiva
    MouseShow();
}

void proced_7()
{
    MouseHide();
    delbuton7();
    buton_7_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
    }
    delbuton7();
    buton_7_1();
    test_afisare_screen_del(); // Rutina efectiva
    MouseShow();
}

int proced_8()
{
    MouseHide();
    delbuton8();
    buton_8_2();
    MouseData(b,x,y);
    while(b==1)
    {
        MouseData(b,x,y);
    }
    delbuton8();
    buton_8_1();
    return b=2; // Rutina efectiva
    MouseShow();
}

