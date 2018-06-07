//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
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
void __fastcall TMainForm::BtnGetClick(TObject *Sender)
{
	Sheet->Text=Web->Get(LinkEdit->Text);
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
	MainBox->Visible=true;
	//MainForm->Height=210;
	Memo->Text=Link240+"\n\n"+Link480+"\n\n"+Link720;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AboutLinkClick(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://alexell.ru", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SourceLinkClick(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://github.com/alexell/", NULL, NULL, SW_SHOWNORMAL);
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
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WebWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar->Position=AWorkCount;
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WebWorkEnd(TObject *ASender, TWorkMode AWorkMode)
{
	ProgressBar->Position=0;
}
//---------------------------------------------------------------------------

