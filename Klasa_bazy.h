//---------------------------------------------------------------------------

#ifndef Klasa_bazyH
#define Klasa_bazyH
//---------------------------------------------------------------------------
#include <Grids.hpp>
//---------------------------------------------------------------------------
struct memo //struktura sluzy do przenoszenia informacji pomiedzy formularzem i klasa bazy
{
        String A[1000];
};
class TDataBase
{
 public:
 TDataBase();
 ~TDataBase();

 void SaveToFile(String FileName, TStringGrid *Grid);
 void LoadFromFile(String FileName, TStringGrid *Grid);
 void SetMemo(String tekst, int number);
 void SetBitmap(String FileName, int number);
 memo GetMemo(int number);
 String GetBitmap(int number);
 void RefreshBase(void);
 int MemoCount;
 bool JestNotatka;

 private:
 int ObliczIleKolumn(String tekst);
 int ObliczIleWierszy(TStringList *lista);

 String SetColSize(int Cols, TStringGrid *Grid);
 void GetColSize(String tekst, int Cols, TStringGrid *Grid);

 bool GetMemoSection(String tekst);
 int WierszeMemo(String tekst);

 TStringList *Memo;
 TStringList *Bitmap;
};
#endif
