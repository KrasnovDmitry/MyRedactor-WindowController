#include "LinkedLine3D.h"
#include "math.h"

namespace G = Redactor::Graphic;

G::LinkedLine3D::LinkedLine3D(void)
{
    this->start_ptr = nullptr;
    this->end_ptr = nullptr;
    this->SetDeallocFlags(true, true);
}

G::LinkedLine3D::LinkedLine3D(const Vertex3D& start, const Vertex3D& end)
{
    this->start_ptr = new Vertex3D(start);
    this->end_ptr = new Vertex3D(end);
    this->SetDeallocFlags(true, true);
}

G::LinkedLine3D::LinkedLine3D(Vertex3D* start_ptr, Vertex3D* end_ptr)
{
    this->start_ptr = start_ptr;
    this->end_ptr = end_ptr;
    this->SetDeallocFlags(true, true);
}

G::LinkedLine3D::LinkedLine3D(double x1, double y1, double z1, double x2, double y2, double z2)
{
    this->start_ptr = new Vertex3D(x1, y1, z1);
    this->end_ptr = new Vertex3D(x2, y2, z2);
    this->SetDeallocFlags(true, true);
}

G::LinkedLine3D::LinkedLine3D(const G::LinkedLine3D& other)
{
    this->start_ptr = new Vertex3D(*other.start_ptr);
    this->end_ptr = new Vertex3D(*other.end_ptr);
    this->SetDeallocFlags(true, true);
}

G::LinkedLine3D::LinkedLine3D(G::LinkedLine3D&& other) noexcept
{
    this->start_ptr = other.start_ptr;
    this->end_ptr = other.end_ptr;
    this->selfDeallocFlags = other.selfDeallocFlags;

    other.start_ptr = nullptr;
    other.end_ptr = nullptr;
}

G::LinkedLine3D& G::LinkedLine3D::operator=(const G::LinkedLine3D& other)
{
    if(this != &other)
    {
        this->start_ptr = new Vertex3D(*other.start_ptr);
        this->end_ptr = new Vertex3D(*other.end_ptr);
        this->SetDeallocFlags(true, true);
    }
    return *this;
}

G::LinkedLine3D& G::LinkedLine3D::operator=(LinkedLine3D&& other) noexcept
{
    if(this != &other)
    {
        this->start_ptr = other.start_ptr;
        this->end_ptr = other.end_ptr;
        this->selfDeallocFlags = other.selfDeallocFlags;

        other.start_ptr = nullptr;
        other.end_ptr = nullptr;
    }
    return *this;
}

G::LinkedLine3D::~LinkedLine3D(void)
{
    if(GetStartDeallocFlag())
        delete this->start_ptr;
    if(GetEndDeallocFlag())
        delete this->end_ptr;
}

G::LinkedLine3D::operator G::Line3D(void) const
{
    return G::Line3D(*this->start_ptr, *this->end_ptr);
}

bool G::LinkedLine3D::GetStartDeallocFlag(void) const
{
    return this->selfDeallocFlags & 1;
}

bool G::LinkedLine3D::GetEndDeallocFlag(void) const
{
    return this->selfDeallocFlags & 2;
}

void G::LinkedLine3D::SetStartDeallocFlag(bool f)
{
    if(f)
        this->selfDeallocFlags = this->selfDeallocFlags | 1;
    else
        this->selfDeallocFlags = this->selfDeallocFlags & 2;
}

void G::LinkedLine3D::SetEndDeallocFlag(bool f)
{
    if(f)
        this->selfDeallocFlags = this->selfDeallocFlags | 2;
    else
        this->selfDeallocFlags = this->selfDeallocFlags & 1;
}

void G::LinkedLine3D::SetDeallocFlags(bool startDeallocFlag, bool endDeallocFlag)
{
    this->selfDeallocFlags = 0;
    if(startDeallocFlag)
        this->selfDeallocFlags += 1;
    if(endDeallocFlag)
        this->selfDeallocFlags += 2;

}

G::Vertex3D G::LinkedLine3D::GetStart(void) const
{
    if(this->start_ptr == nullptr)
        return G::Vertex3D(0, 0, 0);
    return *this->start_ptr;
}

G::Vertex3D G::LinkedLine3D::GetEnd(void) const
{
    if(this->end_ptr == nullptr)
        return G::Vertex3D(0, 0, 0);
    return *this->end_ptr;
}

G::Vertex3D* G::LinkedLine3D::GetStartPtr(void) const
{
    return this->start_ptr;
}

G::Vertex3D* G::LinkedLine3D::GetEndPtr(void) const
{
    return this->end_ptr;
}

double G::LinkedLine3D::GetStartX(void) const
{
    if(this->start_ptr == nullptr)
        return 0;
    return this->start_ptr->GetX();
}

double G::LinkedLine3D::GetStartY(void) const
{
    if(this->start_ptr == nullptr)
        return 0;
    return this->start_ptr->GetY();
}

double G::LinkedLine3D::GetStartZ(void) const
{
    return this->start_ptr->GetZ();
}

double G::LinkedLine3D::GetEndX(void) const
{
    if(this->end_ptr == nullptr)
        return 0;
    return this->end_ptr->GetX();
}

double G::LinkedLine3D::GetEndY(void) const
{
    if(this->end_ptr == nullptr)
        return 0;
    return this->end_ptr->GetY();
}

double G::LinkedLine3D::GetEndZ(void) const
{
    if(this->end_ptr == nullptr)
        return 0;
    return this->end_ptr->GetZ();
}

void G::LinkedLine3D::SetStart(G::Vertex3D vert)
{
    if(this->start_ptr == nullptr)
        this->start_ptr = new G::Vertex3D(vert);
    else
        *this->start_ptr = vert;
}

void G::LinkedLine3D::SetStart(double x, double y, double z)
{
    if(this->start_ptr == nullptr)
        this->start_ptr = new G::Vertex3D(x, y, z);
    else
        *this->start_ptr = G::Vertex3D(x, y, z);
}

void G::LinkedLine3D::SetEnd(G::Vertex3D vert)
{
    if(this->end_ptr == nullptr)
        this->end_ptr = new G::Vertex3D(vert);
    else
        *this->end_ptr = vert;
}

void G::LinkedLine3D::SetEnd(double x, double y, double z)
{
        if(this->end_ptr == nullptr)
        this->end_ptr = new G::Vertex3D(x, y, z);
    else
        *this->end_ptr = G::Vertex3D(x, y, z);
}

void G::LinkedLine3D::SetStartPtr(G::Vertex3D* vertPtr)
{
    if(this->start_ptr != nullptr && this->GetStartDeallocFlag())
        delete this->start_ptr;
    this->start_ptr = vertPtr;
}

void G::LinkedLine3D::SetEndPtr(G::Vertex3D* vertPtr)
{
    if(this->end_ptr != nullptr && this->GetEndDeallocFlag())
        delete this->end_ptr;
    this->end_ptr = vertPtr;
}

void G::LinkedLine3D::SetStartX(double a)
{
    if(this->start_ptr == nullptr)
        this->start_ptr = new G::Vertex3D(a, 0, 0);
    else
        this->start_ptr->SetX(a);
}

void G::LinkedLine3D::SetStartY(double a)
{
    if(this->start_ptr == nullptr)
        this->start_ptr = new G::Vertex3D(0, a, 0);
    else
        this->start_ptr->SetY(a);
}

void G::LinkedLine3D::SetStartZ(double a)
{
    if(this->start_ptr == nullptr)
        this->start_ptr = new G::Vertex3D(0, 0, a);
    else
        this->start_ptr->SetZ(a);
}

void G::LinkedLine3D::SetEndX(double a)
{
    if(this->end_ptr == nullptr)
        this->end_ptr = new G::Vertex3D(a, 0, 0);
    else
        this->end_ptr->SetX(a);
}

void G::LinkedLine3D::SetEndY(double a)
{
    if(this->end_ptr == nullptr)
        this->end_ptr = new G::Vertex3D(0, a, 0);
    else
        this->end_ptr->SetY(a);
}

void G::LinkedLine3D::SetEndZ(double a)
{
    if(this->end_ptr == nullptr)
        this->end_ptr = new G::Vertex3D(0, 0, a);
    else
        this->end_ptr->SetZ(a);
}

double G::LinkedLine3D::Length(void) const
{
    double x = this->GetEndX() - this->GetStartX();
    double y = this->GetEndY() - this->GetStartY();
    double z = this->GetEndZ() - this->GetStartZ();
    return sqrt(x*x + y*y + z*z);
}
