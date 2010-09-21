/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of Qt Creator.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "maemodeployables.h"

#include "maemodeployablelistmodel.h"

#include <profileevaluator.h>
#include <projectexplorer/buildstep.h>
#include <qt4projectmanager/qt4buildconfiguration.h>
#include <qt4projectmanager/qt4project.h>
#include <qt4projectmanager/qt4target.h>

#include <QtCore/QTimer>

namespace Qt4ProjectManager {
namespace Internal {

MaemoDeployables::MaemoDeployables(const ProjectExplorer::BuildStep *buildStep)
    : m_buildStep(buildStep)
{
    QTimer::singleShot(0, this, SLOT(init()));
}

MaemoDeployables::~MaemoDeployables() {}

void MaemoDeployables::init()
{
    createModels();
    connect(qt4BuildConfiguration()->qt4Target()->qt4Project(),
        SIGNAL(proFileUpdated(Qt4ProjectManager::Internal::Qt4ProFileNode*)),
        this, SLOT(createModels()));
}

void MaemoDeployables::createModels()
{
    qDeleteAll(m_listModels);
    m_listModels.clear();
    m_proFileOption = QSharedPointer<ProFileOption>(new ProFileOption);
    m_proFileOption->properties
        = qt4BuildConfiguration()->qtVersion()->versionInfo();
    m_proFileOption->target_mode = ProFileOption::TARG_UNIX_MODE;
    createModels(qt4BuildConfiguration()->qt4Target()->qt4Project()
        ->rootProjectNode());
    emit modelsCreated();
}

void MaemoDeployables::createModels(const Qt4ProFileNode *proFileNode)
{
    if (!proFileNode) // Happens on project creation by wizard.
        return;
    const Qt4ProjectType type = proFileNode->projectType() ;
    switch (type) {
    case ApplicationTemplate:
    case LibraryTemplate:
    case ScriptTemplate:
        m_listModels
            << new MaemoDeployableListModel(proFileNode, m_proFileOption, this);
        break;
    case SubDirsTemplate: {
        const QList<ProjectExplorer::ProjectNode *> &subProjects
            = proFileNode->subProjectNodes();
        foreach (const ProjectExplorer::ProjectNode *subProject, subProjects) {
            const Qt4ProFileNode * const qt4SubProject
                = qobject_cast<const Qt4ProFileNode *>(subProject);
            if (qt4SubProject && !qt4SubProject->path()
                .endsWith(QLatin1String(".pri")))
                createModels(qt4SubProject);
        }
    }
    default:
        break;
    }
}

void MaemoDeployables::setUnmodified()
{
    foreach (MaemoDeployableListModel *model, m_listModels)
        model->setUnModified();
}

bool MaemoDeployables::isModified() const
{
    foreach (const MaemoDeployableListModel *model, m_listModels) {
        if (model->isModified())
            return true;
    }
    return false;
}

int MaemoDeployables::deployableCount() const
{
    int count = 0;
    foreach (const MaemoDeployableListModel *model, m_listModels)
        count += model->rowCount();
    return count;
}

MaemoDeployable MaemoDeployables::deployableAt(int i) const
{
    foreach (const MaemoDeployableListModel *model, m_listModels) {
        Q_ASSERT(i >= 0);
        if (i < model->rowCount())
            return model->deployableAt(i);
        i -= model->rowCount();
    }

    Q_ASSERT(!"Invalid deployable number");
    return MaemoDeployable(QString(), QString());
}

QString MaemoDeployables::remoteExecutableFilePath(const QString &localExecutableFilePath) const
{
    foreach (const MaemoDeployableListModel *model, m_listModels) {
        if (model->localExecutableFilePath() == localExecutableFilePath)
            return model->remoteExecutableFilePath();
    }
    qWarning("No remote executable specified!");
    return QString();
}

const Qt4BuildConfiguration *MaemoDeployables::qt4BuildConfiguration() const
{
    const Qt4BuildConfiguration * const bc
        = qobject_cast<Qt4BuildConfiguration *>(m_buildStep->target()->activeBuildConfiguration());
    Q_ASSERT(bc);
    return bc;
}

} // namespace Qt4ProjectManager
} // namespace Internal
