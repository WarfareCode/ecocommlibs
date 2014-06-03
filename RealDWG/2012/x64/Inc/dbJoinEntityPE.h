// $Header: //depot/release/ironman2012/develop/global/inc/dbxsdk/dbJoinEntityPE.h#1 $ $Change: 237375 $ $DateTime: 2011/01/30 18:32:54 $ $Author: integrat $
// $NoKeywords: $
//
// (C) Copyright 2009-2010 by Autodesk, Inc.
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
// DESCRIPTION: AcDbJoinEntityPE Protocol extension abstract base class
//
#include "acdb.h"
#include "dbmain.h"

#pragma once
#pragma pack (push, 8)

class AcDbJoinEntityPE : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbJoinEntityPE);

    virtual Acad::ErrorStatus 
        joinEntity(AcDbEntity* pPrimaryEntity, 
            AcDbEntity* pSecondaryEntity) const = 0;

    virtual Acad::ErrorStatus 
        joinEntities(AcDbEntity* pPrimaryEntity, 
            const AcArray<AcDbEntity*>& otherEntities,
            AcGeIntArray& joinedEntityIndices) const = 0;
};

#pragma pack (pop)

//#endif

