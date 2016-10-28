/* Copyright (c) 2011-2015, EPFL/Blue Brain Project
 *                     Ahmet Bilgili <ahmet.bilgili@epfl.ch>
 *                     Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 *
 * This file is part of Livre <https://github.com/BlueBrain/Livre>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <livre/core/cache/CacheStatistics.h>
#include <livre/core/cache/CacheObject.h>

namespace livre
{

CacheStatistics::CacheStatistics( const std::string& name )
    : _name( name )
    , _objCount( 0 )
    , _cacheHit( 0 )
    , _cacheMiss( 0 )
{
}

std::ostream& operator<<( std::ostream& stream, const CacheStatistics& statistics )
{
    const int hits = int(
        100.f * float( statistics._cacheHit ) /
        float( statistics._cacheHit + statistics._cacheMiss ));
    stream << statistics._name << std::endl;
    stream << "  Block Count: "
           << statistics._objCount << std::endl;
    stream << "  Cache hits: "
           << statistics._cacheHit << " (" << hits << "%)" << std::endl;
    stream << "  Cache misses: "
           << statistics._cacheMiss << std::endl;

    return stream;
}

CacheStatistics::~CacheStatistics()
{}

}
