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

#ifndef DATA_H
#define DATA_H

#include "Define.h"
#include <ace/Singleton.h>

#include "Achievement.h"
#include "Achievement_Category.h"
#include "Achievement_Criteria.h"

#include "AnimationData.h"

#include "AreaGroup.h"
#include "AreaPOI.h"
#include "AreaTable.h"
#include "AreaTrigger.h"

#include "AttackAnimKits.h"
#include "AttackAnimTypes.h"

#include "AuctionHouse.h"

#include "BankBagSlotPrices.h"

#include "BannedAddOns.h"

#include "BarberShopStyle.h"

#include "BattlemasterList.h"

#include "CameraShakes.h"

#include "Cfg_Categories.h"
#include "Cfg_Configs.h"

#include "CharacterFacialHairStyles.h"

#include "CharBaseInfo.h"
#include "CharHairGeosets.h"
#include "CharHairTextures.h"
#include "CharSections.h"
#include "CharStartOutfit.h"
#include "CharTitles.h"
#include "CharVariations.h"

class Data
{
    public:
        void LoadAchievementData();
        void LoadAchievementCategoryData();
        void LoadAchievementCriteriaData();

        void LoadAnimationDataData();

        void LoadAreaGroupData();
        void LoadAreaPoiData();
        void LoadAreaTableData();
        void LoadAreaTriggerData();

        void LoadAttackAnimKitsData();
        void LoadAttackAnimTypesData();

        void LoadAuctionHouseData();

        void LoadBankBagSlotPricesData();

        void LoadBannedAddOnsData();

        void LoadBarberShopStyleData();

        void LoadBattleMasterListData();

        void LoadCameraShakesData();

        void LoadCfg_CategoriesData();
        void LoadCfg_ConfigsData();

        void LoadCharacterFacialHairStylesData();

        void LoadCharBaseInfoData();
        void LoadCharHairGeosetsData();
        void LoadCharHairTexturesData();
        void LoadCharSectionsData();
        void LoadCharStartOutfitData();
        void LoadCharTitlesData();
        void LoadCharVariationsData();

        AchievementDataContainer AchievementDataTable;
        AchievementCategoryDataContainer AchievementCategoryDataTable;
        AchievementCriteriaDataContainer AchievementCriteriaDataTable;

        AnimationDataDataContainer AnimationDataDataTable;

        AreaGroupDataContainer AreaGroupDataTable;
        AreaPoiDataContainer AreaPoiDataTable;
        AreaTableDataContainer AreaTableDataTable;
        AreaTriggerDataContainer AreaTriggerDataTable;

        AttackAnimKitsDataContainer AttackAnimKitsDataTable;
        AttackAnimTypesDataContainer AttackAnimTypesDataTable;

        AuctionHouseDataContainer AuctionHouseDataTable;

        BankBagSlotPricesDataContainer BankBagSlotPricesDataTable;

        BannedAddOnsDataContainer BannedAddOnsDataTable;

        BarberShopStyleDataContainer BarberShopStyleDataTable;

        BattleMasterListDataContainer BattleMasterListDataTable;

        CameraShakesDataContainer CameraShakesDataTable;

        Cfg_CategoriesDataContainer Cfg_CategoriesDataTable;
        Cfg_ConfigsDataContainer Cfg_ConfigsDataTable;

        CharacterFacialHairStylesDataContainer CharacterFacialHairStylesDataTable;

        CharBaseInfoDataContainer CharBaseInfoDataTable;
        CharHairGeosetsDataContainer CharHairGeosetsDataTable;
        CharHairTexturesDataContainer CharHairTexturesDataTable;
        CharSectionsDataContainer CharSectionsDataTable;
        CharStartOutfitDataContainer CharStartOutfitDataTable;
        CharTitlesDataContainer CharTitlesDataTable;
        CharVariationsDataContainer CharVariationsDataTable;
};

#define sData ACE_Singleton<Data, ACE_Null_Mutex>::instance()

#endif
