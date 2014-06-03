// $Header: //depot/release/ironman2012/develop/global/inc/dbxsdk/gecint3d.h#1 $ $Change: 237375 $ $DateTime: 2011/01/30 18:32:54 $ $Author: integrat $
// $NoKeywords: $
#ifndef AC_GECINT3D_H
#define AC_GECINT3D_H
//
// (C) Copyright 1993-1999 by Autodesk, Inc. 
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
// Description: class  AcGeCurveCurveInt3d to hold data for intersectios
// of two 3d curves

#include "adesk.h"
#include "geent3d.h"
#include "geponc3d.h"
#include "geintrvl.h"
#pragma pack (push, 8)

class AcGeCurve3d;


class  
GE_DLLEXPIMPORT
AcGeCurveCurveInt3d : public AcGeEntity3d
{

public:
    // Constructors.
    //
    AcGeCurveCurveInt3d ();
    AcGeCurveCurveInt3d (const AcGeCurve3d& curve1, const AcGeCurve3d& curve2,
		                 const AcGeVector3d& planeNormal =
						 AcGeVector3d::kIdentity,
                         const AcGeTol& tol = AcGeContext::gTol );
    AcGeCurveCurveInt3d (const AcGeCurve3d& curve1, const AcGeCurve3d& curve2,
                         const AcGeInterval& range1, const AcGeInterval& range2,
		                 const AcGeVector3d& planeNormal=AcGeVector3d::kIdentity,
                         const AcGeTol& tol = AcGeContext::gTol);
    AcGeCurveCurveInt3d (const AcGeCurveCurveInt3d& src);

    // General query functions.
    //
    const AcGeCurve3d  *curve1          () const;
    const AcGeCurve3d  *curve2          () const;
    void               getIntRanges     (AcGeInterval& range1,
                                         AcGeInterval& range2) const;
	AcGeVector3d	   planeNormal		() const;
    AcGeTol            tolerance        () const;

    // Intersection query methods.
    //
    int                numIntPoints     () const;
    AcGePoint3d        intPoint         (int intNum) const;
    void               getIntParams     (int intNum,
                                         double& param1, double& param2) const;
    void               getPointOnCurve1 (int intNum, AcGePointOnCurve3d& pntOnCrv) const;
    void               getPointOnCurve2 (int intNum, AcGePointOnCurve3d& pntOnCrv) const;
    void			   getIntConfigs    (int intNum, AcGe::AcGeXConfig& config1wrt2, 
                                         AcGe::AcGeXConfig& config2wrt1) const;
    Adesk::Boolean     isTangential     (int intNum) const;
    Adesk::Boolean     isTransversal    (int intNum) const;
    double             intPointTol      (int intNum) const;
    int                overlapCount     () const;
	Adesk::Boolean	   overlapDirection () const;
    void               getOverlapRanges (int overlapNum,
                                         AcGeInterval& range1,
                                         AcGeInterval& range2) const;

    // Curves change their places
    //
    void               changeCurveOrder (); 
        
    // Order with respect to parameter on the first/second curve.
    //
    AcGeCurveCurveInt3d& orderWrt1  ();    
    AcGeCurveCurveInt3d& orderWrt2  ();
    
    // Set functions.
    //
    AcGeCurveCurveInt3d& set        (const AcGeCurve3d& curve1,
                                     const AcGeCurve3d& curve2,
		                             const AcGeVector3d& planeNormal = 
								     AcGeVector3d::kIdentity,
                                     const AcGeTol& tol = AcGeContext::gTol);
    AcGeCurveCurveInt3d& set        (const AcGeCurve3d& curve1,
                                     const AcGeCurve3d& curve2,
                                     const AcGeInterval& range1,
                                     const AcGeInterval& range2,
		                             const AcGeVector3d& planeNormal = 
							         AcGeVector3d::kIdentity,
                                     const AcGeTol& tol = AcGeContext::gTol);

    // Assignment operator.
    //
    AcGeCurveCurveInt3d& operator = (const AcGeCurveCurveInt3d& src);
};

#pragma pack (pop)
#endif
