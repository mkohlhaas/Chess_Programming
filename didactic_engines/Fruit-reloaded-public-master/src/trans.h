/* Fruit reloaded, a UCI chess playing engine derived from Fruit 2.1
 *
 * Copyright (C) 2004-2005 Fabien Letouzey
 * Copyright (C) 2012-2014 Daniel Mehrmann
 * Copyright (C) 2013-2014 Ryan Benitez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// trans.h

#ifndef TRANS_H
#define TRANS_H

// includes

#include "util.h"

// functions

extern bool trans_is_ok    ();

extern void trans_init     ();
extern void trans_alloc    ();
extern void trans_free     ();

extern void trans_clear    ();
extern void trans_inc_date ();

extern void trans_store    (uint64 key, int move, int depth, int min_value, int max_value, int eval);
extern bool trans_retrieve (uint64 key, int * move, int * min_depth, int * max_depth, int * min_value, int * max_value, int * eval, bool refresh);

extern void trans_stats    ();

#endif // !defined TRANS_H

// end of trans.h

