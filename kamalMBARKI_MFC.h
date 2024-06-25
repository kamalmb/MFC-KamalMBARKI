
// kamalMBARKI_MFC.h : fichier d'en-tête principal de l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'pch.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CkamalMBARKIMFCApp :
// Consultez kamalMBARKI_MFC.cpp pour l'implémentation de cette classe
//

class CkamalMBARKIMFCApp : public CWinApp
{
public:
	CkamalMBARKIMFCApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CkamalMBARKIMFCApp theApp;
