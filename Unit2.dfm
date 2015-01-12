object Form2: TForm2
  Left = 252
  Top = 247
  BorderStyle = bsDialog
  Caption = 'Nag'#322#243'wki'
  ClientHeight = 187
  ClientWidth = 455
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 87
    Height = 13
    Caption = 'Nazwa nag'#322#243'wka:'
  end
  object Label2: TLabel
    Left = 232
    Top = 8
    Width = 134
    Height = 13
    Caption = 'Typ nagl'#243'wka: tekst / liczba'
  end
  object StringGrid1: TStringGrid
    Left = 6
    Top = 32
    Width = 443
    Height = 113
    ColCount = 2
    DefaultColWidth = 210
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goAlwaysShowEditor]
    TabOrder = 0
    OnClick = FormShow
    OnSetEditText = StringGrid1SetEditText
  end
  object Button1: TButton
    Left = 77
    Top = 150
    Width = 75
    Height = 25
    Caption = 'Zastosuj'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 299
    Top = 150
    Width = 75
    Height = 25
    Caption = 'Zamknij'
    TabOrder = 2
    OnClick = Button2Click
  end
end
