object Form3: TForm3
  Left = 192
  Top = 125
  BorderStyle = bsDialog
  Caption = 'Dodaj opis'
  ClientHeight = 233
  ClientWidth = 262
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
  object ComboBox1: TComboBox
    Left = 8
    Top = 30
    Width = 80
    Height = 21
    ItemHeight = 13
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 8
    Top = 60
    Width = 255
    Height = 140
    Lines.Strings = (
      'Memo1')
    MaxLength = 1000
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 210
    Width = 75
    Height = 25
    Caption = 'Dodaj'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 190
    Top = 210
    Width = 75
    Height = 25
    Caption = 'Zamknij'
    TabOrder = 3
    OnClick = Button2Click
  end
end
