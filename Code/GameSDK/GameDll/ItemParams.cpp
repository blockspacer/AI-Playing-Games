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

#include "StdAfx.h"
#include "Item.h"
#include "ItemSharedParams.h"
#include "Game.h"

//------------------------------------------------------------------------
void CItem::ReadProperties(IScriptTable *pProperties)
{
	if (pProperties)
	{
		GetEntityProperty("HitPoints", m_properties.hitpoints);
		GetEntityProperty("bPickable", m_properties.pickable);
		GetEntityProperty("bMounted", m_properties.mounted);
		GetEntityProperty("bUsable", m_properties.usable);

		GetEntityProperty("Respawn", "bRespawn", m_respawnprops.respawn);
		GetEntityProperty("Respawn", "nTimer", m_respawnprops.timer);
		GetEntityProperty("Respawn", "bUnique", m_respawnprops.unique);

		int physicsTemp;
		GetEntityProperty("eiPhysicsType", physicsTemp);
		m_properties.physics = (ePhysicalization)physicsTemp;

		if(!gEnv->bMultiplayer)
		{
			GetEntityProperty("bSpecialSelect", m_properties.specialSelect);

			ReadMountedProperties(pProperties);
		}
	}
}

//------------------------------------------------------------------------
void CItem::ReadMountedProperties(IScriptTable* pScriptTable)
{
	float minPitch = 0.f;
	float maxPitch = 0.f;

	GetEntityProperty("MountedLimits", "pitchMin", minPitch);
	GetEntityProperty("MountedLimits", "pitchMax", maxPitch);
	GetEntityProperty("MountedLimits", "yaw", m_properties.mounted_yaw_range);

	m_properties.mounted_min_pitch = min(minPitch,maxPitch);
	m_properties.mounted_max_pitch = max(minPitch,maxPitch);

	GetEntityProperty("Respawn", "bRespawn", m_respawnprops.respawn);
	GetEntityProperty("Respawn", "nTimer", m_respawnprops.timer);
	GetEntityProperty("Respawn", "bUnique", m_respawnprops.unique);
}

//------------------------------------------------------------------------
void CItem::InitItemFromParams()
{
	InitGeometry();
	InitAccessories();
	InitDamageLevels();
}

//------------------------------------------------------------------------
void CItem::InitGeometry()
{
	FUNCTION_PROFILER(GetISystem(), PROFILE_GAME);

	//skip loading the first person geometry for now, it may never be used
	m_sharedparams->LoadGeometryForItem(this, eIGS_FirstPerson);
}

//-----------------------------------------------------------------------
void CItem::InitAccessories()
{
	m_initialSetup = m_sharedparams->initialSetup;
}

//-----------------------------------------------------------------------
void CItem::InitDamageLevels()
{
	int numLevels = m_sharedparams->damageLevels.size();

	m_damageLevelEffects.resize(numLevels);

	for(int i = 0; i < numLevels; i++)
	{
		m_damageLevelEffects[i] = -1;
	}
}