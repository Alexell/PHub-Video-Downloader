//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "System.Math.hpp"
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

void __fastcall TMainForm::AboutLinkClick(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://alexell.ru", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SourceLinkClick(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://github.com/Alexell/PHub-Video-Downloader", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Btn240Click(TObject *Sender)
{
    SaveDialog->FileName="video_240p";
	if(SaveDialog->Execute())
	{
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

void __fastcall TMainForm::LinkEditChange(TObject *Sender)
{
    LinkEdit->Enabled=false;
	MainBox->Height=20;
	MainBox->Visible=true;
	MainBox->Caption="Getting available videos...";
	Sheet->Text=Web->Get(LinkEdit->Text);
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
	Btn720->Visible=true;
	Btn480->Visible=true;
	Btn240->Visible=true;
	MainBox->Caption="Available Downloads:";
	MainBox->Height=65;
	//MainForm->Height=210;
	Memo->Text=Link240+"\n\n"+Link480+"\n\n"+Link720;
}
//---------------------------------------------------------------------------

