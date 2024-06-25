
// kamalMBARKI_MFCDlg.h : fichier d'en-tête
//

#pragma once


// boîte de dialogue de CkamalMBARKIMFCDlg
class CkamalMBARKIMFCDlg : public CDialogEx
{
// Construction
public:
	CkamalMBARKIMFCDlg(CWnd* pParent = nullptr);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KAMALMBARKI_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboBox;
	afx_msg void OnCbnSelchangeCombo1(); 
	void UpdateComboBox();
	afx_msg void OnCbnDropdownCombo1();
};
