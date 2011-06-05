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

        AchievementDataContainer AchievementDataTable;
        AchievementCategoryDataContainer AchievementCategoryDataTable;
        AchievementCriteriaDataContainer AchievementCriteriaDataTable;

        AnimationDataDataContainer AnimationDataDataTable;

        AreaGroupDataContainer AreaGroupDataTable;
        AreaPoiDataContainer AreaPoiDataTable;
        AreaTableDataContainer AreaTableDataTable;
        AreaTriggerDataContainer AreaTriggerDataTable;
};

#define sData ACE_Singleton<Data, ACE_Null_Mutex>::instance()

#endif