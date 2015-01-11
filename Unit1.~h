//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Klasa_bazy.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *s1;
        TMenuItem *Nowy1;
        TMenuItem *Otwrz1;
        TMenuItem *Zapisz1;
        TMenuItem *Zapiszjako1;
        TMenuItem *Edytuj1;
        TMenuItem *DodajWiersz1;
        TMenuItem *UsuWiersz1;
        TMenuItem *DodajKolumn1;
        TMenuItem *UsuKolumn1;
        TMenuItem *NagwkiKolumn1;
        
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TStringGrid *StringGrid1;
        TEdit *Edit1;
        TButton *Wyszukaj;
        TComboBox *ComboBox1;
        TLabel *Label1;

        void __fastcall DodajWiersz1Click(TObject *Sender);
        void __fastcall UsuWiersz1Click(TObject *Sender);
        void __fastcall DodajKolumn1Click(TObject *Sender);
        void __fastcall UsuKolumn1Click(TObject *Sender);
        void __fastcall NagwkiKolumn1Click(TObject *Sender);
        
        
        void __fastcall Nowy1Click(TObject *Sender);
        void __fastcall Otwrz1Click(TObject *Sender);
        void __fastcall Zapisz1Click(TObject *Sender);
        void __fastcall Zapiszjako1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall WyszukajClick(TObject *Sender);
        void __fastcall StringGrid1SetEditText(TObject *Sender, int ACol,
          int ARow, const AnsiString Value);
        void __fastcall ComboBox1DropDown(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        
        

private:	// User declarations
        String FileSaveName;
        
public:		// User declarations
        TDataBase *Baza;
        
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 