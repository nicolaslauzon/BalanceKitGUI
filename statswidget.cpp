/*
// ========================================================================
//
// File: statswidget.cpp
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
#include "statswidget.h"
#include "ui_statswidget.h"
#include <QtCharts/QValueAxis>
#include <QGraphicsLayout>

/*!
 * \brief StatsWidget::StatsWidget
 * \param parent
 */
StatsWidget::StatsWidget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::StatsWidget),
    x_axis_format_("%.2f"),
    series_(nullptr),
    x_axis_(nullptr),
    y_axis_(nullptr)
{
    ui->setupUi(this);
    chart_=new QtCharts::QChart();
    chart_->legend()->hide();

    x_axis_ = new QtCharts::QValueAxis();
    x_axis_->setTitleText("Distance (mm)");
    x_axis_->setLabelFormat(x_axis_format_);
    x_axis_->setTickCount(6);
    chart_->addAxis(x_axis_, Qt::AlignBottom);

    y_axis_=new QtCharts::QValueAxis();
    y_axis_->setLabelFormat("%.2f");
    chart_->addAxis(y_axis_, Qt::AlignLeft);

    chart_->setTheme(QtCharts::QChart::ChartThemeDark);
    chart_->setMargins(QMargins(0,0,0,0));
    chart_->layout()->setContentsMargins(0, 0, 0, 0);
    chart_->setBackgroundRoundness(0);

    ui->graph_widget_->setChart(chart_);
    ui->graph_widget_->setRenderHint(QPainter::Antialiasing);
}
/*!
 * \brief StatsWidget::~StatsWidget
 */
StatsWidget::~StatsWidget()
{
    delete ui;
    if (x_axis_!=nullptr)
        x_axis_->deleteLater();
    if (y_axis_!=nullptr)
        y_axis_->deleteLater();
    if (chart_!=nullptr)
        chart_->deleteLater();
    if (series_!=nullptr)
        series_->deleteLater();
}

/*!
 * \brief StatsWidget::SetTitle
 * \param title
 */
void
StatsWidget::SetTitle(const QString &title)
{
    title_=title;
    chart_->setTitle(title_);
}

/*!
 * \brief StatsWidget::SetXAxisTitle
 * \param title
 */
void
StatsWidget::SetXAxisTitle(const QString &title)
{
    x_axis_title_=title;
    if (x_axis_!=nullptr)
        x_axis_->setTitleText(x_axis_title_);
}

/*!
 * \brief StatsWidget::SetXAxisFormat
 * \param format
 */
void
StatsWidget::SetXAxisFormat(const QString &format)
{
    x_axis_format_=format;
    if (x_axis_!=nullptr)
        x_axis_->setLabelFormat(x_axis_format_);
}

/*!
 * \brief StatsWidget::SetYAxisTitle
 * \param title
 */
void
StatsWidget::SetYAxisTitle(const QString &title)
{
    y_axis_title_=title;
    if (y_axis_!=nullptr)
        y_axis_->setTitleText(y_axis_title_);
}

/*!
 * \brief StatsWidget::SetDistribution
 * \param distribution
 */
void
StatsWidget::SetDistribution(const QList<QPointF> &distribution)
{
    distribution_=distribution;
    DisplayDistribution();
}


void
StatsWidget::DisplayDistribution()
{
    if (series_!=nullptr) {
        series_->detachAxis(y_axis_);
        series_->detachAxis(x_axis_);
        chart_->removeSeries(series_);
        series_->deleteLater();
    }

    if (distribution_.isEmpty())
        return;

    // build a line series,
    // for a log point
    x_axis_->setTickCount(distribution_.count());
    series_ = new QtCharts::QLineSeries();
    double min_x=1e10;
    double max_x=-1e10;
    double min_y=1e10;
    double max_y=-1e10;
    for (int i=0; i<distribution_.count(); ++i) {
        const QPointF& current_pt=distribution_.at(i);
        series_->append(current_pt);

        // find min/max
        if (current_pt.x()<min_x) min_x=current_pt.x();
        if (current_pt.x()>max_x) max_x=current_pt.x();
        if (current_pt.y()<min_y) min_y=current_pt.y();
        if (current_pt.y()>max_y) max_y=current_pt.y();
    }


    if (x_axis_!=nullptr)
        x_axis_->setRange(min_x,max_x);
    if (y_axis_!=nullptr)
        // need to put a minimal value because of the log axis: can't have a '0'
        y_axis_->setRange(std::min<double>(0,min_y),max_y);


    chart_->addSeries(series_);
    series_->attachAxis(y_axis_);
    series_->attachAxis(x_axis_);
}
