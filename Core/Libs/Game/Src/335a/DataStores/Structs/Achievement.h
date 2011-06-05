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

#ifndef ACHIEVEMENT_STRUCT_H
#define ACHIEVEMENT_STRUCT_H

#include "Define.h"

struct AchievementData
{
    uint32 Id;
    int32  RequiredFaction;
    int32  MapId;
    uint32 ParentAchievement;
    std::string Name;
    uint32 NameFlags;
    std::string Description;
    uint32 DescFlags;
    uint32 CategoryId;
    uint32 Points;
    uint32 OrderInCategory;
    uint32 Flags;
    uint32 Icon;
    std::string TitleReward;
    uint32 TitleRewardFlags;
    uint32 Count;
    uint32 RefAchievement;
};

typedef UNORDERED_MAP<uint32, AchievementData> AchievementDataContainer;

#endif