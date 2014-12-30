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
  object StringGrid1: TStringGrid
    Left = 78
    Top = 24
    Width = 296
    Height = 120
    ColCount = 1
    DefaultColWidth = 270
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goAlwaysShowEditor]
    TabOrder = 0
    OnClick = FormShow
  end
  object Button1: TButton
    Left = 77
    Top = 150
    Width = 75
    Height = 25
    Caption = 'OK'
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
