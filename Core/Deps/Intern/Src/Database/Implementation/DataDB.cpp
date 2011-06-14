/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com>
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "DataDB.h"

void DataDBConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_DATADB_STATEMENTS);

    PREPARE_STATEMENT(DATA_LOAD_ACHIEVEMENT_DBC, "SELECT Id, RequiredFaction, MapId, ParentAchievement, Name, NameFlags, Description, DescFlags, CategoryId, "
                                                "Points, OrderInCategory, Flags, Icon, TitleReward, TitleRewardFlags, Count, RefAchievement FROM Achievement", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_ACHIEVEMENT_CATEGORY_DBC, "SELECT Id, ParentCategory, Name, NameFlags, SortOrder FROM Achievement_Category", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_ACHIEVEMENT_CRITERIA_DBC, "SELECT Id, ReferredAchievement, RequiredType, Value, Count, AddReqType, AddReqValue, TypeRelatedId, "
                                                          "TypeRelatedCount, Name, NameFlags, Flags, TimedType, TimerStartEvent, TimeLimit, ShowOrder FROM "
                                                          "Achievement_Criteria", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_ANIMATION_DATA_DBC, "SELECT Id, Name, WeaponFlags, BodyFlags, Flags, FallBack, BehaviorId, BehaviorTier FROM AnimationData", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AREAGROUP_DATA_DBC, "SELECT AreaGroupId, AreaId, AreaId1, AreaId2, AreaId3, AreaId4, AreaId5, NextGroup FROM AreaGroup", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AREAPOI_DATA_DBC, "SELECT Id, Icon, Icon1, Icon2, Icon3, Icon4, Icon5, Icon6, Icon7, Icon8, Icon9, Icon10, X, Y, Z, MapId, FactionId, "
                                                  "ZoneId, Name, WorldStateId, WorldMapLink FROM AreaPoi", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AREATABLE_DATA_DBC, "SELECT Id, MapId, ZoneId, ExploreFlag, Flags, SoundProvider, SoundProviderUw, AmbienceId, ZoneMusicId, IntroId, AreaLevel, "
                                                    "AreaName, NameFlags, TeamId, LiquidTypeId, MinElevation, AmbientMultiplier FROM AreaTable", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AREATRIGGER_DATA_DBC, "SELECT Id, MapId, X, Y, Z, Radius, BoxLength_X, BoxLength_Y, BoxLength_Z, BoxOrientation FROM AreaTrigger", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_ATTACKANIMKITS_DATA_DBC, "SELECT Id, Duration, AnimKitStop, AnimFlags FROM AttackAnimKits", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_ATTACKANIMTYPES_DATA_DBC, "SELECT Id, AttackName FROM AttackAnimTypes", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AUCTIONHOUSE_DATA_DBC, "SELECT Id, FactionId, DepositRate, ConsignmentRate, Name, NameFlags FROM AuctionHouse", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BANKBAGSLOTPRICES_DATA_DBC, "SELECT Id, Price FROM BankBagSlotPrices", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BANNEDADDONS_DATA_DBC, "SELECT Id, Md5Name, NameFlags, Md5Name2, NameFlags2, Md5Version, VersionFlags, Md5Version2, VersionFlags2, LastModified, "
                                                       "ModFlags FROM BannedAddOns", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BARBERSHOPSTYLE_DATA_DBC, "SELECT Id, Type, Name, NameFlags, Description, DescriptionFlags, CostMultiplier, RaceId, GenderId, HairId "
                                                          "FROM BarberShopStyle", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BATTLEMASTERLIST_DATA_DBC, "SELECT Id, MapId, MapId1, MapId2, MapId3, MapId4, MapId5, MapId6, MapId7, InstanceTypeId, Groups, Name, "
                                                           "NameFlags, MaxGroupSize, HolidayWorldState, MinLevel, MaxLevel FROM BattleMasterList", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CAMERASHAKES_DATA_DBC, "SELECT Id, ShakeType, Direction, Amplitude, Frequency, Duration, Phase, Coefficient FROM CameraShakes", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CFG_CATEGORIES_DATA_DBC, "SELECT Id, LocaleMask, CharSetMask, Flags, Name, NameFlags FROM Cfg_Categories", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CFG_CONFIGS_DATA_DBC, "SELECT Id, GenId, PvP, RolePlay FROM Cfg_Configs", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CHARACTERFACIALHAIRSTYLES_DATA_DBC, "SELECT GenId, RaceId, VariationId, GeoSet, GeoSet1, GeoSet2, GeoSet3, GeoSet4 FROM "
                                                                    "CharacterFacialHairStyles", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CHARBASEINFO_DATA_DBC, "SELECT RaceId, ClassId FROM CharBaseInfo", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CHARHAIRGEOSETS_DATA_DBC, "SELECT Id, RaceId, GenderId, VariationId, Geoset, ShowScalp FROM CharHairGeosets", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CHARHAIRTEXTURES_DATA_DBC, "SELECT Id, RaceId, GenderId, Unknown, Unknown1, Value, Value1 FROM CharHairTextures", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CHARSECTIONS_DATA_DBC, "SELECT Id, RaceId, GenderId, BaseSection, TextureName, NameFlags, VariationIndex, ColorIndex FROM CharSections", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CHARSTARTOUTFIT_DATA_DBC, "SELECT Id, RaceId, ClassId, GenderId, SomeValues, ItemId, ItemId1, ItemId2, ItemId3, ItemId4, ItemId5, ItemId6, ItemId7, "
                                                          "ItemId8, ItemId9, ItemId10, ItemId11, ItemId12, ItemId13, ItemId14, ItemId15, ItemId16, ItemId17, ItemId18, ItemId19, "
                                                          "ItemId20, ItemId21, ItemId22, ItemId23, DisplayId, DisplayId1, DisplayId2, DisplayId3, DisplayId4, DisplayId5, DisplayId6, "
                                                          "DisplayId7, DisplayId8, DisplayId9, DisplayId10, DisplayId11, DisplayId12, DisplayId13, DisplayId14, DisplayId15, DisplayId16, "
                                                          "DisplayId17, DisplayId18, DisplayId19, DisplayId20, DisplayId21, DisplayId22, DisplayId23, InventoryType, InventoryType1, "
                                                          "InventoryType2, InventoryType3, InventoryType4, InventoryType5, InventoryType6, InventoryType7, InventoryType8, InventoryType9, "
                                                          "InventoryType10, InventoryType11, InventoryType12, InventoryType13, InventoryType14, InventoryType15, InventoryType16, "
                                                          "InventoryType17, InventoryType18, InventoryType19, InventoryType20, InventoryType21, InventoryType22, InventoryType23 "
                                                          "FROM CharStartOutfit", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CHARTITLES_DATA_DBC, "SELECT Id, ConditionId, Title, TitleFlags, SubTitle, SubTitleFlags, MaskIndex FROM CharTitles", CONNECTION_SYNCH);
    //PREPARE_STATEMENT(DATA_LOAD_CHARVARIATIONS_DATA_DBC, "SELECT FROM CharVariations", CONNECTION_SYNCH);
}
