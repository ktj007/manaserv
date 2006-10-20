/*
 *  The Mana World Server
 *  Copyright 2004 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World  is free software; you can redistribute  it and/or modify it
 *  under the terms of the GNU General  Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or any later version.
 *
 *  The Mana  World is  distributed in  the hope  that it  will be  useful, but
 *  WITHOUT ANY WARRANTY; without even  the implied warranty of MERCHANTABILITY
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 *  more details.
 *
 *  You should  have received a  copy of the  GNU General Public  License along
 *  with The Mana  World; if not, write to the  Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *  $Id$
 */

#include "player.h"

#include <cassert>

void Player::setDatabaseID(int id)
{
    assert(mDatabaseID == -1);
    mDatabaseID = id;
}

/**
 * Update the internal status.
 */
void Player::update()
{
    // computed stats.
    setStat(STAT_HEAT, 20 + (20 * mRawStats.stats[STAT_VITALITY]));
    setStat(STAT_ATTACK, 10 + mRawStats.stats[STAT_STRENGTH]);
    setStat(STAT_DEFENCE, 10 + mRawStats.stats[STAT_STRENGTH]);
    setStat(STAT_MAGIC, 10 + mRawStats.stats[STAT_INTELLIGENCE]);
    setStat(STAT_ACCURACY, 50 + mRawStats.stats[STAT_DEXTERITY]);
    setStat(STAT_SPEED, mRawStats.stats[STAT_DEXTERITY]);
}

void Player::setInventory(const Inventory &inven)
{
    inventory = inven;
}

bool Player::addItem(unsigned int itemId, unsigned char amount)
{
    return inventory.addItem(itemId, amount);
}

bool Player::removeItem(unsigned int itemId, unsigned char amount)
{
    return inventory.removeItem(itemId, amount);
}

bool Player::hasItem(unsigned int itemId)
{
    return inventory.hasItem(itemId);
}

bool Player::equip(unsigned char slot)
{
    return true; // TODO
}

bool Player::unequip(unsigned char slot)
{
    return true; // TODO
}