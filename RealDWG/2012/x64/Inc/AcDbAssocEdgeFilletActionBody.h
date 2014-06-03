// $Header: //depot/release/ironman2012/develop/global/inc/dbxsdk/AcDbAssocEdgeFilletActionBody.h#1 $ 
// $Change: 237375 $ $DateTime: 2011/01/30 18:32:54 $ $Author: integrat $
// $NoKeywords: $
//////////////////////////////////////////////////////////////////////////////
//
// Copyright � 2009-2011 by Autodesk, Inc. 
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
// CREATED BY: Sharad Jaiswal                           Sept 2009
//
// DESCRIPTION:
//
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "acdbassocpathbasedsurfaceactionbody.h"
#pragma pack (push, 8)


/// <summary>
/// AcDbAssocEdgeFilletActionBody is an action body that controls edge fillet 
/// applied to a surface with the set of input data of the action. 
/// The "input data" for this action are list of edges, fillet radius and the
/// surface to which the input edges belongs.
/// </summary>
///
class ACDB_PORT AcDbAssocEdgeFilletActionBody : public AcDbAssocPathBasedSurfaceActionBody
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocEdgeFilletActionBody);

    /// <summary> Default constructor. </summary>
    /// <param name="createImpObject"> See AcDbAssocCreateImpObject. </param>
    ///
    explicit AcDbAssocEdgeFilletActionBody(AcDbAssocCreateImpObject createImpObject = kAcDbAssocCreateImpObject);

    /// <summary> Method to set input edges for fillet. </summary>
    /// <param name="filletEdges"> List of input edges. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus setInputEdges(const AcDbFullSubentPathArray& filletEdges);

    /// <summary><para> 
    /// Sets fillet radius value, expression and evaluatorId for this action.
    /// If there is no expression, the expression string and the evaluatorId 
    /// must be empty strings. 
    /// </para><para>
    /// Fillet radius can also be set using setValueParam method with paramName
    /// kFilletRadiusParamName and value index 0.
    /// </para></summary>
    /// <param name="radius"> Radius value. </param>
    /// <param name="expression">  expression of radius parameter. </param>
    /// <param name="evaluatorId"> evaluator id. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    ///
    Acad::ErrorStatus setRadius(double radius, const AcString& expression = AcString(), 
        const AcString& evaluatorId = AcString());
    
    /// <summary><para> 
    /// Gets fillet radius value, expression and evaluatorId for this action.
    /// If there is no expression, the expression string and the evaluatorId 
    /// are empty strings. 
    /// </para><para>
    /// Fillet radius can also be obtained using getValueParam method with 
    /// paramName kFilletRadiusParamName and value index 0.
    /// </para></summary>
    /// <param name="expression">  expression of the parameter. </param>
    /// <param name="evaluatorId"> evaluator id. </param>
    /// <returns> Radius value. </returns>
    ///
    double radius(AcString& expression = dummyString(), AcString& evaluatorId = dummyString()) const;

    /// <summary>
    /// Implements abstract method AcDbAssocActionBody::evaluateOverride(), this
    /// method is called while evaluating the parent action that owns this action 
    /// body object.
    /// </summary>
    ///
    virtual void evaluateOverride();

    /// <summary><para>
    /// Utility function to create AcDbAssocEdgeFilletActionBody and attach 
    /// dependencies and actions for given filletEdges.
    /// </para><para>
    /// This method must be called before applying actual fillet on the input 
    /// edges and after calling this method, it is advised to evaluate the
    /// associative network.
    /// </para></summary>
    /// <param name="filletEdges"> List of input edges. </param>
    /// <param name="radius"> Radius value. </param>
    /// <param name="bEnabled">  Specify if the action is fully associative. </param>
    /// <param name="createdActionId"> Object id for action owning 
    /// created instance of AcDbAssocEdgeFilletActionBody. </param>
    /// <returns> Acad::ErrorStatus. </returns>
    /// 
    static Acad::ErrorStatus createInstance( const AcDbFullSubentPathArray& filletEdges,
                                             double radius,
                                             bool bEnabled,
                                             AcDbObjectId& createdActionId);
};

#pragma pack (pop)

