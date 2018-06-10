object AboutForm: TAboutForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  ClientHeight = 105
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object AboutPanel: TPanel
    Left = 8
    Top = 8
    Width = 345
    Height = 57
    BevelInner = bvLowered
    ParentShowHint = False
    ShowCaption = False
    ShowHint = False
    TabOrder = 0
    object AboutLabel1: TLabel
      Left = 8
      Top = 8
      Width = 83
      Height = 13
      Caption = 'Author: Alexell'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object AboutLabel2: TLabel
      Left = 195
      Top = 8
      Width = 49
      Height = 13
      Caption = 'Website:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object AboutLink: TLabel
      Left = 250
      Top = 8
      Width = 81
      Height = 13
      Cursor = crHandPoint
      Caption = 'https://alexell.ru'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = AboutLinkClick
    end
    object AboutLabel3: TLabel
      Left = 8
      Top = 30
      Width = 72
      Height = 13
      Caption = 'Source code:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object SourceLink: TLabel
      Left = 86
      Top = 30
      Width = 245
      Height = 13
      Cursor = crHandPoint
      Caption = 'https://github.com/Alexell/PHub-Video-Downloader'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsUnderline]
      ParentFont = False
      OnClick = SourceLinkClick
    end
  end
  object OkBtn: TButton
    Left = 136
    Top = 73
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = OkBtnClick
  end
end
