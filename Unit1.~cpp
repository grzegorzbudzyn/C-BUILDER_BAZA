//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
  Baza = new TDataBase();
  FileSaveName = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DodajWiersz1Click(TObject *Sender)
{
    StringGrid1->RowCount++;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UsuWiersz1Click(TObject *Sender)
{
    StringGrid1->RowCount--;    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DodajKolumn1Click(TObject *Sender)
{
      StringGrid1->ColCount++;  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UsuKolumn1Click(TObject *Sender)
{
         StringGrid1->ColCount--;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::NagwkiKolumn1Click(TObject *Sender)
{
        Form2->ShowModal();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
Baza->RefreshBase();

  for(int i = 0; i < StringGrid1->RowCount; i++){
    for(int j = 0; j < StringGrid1->ColCount; j++){
      StringGrid1->Cells[j][i] = "";
                               }
                                 }

  StringGrid1->RowCount = 2;
  StringGrid1->ColCount = 2;
  FileSaveName = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Otwrz1Click(TObject *Sender)
{
 if(OpenDialog1->Execute())
    {
      Baza->RefreshBase();
      Baza->LoadFromFile(OpenDialog1->FileName, StringGrid1);
      FileSaveName = OpenDialog1->FileName;
      StringGrid1->Col = (StringGrid1->Col == 0) ? 1 : 0;
    }       
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
            if(FileSaveName.IsEmpty())
    {
      if(SaveDialog1->Execute())
        Baza->SaveToFile(SaveDialog1->FileName, StringGrid1);
    }
  else Baza->SaveToFile(FileSaveName, StringGrid1);
  FileSaveName = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
        if(SaveDialog1->Execute())
    Baza->SaveToFile(SaveDialog1->FileName, StringGrid1);

  FileSaveName = SaveDialog1->FileName;  
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
       delete Baza; 
}


