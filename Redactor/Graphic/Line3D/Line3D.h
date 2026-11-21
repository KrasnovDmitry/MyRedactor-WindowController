#ifndef __LINE_3D_H__
#define __LINE_3D_H__

#include "../Vertex3D/Vertex3D.h"
#include "string"

namespace Redactor
{

namespace Graphic
{
    class Line3D
    {
    public:
        Line3D(void);
        Line3D(double x1, double y1, double z1, double x2, double y2, double z2);
        Line3D(Vertex3D vert1, Vertex3D vert2);
        Line3D(const Line3D& other);
        Line3D(Line3D&& other) noexcept;
        Line3D& operator=(const Line3D& other);
        Line3D& operator=(Line3D&& other) noexcept;
        virtual ~Line3D(void);

        Vertex3D GetStart(void) const;
        Vertex3D GetEnd(void) const;

        double GetStartX(void) const;
        double GetStartY(void) const;
        double GetStartZ(void) const;
        double GetEndX(void) const;
        double GetEndY(void) const;
        double GetEndZ(void) const;

        void SetStart(Vertex3D vert);
        void SetStart(double x, double y, double z);
        void SetEnd(Vertex3D vert);
        void SetEnd(double x, double y, double z);

        void SetStartX(double a);
        void SetStartY(double a);
        void SetStartZ(double a);
        void SetEndX(double a);
        void SetEndY(double a);
        void SetEndZ(double a);

    protected:
        Vertex3D start;
        Vertex3D end;
    };
}

}

#endif // __LINE_3D_H__
