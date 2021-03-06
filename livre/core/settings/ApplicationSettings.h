/*
 * Copyright (c) 2016, ahmetbilgili@gmail.com
 *
 * This file is part of Livre <https://github.com/bilgili/Libre>
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

#ifndef _ApplicationSettings_h_
#define _ApplicationSettings_h_

#include <livre/core/types.h>
#include <livre/core/data/SignalledVariable.h>

namespace livre
{

class ApplicationSettings
{

public:

    /** ApplicationSettings constructor. */
    ApplicationSettings();

    /**
     * Adds resource folder.
     * @param cm is the color map
     */
    void addResourceFolder( const std::string& folder );

    /** @return the resource folder. */
    Strings getResourceFolders() const;

    /**
     * Adds resource folder.
     * @param renderer is the name of the renderer
     */
    void setRenderer( const std::string& renderer );

    /** @return the resource folder. */
    std::string getRenderer() const;

protected:

    SignalledVariable< Strings > _resourceFolders;
    SignalledVariable< std::string > _renderer;
};

}

#endif // _ApplicationSettings_h_
