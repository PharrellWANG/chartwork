#include <chartwork/elements/Title.h>

#include <QPainter>

#include <chartwork/Design.h>

namespace chartwork
{
namespace elements
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Title
//
////////////////////////////////////////////////////////////////////////////////////////////////////

Title::Title()
:	m_text("Untitled")
{
	m_font.setBold(true);

	updateSize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Title::setText(const QString &text)
{
	m_text = text;

	updateSize();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const QString &Title::text() const
{
	return m_text;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Title::moveTopLeft(const QPoint &p)
{
	m_rect.moveTopLeft(p);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Title::setWidth(int width)
{
	m_rect.setWidth(width);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Title::paint(QPainter &painter)
{
	painter.setPen(Qt::SolidLine);
	painter.setBrush(design::darkergray);
	painter.setFont(m_font);
	painter.drawText(m_rect, m_text, QTextOption(Qt::AlignHCenter | Qt::AlignTop));
	painter.setPen(Qt::NoPen);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

const QRect &Title::rect() const
{
	return m_rect;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void Title::updateSize()
{
	if (m_text.isEmpty())
		m_rect.setHeight(0);
	else
		m_rect.setHeight(design::titleHeight);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
