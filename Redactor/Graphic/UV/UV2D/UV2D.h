#ifndef __UV_2_DOUBLE_H__
#define __UV_2_DOUBLE_H__

namespace Redactor
{

namespace Graphic
{

namespace UVs
{
    class UV2D
    {
    public:
        UV2D(void);
        UV2D(double u, double v);

        UV2D(const UV2D& other);
        UV2D(UV2D&& other) noexcept;

        UV2D& operator=(const UV2D& other);
        UV2D& operator=(UV2D&& other) noexcept;

        ~UV2D(void);

        double GetU(void) const;
        double GetV(void) const;

        void SetU(double u);
        void SetV(double v);

        UV2D& operator+=(const UV2D& other);
        UV2D& operator-=(const UV2D& other);
        UV2D& operator*=(double num);
        UV2D& operator/=(double num);
        UV2D operator-() const;

        friend UV2D operator+(UV2D left, const UV2D& right);
        friend UV2D operator-(UV2D left, const UV2D& right);
        friend UV2D operator/(UV2D left, double right);
        friend UV2D operator*(UV2D left, double right);
        friend UV2D operator*(double left, UV2D right);

    protected:
        double u;
        double v;
    };
}

}

}

#endif // __UV_2_DOUBLE_H__
