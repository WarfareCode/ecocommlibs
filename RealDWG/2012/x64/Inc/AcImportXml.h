// $Header: //depot/release/ironman2012/develop/global/inc/arxsdk/acimportxml.h#1 $ $Change: 237375 $ $DateTime: 2011/01/30 18:32:54 $ $Author: integrat $
// $NoKeywords: $
//
//////////////////////////////////////////////////////////////////////////////
//
//          (C) Copyright 2006-2010 by Autodesk, Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//
#pragma once
#include "adesk.h"
#ifdef _ADESK_WINDOWS_
#ifndef AC_DO_NO_IMPORT
#pragma warning (push)
#pragma warning(disable : 4279)
#import "msxml6.dll" named_guids rename_namespace("MSXML") rename("offset", "MSXMLoffset")
#pragma warning (pop)
#else // AC_DO_NO_IMPORT
#include "msxml6.tlh"
#endif
__declspec(selectany) extern const GUID CLSID_DOMDocumentAcad = MSXML::CLSID_DOMDocument60;
#endif // _ADESK_WINDOWS_
