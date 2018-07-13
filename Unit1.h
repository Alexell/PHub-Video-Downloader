//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LinkEdit;
	TIdHTTP *Web;
	TIdSSLIOHandlerSocketOpenSSL *IndySSL;
	TGroupBox *MainBox;
	TButton *Btn240;
	TButton *Btn480;
	TButton *Btn720;
	TSaveDialog *SaveDialog;
	TProgressBar *ProgressBar;
	TIdAntiFreeze *AntiFreeze;
	TLabel *ProgLabel;
	TLabel *SizeLabel;
	TButton *ExBtn;
	TImage *AboutBtn;
	TLabel *Label1;
	void __fastcall Btn240Click(TObject *Sender);
	void __fastcall WebWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall WebWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall WebWorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall Btn480Click(TObject *Sender);
	void __fastcall Btn720Click(TObject *Sender);
	void __fastcall ExBtnClick(TObject *Sender);
	void __fastcall LinkEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AboutBtnClick(TObject *Sender);




private:	// User declarations
public:		// User declarations
    String TMainForm::GetLink(String Str, String Qa);
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
