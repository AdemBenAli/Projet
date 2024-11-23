#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMap>
#include "maintenance.h"
class BarChartView : public QGraphicsView {
    Q_OBJECT
public:
    explicit BarChartView(QWidget *parent = nullptr);

    void setData(const QMap<QString, int>& data);

private:
    QGraphicsScene *scene;
};

BarChartView::BarChartView(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void BarChartView::setData(const QMap<QString, int>& data) {
    scene->clear();

    // Calculate total for percentages and maximum value for scaling
    int total = 0, maxValue = 0;
    for (int value : data.values()) {
        total += value;
        if (value > maxValue) maxValue = value;
    }

    int barWidth = 50;       // Width of each bar
    int spacing = 20;        // Spacing between bars
    int xOffset = 50;        // Initial offset
    int chartHeight = 300;   // Chart height

    int x = xOffset;
    for (const QString &key : data.keys()) {
        int value = data[key];

        // Calculate bar height proportional to maxValue
        int barHeight = (value / static_cast<double>(maxValue)) * chartHeight;

        // Draw bar
        QGraphicsRectItem *bar = scene->addRect(x, chartHeight - barHeight, barWidth, barHeight, QPen(), QBrush(Qt::blue));

        // Add label for the bar (etat)
        QGraphicsTextItem *label = scene->addText(key);
        label->setPos(x + barWidth / 4, chartHeight + 10);

        // Add count value on top of bar
        QGraphicsTextItem *countLabel = scene->addText(QString::number(value));
        countLabel->setPos(x + barWidth / 4, chartHeight - barHeight - 20);

        // Move to the next bar position
        x += barWidth + spacing;
    }
}
