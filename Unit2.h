//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
	TPanel *AboutPanel;
	TLabel *AboutLabel1;
	TLabel *AboutLabel2;
	TLabel *AboutLink;
	TLabel *AboutLabel3;
	TLabel *SourceLink;
	TButton *OkBtn;
	void __fastcall AboutLinkClick(TObject *Sender);
	void __fastcall SourceLinkClick(TObject *Sender);
	void __fastcall OkBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
