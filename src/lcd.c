void Sleep_ (int intervalo)
{
  int i = 0;
  //1 loop = 200 us
        for(;i<intervalo;i++)
        {
        }
}
void inputOp()
{        //RS = 0
        //RS na  porta A bit 4
        //Enable porta A bit 0
        //00000000 -> 00000001-> 00000000  0->1->0
        PORTA = 0;
        Sleep_(25);
        PORTA = 1;
        Sleep_(25);
        PORTA = 0;
        Sleep_(25);
}
void inputDt()
{        //RS = 1
        //RS na  porta A bit 4
        //Enable porta A bit 0
        //00010000 -> 00010001-> 00010000 16->17->16
        PORTA = 16;
        Sleep_(25);
        PORTA = 17;
        Sleep_(25);
        PORTA = 16;
        Sleep_(25);
        PORTA = 0;
        Sleep_(25);
}
void ClearLcd()
{        //Comando de Clear
        PORTB = 1;
        InputOp();
        Sleep_(25);
}
void InitLcd()
{
 PORTB = 56;
 InputOp();
 Sleep_(25);
}
void OnOffLcd()
{
 PORTB = 15;
 InputOp();
 Sleep_(25);
}

void ChangeLineLcd(int line)
{
 if (line == 1)
 {
  PORTB = 0;
  InputOp();
  //OnOffLcd();

 }
 else if (line == 2)
 {
  PORTB = 192;
  InputOp();
  //OnOffLcd();
 }
}


void WriteLcd(char * Text,int line)
{
 int i;
 int total = strlen(Text);

 ChangeLineLcd(line);


 for( i=0; i < total;i++)
 {
  PORTB = Text[i];
  InputDt();
 }
}



void main()
{        //porta para saida
        TRISA = 0;
        TRISB = 0;
        //envia 0
        PORTA = 0;
        PORTB = 0;

        Sleep_(25);
        InitLcd();
        ClearLcd();
        OnOffLcd();

 WriteLcd("Marcelo Mariano",1);
 WriteLcd("Zilma Mariano",2);

}