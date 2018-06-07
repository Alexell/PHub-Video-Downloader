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
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabeledEdit *LinkEdit;
	TIdHTTP *Web;
	TIdSSLIOHandlerSocketOpenSSL *IndySSL;
	TButton *BtnGet;
	TGroupBox *MainBox;
	TButton *Btn240;
	TButton *Btn480;
	TButton *Btn720;
	TSaveDialog *SaveDialog;
	TPanel *AboutPanel;
	TLabel *AboutLabel1;
	TLabel *AboutLabel2;
	TLabel *AboutLink;
	TLabel *AboutLabel3;
	TLabel *SourceLink;
	TMemo *Memo;
	TProgressBar *ProgressBar;
	void __fastcall BtnGetClick(TObject *Sender);
	void __fastcall AboutLinkClick(TObject *Sender);
	void __fastcall SourceLinkClick(TObject *Sender);
	void __fastcall Btn240Click(TObject *Sender);
	void __fastcall WebWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall WebWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall WebWorkEnd(TObject *ASender, TWorkMode AWorkMode);
	void __fastcall Btn480Click(TObject *Sender);
	void __fastcall Btn720Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
    String TMainForm::GetLink(String Str, String Qa);
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
