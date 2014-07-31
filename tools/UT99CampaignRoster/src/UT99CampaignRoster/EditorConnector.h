/*
 * EditorConnector is a mediator class for connection between QAbstractSlider and QDoubleSpinBox
 * It listens for valueChanged signals and set value for slider and spinBox depending on mutiplier
 * This allows connect slider to double spin box and change their values simultaneously
 *
 * EditorConnector also change minimum and maximum values for slider according to spinbox's min/max values
*/

#ifndef EDITORCONNECTOR_H
#define EDITORCONNECTOR_H

#include <QObject>

#include <QPointer>

class QAbstractSlider;
class QDoubleSpinBox;

class EditorConnector : public QObject
{
    Q_OBJECT    
public:
    explicit EditorConnector(QObject *parent = 0);

    // Setup connection between slider and spinBox
    // Multiplier shows how value from spinBox will increse for slider.
    // I.e. 0.25 from spinBox will be 0.25*m_multiplier on slider and otherwise
    bool setup(QAbstractSlider *slider, QDoubleSpinBox *spinBox, double multiplier);

signals:

public slots:

private slots:
    void onSliderValueChanged(int value);
    void onSpinBoxValueChanged(double value);

private:
    QPointer<QAbstractSlider> m_slider;
    QPointer<QDoubleSpinBox> m_spinBox;

    double m_multiplier;
};

#endif // EDITORCONNECTOR_H
