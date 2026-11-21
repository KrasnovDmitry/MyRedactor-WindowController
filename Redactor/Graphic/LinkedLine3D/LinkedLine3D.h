#ifndef __LINKED_LINE_3D_H__
#define __LINKED_LINE_3D_H__

#include "../Line3D/Line3D.h"

namespace Redactor
{

namespace Graphic
{
    class LinkedLine3D
    {
    public:
        LinkedLine3D(void);
        LinkedLine3D(const Vertex3D& start, const Vertex3D& end);
        LinkedLine3D(Vertex3D* start_ptr, Vertex3D* end_ptr);
        LinkedLine3D(double x1, double y1, double z1, double x2, double y2, double z2);
        LinkedLine3D(const LinkedLine3D& other);
        LinkedLine3D(LinkedLine3D&& other) noexcept;
        LinkedLine3D& operator=(const LinkedLine3D& other);
        LinkedLine3D& operator=(LinkedLine3D&& other) noexcept;
        virtual ~LinkedLine3D(void);

        operator Line3D(void) const;

        bool GetStartDeallocFlag(void) const;
        bool GetEndDeallocFlag(void) const;

        void SetStartDeallocFlag(bool f);
        void SetEndDeallocFlag(bool f);
        void SetDeallocFlags(bool startDeallocFlag, bool endDeallocFlag);

        Vertex3D GetStart(void) const;
        Vertex3D GetEnd(void) const;

        Vertex3D* GetStartPtr(void) const;
        Vertex3D* GetEndPtr(void) const;

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

        void SetStartPtr(Vertex3D* vertPtr);
        void SetEndPtr(Vertex3D* vertPtr);

        void SetStartX(double a);
        void SetStartY(double a);
        void SetStartZ(double a);
        void SetEndX(double a);
        void SetEndY(double a);
        void SetEndZ(double a);

        double Length(void) const;
    protected:
        Vertex3D* start_ptr;
        Vertex3D* end_ptr;
        unsigned char selfDeallocFlags;
    };
}

}

#endif // __LINKED_LINE_3D_H__
