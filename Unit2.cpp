//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
	: TForm(Owner)
{
	AboutForm->Caption="About "+Application->Title;
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::AboutLinkClick(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://alexell.ru", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::SourceLinkClick(TObject *Sender)
{
	ShellExecute(Handle, NULL, L"https://github.com/Alexell/PHub-Video-Downloader", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::OkBtnClick(TObject *Sender)
{
    AboutForm->Visible=false;
}
//---------------------------------------------------------------------------
