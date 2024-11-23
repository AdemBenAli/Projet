#include "CustomWidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QFont>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    // Initial empty stats
    stats_.clear();
}

void CustomWidget::setStats(const QMap<QString, int> &stats)
{
    stats_ = stats;
    update();  // Trigger a repaint
}

void CustomWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Define margins and sizes
    int margin = 40;
    int barWidth = 40;
    int maxHeight = height() - 2 * margin;
    int x = margin;
    int total = 0;

    // Calculate total count to scale the chart
    for (auto &value : stats_) {
        total += value;
    }

    // Draw the bars
    painter.setBrush(QBrush(Qt::blue));
    int yStart = margin;
    for (auto it = stats_.begin(); it != stats_.end(); ++it) {
        QString label = it.key();
        int count = it.value();

        // Calculate the height of the bar based on the count
        int barHeight = (maxHeight * count) / total;

        // Draw the bar
        QRect rect(x, yStart + maxHeight - barHeight, barWidth, barHeight);
        painter.drawRect(rect);

        // Draw the label
        painter.setFont(QFont("Arial", 10));
        painter.drawText(x, yStart + maxHeight + 10, label);

        x += barWidth + 10;
    }
}
