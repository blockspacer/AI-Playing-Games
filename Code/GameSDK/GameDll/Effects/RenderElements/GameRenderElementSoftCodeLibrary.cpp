/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
// Original file Copyright Crytek GMBH or its affiliates, used under license.

// Description : Render Node Soft Code Library


#include "StdAfx.h"
#include <TypeLibrary.h>
#include "Effects/RenderElements/GameRenderElement.h"

#ifdef SOFTCODE
// Pull in the system and platform util functions
#include <platform_impl.h>
#endif

IMPLEMENT_TYPELIB(GameSDKIGameRenderElement, GAME_RENDER_ELEMENT_LIBRARY_NAME); // Implementation of Soft Coding library