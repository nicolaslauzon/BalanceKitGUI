/*
// ========================================================================
//
// File: statswidget.h
// Created: 2021-11-25
// Author: FranÃ§ois Lauzon <flauzon@pragmandt.com>
//
// Copyright (C) PRAGMA. All rights reserved.
//
// The code contained in this file is strictly CONFIDENTIAL and shall not be PROPAGATED BY ANY
// MEANS UNLESS OTHERWISE AUTHORIZED BY PRAGMA.
//
// ========================================================================
*/
#ifndef STATSWIDGET_H
#define STATSWIDGET_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

namespace Ui {
class StatsWidget;
}

/*!
 * \brief The StatsWidget class
 */
class StatsWidget: public QWidget
{
    Q_OBJECT
public:
    StatsWidget(QWidget *parent = nullptr);
    virtual ~StatsWidget();

    void SetTitle(const QString& title);
    void SetXAxisTitle(const QString& title);
    void SetXAxisFormat(const QString& format);
    void SetYAxisTitle(const QString& title);
    void SetDistribution(const QList<QPointF>& distribution);

private:
    Ui::StatsWidget *ui;

    QList<QPointF> distribution_;
    QString title_;
    QString x_axis_title_;
    QString x_axis_format_;
    QString y_axis_title_;

    void DisplayDistribution();

    QtCharts::QChart *chart_;
    QtCharts::QLineSeries *series_;
    QtCharts::QValueAxis *x_axis_;
    QtCharts::QValueAxis *y_axis_;

};

#endif // STATSWIDGET_H
