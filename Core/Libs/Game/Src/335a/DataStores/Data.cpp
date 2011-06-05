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

#include "Data.h"
#include "ObjectMgr.h"

void Data::LoadAchievementData()
{
    sLog->outString("Loading Achievement Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AchievementStatement = DataDB.GetPreparedStatement(DATA_LOAD_ACHIEVEMENT_DBC);
        PreparedQueryResult AchievementResult = DataDB.Query(AchievementStatement);

        if (!AchievementResult)
        {
            sLog->outError("Error while loading Achievement Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AchievementResult->Fetch();
                AchievementData achievementData;

                achievementData.Id                = TableFields[0].GetUInt32();
                achievementData.RequiredFaction   = TableFields[1].GetInt32();
                achievementData.MapId             = TableFields[2].GetInt32();
                achievementData.ParentAchievement = TableFields[3].GetUInt32();
                achievementData.Name              = TableFields[4].GetString();
                achievementData.NameFlags         = TableFields[5].GetUInt32();
                achievementData.Description       = TableFields[6].GetString();
                achievementData.DescFlags         = TableFields[7].GetUInt32();
                achievementData.CategoryId        = TableFields[8].GetUInt32();
                achievementData.Points            = TableFields[9].GetUInt32();
                achievementData.OrderInCategory   = TableFields[10].GetUInt32();
                achievementData.Flags             = TableFields[11].GetUInt32();
                achievementData.Icon              = TableFields[12].GetUInt32();
                achievementData.TitleReward       = TableFields[13].GetString();
                achievementData.TitleRewardFlags  = TableFields[14].GetUInt32();
                achievementData.Count             = TableFields[15].GetUInt32();
                achievementData.RefAchievement    = TableFields[16].GetUInt32();

                AchievementDataTable[achievementData.Id] = achievementData;

                ++count;
            }
            while (AchievementResult->NextRow());

            sLog->outString(">> Loaded %u achievements %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAchievementCategoryData()
{
    sLog->outString("Loading Achievement Category Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AchievementCategoryStatement = DataDB.GetPreparedStatement(DATA_LOAD_ACHIEVEMENT_CATEGORY_DBC);
        PreparedQueryResult AchievementCategoryResult = DataDB.Query(AchievementCategoryStatement);

        if (!AchievementCategoryResult)
        {
            sLog->outError("Error while loading Achievement Category Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AchievementCategoryResult->Fetch();
                AchievementCategoryData achievementCategoryData;

                achievementCategoryData.Id             = TableFields[0].GetUInt32();
                achievementCategoryData.Name           = TableFields[1].GetString();
                achievementCategoryData.NameFlags      = TableFields[2].GetUInt32();
                achievementCategoryData.ParentCategory = TableFields[3].GetUInt32();
                achievementCategoryData.SortOrder      = TableFields[4].GetUInt32();

                AchievementCategoryDataTable[achievementCategoryData.Id] = achievementCategoryData;

                ++count;
            }
            while (AchievementCategoryResult->NextRow());

            sLog->outString(">> Loaded %u achievement categories %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAchievementCriteriaData()
{
    sLog->outString("Loading Achievement Criteria Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AchievementCriteriaStatement = DataDB.GetPreparedStatement(DATA_LOAD_ACHIEVEMENT_CRITERIA_DBC);
        PreparedQueryResult AchievementCriteriaResult = DataDB.Query(AchievementCriteriaStatement);

        if (!AchievementCriteriaResult)
        {
            sLog->outError("Error while loading Achievement Criteria Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AchievementCriteriaResult->Fetch();
                AchievementCriteriaData achievementCriteriaData;
                uint32 AddReqType = achievementCriteriaData.AdditionalRequirements[MAX_CRITERIA_REQUIREMENTS].AdditionalRequirementType;
                uint32 AddReqValue = achievementCriteriaData.AdditionalRequirements[MAX_CRITERIA_REQUIREMENTS].AdditionalRequirementValue;

                achievementCriteriaData.Id                         = TableFields[0].GetUInt32();
                achievementCriteriaData.ReferredAchievement        = TableFields[1].GetUInt32();
                achievementCriteriaData.RequiredType               = TableFields[2].GetUInt32();
                AddReqType                                         = TableFields[3].GetUInt32();
                AddReqValue                                        = TableFields[4].GetUInt32();
                achievementCriteriaData.TypeRelatedId              = TableFields[5].GetUInt32();
                achievementCriteriaData.TypeRelatedCount           = TableFields[6].GetUInt32();
                achievementCriteriaData.Name                       = TableFields[7].GetString();
                achievementCriteriaData.NameFlags                  = TableFields[8].GetUInt32();
                achievementCriteriaData.Flags                      = TableFields[9].GetUInt32();
                achievementCriteriaData.TimedType                  = TableFields[10].GetUInt32();
                achievementCriteriaData.TimerStartEvent            = TableFields[11].GetUInt32();
                achievementCriteriaData.TimeLimit                  = TableFields[12].GetUInt32();
                achievementCriteriaData.ShowOrder                  = TableFields[13].GetUInt32();

                AchievementCriteriaDataTable[achievementCriteriaData.Id] = achievementCriteriaData;

                ++count;
            }
            while (AchievementCriteriaResult->NextRow());

            sLog->outString(">> Loaded %u achievemt criterias %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAnimationDataData()
{
    sLog->outString("Loading Animation Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AnimationDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_ANIMATION_DATA_DBC);
        PreparedQueryResult AnimationDataResult = DataDB.Query(AnimationDataStatement);

        if (!AnimationDataResult)
        {
            sLog->outError("Error while loading Animation Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AnimationDataResult->Fetch();
                AnimationDataData animationDataData;

                animationDataData.Id           = TableFields[0].GetUInt32();
                animationDataData.Name         = TableFields[1].GetString();
                animationDataData.WeaponFlags  = TableFields[2].GetUInt32();
                animationDataData.BodyFlags    = TableFields[3].GetUInt32();
                animationDataData.Flags        = TableFields[4].GetUInt32();
                animationDataData.FallBack     = TableFields[5].GetUInt32();
                animationDataData.BehaviorId   = TableFields[6].GetUInt32();
                animationDataData.BehaviorTier = TableFields[7].GetUInt32();

                AnimationDataDataTable[animationDataData.Id] = animationDataData;

                ++count;
            }
            while (AnimationDataResult->NextRow());

            sLog->outString(">> Loaded %u Animation Datas %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAreaGroupData()
{
    sLog->outString("Loading AreaGroup Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AreaGroupDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_AREAGROUP_DATA_DBC);
        PreparedQueryResult AreaGroupDataResult = DataDB.Query(AreaGroupDataStatement);

        if (!AreaGroupDataResult)
        {
            sLog->outError("Error while loading AreaGroup Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AreaGroupDataResult->Fetch();
                AreaGroupData areaGroupData;

                areaGroupData.AreaGroupId = TableFields[0].GetUInt32();

                for (int i = 0; i < MAX_GROUP_AREA_IDS; i++)
                    areaGroupData.AreaId[i] = TableFields[1 + i].GetUInt32();

                areaGroupData.NextGroup = TableFields[7].GetUInt32();

                AreaGroupDataTable[areaGroupData.AreaGroupId] = areaGroupData;

                ++count;
            }
            while (AreaGroupDataResult->NextRow());

            sLog->outString(">> Loaded %u Area Groups %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAreaPoiData()
{
    sLog->outString("Loading AreaPoi Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AreaPoiDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_AREAPOI_DATA_DBC);
        PreparedQueryResult AreaPoiDataResult = DataDB.Query(AreaPoiDataStatement);

        if (!AreaPoiDataResult)
        {
            sLog->outError("Error while loading AreaPoi Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AreaPoiDataResult->Fetch();
                AreaPoiData areaPoiData;

                areaPoiData.Id = TableFields[0].GetUInt32();

                for (int i = 0; i < 11; i++)
                    areaPoiData.Icon[i] = TableFields[1 + i].GetUInt32();

                areaPoiData.X            = TableFields[12].GetFloat();
                areaPoiData.Y            = TableFields[13].GetFloat();
                areaPoiData.Z            = TableFields[14].GetFloat();
                areaPoiData.MapId        = TableFields[15].GetUInt32();
                areaPoiData.FactionId    = TableFields[16].GetUInt32();
                areaPoiData.ZoneId       = TableFields[17].GetUInt32();
                areaPoiData.Name         = TableFields[18].GetString();
                areaPoiData.NameFlag     = TableFields[19].GetUInt32();
                areaPoiData.Description  = TableFields[20].GetString();
                areaPoiData.Flags        = TableFields[21].GetUInt32();
                areaPoiData.WorldState   = TableFields[22].GetUInt32();
                areaPoiData.WorldMapLink = TableFields[23].GetUInt32();

                AreaPoiDataTable[areaPoiData.Id] = areaPoiData;

                ++count;
            }
            while (AreaPoiDataResult->NextRow());

            sLog->outString(">> Loaded %u area pois %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAreaTableData()
{
    sLog->outString("Loading AreaTable Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AreaTableDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_AREATABLE_DATA_DBC);
        PreparedQueryResult AreaTableDataResult = DataDB.Query(AreaTableDataStatement);

        if (!AreaTableDataResult)
        {
            sLog->outError("Error while loading AreaTable Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AreaTableDataResult->Fetch();
                AreaTableData areaTableData;

                areaTableData.Id          = TableFields[0].GetUInt32();
                areaTableData.MapId       = TableFields[1].GetUInt32();
                areaTableData.ZoneId      = TableFields[2].GetUInt32();
                areaTableData.ExploreFlag = TableFields[3].GetUInt32();
                areaTableData.Flags       = TableFields[4].GetUInt32();
                areaTableData.AreaLevel   = TableFields[5].GetInt32();
                areaTableData.AreaName    = TableFields[6].GetString();
                areaTableData.NameFlags   = TableFields[7].GetUInt32();
                areaTableData.TeamId      = TableFields[8].GetUInt32();

                AreaTableDataTable[areaTableData.Id] = areaTableData;

                ++count;
            }
            while (AreaTableDataResult->NextRow());

            sLog->outString(">> Loaded %u area tables %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAreaTriggerData()
{
    sLog->outString("Loading AreaTrigger Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AreaTriggerDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_AREATRIGGER_DATA_DBC);
        PreparedQueryResult AreaTriggerDataResult = DataDB.Query(AreaTriggerDataStatement);

        if (!AreaTriggerDataResult)
        {
            sLog->outError("Error while loading AreaTrigger Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AreaTriggerDataResult->Fetch();
                AreaTriggerData areaTriggerData;

                areaTriggerData.Id             = TableFields[0].GetUInt32();
                areaTriggerData.MapId          = TableFields[1].GetUInt32();
                areaTriggerData.X              = TableFields[2].GetFloat();
                areaTriggerData.Y              = TableFields[3].GetFloat();
                areaTriggerData.Z              = TableFields[4].GetFloat();
                areaTriggerData.Radius         = TableFields[5].GetFloat();
                areaTriggerData.BoxLength_X    = TableFields[6].GetFloat();
                areaTriggerData.BoxLength_Y    = TableFields[7].GetFloat();
                areaTriggerData.BoxLength_Z    = TableFields[8].GetFloat();
                areaTriggerData.BoxOrientation = TableFields[9].GetFloat();

                AreaTriggerDataTable[areaTriggerData.Id] = areaTriggerData;

                ++count;
            }
            while (AreaTriggerDataResult->NextRow());

            sLog->outString(">> Loaded %u area triggers %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}
