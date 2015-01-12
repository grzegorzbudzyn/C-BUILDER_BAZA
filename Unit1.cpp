//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <locale>

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
void Usun_liczby(int Akolumna,int Awiersz,TStringGrid *Grid)   //maska usuwajaca liczby
{
     if(Grid->Cells[Akolumna][1]=="tekst")
        {
                AnsiString tab[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
                AnsiString temp=Grid->Cells[Akolumna][Awiersz];
                for(int i = 0; i < 10; i++)
                        temp = StringReplace(temp, tab[i], "", TReplaceFlags() << rfReplaceAll);
               Grid->Cells[Akolumna][Awiersz]=temp;
               Grid->Perform(EM_SETSEL, temp.Length(), temp.Length());
        }
}
void Usun_litery(int Akolumna,int Awiersz,TStringGrid *Grid)   //maska usuwajaca litery
{
     if(Grid->Cells[Akolumna][1]=="liczba")
        {
                AnsiString tab[] = {"A","•","B","C","∆","D","E"," ","F","G","H","I","J","K","L","£","M","N","—","O","”","P","R","S","å","T","U","W","Y","Z","è","Ø","a","π","b","Ê","c","d","e","Í","f","g","h","i","j","k","l","m","n","o","p","r","s","t","u","w","y","z"};
                AnsiString temp=Grid->Cells[Akolumna][Awiersz];
                for(int i = 0; i < 58; i++)
                        temp = StringReplace(temp, tab[i], "", TReplaceFlags() << rfReplaceAll);
               Grid->Cells[Akolumna][Awiersz]=temp;
               Grid->Perform(EM_SETSEL, temp.Length(), temp.Length());
        }
}
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
  Application->MessageBox("Nie wybrano wiersza do usuniÍcia", "Usuwanie wiersza", MB_OK | MB_ICONSTOP);
  return;
 }
 if(Grid->RowCount == Grid->FixedRows + 1)
 {
  int id = Application->MessageBox("Conajmniej jeden wiersz (nie liczπc nag≥Ûwka) musi pozostaÊ w tabeli. "

           "Czy chcesz wyczyúciÊ zawartoúÊ komÛrek w tym wierszu?", "Usuwanie wiersza", MB_YESNO | MB_ICONQUESTION);
  if(id == ID_YES)
   for(int y = 0; y < Grid->ColCount; y++)
    Grid->Cells[y][ARow] = "";
  return;
 }

 int id = Application->MessageBox("Czy na pewno chcesz usunπÊ wybrany wiersz?\nOperacji nie bÍdzie moøna cofnπÊ!",
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
// USUWANIE KOLUMNY Z TABELI
void __fastcall DeleteCol(TStringGrid *Grid, int ACol)
{
 if(ACol < Grid->FixedCols)
 {
  Application->MessageBox("Nie wybrano kolumny do usuniÍcia", "Usuwanie kolumny",
  MB_OK | MB_ICONSTOP);
  return;
 }
 if(Grid->ColCount == Grid->FixedCols + 1)
 {
  int id = Application->MessageBox("Conajmniej jedna kolumna (nie liczπc nag≥Ûwka) musi pozostaÊ w tabeli. "
           "Czy chcesz wyczyúciÊ zawartoúÊ komÛrek w tej kolumnie?", "Usuwanie kolumny", MB_YESNO | MB_ICONQUESTION);
  if(id == ID_YES)
   for(int y = 0; y < Grid->RowCount; y++)
    Grid->Cells[ACol][y] = "";
  return;
 }

 int id = Application->MessageBox("Czy na pewno chcesz usunπÊ wybranπ kolumnÍ?\nOperacji nie bÍdzie moøna cofnπÊ!",
         "Usuwanie kolumny", MB_YESNO | MB_ICONQUESTION);
 if(id == ID_YES)
 {
  for(int i = ACol; i <= Grid->ColCount - 1; i++)
  {
   for(int y = 0; y < Grid->RowCount; y++)
   {
    Grid->Cells[i][y] = Grid->Cells[i + 1][y];
    Grid->ColWidths[i] = Grid->ColWidths[i + 1];
    Grid->Cells[i + 1][y] = "";
   }
  }
  Grid->ColCount--;
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
         DeleteCol(StringGrid1, StringGrid1->Col);
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
if( Application->MessageBox(
			"Czy jestes pewien? Nie zapisane dane zostanπ bezpowrotnie utracone!",
			"Ostrzeøenie",
			MB_OKCANCEL | MB_ICONQUESTION) == IDOK )
                        {
Baza->RefreshBase();

  for(int i = 0; i < StringGrid1->RowCount; i++){
    for(int j = 0; j < StringGrid1->ColCount; j++){
      StringGrid1->Cells[j][i] = "";
                               }
                                 }

  StringGrid1->RowCount = 4;
  StringGrid1->ColCount = 2;
  FileSaveName = "";
  }
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
Usun_liczby(Akolumna,Awiersz,StringGrid1);

        if(FileSaveName.IsEmpty())
        {
                if(SaveDialog1->Execute())
                Baza->SaveToFile(SaveDialog1->FileName, StringGrid1);
        }
        else
        Baza->SaveToFile(FileSaveName, StringGrid1);
        FileSaveName = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
Usun_liczby(Akolumna,Awiersz,StringGrid1);
Usun_litery(Akolumna,Awiersz,StringGrid1);

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
  Application->MessageBox(("Nie moøna odnaleüÊ Ñ" + Edit1->Text + "î").c_str(),
   "Znajdü", MB_OK | MB_ICONINFORMATION);
  return;
 }
 StringGrid1->Col = fc.Col;
 StringGrid1->Row = fc.Row;
 StringGrid1->SetFocus();

}

//---------------------------------------------------------------
void __fastcall TForm1::StringGrid1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{

 if(!StringGrid1->Cells[ACol][ARow].IsEmpty())  //jesli nei jest pusty
        if( StringGrid1->ColWidths[ACol] < (5 + StringGrid1->Canvas->TextWidth(StringGrid1->Cells[ACol][ARow]))) //jesli nei jest mniejszy od poprzedniej wartosci
                {
                        StringGrid1->ColWidths[ACol] = 5 + StringGrid1->Canvas->TextWidth(StringGrid1->Cells[ACol][ARow]);
                }


        //StringGrid1->Cells[ACol][ARow]->Perform

 //if(StringGrid1->Cells[ACol][1]=="liczba")
 //       {
 //               AnsiString tab[] = {"A","•","B","C","∆","D","E"," ","F","G","H","I","J","K","L","£","M","N","—","O","”","P","R","S","å","T","U","W","Y","Z","è","Ø"};
 //               AnsiString temp;
 //               for(int i = 0; i < 10; i++)
 //                       temp = StringReplace(temp, tab[i], "", TReplaceFlags() << rfReplaceAll);
 //               StringGrid1->Cells[ACol][ARow]=temp;
 //       }

 }
//---------------------------------------------------------------------------
//SORTOWANIE Bπbelkowe!!!
int __fastcall CustomSortIncrease(TStringList *Lista, int idx1, int idx2)
{
 String cTemp1 = Lista->Strings[idx1];
 String cTemp2 = Lista->Strings[idx2];
 return CompareText(cTemp1, cTemp2);
}

void __fastcall sortuj(TStringGrid *Grid, int Col)
{
 TStringList *SortList = new TStringList;
 String temp = "";

 for(int i = Grid->FixedRows; i < Grid->RowCount; i++)
 {
  temp = Grid->Cells[Col][i];
  if(temp.IsEmpty()) temp = " ";
  for(int z = Grid->FixedCols; z <= Grid->ColCount; z++)
  {
   if(Grid->Cells[z][i].IsEmpty()) Grid->Cells[z][i] = " ";
   if(z != Col)
    temp = temp + "^" + Grid->Cells[z][i];
  }
  SortList->Add(temp.SubString(0, temp.Length() - 1));
  temp = "";
 }


 SortList->CustomSort(CustomSortIncrease);


 temp = "";
 for(int i = 0; i < SortList->Count; i++)
 {
  temp = SortList->Strings[i];

  int y = temp.Pos("^");
  Grid->Cells[Col][i + 1] = temp.SubString(1, y - 1).Trim();
  temp = temp.Delete(1, y);
  int z;
  for(z = Grid->FixedCols; z < Grid->ColCount; z++)
  {
   if(z != Col)
   {
    y = temp.Pos("^");
    Grid->Cells[z][i + 1] = temp.SubString(1, y - 1).Trim();
    temp = temp.Delete(1, y);
   }
  }
  z++;
  y = temp.Pos("^");
  Grid->Cells[z][i + 1] = temp.SubString(1, y - 1).Trim();
  temp = temp.Delete(1, y);
 }

 delete SortList;
}                //temp = Grid->Rows[i]->GetText();
                //Grid->Rows[i]->SetText(Grid->Rows[j]->GetText());
                //Grid->Rows[j]->SetText(temp.c_str());

void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
        sortuj(StringGrid1,ComboBox1->ItemIndex);
}
//---------------------------------------------------------------------------
//sortowanie end

//Wyswietlanie Comboboxa--------------------------------------------------------------

void __fastcall TForm1::ComboBox1DropDown(TObject *Sender)
{
ComboBox1->Items->Clear();
for(int i = 0; i < StringGrid1->ColCount; i++)
        {
                ComboBox1->Items->Add(StringGrid1->Cells[i][0]);
      }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1SelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
Usun_liczby(ACol,ARow,StringGrid1);
Usun_litery(ACol,ARow,StringGrid1);
Usun_liczby(Akolumna,Awiersz,StringGrid1);
Usun_litery(Akolumna,Awiersz,StringGrid1);

Akolumna=ACol;
Awiersz=ARow;
}
//---------------------------------------------------------------------------


