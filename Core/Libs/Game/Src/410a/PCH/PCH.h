//add here most rarely modified headers to speed up debug build compilation

#include "WorldSocket.h"        // must be first to make ACE happy with ACE includes in it

#include "Common.h"

#include "MapManager.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectDefines.h"
#include "SQLStorage.h"
#include "SharedDefines.h"
#include "ObjectMgr.h"

// Opcode Handler includes
#include "OpcodeHandler.h"
#include "ClientOpcodeHandler.h"
#include "ClientServerOpcodeHandler.h"
#include "ServerOpcodeHandler.h"

// Script includes
#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
