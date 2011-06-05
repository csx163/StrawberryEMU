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

#ifndef ACHIEVEMENT_CRITERIA_STRUCT_H
#define ACHIEVEMENT_CRITERIA_STRUCT_H

#include "Define.h"

struct AchievementCriteriaData
{
    uint32 Id;
    uint32 ReferredAchievement;
    uint32 RequiredType;

    union
    {
        // Type 0 - Kill Creature
        struct
        {
            uint32 CreatureID;
            uint32 CreatureCount;
        } Kill_Creature;

        // Type 1 - Win BG
        struct
        {
            uint32 BgMapId;
            uint32 WinCount;
        } Win_Bg;

        // Type 5 - Reach Level
        struct
        {
            uint32 Unknown;
            uint32 Level;
        } Reach_Level;

        // Type 7 - Reach Skill Level
        struct
        {
            uint32 SkillId;
            uint32 SkillLevel;
        } Reach_Skill_Level;

        // Type 8 - Complete Achievement
        struct
        {
            uint32 LinkedAchievement;
        } Complete_Achievement;

        // Type 9 - Complete Quest Count
        struct
        {
            uint32 Unknown;
            uint32 TotalQuestCount;
        } Complete_Quest_Count;

        // Type 10 - Complete Daily Quest Daily
        struct
        {
            uint32 Unknown;
            uint32 NumberOfDays;
        } Complete_Daily_Quest_Daily;

        // Type 11 - Complete Quests in Zone
        struct
        {
            uint32 ZoneID;
            uint32 QuestCount;
        } Complete_Quests_In_Zone;

        // Type 14 - Complete Daily Quest
        struct
        {
            uint32 Unknown;
            uint32 QuestCount;
        } Complete_Daily_Quest;

        // Type 15 - Complete Battleground
        struct
        {
            uint32 MapID;
        } Complete_Battleground;

        // Type 16 - Death At Map
        struct
        {
            uint32 MapID;
        } Death_At_Map;

        // Type 18 - Death in Dungeon
        struct
        {
            uint32 ManLimit;
        } Death_In_Dungeon;

        // Type 19 - Complete Raid
        struct
        {
            uint32 GroupSize;
        } Complete_Raid;

        // Type 20 - Killed by Creature
        struct
        {
            uint32 CreatureEntry;
        } Killed_By_Creature;

        // Type 24 - Fall without dying
        struct
        {
            uint32 Unknown;
            uint32 FallHeight;
        } Fall_Without_Dying;

        // Type 26 - Death from
        struct
        {
            uint32 Type;
        } Death_From;

        // Type 27 - Complete Quest
        struct
        {
            uint32 QuestID;
            uint32 QuestCount;
        } Complete_Quest;

        // Type 28, 69 - Be Spell target
        struct
        {
            uint32 SpellID;
            uint32 SpellCount;
        } Be_Spell_Target;

        // Type 29, 110 - Cast Spell
        struct
        {
            uint32 SpellID;
            uint32 CastCount;
        } Cast_Spell;

        // Type 30 - BG Objective Capture
        struct
        {
            uint32 ObjectiveId;
            uint32 CompleteCount;
        } Bg_Objective_Capture;

        // Type 31 - Honorable Kill At Area
        struct
        {
            uint32 AreaID;
            uint32 KillCount;
        } Honorable_Kill_At_Area;

        // Type 32 - Win Arena
        struct
        {
            uint32 MapID;
        } Win_Arena;

        // Type 33 - Play Arena
        struct
        {
            uint32 MapID;
        } Play_Arena;

        // Type 34 - Learn Spell
        struct
        {
            uint32 SpellID;
        } Learn_Spell;

        // Type 36 - Own item
        struct
        {
            uint32 ItemID;
            uint32 ItemCount;
        } Own_Item;

        // Type 37 - Win Rated Arena
        struct
        {
            uint32 Unknown;
            uint32 Count;
        } Win_Rated_Arena;

        // Type 38 - Highest Team Rating
        struct
        {
            uint32 TeamType;
        } Highest_Team_Rating;

        // Type 39 - Reach Team Rating
        struct
        {
            uint32 TeamType;
            uint32 PersonalRating;
        } Highest_Personal_Rating;

        // Type 40 - Learn Skill Level
        struct
        {
            uint32 SkillId;
            uint32 SkillLevel;
        } Learn_Skill_Level;

        // Type 41 - Use Item
        struct
        {
            uint32 ItemId;
            uint32 ItemCount;
        } Use_Item;

        // Type 42 - Loot Item
        struct
        {
            uint32 ItemID;
            uint32 ItemCount;
        } Loot_Item;

        // Type 43 - Explore Area
        struct
        {
            uint32 AreaReference;
        } Explore_Area;

        // Type 44 - Own Rank
        struct
        {
            uint32 Rank;
        } Own_Rank;

        // Type 45 - Buy Bank Slot
        struct
        {
            uint32 Unknown;
            uint32 NumberOfSlots;
        } Buy_Bank_Slot;

        // Type 46 - Gain Reputation
        struct
        {
            uint32 FactionId;
            uint32 ReputationAmount;
        } Gain_Reputation;

        // Type 47 - Gain Exalted Reputation
        struct
        {
            uint32 Unknown;
            uint32 NumberOfExaltedFactions;
        } Gain_Exalted_Reputation;

        // Type 48 - Visit barber Shop
        struct
        {
            uint32 Unknown;
            uint32 NumberOfVisits;
        } Visit_Barber_Shop;

        // Type 49 - Equip Epic Item
        struct
        {
            uint32 ItemSlot;
            uint32 Count;
        } Equip_Epic_Item;

        // Type 50 - Roll Need On Loot
        struct
        {
            uint32 RollValue;
            uint32 Count;
        } Roll_Need_On_Loot;

        // Type 51 - Roll Greed On Loot
        struct
        {
            uint32 RollValue;
            uint32 Count;
        } Roll_Greed_On_Loot;

        // Type 52 - HK Class
        struct
        {
            uint32 ClassID;
            uint32 Count;
        } Hk_Class;

        // Type 53 - HK Race
        struct
        {
            uint32 RaceID;
            uint32 Count;
        } Hk_Race;

        // Type 54 - Do Emote
        struct
        {
            uint32 EmoteID;
            uint32 Count;
        } do_emote;

        // Type 13, 55 - Damage Done, Healing Done
        struct
        {
            uint32 Unknown;
            uint32 Count;
        } Healing_Done;

        // Type 56 - Get Killing Blows
        struct
        {
            uint32 Unknown;
            uint32 KillCount;
        } Get_Killing_Blow;

        // Type 57 - Equip Item
        struct
        {
            uint32 ItemId;
            uint32 Count;
        } Equip_Item;

        // Type 62 - Money From Quest Reward
        struct
        {
            uint32 Unknown;
            uint32 GoldInCopper;
        } Quest_Reward_Money;

        // Type 67 - Loot Money
        struct
        {
            uint32 Unknown;
            uint32 GoldInCopper;
        } Loot_Money;

        // Type 68 - Use Game object
        struct
        {
            uint32 GoEntry;
            uint32 UseCount;
        } Use_GameObject;

        // Type 70 - Special PvP Kill
        struct
        {
            uint32 Unknown;
            uint32 KillCount;
        } Special_Pvp_Kill;

        // Type 72 - Fish in Game object
        struct
        {
            uint32 GoEntry;
            uint32 LootCount;
        } Fish_In_GameObject;

        // Type 75 - Learn Skill line Spell
        struct
        {
            uint32 SkillLine;
            uint32 SpellCount;
        } Learn_Skillline_Spell;

        // Type 76 - Win Duel
        struct
        {
            uint32 Unknown;
            uint32 DuelCount;
        } Win_Duel;

        // Type 96 - Highest Power
        struct
        {
            uint32 PowerType;
        } Highest_Power;

        // Type 97 - Highest Stat
        struct
        {
            uint32 StatType;
        } Highest_Stat;

        // Type 98 - Highest SpellPower
        struct
        {
            uint32 SpellSchool;
        } Highest_Spellpower;

        // Type 100 - Highest Rating
        struct
        {
            uint32 RatingType;
        } Highest_Rating;

        // Type 109 - Loot Type
        struct
        {
            uint32 LootType;
            uint32 LootTypeCount;
        } Loot_Type;

        // Type 112 - Learn Skill Line
        struct
        {
            uint32 SkillLine;
            uint32 SpellCount;
        } Learn_Skill_Line;

        // Type 113 - Earn Honorable Kill
        struct
        {
            uint32 Unknown;
            uint32 KillCount;
        } Honorable_Kill;

        struct
        {
            uint32 Unknown;
            uint32 DungeonsComplete;
        } Use_Lfg;

        struct
        {
            uint32 Field3;
            uint32 Count;
        } Raw;
    };

    struct
    {
        uint32 AdditionalRequirementType;
        uint32 AdditionalRequirementValue;
    } AdditionalRequirements[2];

    uint32 TypeRelatedId;
    uint32 TypeRelatedCount;
    std::string Name;
    uint32 NameFlags;
    uint32 Flags;
    uint32 TimedType;
    uint32 TimerStartEvent;
    uint32 TimeLimit;
    uint32 ShowOrder;
};

typedef UNORDERED_MAP<uint32, AchievementCriteriaData> AchievementCriteriaDataContainer;

#endif