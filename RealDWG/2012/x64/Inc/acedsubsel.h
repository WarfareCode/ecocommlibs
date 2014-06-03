// $Header: //depot/release/ironman2012/develop/global/inc/dbxsdk/acedsubsel.h#1 $ $Change: 237375 $ $DateTime: 2011/01/30 18:32:54 $ $Author: integrat $
// $NoKeywords: $
//
// (C) Copyright 2005-2010 by Autodesk, Inc. 
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

#ifndef _acedsubsel_h
#define _acedsubsel_h 1

#pragma once

class AcDbFullSubentPath;

#include "acarray.h"
#include "acdb.h"
#include "adsdef.h"

#pragma pack (push, 8)

/* AutoCAD Sub-entity selection set routines */

int            acedSSSubentLength (const ads_name sname, Adesk::Int32 index, Adesk::Int32* len);

int            acedSSSubentAdd    (const AcDbFullSubentPath& subentity, 
                                   const ads_name sname, 
                                   ads_name result);

int            acedSSSubentDel    (const AcDbFullSubentPath& subentity, 
                                   const ads_name ss);

int            acedSSSubentMemb   (const AcDbFullSubentPath& subentity,
                                   const ads_name ss);

int            acedSSSubentName   (const ads_name ss, 
                                   Adesk::Int32 entIndex, 
                                   Adesk::Int32 subentIndex, 
                                   AcDbFullSubentPath& subentity);

int            acedSSSubentNameX  (struct resbuf** rbpp, 
                                   const ads_name ss,
                                   const Adesk::Int32 entIndex, 
                                   const Adesk::Int32 subentIndex,
                                   unsigned int flags);

int            acedSSSetSubentTypes(const AcArray<AcDb::SubentType>& types);


#pragma pack (pop)
#endif  /* !_acedads_h */
