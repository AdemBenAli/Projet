#ifndef CHART_H
#define CHART_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QVector>
#include <QMap>

class BarChartView : public QGraphicsView
{
    Q_OBJECT

public:
    BarChartView(QWidget *parent = nullptr);
    void setData(const QMap<QString, int>& data);  // Set data for the chart

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;  // Drawing the background of the view

private:
    QGraphicsScene *scene;  // The scene to hold the chart items
    QMap<QString, int> chartData;  // The data for the chart, with the label (e.g., 'bonne', 'moyenne', 'faible') as the key
};

#endif // CHART_H
