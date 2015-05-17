#include <QtGui>
#include <QColor>

#include <QDynamicPropertyChangeEvent>

#include <cassert>

#include <chartwork/BarChart.h>
#include <chartwork/Design.h>
#include <chartwork/elements/Key.h>
#include <chartwork/elements/Background.h>
#include <chartwork/elements/Title.h>

namespace chartwork
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BarChart
//
////////////////////////////////////////////////////////////////////////////////////////////////////

BarChart::BarChart(QWidget *parent)
:	Chart(parent),
	m_yAxis(elements::Axis::Y_AXIS),
	m_yMax(100.0),
	m_yPrecision(0)
{
	m_yAxis.setMin(0.0);
	m_yAxis.setMax(m_yMax);
	m_yAxis.setPrecision(m_yPrecision);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

double BarChart::yMax() const
{
	return m_yMax;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void BarChart::setYMax(double yMax)
{
	m_yMax = yMax;
	m_yAxis.setMax(yMax);

	generateRandomValues();
	update();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int BarChart::yPrecision() const
{
	return m_yPrecision;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void BarChart::setYPrecision(int yPrecision)
{
	m_yPrecision = std::max(0, yPrecision);
	m_yAxis.setPrecision(yPrecision);

	update();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
