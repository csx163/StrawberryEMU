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

    PREPARE_STATEMENT(DATA_LOAD_ATTACKANIMTYPES_DATA_DBC, "SELECT Id, Name FROM AttackAnimTypes", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AUCTIONHOUSE_DATA_DBC, "SELECT Id, FactionId, DepositRate, ConsignmentRate, Name, NameFlags FROM AuctionHouse", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BANKBAGSLOTPRICES_DATA_DBC, "SELECT Id, Price FROM BangBagSlotPrices", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BANNEDADDONS_DATA_DBC, "SELECT Id, Md5Name, NameFlags, Md5Name2, NameFlags2, Md5Version, VersionFlags, Md5Version2, VersionFlags2, LastModified, "
                                                       "ModFlags FROM BannedAddOns", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BARBERSHOPSTYLE_DATA_DBC, "SELECT Id, Type, Name, NameFlags, Description, DescriptionFlags, CostMultiplier, RaceId, GenderId, HairId "
                                                          "FROM BarberShopStyle", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_BATTLEMASTERLIST_DATA_DBC, "SELECT Id, MapId, MapId1, MapId2, MapId3, MapId4, MapId5, MapId6, MapId7, InstanceTypeId, Groups, Name, "
                                                           "NameFlags, MaxGroupSize, HolidayWorldState, MinLevel, MaxLevel", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CAMERASHAKES_DATA_DBC, "SELECT Id, ShakeType, Direction, Amplitude, Frequency, Duration, Phase, Coefficient FROM CameraShakes", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CFG_CATEGORIES_DATA_DBC, "SELECT Id, LocaleMask, CharSetMask, Flags, Name, NameFlags FROM Cfg_Categories", CONNECTION_SYNCH);
    PREPARE_STATEMENT(DATA_LOAD_CFG_CONFIGS_DATA_DBC, "SELECT Id, GenId, PvP, RolePlay", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_CHARACTERFACIALHAIRSTYLES_DATA_DBC, "SELECT GenId, RaceId, VariationId, GeoSet, GeoSet1, GeoSet2, GeoSet3, GeoSet4", CONNECTION_SYNCH);
}
