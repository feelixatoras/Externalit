#pragma once
#include <winsock2.h>
#include "Windows.h"
#include <stdio.h>
#include <cstdint>
#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <deque>
#include <random>
#include <Psapi.h>
#include <atomic>
#include <array>
#include <chrono>
#include <iomanip>
#include <iphlpapi.h>
#include <locale>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <thread>
#include <assert.h>
#include <cstddef>
#include <thread>
#include <TlHelp32.h>
#include <tchar.h>

#define PI 3.14159265358979323846f

//shit
#include "memory/memory.h"
#include "math/vector.h"
#include "utils/utils.h"
#include "weapon/weapon.h"
#include "entity/entity.h"
#include "csgo/engine.h"
#include "csgo/client.h"
#include "math/math.h"
#include "iniparser/iniparser.h"
#include "settings/settings.h"


//cheetos
#include "../features/aimbot/aimbot.h"
#include "../features/triggerbot/triggerbot.h"
#include "../features//misc/autopistol.h"
#include "../features//misc/clantag.h"
#include "../features//misc/fovchanger.h"
#include "../features//misc/noflash.h"
#include "../features//misc/radarhack.h"
#include "../features//misc/rankreveal.h"
#include "../features/misc/bunnyhop.h"
#include "../features/misc/fakelag.h"
#include "../features//misc/slowaim.h"
#include "../features//visuals/chams.h"
#include "../features//visuals/glow.h"
#include "../features/skinchanger/skinchanger.h"

namespace sdk {

	namespace offys {
		extern uint32_t clientdll;
		extern uint32_t enginedll;
		extern uint32_t m_bDormant;
		extern uint32_t m_zoomLevel;
		extern uint32_t m_dwRankRevealAllFn;
		extern uint32_t m_clrRender;
		extern uint32_t m_ArmorValue;
		extern uint32_t m_Collision;
		extern uint32_t m_CollisionGroup;
		extern uint32_t m_Local;
		extern uint32_t m_MoveType;
		extern uint32_t m_OriginalOwnerXuidHigh;
		extern uint32_t m_OriginalOwnerXuidLow;
		extern uint32_t m_aimPunchAngle;
		extern uint32_t m_aimPunchAngleVel;
		extern uint32_t m_bGunGameImmunity;
		extern uint32_t m_bHasDefuser;
		extern uint32_t m_bHasHelmet;
		extern uint32_t m_bInReload;
		extern uint32_t m_bIsDefusing;
		extern uint32_t m_bIsScoped;
		extern uint32_t m_bSpotted;
		extern uint32_t m_bSpottedByMask;
		extern uint32_t m_dwBoneMatrix;
		extern uint32_t m_fAccuracyPenalty;
		extern uint32_t m_fFlags;
		extern uint32_t m_flFallbackWear;
		extern uint32_t m_flFlashDuration;
		extern uint32_t m_flFlashMaxAlpha;
		extern uint32_t m_flNextPrimaryAttack;
		extern uint32_t m_hActiveWeapon;
		extern uint32_t m_hMyWeapons;
		extern uint32_t m_hObserverTarget;
		extern uint32_t m_hOwner;
		extern uint32_t m_hOwnerEntity;
		extern uint32_t m_iAccountID;
		extern uint32_t m_iClip1;
		extern uint32_t m_iCompetitiveRanking;
		extern uint32_t m_iCompetitiveWins;
		extern uint32_t m_iCrosshairId;
		extern uint32_t m_iEntityQuality;
		extern uint32_t m_iFOVStart;
		extern uint32_t m_iGlowIndex;
		extern uint32_t m_iHealth;
		extern uint32_t m_iItemDefinitionIndex;
		extern uint32_t m_iItemIDHigh;
		extern uint32_t m_iObserverMode;
		extern uint32_t m_iShotsFired;
		extern uint32_t m_iState;
		extern uint32_t m_iTeamNum;
		extern uint32_t m_lifeState;
		extern uint32_t m_nFallbackPaintKit;
		extern uint32_t m_nFallbackSeed;
		extern uint32_t m_nFallbackStatTrak;
		extern uint32_t m_nForceBone;
		extern uint32_t m_nTickBase;
		extern uint32_t m_rgflCoordinateFrame;
		extern uint32_t m_szCustomName;
		extern uint32_t m_szLastPlaceName;
		extern uint32_t m_thirdPersonViewAngles;
		extern uint32_t m_vecOrigin;
		extern uint32_t m_vecVelocity;
		extern uint32_t m_vecViewOffset;
		extern uint32_t m_viewPunchAngle;
		extern uint32_t dwClientState;
		extern uint32_t dwClientState_GetLocalPlayer;
		extern uint32_t dwClientState_IsHLTV;
		extern uint32_t dwClientState_Map;
		extern uint32_t dwClientState_MapDirectory;
		extern uint32_t dwClientState_MaxPlayer;
		extern uint32_t dwClientState_PlayerInfo;
		extern uint32_t dwClientState_State;
		extern uint32_t dwClientState_ViewAngles;
		extern uint32_t dwEntityList;
		extern uint32_t dwForceAttack;
		extern uint32_t dwForceAttack2;
		extern uint32_t dwForceBackward;
		extern uint32_t dwForceForward;
		extern uint32_t dwForceJump;
		extern uint32_t dwForceLeft;
		extern uint32_t dwForceRight;
		extern uint32_t dwGameDir;
		extern uint32_t dwGameRulesProxy;
		extern uint32_t dwGetAllClasses;
		extern uint32_t dwGlobalVars;
		extern uint32_t dwGlowObjectManager;
		extern uint32_t dwInput;
		extern uint32_t dwInterfaceLinkList;
		extern uint32_t dwLocalPlayer;
		extern uint32_t dwMouseEnable;
		extern uint32_t dwMouseEnablePtr;
		extern uint32_t dwPlayerResource;
		extern uint32_t dwRadarBase;
		extern uint32_t dwSensitivity;
		extern uint32_t dwSensitivityPtr;
		extern uint32_t dwSetClanTag;
		extern uint32_t dwViewMatrix;
		extern uint32_t dwWeaponTable;
		extern uint32_t dwWeaponTableIndex;
		extern uint32_t dwYawPtr;
		extern uint32_t dwZoomSensitivityRatioPtr;
		extern uint32_t dwbSendPackets;
		extern uint32_t dwppDirect3DDevice9;
		extern uint32_t m_pStudioHdr;
	}
	namespace globals {
		extern std::auto_ptr<centity> local;
		extern std::auto_ptr<cweapon> weapon;
	}
	enum itemdefinitionindex
	{
		weapon_none,
		weapon_deagle = 1,
		weapon_elite = 2,
		weapon_fiveseven = 3,
		weapon_glock = 4,
		weapon_ak47 = 7,
		weapon_aug = 8,
		weapon_awp = 9,
		weapon_famas = 10,
		weapon_g3sg1 = 11,
		weapon_galilar = 13,
		weapon_m249 = 14,
		weapon_m4a1 = 16,
		weapon_mac10 = 17,
		weapon_p90 = 19,
		weapon_mp5 = 23,
		weapon_ump45 = 24,
		weapon_xm1014 = 25,
		weapon_bizon = 26,
		weapon_mag7 = 27,
		weapon_negev = 28,
		weapon_sawedoff = 29,
		weapon_tec9 = 30,
		weapon_taser = 31,
		weapon_hkp2000 = 32,
		weapon_mp7 = 33,
		weapon_mp9 = 34,
		weapon_nova = 35,
		weapon_p250 = 36,
		weapon_scar20 = 38,
		weapon_sg556 = 39,
		weapon_ssg08 = 40,
		weapon_knifegg = 41,
		weapon_knife = 42,
		weapon_flashbang = 43,
		weapon_hegrenade = 44,
		weapon_smokegrenade = 45,
		weapon_molotov = 46,
		weapon_decoy = 47,
		weapon_incgrenade = 48,
		weapon_c4 = 49,
		weapon_knife_t = 59,
		weapon_m4a1_silencer = 60,
		weapon_usp_silencer = 61,
		weapon_cz75a = 63,
		weapon_r8revolver = 64,
		weapon_knife_bayonet = 500,
		weapon_knife_flip = 505,
		weapon_knife_gut = 506,
		weapon_knife_karambit = 507,
		weapon_knife_m9_bayonet = 508,
		weapon_knife_tactical = 509,
		weapon_knife_falchion = 512,
		weapon_knife_bowie = 514,
		weapon_knife_butterfly = 515,
		weapon_knife_push = 516,
		max_value
	};

	struct glow_t
	{
		float    unk1;

		float            r;
		float			 g;
		float			 b;
		float            a;

		char            unk2[16];


		bool            occluded;
		bool            unoccluded;
	}; 
	struct clr_t
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;
	};
}
























