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
//usuwanie wiersza
void __fastcall DeleteRow(TStringGrid *Grid, int ARow)
{
 if(ARow < Grid->FixedRows)
 {
  Application->MessageBox("Nie wybrano wiersza do usuniêcia", "Usuwanie wiersza", MB_OK | MB_ICONSTOP);
  return;
 }
 if(Grid->RowCount == Grid->FixedRows + 1)
 {
  int id = Application->MessageBox("Conajmniej jeden wiersz (nie licz¹c nag³ówka) musi pozostaæ w tabeli. "

           "Czy chcesz wyczyœciæ zawartoœæ komórek w tym wierszu?", "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
  if(id == ID_YES)
   for(int y = 0; y < Grid->ColCount; y++)
    Grid->Cells[y][ARow] = "";
  return;
 }

 int id = Application->MessageBox("Czy na pewno chcesz usun¹æ wybrany wiersz?\nOperacji nie bêdzie mo¿na cofn¹æ!",
          "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
 if(id == ID_YES)
 {
  for(int i = ARow; i <= Grid->RowCount - 1; i++)
  {
   for(int y = 0; y < Grid->ColCount; y++)
   {
    Grid->Cells[y][i] = Grid->Cells[y][i + 1];
    Grid->Cells[y][i + 1] = "";
   }
  }
  Grid->RowCount--;
 }
 Grid->SetFocus();
}
//--------------------
void __fastcall TForm1::UsuWiersz1Click(TObject *Sender)
{
    DeleteRow(StringGrid1, StringGrid1->Row);
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
//wyszukiwanie
struct FindCells
{
 int Row;
 int Col;
};
FindCells FindInGrid(TStringGrid *Grid, String tekst)
{
 FindCells fc;
 fc.Col = -1;
 fc.Row = -1;

 static int row = Grid->FixedRows;
 if(row >= Grid->RowCount - 1)
 row = Grid->FixedRows;

 for(int i = Grid->FixedCols; i < Grid->ColCount; i++)
 {
  for(int j = row; j < Grid->RowCount; j++)
  {
   String find = Grid->Cells[i][j];
   int x = find.Pos(tekst);
   if(x > 0)
   {
    fc.Col = i;
    fc.Row = j;
    row = j + 1;
    return fc;
   }
  }
 }
 row = Grid->FixedRows;
 return fc;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
       delete Baza;
}

//przycisk wyszukania
void __fastcall TForm1::WyszukajClick(TObject *Sender)
{
    FindCells fc;
 fc = FindInGrid(StringGrid1, Edit1->Text);
 if(fc.Col < 0)
 {
  Application->MessageBox(("Nie mo¿na odnaleŸæ „" + Edit1->Text + "”").c_str(),
   "ZnajdŸ", MB_OK | MB_ICONINFORMATION);
  return;
 }
 StringGrid1->Col = fc.Col;
 StringGrid1->Row = fc.Row;
 StringGrid1->SetFocus();

}

//---------------------------------------------------------------------------

