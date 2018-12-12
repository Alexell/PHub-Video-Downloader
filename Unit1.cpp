//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "System.Math.hpp"
#include "Clipbrd.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
float prog, cur, full;
TStringList * Sheet = new TStringList();
UnicodeString Links, Link240, Link480, Link720;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	MainForm->Caption=Application->Title;
	MainForm->Height=80;
	MainBox->Height=20;
}
//---------------------------------------------------------------------------

String TMainForm::GetLink(String Str, String Qa)
{
	String Temp, Temp2;
	Temp=Str.SubString(Str.Pos("\"quality\":\""+Qa+"\"")+28,Str.Pos("\"}")-2);
	Temp2=Temp.SubString(0,Temp.Pos("\"}")-1);
	Temp2=StringReplace(Temp2,"\\/","/",TReplaceFlags()<< rfReplaceAll);
	return Temp2;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Btn240Click(TObject *Sender)
{
    SaveDialog->FileName="video_240p";
	if(SaveDialog->Execute())
	{
		MainForm->Height=247;
		TFileStream* Stream = new TFileStream(SaveDialog->FileName, fmCreate|fmOpenWrite);
		Web->Get(Link240, Stream);
		delete Stream;
		SaveDialog->FileName="";
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Btn480Click(TObject *Sender)
{
	SaveDialog->FileName="video_480p";
	if(SaveDialog->Execute())
	{
		MainForm->Height=247;
		TFileStream* Stream = new TFileStream(SaveDialog->FileName, fmCreate|fmOpenWrite);
		Web->Get(Link480, Stream);
		delete Stream;
		SaveDialog->FileName="";
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Btn720Click(TObject *Sender)
{
	SaveDialog->FileName="video_720p";
	if(SaveDialog->Execute())
	{
		MainForm->Height=247;
		TFileStream* Stream = new TFileStream(SaveDialog->FileName, fmCreate|fmOpenWrite);
		Web->Get(Link720, Stream);
		delete Stream;
		SaveDialog->FileName="";
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WebWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax)

{
	ProgressBar->Max=AWorkCountMax;
	ProgressBar->Position=0;
	ProgLabel->Caption="0 %";
    SizeLabel->Font->Style=TFontStyles() >> fsBold;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WebWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar->Position=AWorkCount;
	cur=AWorkCount;
	full=ProgressBar->Max;
	if(full>0)
	{
		prog=int(10.*cur/full*10);
		ProgLabel->Caption = FloatToStr(prog)+" %";
	}
	cur=cur/1048576;
	full=full/1048576;
	SizeLabel->Caption = "Downloaded: "+FloatToStrF(cur, ffGeneral, 4, 2)+" / "+FloatToStrF(full, ffGeneral, 4, 2)+" Mb";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WebWorkEnd(TObject *ASender, TWorkMode AWorkMode)
{
	SizeLabel->Font->Style=TFontStyles() << fsBold;
	if(cur==full)
	{
		LinkEdit->Enabled=true;
		SizeLabel->Caption="Download Complete";
	}
	else
		SizeLabel->Caption="Download Canceled";

	cur=0; full=0; prog=0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExBtnClick(TObject *Sender)
{
	Web->Disconnect();
	LinkEdit->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LinkEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	TClipboard *Clipboard=new TClipboard();
	if (Key == 86 && Shift == TShiftState() <<ssCtrl)
	{
		if(Clipboard->HasFormat(CF_TEXT))
		{
			LinkEdit->Enabled=false;
			MainForm->Height=108;
			MainBox->Height=20;
			MainBox->Visible=true;
			MainBox->Caption="Getting available videos...";
			if(Clipboard->AsText.Pos("https://rt.pornhub.com/view_video.php") || Clipboard->AsText.Pos("https://www.pornhub.com/view_video.php") || Clipboard->AsText.Pos("https://ru.redtube.com/") || Clipboard->AsText.Pos("https://www.redtube.com/"))
			{
				Sheet->Text=Web->Get(Clipboard->AsText);
				Web->Disconnect();
				for (int i = 0; i < Sheet->Count; i++)
				{
					if(Sheet->Strings[i].Pos("\"quality\":\"480\""))
					{
						Links=Sheet->Strings[i];
						break;
					}
				}

				if(Links.Pos("\"quality\":\"720\""))
				{
					Link720=GetLink(Links,"720");
					Btn720->Enabled=true;
				}

				if(Links.Pos("\"quality\":\"480\""))
				{
					Link480=GetLink(Links,"480");
					Btn480->Enabled=true;
				}

				if(Links.Pos("\"quality\":\"240\""))
				{
					Link240=GetLink(Links,"240");
					Btn240->Enabled=true;
				}
				MainForm->Height=150;
				MainBox->Height=65;
				MainBox->Caption="Available Downloads:";
				Btn720->Visible=true;
				Btn480->Visible=true;
				Btn240->Visible=true;
			}
			else
			{
				ShowMessage("Unsupported link!");
				LinkEdit->Text="";
				LinkEdit->Enabled=true;
				MainBox->Height=20;
				MainBox->Visible=false;
				MainForm->Height=80;
			}
		}
		Clipboard->Clear();
		delete Clipboard;
	}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AboutBtnClick(TObject *Sender)
{
	AboutForm->Visible=true;
}
//---------------------------------------------------------------------------

