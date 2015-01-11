//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Klasa_bazy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
TDataBase::TDataBase()
{   // konstruktor
 Memo = new TStringList;
}
//---------------------------------------------------------------------------
TDataBase::~TDataBase()
{   // destruktor
}
//---------------------------------------------------------------------------
String TDataBase::SetColSize(int Cols, TStringGrid *Grid)
{
 String temp = "";
 for(int i = 0; i < Cols; i++){
     temp = temp + IntToStr(Grid->ColWidths[i]) + "#";
                              }
     temp.Delete(temp.Length(), 1);
 return temp;
}
//---------------------------------------------------------------------------
void TDataBase::GetColSize(String tekst, int Cols, TStringGrid *Grid)
{
 int Cx;
 for(int i = 0; i < Cols; i++){
     int x = tekst.LastDelimiter("#");
     try{Cx = (tekst.SubString(x + 1, 4)).ToInt();}catch(...){Cx = 60;}
     Grid->ColWidths[Cols - i - 1] = Cx;
     tekst.Delete(x, 4);
                              }
}
//---------------------------------------------------------------------------
void TDataBase::SaveToFile(String FileName, TStringGrid *Grid)
{
 TStringList *Lista = new TStringList;

 String temp1 = "", temp2;

 for(int i = 0; i < Grid->RowCount; i++){
  for(int j = 0; j < Grid->ColCount; j++){
      if(Grid->Cells[j][i].IsEmpty())temp2 = "[EMPTY]";
      else temp2 = Grid->Cells[j][i];
      temp1 = temp1 + temp2 + "#";
                                         }
      temp1.Delete(temp1.Length(), 1);
      Lista->Add(temp1);
      temp1 = "";
                                        }
 Lista->Add("[SECTION MEMO]");
 for(int i = 0; i < Memo->Count; i++){
      Lista->Add(Memo->Strings[i]);
                                     }

 Lista->Add(SetColSize(Grid->ColCount, Grid));
 Lista->SaveToFile(FileName);
 Lista->Free();
}
//---------------------------------------------------------------------------
int TDataBase::ObliczIleKolumn(String tekst)
{
 int x = 0;
 for(int i = 0; i < tekst.Length(); i++){
     x = (tekst.SubString(i, 1) == "#") ? x + 1 : x;
                                        }
 return x + 1;
}
//---------------------------------------------------------------------------
int TDataBase::ObliczIleWierszy(TStringList *lista)
{
 for(int i = 0; i < lista->Count; i++){
     if(lista->Strings[i] == "[SECTION MEMO]")
     return i;
                                      }
 return lista->Count - 1;
}
//---------------------------------------------------------------------------
bool TDataBase::GetMemoSection(String tekst)
{
 bool test = (tekst.SubString(1, 6) == "[MEMO]" ||
              tekst.SubString(1, 9) == "[BITMAPA]" ||
              tekst.SubString(1, 14) == "[SECTION MEMO]") ? true : false;
 return test;
}
//---------------------------------------------------------------------------
void TDataBase::LoadFromFile(String FileName, TStringGrid *Grid)
{
 TStringList *Lista = new TStringList;
 Lista->LoadFromFile(FileName);
 int x = ObliczIleKolumn(Lista->Strings[0]);
 Grid->ColCount = x;
 Grid->RowCount = ObliczIleWierszy(Lista);
 GetColSize(Lista->Strings[Lista->Count - 1], x, Grid);

 String temp;

 for(int i = 0; i < Lista->Count - 1; i++){
  if(!GetMemoSection(Lista->Strings[i])){
   for(int j = 0; j < x; j++){
          int y = Lista->Strings[i].LastDelimiter("#");
             temp = Lista->Strings[i].SubString(y + 1, 1000);

          if(temp == "[EMPTY]")temp = "";
             Grid->Cells[x - j - 1][i] = temp;
             Lista->Strings[i] = Lista->Strings[i].Delete(y, 1000);
                             }
                                        }
  else {
        if(Lista->Strings[i].SubString(1, 6) == "[MEMO]")
            Memo->Add(Lista->Strings[i]);
       }
                                      }

 Lista->Free();
}
//---------------------------------------------------------------------------
void TDataBase::SetMemo(String tekst, int number)
{
 String temp = "[MEMO]" + IntToStr(number) + "#";
 int length = temp.Length();
 bool test = false;
 for(int i = 0; i < Memo->Count; i++){
 if(Memo->Strings[i].SubString(1, length) == temp){
    Memo->Strings[i] = temp + tekst;
    test = true;
    break;
                                                  }
                                     }
 if(!test)Memo->Add(temp + tekst);
}
//---------------------------------------------------------------------------
int TDataBase::WierszeMemo(String tekst)
{
 int x = 0;
 for(int i = 0; i < tekst.Length(); i++){
     x = (tekst.SubString(i, 1) == "|") ? x + 1 : x;
                                        }
 return x;
}
//---------------------------------------------------------------------------
memo TDataBase::GetMemo(int number)
{
 String temp;
 memo zwrot;
 int z;

 for(int i = 0; i < Memo->Count; i++){
     temp = Memo->Strings[i].SubString(7, 1000);
     int x = temp.LastDelimiter("#");
     try{z = (temp.SubString(0, x - 1)).ToInt();}catch(...){z = 0;}
     if(z == number){
     temp = temp.Delete(1, x);
     break;
                    }
                                     }
 if(z == number){
 
 MemoCount = WierszeMemo(temp);

 for(int i = 0; i < MemoCount; i++){
     int x = temp.LastDelimiter("|");
     zwrot.A[i] = (temp.SubString(x + 1, 1000));
     temp = temp.Delete(x, 1000);
                                           }
               }
 return zwrot;
}
//---------------------------------------------------------------------------

void TDataBase::RefreshBase(void)
{

 Memo->Clear();
}
//---------------------------------------------------------------------------
