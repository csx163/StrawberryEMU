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
                areaPoiData.WorldStateId = TableFields[19].GetUInt32();
                areaPoiData.WorldMapLink = TableFields[20].GetUInt32();

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

                areaTableData.Id                = TableFields[0].GetUInt32();
                areaTableData.MapId             = TableFields[1].GetUInt32();
                areaTableData.ZoneId            = TableFields[2].GetUInt32();
                areaTableData.ExploreFlag       = TableFields[3].GetUInt32();
                areaTableData.Flags             = TableFields[4].GetUInt32();
                areaTableData.SoundProvider     = TableFields[5].GetUInt32();
                areaTableData.SoundProviderUw   = TableFields[6].GetUInt32();
                areaTableData.AmbienceId        = TableFields[7].GetUInt32();
                areaTableData.ZoneMusicId       = TableFields[8].GetUInt32();
                areaTableData.IntroId           = TableFields[9].GetUInt32();
                areaTableData.AreaLevel         = TableFields[10].GetInt32();
                areaTableData.AreaName          = TableFields[11].GetString();
                areaTableData.NameFlags         = TableFields[12].GetUInt32();
                areaTableData.TeamId            = TableFields[13].GetUInt32();
                areaTableData.LiquidTypeId      = TableFields[14].GetUInt32();
                areaTableData.MinElevation      = TableFields[15].GetFloat();
                areaTableData.AmbientMultiplier = TableFields[16].GetFloat();

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

void Data::LoadAttackAnimKitsData()
{
    sLog->outString("Loading AttackAnimKits Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AttackAnimKitDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_ATTACKANIMKITS_DATA_DBC);
        PreparedQueryResult AttackAnimKitDataResult = DataDB.Query(AttackAnimKitDataStatement);

        if (!AttackAnimKitDataResult)
        {
            sLog->outError("Error while loading AttackAnimKits Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AttackAnimKitDataResult->Fetch();
                AttackAnimKitsData attackAnimKitsData;

                attackAnimKitsData.Id          = TableFields[0].GetUInt32();
                attackAnimKitsData.Duration    = TableFields[1].GetUInt32();
                attackAnimKitsData.AnimKitStop = TableFields[2].GetUInt32();
                attackAnimKitsData.AnimFlags   = TableFields[3].GetUInt32();

                AttackAnimKitsDataTable[attackAnimKitsData.Id] = attackAnimKitsData;

                ++count;
            }
            while (AttackAnimKitDataResult->NextRow());

            sLog->outString(">> Loaded %u attack anim kits %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAuctionHouseData()
{
    sLog->outString("Loading AuctionHouse Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AuctionHouseDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_AUCTIONHOUSE_DATA_DBC);
        PreparedQueryResult AuctionHouseDataResult = DataDB.Query(AuctionHouseDataStatement);

        if (!AuctionHouseDataResult)
        {
            sLog->outError("Error while loading AuctionHouse Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AuctionHouseDataResult->Fetch();
                AuctionHouseData auctionHouseData;

                auctionHouseData.Id              = TableFields[0].GetUInt32();
                auctionHouseData.FactionId       = TableFields[1].GetUInt32();
                auctionHouseData.DepositRate     = TableFields[2].GetUInt32();
                auctionHouseData.ConsignmentRate = TableFields[3].GetUInt32();
                auctionHouseData.Name            = TableFields[4].GetString();
                auctionHouseData.NameFlags       = TableFields[5].GetUInt32();

                AuctionHouseDataTable[auctionHouseData.Id] = auctionHouseData;

                ++count;
            }
            while (AuctionHouseDataResult->NextRow());

            sLog->outString(">> Loaded %u auction houses %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadAttackAnimTypesData()
{
    sLog->outString("Loading AttackAnimTypes Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* AttackAnimTypesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_ATTACKANIMTYPES_DATA_DBC);
        PreparedQueryResult AttackAnimTypesDataResult = DataDB.Query(AttackAnimTypesDataStatement);

        if (!AttackAnimTypesDataResult)
        {
            sLog->outError("Error while loading AttackAnimTypes Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = AttackAnimTypesDataResult->Fetch();
                AttackAnimTypesData attackAnimTypesData;

                attackAnimTypesData.Id         = TableFields[0].GetUInt32();
                attackAnimTypesData.AttackName = TableFields[1].GetString();

                AttackAnimTypesDataTable[attackAnimTypesData.Id] = attackAnimTypesData;

                ++count;
            }
            while (AttackAnimTypesDataResult->NextRow());

            sLog->outString(">> Loaded %u attack anim types %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}



///////////////////

void Data::LoadBankBagSlotPricesData()
{
    sLog->outString("Loading BankBagSlotPrices Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* BankBagSlotPricesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_BANKBAGSLOTPRICES_DATA_DBC);
        PreparedQueryResult BankBagSlotPricesDataResult = DataDB.Query(BankBagSlotPricesDataStatement);

        if (!BankBagSlotPricesDataResult)
        {
            sLog->outError("Error while loading BankBagSlotPrices Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = BankBagSlotPricesDataResult->Fetch();
                BankBagSlotPricesData bankBagSlotPricesData;

                bankBagSlotPricesData.Id    = TableFields[0].GetUInt32();
                bankBagSlotPricesData.Price = TableFields[1].GetUInt32();

                BankBagSlotPricesDataTable[bankBagSlotPricesData.Id] = bankBagSlotPricesData;

                ++count;
            }
            while (BankBagSlotPricesDataResult->NextRow());

            sLog->outString(">> Loaded %u bankslot prices %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadBannedAddOnsData()
{
    sLog->outString("Loading BannedAddOns Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* BannedAddOnsDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_BANNEDADDONS_DATA_DBC);
        PreparedQueryResult BannedAddOnsDataResult = DataDB.Query(BannedAddOnsDataStatement);

        if (!BannedAddOnsDataResult)
        {
            sLog->outError("Error while loading BannedAddOns Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = BannedAddOnsDataResult->Fetch();
                BannedAddOnsData bannedAddOnsData;

                bannedAddOnsData.Id            = TableFields[0].GetUInt32();
                bannedAddOnsData.Md5Name       = TableFields[1].GetFloat();
                bannedAddOnsData.NameFlags     = TableFields[2].GetUInt32();
                bannedAddOnsData.Md5Name2      = TableFields[3].GetFloat();
                bannedAddOnsData.NameFlags2    = TableFields[4].GetUInt32();
                bannedAddOnsData.Md5Version    = TableFields[5].GetFloat();
                bannedAddOnsData.VersionFlags  = TableFields[6].GetUInt32();
                bannedAddOnsData.Md5Version2   = TableFields[7].GetFloat();
                bannedAddOnsData.VersionFlags2 = TableFields[8].GetUInt32();
                bannedAddOnsData.LastModified  = TableFields[9].GetFloat();
                bannedAddOnsData.ModFlags      = TableFields[10].GetUInt32();

                BannedAddOnsDataTable[bannedAddOnsData.Id] = bannedAddOnsData;

                ++count;
            }
            while (BannedAddOnsDataResult->NextRow());

            sLog->outString(">> Loaded %u banned addons %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadBarberShopStyleData()
{
    sLog->outString("Loading BarberShopStyleData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* BarberShopStyleDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_BARBERSHOPSTYLE_DATA_DBC);
        PreparedQueryResult BarberShopStyleDataResult = DataDB.Query(BarberShopStyleDataStatement);

        if (!BarberShopStyleDataResult)
        {
            sLog->outError("Error while loading BarberShopStyleData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = BarberShopStyleDataResult->Fetch();
                BarberShopStyleData barberShopStyleData;

                barberShopStyleData.Id               = TableFields[0].GetUInt32();
                barberShopStyleData.Type             = TableFields[1].GetUInt32();
                barberShopStyleData.Name             = TableFields[2].GetString();
                barberShopStyleData.NameFlags        = TableFields[3].GetUInt32();
                barberShopStyleData.Description      = TableFields[4].GetString();
                barberShopStyleData.DescriptionFlags = TableFields[5].GetUInt32();
                barberShopStyleData.CostMultiplier   = TableFields[6].GetFloat();
                barberShopStyleData.RaceId           = TableFields[7].GetUInt32();
                barberShopStyleData.GenderId         = TableFields[8].GetUInt32();
                barberShopStyleData.HairId           = TableFields[9].GetUInt32();
                
                BarberShopStyleDataTable[barberShopStyleData.Id] = barberShopStyleData;

                ++count;
            }
            while (BarberShopStyleDataResult->NextRow());

            sLog->outString(">> Loaded %u barbershop styles %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadBattleMasterListData()
{
    sLog->outString("Loading BattleMasterListData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* BattleMasterListDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_BATTLEMASTERLIST_DATA_DBC);
        PreparedQueryResult BattleMasterListDataResult = DataDB.Query(BattleMasterListDataStatement);

        if (!BattleMasterListDataResult)
        {
            sLog->outError("Error while loading BattleMasterListData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = BattleMasterListDataResult->Fetch();
                BattleMasterListData battleMasterListData;

                battleMasterListData.Id                = TableFields[0].GetUInt32();
                
                for (int i = 0; i < 8; i++)
                    battleMasterListData.MapId[i] = TableFields[1 + i].GetUInt32();

                battleMasterListData.InstanceTypeId    = TableFields[9].GetUInt32();
                battleMasterListData.Groups            = TableFields[10].GetUInt32();
                battleMasterListData.Name              = TableFields[11].GetString();
                battleMasterListData.NameFlags         = TableFields[12].GetUInt32();
                battleMasterListData.MaxGroupSize      = TableFields[13].GetUInt32();
                battleMasterListData.HolidayWorldState = TableFields[14].GetUInt32();
                battleMasterListData.MinLevel          = TableFields[15].GetUInt32();
                battleMasterListData.MaxLevel          = TableFields[16].GetUInt32();

                BattleMasterListDataTable[battleMasterListData.Id] = battleMasterListData;

                ++count;
            }
            while (BattleMasterListDataResult->NextRow());

            sLog->outString(">> Loaded %u battle masters %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCameraShakesData()
{
    sLog->outString("Loading CameraShakesData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CameraShakesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CAMERASHAKES_DATA_DBC);
        PreparedQueryResult CameraShakesDataResult = DataDB.Query(CameraShakesDataStatement);

        if (!CameraShakesDataResult)
        {
            sLog->outError("Error while loading CameraShakesData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CameraShakesDataResult->Fetch();
                CameraShakesData cameraShakesData;

                cameraShakesData.Id          = TableFields[0].GetUInt32();
                cameraShakesData.ShakeType   = TableFields[1].GetUInt32();
                cameraShakesData.Direction   = TableFields[2].GetUInt32();
                cameraShakesData.Amplitude   = TableFields[3].GetFloat();
                cameraShakesData.Frequency   = TableFields[4].GetFloat();
                cameraShakesData.Duration    = TableFields[5].GetFloat();
                cameraShakesData.Phase       = TableFields[6].GetFloat();
                cameraShakesData.Coefficient = TableFields[7].GetFloat();

                CameraShakesDataTable[cameraShakesData.Id] = cameraShakesData;

                ++count;
            }
            while (CameraShakesDataResult->NextRow());

            sLog->outString(">> Loaded %u camera shakes %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCfg_CategoriesData()
{
    sLog->outString("Loading Cfg_CategoriesData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* Cfg_CategoriesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CFG_CATEGORIES_DATA_DBC);
        PreparedQueryResult Cfg_CategoriesDataResult = DataDB.Query(Cfg_CategoriesDataStatement);

        if (!Cfg_CategoriesDataResult)
        {
            sLog->outError("Error while loading Cfg_CategoriesData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = Cfg_CategoriesDataResult->Fetch();
                Cfg_CategoriesData cfg_CategoriesData;

                cfg_CategoriesData.Id          = TableFields[0].GetUInt32();
                cfg_CategoriesData.LocaleMask  = TableFields[1].GetUInt32();
                cfg_CategoriesData.CharSetMask = TableFields[2].GetUInt32();
                cfg_CategoriesData.Flags       = TableFields[3].GetUInt32();
                cfg_CategoriesData.Name        = TableFields[4].GetString();
                cfg_CategoriesData.NameFlags   = TableFields[5].GetUInt32();

                Cfg_CategoriesDataTable[cfg_CategoriesData.Id] = cfg_CategoriesData;

                ++count;
            }
            while (Cfg_CategoriesDataResult->NextRow());

            sLog->outString(">> Loaded %u cfg categories %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCfg_ConfigsData()
{
    sLog->outString("Loading Cfg_ConfigsData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* Cfg_ConfigsDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CFG_CONFIGS_DATA_DBC);
        PreparedQueryResult Cfg_ConfigsDataResult = DataDB.Query(Cfg_ConfigsDataStatement);

        if (!Cfg_ConfigsDataResult)
        {
            sLog->outError("Error while loading Cfg_ConfigsData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = Cfg_ConfigsDataResult->Fetch();
                Cfg_ConfigsData cfg_ConfigsData;

                cfg_ConfigsData.Id       = TableFields[0].GetUInt32();
                cfg_ConfigsData.GenId    = TableFields[1].GetUInt32();
                cfg_ConfigsData.PvP      = TableFields[2].GetUInt32();
                cfg_ConfigsData.RolePlay = TableFields[3].GetUInt32();

                Cfg_ConfigsDataTable[cfg_ConfigsData.Id] = cfg_ConfigsData;

                ++count;
            }
            while (Cfg_ConfigsDataResult->NextRow());

            sLog->outString(">> Loaded %u cfg configs %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharacterFacialHairStylesData()
{
    sLog->outString("Loading CharacterFacialHairStylesData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharacterFacialHairStylesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARACTERFACIALHAIRSTYLES_DATA_DBC);
        PreparedQueryResult CharacterFacialHairStylesDataResult = DataDB.Query(CharacterFacialHairStylesDataStatement);

        if (!CharacterFacialHairStylesDataResult)
        {
            sLog->outError("Error while loading CharacterFacialHairStylesData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharacterFacialHairStylesDataResult->Fetch();
                CharacterFacialHairStylesData characterFacialHairStylesData;

                characterFacialHairStylesData.GenId       = TableFields[0].GetUInt32();
                characterFacialHairStylesData.RaceId      = TableFields[1].GetUInt32();
                characterFacialHairStylesData.VariationId = TableFields[2].GetUInt32();

                for (int i = 0; i < 5; i++)
                    characterFacialHairStylesData.GeoSet[i] = TableFields[1 + i].GetInt32();

                CharacterFacialHairStylesDataTable[characterFacialHairStylesData.GenId] = characterFacialHairStylesData;

                ++count;
            }
            while (CharacterFacialHairStylesDataResult->NextRow());

            sLog->outString(">> Loaded %u character facial hairstyles %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharBaseInfoData()
{
    sLog->outString("Loading CharBaseInfoData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharBaseInfoDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARBASEINFO_DATA_DBC);
        PreparedQueryResult CharBaseInfoDataDataResult = DataDB.Query(CharBaseInfoDataStatement);

        if (!CharBaseInfoDataDataResult)
        {
            sLog->outError("Error while loading CharBaseInfoData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharBaseInfoDataDataResult->Fetch();
                CharBaseInfoData charBaseInfoData;

                charBaseInfoData.RaceId  = TableFields[0].GetUInt32();
                charBaseInfoData.ClassId = TableFields[0].GetUInt32();

                CharBaseInfoDataTable[charBaseInfoData.RaceId] = charBaseInfoData;
                CharBaseInfoDataTable[charBaseInfoData.ClassId] = charBaseInfoData;

                ++count;
            }
            while (CharBaseInfoDataDataResult->NextRow());

            sLog->outString(">> Loaded %u charbase infos %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharHairGeosetsData()
{
    sLog->outString("Loading CharHairGeosetsData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharHairGeosetsDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARHAIRGEOSETS_DATA_DBC);
        PreparedQueryResult CharHairGeosetsDataResult = DataDB.Query(CharHairGeosetsDataStatement);

        if (!CharHairGeosetsDataResult)
        {
            sLog->outError("Error while loading CharHairGeosetsData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharHairGeosetsDataResult->Fetch();
                CharHairGeosetsData charHairGeosetsData;

                charHairGeosetsData.Id          = TableFields[0].GetUInt32();
                charHairGeosetsData.RaceId      = TableFields[1].GetUInt32();
                charHairGeosetsData.GenderId    = TableFields[2].GetUInt32();
                charHairGeosetsData.VariationId = TableFields[3].GetUInt32();
                charHairGeosetsData.Geoset      = TableFields[4].GetUInt32();
                charHairGeosetsData.ShowScalp   = TableFields[5].GetUInt32();

                CharHairGeosetsDataTable[charHairGeosetsData.Id] = charHairGeosetsData;

                ++count;
            }
            while (CharHairGeosetsDataResult->NextRow());

            sLog->outString(">> Loaded %u charhair geosets %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharHairTexturesData()
{
    sLog->outString("Loading CharHairTexturesData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharHairTexturesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARHAIRTEXTURES_DATA_DBC);
        PreparedQueryResult CharHairTexturesDataResult = DataDB.Query(CharHairTexturesDataStatement);

        if (!CharHairTexturesDataResult)
        {
            sLog->outError("Error while loading CharHairTexturesData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharHairTexturesDataResult->Fetch();
                CharHairTexturesData charHairTexturesData;

                charHairTexturesData.Id       = TableFields[0].GetUInt32();
                charHairTexturesData.RaceId   = TableFields[1].GetUInt32();
                charHairTexturesData.GenderId = TableFields[2].GetUInt32();
                charHairTexturesData.Unknown  = TableFields[3].GetUInt32();
                charHairTexturesData.Unknown1 = TableFields[4].GetUInt32();
                charHairTexturesData.Value    = TableFields[5].GetInt32();
                charHairTexturesData.Value1   = TableFields[6].GetInt32();

                CharHairTexturesDataTable[charHairTexturesData.Id] = charHairTexturesData;

                ++count;
            }
            while (CharHairTexturesDataResult->NextRow());

            sLog->outString(">> Loaded %u charhair textures %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharSectionsData()
{
    sLog->outString("Loading CharSectionsData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharSectionsDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARSECTIONS_DATA_DBC);
        PreparedQueryResult CharSectionsDataResult = DataDB.Query(CharSectionsDataStatement);

        if (!CharSectionsDataResult)
        {
            sLog->outError("Error while loading CharSectionsData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharSectionsDataResult->Fetch();
                CharSectionsData charSectionsData;

                charSectionsData.Id             = TableFields[0].GetUInt32();
                charSectionsData.RaceId         = TableFields[1].GetUInt32();
                charSectionsData.GenderId       = TableFields[2].GetUInt32();
                charSectionsData.BaseSection    = TableFields[3].GetUInt32();
                charSectionsData.TextureName    = TableFields[4].GetString();
                charSectionsData.NameFlags      = TableFields[5].GetUInt32();
                charSectionsData.VariationIndex = TableFields[6].GetUInt32();
                charSectionsData.ColorIndex     = TableFields[7].GetUInt32();

                CharSectionsDataTable[charSectionsData.Id] = charSectionsData;

                ++count;
            }
            while (CharSectionsDataResult->NextRow());

            sLog->outString(">> Loaded %u char sections %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharStartOutfitData()
{
    sLog->outString("Loading CharStartOutfitData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharStartOutfitDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARSTARTOUTFIT_DATA_DBC);
        PreparedQueryResult CharStartOutfitDataResult = DataDB.Query(CharStartOutfitDataStatement);

        if (!CharStartOutfitDataResult)
        {
            sLog->outError("Error while loading CharStartOutfitData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharStartOutfitDataResult->Fetch();
                CharStartOutfitData charStartOutfitData;

                charStartOutfitData.Id         = TableFields[0].GetUInt32();
                charStartOutfitData.RaceId     = TableFields[1].GetUInt8();
                charStartOutfitData.ClassId    = TableFields[2].GetUInt8();
                charStartOutfitData.GenderId   = TableFields[3].GetUInt8();
                charStartOutfitData.SomeValues = TableFields[4].GetUInt8();

                for (int i = 0; i < MAX_ITEMS; i++)
                    charStartOutfitData.ItemId[i] = TableFields[5 + i].GetUInt32();

                for (int i = 0; i < MAX_ITEMS; i++)
                    charStartOutfitData.DisplayId[i] = TableFields[29 + i].GetUInt32();

                for (int i = 0; i < MAX_ITEMS; i++)
                    charStartOutfitData.InventoryType[i] = TableFields[53 + i].GetUInt32();

                CharStartOutfitDataTable[charStartOutfitData.Id] = charStartOutfitData;

                ++count;
            }
            while (CharStartOutfitDataResult->NextRow());

            sLog->outString(">> Loaded %u char startoutfits %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}

void Data::LoadCharTitlesData()
{
    sLog->outString("Loading CharTitlesData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharTitlesDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARTITLES_DATA_DBC);
        PreparedQueryResult CharTitlesDataResult = DataDB.Query(CharTitlesDataStatement);

        if (!CharTitlesDataResult)
        {
            sLog->outError("Error while loading CharTitlesData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharTitlesDataResult->Fetch();
                CharTitlesData charTitlesData;

                charTitlesData.Id            = TableFields[0].GetUInt32();
                charTitlesData.ConditionId   = TableFields[1].GetUInt32();
                charTitlesData.Title         = TableFields[2].GetString();
                charTitlesData.TitleFlags    = TableFields[3].GetUInt32();
                charTitlesData.SubTitle      = TableFields[4].GetString();
                charTitlesData.SubTitleFlags = TableFields[5].GetUInt32();
                charTitlesData.MaskIndex     = TableFields[6].GetUInt32();

                CharTitlesDataTable[charTitlesData.Id] = charTitlesData;

                ++count;
            }
            while (CharTitlesDataResult->NextRow());

            sLog->outString(">> Loaded %u char titles %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }
}


void Data::LoadCharVariationsData()
{
    /*sLog->outString("Loading CharVariationsData Data...");
    {
        uint32 oldMSTime = getMSTime();

        PreparedStatement* CharVariationsDataStatement = DataDB.GetPreparedStatement(DATA_LOAD_CHARVARIATIONS_DATA_DBC);
        PreparedQueryResult CharVariationsDataResult = DataDB.Query(CharVariationsDataStatement);

        if (!CharVariationsDataResult)
        {
            sLog->outError("Error while loading CharVariationsData Data");
            sLog->outString();
        } 
        else
        {
            uint32 count = 0;
            do
            {
                Field* TableFields = CharVariationsDataResult->Fetch();
                CharVariationsData charVariationsData;

                CharVariationsDataTable[charVariationsData.Id] = charVariationsData;

                ++count;
            }
            while (CharVariationsDataResult->NextRow());

            sLog->outString(">> Loaded %u char variations %u ms", count, GetMSTimeDiffToNow(oldMSTime));
            sLog->outString();
        }
    }*/
}
