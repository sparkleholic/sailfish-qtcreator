import qbs.base 1.0

import "../QtcPlugin.qbs" as QtcPlugin

QtcPlugin {
    name: "Madde"

    Depends { name: "Debugger" }
    Depends { name: "ProjectExplorer" }
    Depends { name: "Qt4ProjectManager" }
    Depends { name: "QtSupport" }
    Depends { name: "RemoteLinux" }
    Depends { name: "Qt.gui" }

    Depends { name: "cpp" }
    cpp.defines: base.concat(["QT_NO_CAST_FROM_ASCII"])

    files: [
        "debianmanager.cpp",
        "debianmanager.h",
        "madde_exports.h",
        "maddedevice.cpp",
        "maddedevice.h",
        "maddedeviceconfigurationfactory.cpp",
        "maddedeviceconfigurationfactory.h",
        "maddedevicetester.cpp",
        "maddedevicetester.h",
        "maddeplugin.cpp",
        "maddeplugin.h",
        "maddeqemustartstep.cpp",
        "maddeqemustartstep.h",
        "maddeuploadandinstallpackagesteps.cpp",
        "maddeuploadandinstallpackagesteps.h",
        "maemoapplicationrunnerhelperactions.cpp",
        "maemoapplicationrunnerhelperactions.h",
        "maemoconstants.h",
        "maemodeploybymountsteps.cpp",
        "maemodeploybymountsteps.h",
        "maemodeploymentmounter.cpp",
        "maemodeploymentmounter.h",
        "maemodeploystepfactory.cpp",
        "maemodeploystepfactory.h",
        "maemodeviceconfigwizard.cpp",
        "maemodeviceconfigwizard.h",
        "maemodeviceconfigwizardkeycreationpage.ui",
        "maemodeviceconfigwizardkeydeploymentpage.ui",
        "maemodeviceconfigwizardpreviouskeysetupcheckpage.ui",
        "maemodeviceconfigwizardreusekeyscheckpage.ui",
        "maemodeviceconfigwizardstartpage.ui",
        "maemoglobal.cpp",
        "maemoglobal.h",
        "maemoinstalltosysrootstep.cpp",
        "maemoinstalltosysrootstep.h",
        "maemomountspecification.cpp",
        "maemomountspecification.h",
        "maemopackagecreationfactory.cpp",
        "maemopackagecreationfactory.h",
        "maemopackagecreationstep.cpp",
        "maemopackagecreationstep.h",
        "maemopackagecreationwidget.cpp",
        "maemopackagecreationwidget.h",
        "maemopackagecreationwidget.ui",
        "maemopackageinstaller.cpp",
        "maemopackageinstaller.h",
        "maemopublishedprojectmodel.cpp",
        "maemopublishedprojectmodel.h",
        "maemopublisherfremantlefree.cpp",
        "maemopublisherfremantlefree.h",
        "maemopublishingbuildsettingspagefremantlefree.cpp",
        "maemopublishingbuildsettingspagefremantlefree.h",
        "maemopublishingbuildsettingspagefremantlefree.ui",
        "maemopublishingfileselectiondialog.cpp",
        "maemopublishingfileselectiondialog.h",
        "maemopublishingfileselectiondialog.ui",
        "maemopublishingresultpagefremantlefree.cpp",
        "maemopublishingresultpagefremantlefree.h",
        "maemopublishingresultpagefremantlefree.ui",
        "maemopublishinguploadsettingspagefremantlefree.cpp",
        "maemopublishinguploadsettingspagefremantlefree.h",
        "maemopublishinguploadsettingspagefremantlefree.ui",
        "maemopublishingwizardfactories.cpp",
        "maemopublishingwizardfactories.h",
        "maemopublishingwizardfremantlefree.cpp",
        "maemopublishingwizardfremantlefree.h",
        "maemoqemumanager.cpp",
        "maemoqemumanager.h",
        "maemoqemuruntime.h",
        "maemoqemuruntimeparser.cpp",
        "maemoqemuruntimeparser.h",
        "maemoqemusettings.cpp",
        "maemoqemusettings.h",
        "maemoqemusettingswidget.cpp",
        "maemoqemusettingswidget.h",
        "maemoqemusettingswidget.ui",
        "maemoqtversion.cpp",
        "maemoqtversion.h",
        "maemoqtversionfactory.cpp",
        "maemoqtversionfactory.h",
        "maemoremotecopyfacility.cpp",
        "maemoremotecopyfacility.h",
        "maemoremotemounter.cpp",
        "maemoremotemounter.h",
        "maemoremotemountsmodel.cpp",
        "maemoremotemountsmodel.h",
        "maemorunconfiguration.cpp",
        "maemorunconfiguration.h",
        "maemorunconfigurationwidget.cpp",
        "maemorunconfigurationwidget.h",
        "maemorunfactories.cpp",
        "maemorunfactories.h",
        "maemosettingspages.cpp",
        "maemosettingspages.h",
        "qt-maemo.qrc",
        "qt4maemodeployconfiguration.cpp",
        "qt4maemodeployconfiguration.h",
    ]
}
