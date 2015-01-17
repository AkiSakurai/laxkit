//
//	
//    The Laxkit, a windowing toolkit
//    Please consult http://laxkit.sourceforge.net about where to send any
//    correspondence about this software.
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU Library General Public
//    License as published by the Free Software Foundation; either
//    version 2 of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Library General Public License for more details.
//
//    You should have received a copy of the GNU Library General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    Copyright (C) 2013-2014 by Tom Lechner
//

#ifndef _LAX_CURVEINFO_H
#define _LAX_CURVEINFO_H

#include <lax/anobject.h>
#include <lax/dump.h>


namespace Laxkit {


//------------------------------- CurveInfo ------------------------------------

class CurveInfo : public anObject, public LaxFiles::DumpUtility
{
  private:
	void base_init();
	
  public:
	enum CurveTypes {
		Linear,
		Autosmooth,
		Bezier
	};

	double xmin, xmax;
	double ymin, ymax;
	char *xlabel, *ylabel;
	char *title;
	CurveTypes curvetype;
	bool wrap;

	NumStack<flatpoint> points;
	NumStack<flatpoint> fauxpoints;

	int numsamples, lookup_min, lookup_max;
	int *lookup;

	CurveInfo();
	CurveInfo(const char *ntitle,
			  const char *xl, double nxmin, double nxmax,
			  const char *yl, double nymin, double nymax);
	virtual ~CurveInfo();
	virtual const char *whattype() { return "CurveInfo"; }
	CurveInfo &operator=(CurveInfo &l);
	virtual void SetXBounds(double nxmin, double nxmax, const char *nxlabel, bool remap);
	virtual void SetYBounds(double nymin, double nymax, const char *nylabel, bool remap);
	virtual void SetTitle(const char *ntitle);
	virtual flatpoint tangent(double x);
	virtual double f(double x);
	virtual double f_linear(double x);
	virtual double f_autosmooth(double x);
	virtual double f_bezier(double x);
	virtual flatpoint MapUnitPoint(flatpoint p);
	virtual flatpoint MapToUnitPoint(flatpoint p);
	virtual int AddPoint(double x,double y);
	virtual int MovePoint(int index, double x,double y);
	virtual void SetSinusoidal(int samples);
	virtual void SetFlat(double y);
	virtual void Reset(bool leaveblank);
	virtual void SetData(flatpoint *p, int n);
	virtual void SetDataRaw(flatpoint *p, int n);
	virtual void Wrap(bool wrapx);
	virtual void InvertY();
	virtual void InvertX();

	virtual void MakeFakeCurve();
	virtual int MakeLookupTable(int *table,int numentries, int minvalue, int maxvalue);
	virtual void RefreshLookup();
	virtual void RefreshLookup(int nsamples, int nmin, int nmax);
	virtual void LookupDump(const char *label,FILE *f);

	 //serializing aids
	virtual void dump_out(FILE *f,int indent,int what,anObject *context);
	virtual LaxFiles::Attribute *dump_out_atts(LaxFiles::Attribute *att,int what,anObject *context);
	virtual void dump_in_atts(LaxFiles::Attribute *att,int flag,anObject *context);
};


} // namespace Laxkit

#endif

