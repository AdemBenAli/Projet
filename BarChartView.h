#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMap>

class BarChartView : public QGraphicsView {
    Q_OBJECT
public:
    explicit BarChartView(QWidget *parent = nullptr);
    void setData(const QMap<QString, int>& data);

private:
    QGraphicsScene *scene;
};

#endif // BARCHARTVIEW_H
