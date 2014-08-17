#include "EditorConnector.h"

#include <QAbstractSlider>
#include <QDoubleSpinBox>
#include <qmath.h>

EditorConnector::EditorConnector(QObject *parent) :
    QObject(parent),
    m_slider(nullptr),
    m_spinBox(nullptr),
    m_multiplier(100)
{
}

bool EditorConnector::setup(QAbstractSlider *slider, QDoubleSpinBox *spinBox, double multiplier)
{
    if (!slider)
        return false;

    if (!spinBox)
        return false;

    m_slider = slider;
    m_spinBox = spinBox;
    m_multiplier = multiplier;

    connect(m_slider, SIGNAL(valueChanged(int)), SLOT(onSliderValueChanged(int)));
    connect(m_spinBox, SIGNAL(valueChanged(double)), SLOT(onSpinBoxValueChanged(double)));

    m_slider->setMaximum(m_spinBox->maximum() * m_multiplier);
    m_slider->setMinimum(m_spinBox->minimum() * m_multiplier);

    return true;
}

void EditorConnector::onSliderValueChanged(int value)
{
    if (m_spinBox.isNull())
        return;

    m_spinBox->setValue(value * 1/m_multiplier);
}

void EditorConnector::onSpinBoxValueChanged(double value)
{
    if (m_slider.isNull())
        return;

    m_slider->setValue(value * m_multiplier);
}
