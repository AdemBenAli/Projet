#include "chart.h"
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
#include <QPen>
#include <QBrush>

BarChartView::BarChartView(QWidget *parent)
    : QGraphicsView(parent), scene(new QGraphicsScene(this))
{
    setScene(scene);  // Set the scene to the view
}

void BarChartView::setData(const QMap<QString, int>& data)
{
    chartData = data;  // Set the data for the chart

    // Clear the previous items in the scene
    scene->clear();

    // Define parameters for the chart
    int chartWidth = 500;  // Width of the chart
    int chartHeight = 300; // Height of the chart
    int barWidth = 40;     // Width of each bar
    int gap = 20;          // Space between bars
    int xOffset = 30;      // X offset for placing bars
    int yOffset = 50;      // Y offset for placing the bars

    int maxValue = 0;
    for (auto it = chartData.begin(); it != chartData.end(); ++it)
    {
        if (it.value() > maxValue)
            maxValue = it.value();  // Find the maximum value to scale the bars
    }

    // Iterate through the data and draw the bars
    int xPos = xOffset;
    for (auto it = chartData.begin(); it != chartData.end(); ++it)
    {
        int barHeight = (it.value() * chartHeight) / maxValue;  // Scale the bar height according to the data
        QGraphicsRectItem *bar = scene->addRect(xPos, chartHeight - barHeight + yOffset, barWidth, barHeight,
                                                QPen(Qt::black), QBrush(Qt::blue));  // Add a bar to the scene
        QGraphicsTextItem *label = scene->addText(it.key(), QFont("Arial", 10));
        label->setPos(xPos, chartHeight - barHeight + yOffset + barHeight + 5);  // Add label under the bar
        xPos += barWidth + gap;  // Move the X position for the next bar
    }

    // Draw the axes (Optional, for better visualization)
    QGraphicsLineItem *xAxis = scene->addLine(xOffset, yOffset + chartHeight, xOffset + chartWidth, yOffset + chartHeight, QPen(Qt::black));
    QGraphicsLineItem *yAxis = scene->addLine(xOffset, yOffset, xOffset, yOffset + chartHeight, QPen(Qt::black));
}
