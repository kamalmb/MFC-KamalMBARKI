
// kamalMBARKI_MFCDlg.cpp : fichier d'implémentation
//

#include "pch.h"
#include "framework.h"
#include "kamalMBARKI_MFC.h"
#include "kamalMBARKI_MFCDlg.h"
#include "afxdialogex.h"
#include "RandomCityGenerator.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <vector>


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// boîte de dialogue de CkamalMBARKIMFCDlg



CkamalMBARKIMFCDlg::CkamalMBARKIMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KAMALMBARKI_MFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkamalMBARKIMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboBox);
}

BEGIN_MESSAGE_MAP(CkamalMBARKIMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO1, &CkamalMBARKIMFCDlg::OnCbnSelchangeCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO1, &CkamalMBARKIMFCDlg::OnCbnDropdownCombo1)
END_MESSAGE_MAP()


// gestionnaires de messages de CkamalMBARKIMFCDlg


void CkamalMBARKIMFCDlg::UpdateComboBox()
{

	// Forcer le ComboBox à se redessiner 
	m_comboBox.Invalidate(TRUE);

	m_comboBox.ResetContent();
	std::vector<std::string> strings = { "Lyon", "Marseille", "St Etienne", "Orange", "Orléans", "Strasbourg" };

	// List of cities
	//  pour obtenir des chaînes de caractères aléatoires
	RandomCityGenerator generator;

	auto cities = generator.RandomCities(strings);

	for (auto& str : cities)
	{
		m_comboBox.AddString(CStringW(str.c_str())); // Convertir std::string to CString
		std::cout << str<<" ";
	}
	std::cout << std::endl;
	
	// Forcer le ComboBox à se redessiner 
	m_comboBox.Invalidate(TRUE);
	
	UpdateData(FALSE);
	
}


BOOL CkamalMBARKIMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// Allocating a console for debugging output
	AllocConsole();
	// Rediriger stdout vers la console en utilisant freopen_s
	FILE* pConsole;
	if (freopen_s(&pConsole, "CONOUT$", "w", stdout) != 0)
	{
		MessageBox(_T("Failed to redirect stdout to console"), _T("Error"), MB_ICONERROR);
		return FALSE;
	}
	
	//link combo box with membre variable
	 m_comboBox.SubclassDlgItem(IDC_COMBO2, this);
	 m_comboBox.ResetContent();
	 
	 
	// Ajouter l'élément de menu "À propos de..." au menu Système.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire
	//UpdateData(FALSE);

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CkamalMBARKIMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CkamalMBARKIMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CkamalMBARKIMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CkamalMBARKIMFCDlg::OnCbnSelchangeCombo1()
{
	/*   */ 
}


void CkamalMBARKIMFCDlg::OnCbnDropdownCombo1()
{
	//l'appelle de la fonction updatecombobx pour mettre aléatoire à nouveau la liste des villes  
	UpdateComboBox();
	
}
