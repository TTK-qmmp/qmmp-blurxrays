#include "visualblurxraysfactory.h"
#include "blurxrays.h"

#include <QMessageBox>

VisualProperties VisualBlurXRaysFactory::properties() const
{
    VisualProperties properties;
    properties.name = tr("BlurXRays Plugin");
    properties.shortName = "blurxrays";
    properties.hasAbout = true;
    return properties;
}

Visual *VisualBlurXRaysFactory::create(QWidget *parent)
{
    return new BlurXRays(parent);
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
QDialog *VisualBlurXRaysFactory::createConfigDialog(QWidget *parent)
#else
QDialog *VisualBlurXRaysFactory::createSettings(QWidget *parent)
#endif
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualBlurXRaysFactory::showAbout(QWidget *parent)
{
    QMessageBox::about(parent, tr("About BlurXRays Visual Plugin"),
                       tr("Qmmp BlurXRays Visual Plugin") + "\n" +
                       tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualBlurXRaysFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(blurxrays, VisualBlurXRaysFactory)
#endif
