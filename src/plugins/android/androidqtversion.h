/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2012 BogDan Vatra <bog_dan_ro@yahoo.com>
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef ANDROIDQTVERSION_H
#define ANDROIDQTVERSION_H
#include <qtsupport/baseqtversion.h>

namespace Android {
namespace Internal {

class AndroidQtVersion : public QtSupport::BaseQtVersion
{
public:
    AndroidQtVersion();
    AndroidQtVersion(const Utils::FileName &path, bool isAutodetected = false, const QString &autodetectionSource = QString());
    ~AndroidQtVersion ();
    AndroidQtVersion *clone() const;

    virtual QString type() const;

    virtual bool isValid() const;
    virtual QString invalidReason() const;

    virtual QList<ProjectExplorer::Abi> detectQtAbis() const;

    virtual bool supportsTargetId(const QString &id) const;
    virtual QSet<QString> supportedTargetIds() const;

    virtual Core::FeatureSet availableFeatures() const;
    virtual QString platformName() const;
    virtual QString platformDisplayName() const;

    QString description() const;
};

} // namespace Internal
} // namespace Android

#endif // ANDROIDQTVERSION_H
