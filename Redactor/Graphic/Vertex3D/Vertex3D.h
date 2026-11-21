#ifndef __VERTEX_3D_H__
#define __VERTEX_3D_H__

namespace Redactor
{

namespace Graphic
{
    class Vertex3D
    {
    public:
        Vertex3D(void);
        Vertex3D(double x, double y, double z);

        Vertex3D(const Vertex3D& other);
        Vertex3D(Vertex3D&& other) noexcept;
        Vertex3D& operator=(const Vertex3D& other);
        Vertex3D& operator=(Vertex3D&& other) noexcept;

        virtual ~Vertex3D(void);

        double GetX(void) const;
        double GetY(void) const;
        double GetZ(void) const;

        void SetX(double x);
        void SetY(double y);
        void SetZ(double z);

        Vertex3D& operator+=(const Vertex3D& other);
        Vertex3D& operator-=(const Vertex3D& other);
        Vertex3D& operator/=(double num);
        Vertex3D& operator*=(double num);

        Vertex3D operator-() const;

        friend Vertex3D operator+(Vertex3D left, const Vertex3D& right);
        friend Vertex3D operator-(Vertex3D left, const Vertex3D& right);
        friend Vertex3D operator/(Vertex3D left, double right);
        friend Vertex3D operator*(Vertex3D left, double right);
        friend Vertex3D operator*(double left, Vertex3D right);

    protected:
        double x;
        double y;
        double z;
    };
}

}

#endif // __VERTEX_3D_H__
