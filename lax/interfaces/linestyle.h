//
//	
//    The Laxkit, a windowing toolkit
//    Please consult https://github.com/Laidout/laxkit about where to send any
//    correspondence about this software.
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Library General Public
//    License as published by the Free Software Foundation; either
//    version 3 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Library General Public License for more details.
//
//    You should have received a copy of the GNU Library General Public
//    License along with this library; If not, see <http://www.gnu.org/licenses/>.
//
//    Copyright (C) 2004-2007,2010-2012 by Tom Lechner
//
#ifndef _LAX_LINESTYLE_H
#define _LAX_LINESTYLE_H

#include <cstdio>

#include <lax/anobject.h>
#include <lax/dump.h>
#include <lax/colors.h>
#include <lax/laxutils.h>


namespace LaxInterfaces {

enum LineStyleMask {
	LINESTYLE_Width     =(1<<0),
	LINESTYLE_Color     =(1<<1),
	LINESTYLE_Color2    =(1<<2),
	LINESTYLE_Dash      =(1<<3),
	LINESTYLE_Joinstyle =(1<<4),
	LINESTYLE_Miterlimit=(1<<5),
	LINESTYLE_Capstyle  =(1<<6),
	LINESTYLE_MAX
};

class LineStyle : virtual public Laxkit::anObject, virtual public LaxFiles::DumpUtility
{
  public:
  	double width;
	int widthtype;
	int capstyle, endcapstyle;
	int joinstyle;
	double miterlimit;
	int dotdash;
	int function;

	double *dashes;
	double dash_offset;
	int numdashes;

	Laxkit::Color *color2;
	Laxkit::ScreenColor color;

	unsigned long mask;

	// typedef LineStyle *(*NewLineStyleFunc)();
	// static NewLineStyleFunc newLineStyle;
	// static LineStyle *DefaultLineStyle() { return new LineStyle(); }

	LineStyle();
	LineStyle(const LineStyle &l);
	LineStyle &operator=(LineStyle &l);
	virtual ~LineStyle();
	virtual const char *whattype() { return "LineStyle"; }
	virtual anObject *duplicate(anObject *ref);
	virtual void Color(unsigned long col);
	virtual void Color(int r,int g,int b,int a);
	virtual void Colorf(double r,double g,double b,double a);
	virtual void Colorf(const Laxkit::ScreenColor &col);
	virtual void dump_in_atts(LaxFiles::Attribute *att,int flag,LaxFiles::DumpContext *context);
	virtual void dump_out(FILE *f,int indent,int what,LaxFiles::DumpContext *context);
	virtual LaxFiles::Attribute *dump_out_atts(LaxFiles::Attribute *att,int what, LaxFiles::DumpContext *context);

	virtual int hasStroke();
};

} // namespace LaxInterfaces

#endif

