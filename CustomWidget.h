#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QMap>

class CustomWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CustomWidget(QWidget *parent = nullptr);
    void setStats(const QMap<QString, int> &stats);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<QString, int> stats_;
};

#endif // CUSTOMWIDGET_H
