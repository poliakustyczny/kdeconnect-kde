/**
 * Copyright 2013 Albert Vaca <albertvaka@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License or (at your option) version 3 or any later version
 * accepted by the membership of KDE e.V. (or its successor approved
 * by the membership of KDE e.V.), which shall act as a proxy
 * defined in Section 14 of version 3 of the license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MPRISCONTROLPACKAGEINTERFACE_H
#define MPRISCONTROLPACKAGEINTERFACE_H

#include "packageinterface.h"
#include "mprisdbusinterface.h"

#include <QSet>
#include <QString>
#include <QHash>
#include <QDBusArgument>

class MprisControlPackageInterface
    : public PackageInterface
{
    Q_OBJECT

public:
    MprisControlPackageInterface();
    virtual bool receivePackage(const Device& device, const NetworkPackage& np);

private Q_SLOTS:
    void serviceOwnerChanged(const QString &name, const QString &oldOwner, const QString &newOwner);
    void propertiesChanged(const QString& interface, const QVariantMap& properties);

private:
    QHash<QString, QString> playerList;
    void addPlayer(const QString& ifaceName);
    void removePlayer(const QString& ifaceName);
    void sendPlayerList(const Device* device = 0);
    int prevVolume;

};

#endif
