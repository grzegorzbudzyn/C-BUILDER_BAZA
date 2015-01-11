object Form1: TForm1
  Left = 375
  Top = 166
  ActiveControl = StringGrid1
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 443
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 432
    Top = 8
    Width = 73
    Height = 13
    Caption = 'Sortowanie wg:'
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 64
    Width = 609
    Height = 356
    ColCount = 2
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowMoving, goColMoving, goEditing]
    TabOrder = 0
    OnSetEditText = StringGrid1SetEditText
  end
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 297
    Height = 21
    TabOrder = 1
    Text = 'Wyszukiwanie...'
  end
  object Wyszukaj: TButton
    Left = 104
    Top = 32
    Width = 105
    Height = 25
    Caption = 'Wyszukaj'
    TabOrder = 2
    OnClick = WyszukajClick
  end
  object ComboBox1: TComboBox
    Left = 328
    Top = 32
    Width = 289
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
    OnChange = ComboBox1Change
    OnDropDown = ComboBox1DropDown
  end
  object MainMenu1: TMainMenu
    Left = 520
    Top = 408
    object s1: TMenuItem
      Caption = 'Plik'
      object Nowy1: TMenuItem
        Caption = 'Nowy'
        OnClick = Nowy1Click
      end
      object Otwrz1: TMenuItem
        Caption = 'Otw'#243'rz'
        OnClick = Otwrz1Click
      end
      object Zapisz1: TMenuItem
        Caption = 'Zapisz'
        OnClick = Zapisz1Click
      end
      object Zapiszjako1: TMenuItem
        Caption = 'Zapisz jako'
        OnClick = Zapiszjako1Click
      end
    end
    object Edytuj1: TMenuItem
      Caption = 'Edytuj'
      object DodajWiersz1: TMenuItem
        Caption = 'Dodaj Wiersz'
        OnClick = DodajWiersz1Click
      end
      object UsuWiersz1: TMenuItem
        Caption = 'Usu'#324' Wiersz'
        OnClick = UsuWiersz1Click
      end
      object DodajKolumn1: TMenuItem
        Caption = 'Dodaj Kolumn'#281
        OnClick = DodajKolumn1Click
      end
      object UsuKolumn1: TMenuItem
        Caption = 'Usu'#324' Kolumn'#281
        OnClick = UsuKolumn1Click
      end
      object NagwkiKolumn1: TMenuItem
        Caption = 'Nag'#322#243'wki Kolumn'
        OnClick = NagwkiKolumn1Click
      end
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'dbf'
    Filter = 'Pliki data base format (*.dbf)|*.dbf'
    Left = 552
    Top = 408
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'dbf'
    Filter = 
      'Pliki data base format (*.dbf) |*.dbf|*.dbf | Wszystkie pliki (*' +
      '.*)'
    Left = 584
    Top = 408
  end
end
