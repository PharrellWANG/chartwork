#ifndef __ELEMENTS__BACKGROUND_H
#define __ELEMENTS__BACKGROUND_H

#include <QRect>
#include <QWidget>

class QPainter;

namespace chartwork
{
namespace elements
{

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Background
//
////////////////////////////////////////////////////////////////////////////////////////////////////

class Background
{
	public:
		Background(QWidget *parent);

		void paint(QPainter &painter);

	private:
		QWidget *m_parent;
};

////////////////////////////////////////////////////////////////////////////////////////////////////

}
}

#endif
