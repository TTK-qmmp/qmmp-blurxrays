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

QDialog *VisualBlurXRaysFactory::createConfigDialog(QWidget *parent)
{
    Q_UNUSED(parent);
    return nullptr;
}

void VisualBlurXRaysFactory::showAbout(QWidget *parent)
{
    QMessageBox::about (parent, tr("About BlurXRays Visual Plugin"),
                        tr("Qmmp BlurXRays Visual Plugin")+"\n"+
                        tr("This plugin adds BlurXRays visualization")+"\n"+
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString VisualBlurXRaysFactory::translation() const
{
    return QString();
}
