//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormShow(TObject *Sender)
{
        StringGrid1->RowCount = Form1->StringGrid1->ColCount;
        for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
        {
                StringGrid1->Cells[0][i] = Form1->StringGrid1->Cells[i][0];
        }
        for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
        {
                StringGrid1->Cells[1][i] = Form1->StringGrid1->Cells[i][1];
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
 for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
      {
        Form1->StringGrid1->Cells[i][0] = StringGrid1->Cells[0][i];
      }
      for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
        {
                Form1->StringGrid1->Cells[i][1] = StringGrid1->Cells[1][i];
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::StringGrid1SetEditText(TObject *Sender, int ACol,
      int ARow, const AnsiString Value)
{
 for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
      {
        Form1->StringGrid1->Cells[i][0] = StringGrid1->Cells[0][i];
      }
      for(int i = 0; i < Form1->StringGrid1->ColCount; i++)
        {
                Form1->StringGrid1->Cells[i][1] = StringGrid1->Cells[1][i];
        }
        
}
//---------------------------------------------------------------------------

