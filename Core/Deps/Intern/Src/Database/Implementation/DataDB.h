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

#ifndef _DATADATABASE_H
#define _DATADATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class DataDBConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        DataDBConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) {}
        DataDBConnection(ACE_Activation_Queue* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) {}

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<DataDBConnection> DataDBWorkerPool;

enum DataDBStatements
{
    DATA_LOAD_ACHIEVEMENT_DBC,
    DATA_LOAD_ACHIEVEMENT_CATEGORY_DBC,
    DATA_LOAD_ACHIEVEMENT_CRITERIA_DBC,

    DATA_LOAD_ANIMATION_DATA_DBC,

    DATA_LOAD_AREAGROUP_DATA_DBC,
    DATA_LOAD_AREAPOI_DATA_DBC,
    DATA_LOAD_AREATABLE_DATA_DBC,
    DATA_LOAD_AREATRIGGER_DATA_DBC,

    DATA_LOAD_ATTACKANIMKITS_DATA_DBC,
    DATA_LOAD_ATTACKANIMTYPES_DATA_DBC,

    DATA_LOAD_AUCTIONHOUSE_DATA_DBC,
    MAX_DATADB_STATEMENTS,
};

#endif
