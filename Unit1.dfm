object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 434
  ClientWidth = 606
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ProgLabel: TLabel
    Left = 554
    Top = 361
    Width = 3
    Height = 13
  end
  object SizeLabel: TLabel
    Left = 8
    Top = 383
    Width = 450
    Height = 13
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object LinkEdit: TLabeledEdit
    Left = 8
    Top = 59
    Width = 377
    Height = 21
    EditLabel.Width = 95
    EditLabel.Height = 13
    EditLabel.Caption = 'Pornhub Video URL:'
    TabOrder = 0
  end
  object BtnGet: TButton
    Left = 391
    Top = 57
    Width = 75
    Height = 25
    Caption = 'Get Links'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = BtnGetClick
  end
  object MainBox: TGroupBox
    Left = 8
    Top = 96
    Width = 377
    Height = 65
    Caption = 'Available Downloads:'
    TabOrder = 2
    object Btn240: TButton
      Left = 16
      Top = 24
      Width = 75
      Height = 25
      Caption = '240p'
      Enabled = False
      TabOrder = 0
      OnClick = Btn240Click
    end
    object Btn480: TButton
      Left = 152
      Top = 24
      Width = 75
      Height = 25
      Caption = '480p'
      Enabled = False
      TabOrder = 1
      OnClick = Btn480Click
    end
    object Btn720: TButton
      Left = 288
      Top = 24
      Width = 75
      Height = 25
      Caption = '720p'
      Enabled = False
      TabOrder = 2
      OnClick = Btn720Click
    end
  end
  object AboutPanel: TPanel
    Left = 8
    Top = 8
    Width = 585
    Height = 30
    BevelInner = bvLowered
    ParentShowHint = False
    ShowCaption = False
    ShowHint = False
    TabOrder = 3
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
      Left = 104
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
      Left = 159
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
      Left = 256
      Top = 8
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
      Left = 334
      Top = 8
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
  object Memo: TMemo
    Left = 8
    Top = 167
    Width = 521
    Height = 178
    Lines.Strings = (
      'Memo')
    TabOrder = 4
  end
  object ProgressBar: TProgressBar
    Left = 8
    Top = 360
    Width = 540
    Height = 17
    TabOrder = 5
  end
  object ExBtn: TButton
    Left = 239
    Top = 402
    Width = 113
    Height = 25
    Caption = 'Cancel Download'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = ExBtnClick
  end
  object Web: TIdHTTP
    IOHandler = IndySSL
    OnWork = WebWork
    OnWorkBegin = WebWorkBegin
    OnWorkEnd = WebWorkEnd
    AllowCookies = True
    HandleRedirects = True
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 472
    Top = 32
  end
  object IndySSL: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 560
    Top = 32
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'mp4'
    Filter = 'MP4|.mp4'
    Left = 520
    Top = 32
  end
  object AntiFreeze: TIdAntiFreeze
    Left = 552
    Top = 96
  end
end
