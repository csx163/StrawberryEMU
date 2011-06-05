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
                                                  "ZoneId, Name, NameFlag, Description, Flags, WorldState, WorldMapLink FROM AreaPoi", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AREATABLE_DATA_DBC, "SELECT Id, MapId, ZoneId, ExploreFlag, Flags, AreaLevel, AreaName, NameFlags, TeamId FROM AreaTable", CONNECTION_SYNCH);

    PREPARE_STATEMENT(DATA_LOAD_AREATRIGGER_DATA_DBC, "SELECT Id, MapId, X, Y, Z, Radius, BoxLength_X, BoxLength_Y, BoxLength_Z, BoxOrientation FROM AreaTrigger", CONNECTION_SYNCH);
}
