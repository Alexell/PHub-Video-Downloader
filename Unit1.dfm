object MainForm: TMainForm
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  ClientHeight = 209
  ClientWidth = 433
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object ProgLabel: TLabel
    Left = 392
    Top = 128
    Width = 32
    Height = 13
    Caption = '100 %'
  end
  object SizeLabel: TLabel
    Left = 8
    Top = 150
    Width = 3
    Height = 13
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object AboutBtn: TImage
    Left = 384
    Top = 161
    Width = 40
    Height = 40
    Cursor = crHandPoint
    Center = True
    Picture.Data = {
      0A544A504547496D616765C4030000FFD8FFE000104A46494600010101006000
      600000FFE100664578696600004D4D002A000000080004011A00050000000100
      00003E011B000500000001000000460128000300000001000200000131000200
      0000100000004E00000000000000600000000100000060000000015061696E74
      2E4E45542076332E333600FFDB00430007050506050407060506080707080A11
      0B0A09090A150F100C1118151A19181518171B1E27211B1D251D1718222E2225
      28292B2C2B1A202F332F2A32272A2B2AFFDB0043010708080A090A140B0B142A
      1C181C2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A
      2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2A2AFFC0001108002800280301
      2200021101031101FFC4001F0000010501010101010100000000000000000102
      030405060708090A0BFFC400B5100002010303020403050504040000017D0102
      0300041105122131410613516107227114328191A1082342B1C11552D1F02433
      627282090A161718191A25262728292A3435363738393A434445464748494A53
      5455565758595A636465666768696A737475767778797A838485868788898A92
      939495969798999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7
      C8C9CAD2D3D4D5D6D7D8D9DAE1E2E3E4E5E6E7E8E9EAF1F2F3F4F5F6F7F8F9FA
      FFC4001F0100030101010101010101010000000000000102030405060708090A
      0BFFC400B5110002010204040304070504040001027700010203110405213106
      1241510761711322328108144291A1B1C109233352F0156272D10A162434E125
      F11718191A262728292A35363738393A434445464748494A535455565758595A
      636465666768696A737475767778797A82838485868788898A92939495969798
      999AA2A3A4A5A6A7A8A9AAB2B3B4B5B6B7B8B9BAC2C3C4C5C6C7C8C9CAD2D3D4
      D5D6D7D8D9DAE2E3E4E5E6E7E8E9EAF2F3F4F5F6F7F8F9FAFFDA000C03010002
      110311003F00F9B402CC001926B62C34196E70581E7B0A341B0FB4DC06233CF1
      5EB1E1EF0F2C8ABF27E9401E7C3C22766765665FF8764B704A022BE864F09660
      CF97DBD2B97D7FC382246F93F4A00F067468D8AB8C1145741E23D37ECF217518
      C1A2802F78442E5335EE7E1248CECCE2BE79F0EDFF00D9E70AC71835EBDE1CD7
      D6254F9BF5A00F7C820B23A61248DF8AF39F16A4403EDC509E2DC5BE3CCEDEB5
      C9F887C42B2AB7CFFAD0079CF8B957F794564789B52133B2A9C9268A00E651DA
      370CA7045741A6F88DEDF01C918A28A00DD5F177EEFF00D67EB591A97899A604
      231268A28039B9A669A42EE7268A28A00FFFD9}
    OnClick = AboutBtnClick
  end
  object LinkEdit: TLabeledEdit
    Left = 8
    Top = 21
    Width = 413
    Height = 21
    EditLabel.Width = 175
    EditLabel.Height = 13
    EditLabel.Caption = 'Pornhub / RedTube Video Page URL:'
    TabOrder = 0
    OnKeyDown = LinkEditKeyDown
  end
  object MainBox: TGroupBox
    Left = 8
    Top = 48
    Width = 413
    Height = 65
    Caption = 'Available Downloads:'
    TabOrder = 1
    Visible = False
    object Btn240: TButton
      Left = 16
      Top = 24
      Width = 75
      Height = 25
      Caption = '240p'
      Enabled = False
      TabOrder = 0
      Visible = False
      OnClick = Btn240Click
    end
    object Btn480: TButton
      Left = 168
      Top = 24
      Width = 75
      Height = 25
      Caption = '480p'
      Enabled = False
      TabOrder = 1
      Visible = False
      OnClick = Btn480Click
    end
    object Btn720: TButton
      Left = 320
      Top = 24
      Width = 75
      Height = 25
      Caption = '720p'
      Enabled = False
      TabOrder = 2
      Visible = False
      OnClick = Btn720Click
    end
  end
  object ProgressBar: TProgressBar
    Left = 8
    Top = 127
    Width = 377
    Height = 17
    TabOrder = 2
  end
  object ExBtn: TButton
    Left = 159
    Top = 176
    Width = 113
    Height = 25
    Caption = 'Cancel Download'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
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
    Left = 280
    Top = 160
  end
  object IndySSL: TIdSSLIOHandlerSocketOpenSSL
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 72
    Top = 152
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'mp4'
    Filter = 'MP4|.mp4'
    Left = 336
    Top = 160
  end
  object AntiFreeze: TIdAntiFreeze
    Left = 16
    Top = 152
  end
end
