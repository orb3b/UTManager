#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include <QScopedPointer>
#include <QSlider>
#include <QDoubleSpinBox>

#include "EditorConnector.h"

class tst_EditorConnector : public QObject
{
    Q_OBJECT

public:
    tst_EditorConnector();

private Q_SLOTS:
    void setup();
};

tst_EditorConnector::tst_EditorConnector()
{
}

void tst_EditorConnector::setup()
{
    QScopedPointer<QSlider> slider(new QSlider());
    QScopedPointer<QDoubleSpinBox> spinBox(new QDoubleSpinBox());
    spinBox->setMaximum(1.0);
    spinBox->setMinimum(-1.0);
    double multiplier = 100;

    EditorConnector connector;

    QVERIFY(!connector.setup(slider.data(), nullptr, multiplier));
    QVERIFY(!connector.setup(nullptr, spinBox.data(), multiplier));
    QVERIFY(connector.setup(slider.data(), spinBox.data(), multiplier));

    QCOMPARE(static_cast<double>(slider->minimum()), spinBox->minimum() * multiplier);
    QCOMPARE(static_cast<double>(slider->maximum()), spinBox->maximum() * multiplier);

    spinBox->setValue(0.5);
    QCOMPARE(static_cast<double>(slider->value()), 0.5 * multiplier);
}

QTEST_MAIN(tst_EditorConnector)

#include "tst_editorConnector.moc"
