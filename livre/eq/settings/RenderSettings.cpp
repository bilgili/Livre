
/* Copyright (c) 2011, Maxim Makhinya <maxmah@gmail.com>
 *               2012, David Steiner  <steiner@ifi.uzh.ch>
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

#include <livre/eq/settings/RenderSettings.h>

namespace livre
{

RenderSettings::RenderSettings()
    : _colorMap( lexis::render::ColorMap::getDefaultColorMap( 0, 256 ))
    , _depth( 0 )
{
    _colorMap.registerDeserializedCallback( [this]
        { setDirty( DIRTY_COLORMAP ); });

    _clipPlanes.registerDeserializedCallback( [this]
        { setDirty( DIRTY_CLIPPLANES ); });

    _clipPlanes.clear();
}

void RenderSettings::resetColorMap( )
{
    setColorMap( lexis::render::ColorMap::getDefaultColorMap( 0.0f, 256.0f ));
}

void RenderSettings::setColorMap( const lexis::render::ColorMap& cm )
{
    _colorMap = cm;
    setDirty( DIRTY_COLORMAP );
}

void RenderSettings::setClipPlanes( const ClipPlanes& clipPlanes )
{
    _clipPlanes = clipPlanes;
    setDirty( DIRTY_CLIPPLANES );
}

void RenderSettings::serialize( co::DataOStream& os, const uint64_t dirtyBits )
{
    if( dirtyBits & DIRTY_COLORMAP )
        os << _colorMap;

    if( dirtyBits & DIRTY_DEPTH )
        os << _depth;

    if( dirtyBits & DIRTY_CLIPPLANES )
        os << _clipPlanes;

    co::Serializable::serialize( os, dirtyBits );
}

void RenderSettings::deserialize( co::DataIStream& is, const uint64_t dirtyBits )
{
    if( dirtyBits & DIRTY_COLORMAP )
        is >> _colorMap;

    if( dirtyBits & DIRTY_DEPTH )
        is >> _depth;

    if( dirtyBits & DIRTY_CLIPPLANES )
        is >> _clipPlanes;

    co::Serializable::deserialize( is, dirtyBits );
}

void RenderSettings::setMaxTreeDepth( const uint8_t depth )
{
    _depth = depth;
    setDirty( DIRTY_DEPTH );
}

uint8_t RenderSettings::getMaxTreeDepth( ) const
{
    return _depth;
}

}
