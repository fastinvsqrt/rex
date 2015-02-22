#ifndef __REX_GEOOBJECT_HXX
#define __REX_GEOOBJECT_HXX

#include "Config.hxx"
#include "BoundingBox.hxx"
#include "Color.hxx"
#include "Material.hxx"
#include "Ray.hxx"

REX_NS_BEGIN

struct ShadePoint;

/// <summary>
/// An enumeration of possible geometry types.
/// </summary>
enum class GeometryType
{
    Plane,
    Sphere
};

/// <summary>
/// The base class for geometric objects.
/// </summary>
class Geometry
{
protected:
    Handle<Material> _material;

public:
    /// <summary>
    /// Creates a new geometric object.
    /// </summary>
    Geometry();

    /// <summary>
    /// Creates a new geometric object.
    /// </summary>
    /// <param name="material">The material to use.</param>
    template<class T> Geometry( const T& material );

    /// <summary>
    /// Destroys this geometric object.
    /// </summary>
    virtual ~Geometry();

    /// <summary>
    /// Gets this piece of geometry's material.
    /// </summary>
    const Material* GetMaterial() const;

    /// <summary>
    /// Gets the type of this piece of geometry.
    /// </summary>
    virtual GeometryType GetType() const = 0;

    /// <summary>
    /// Gets this piece of geometry's bounds.
    /// </summary>
    virtual BoundingBox GetBounds() const = 0;

    /// <summary>
    /// Checks to see if the given ray hits this geometric object. If it does, the shading
    /// point information is populated and the collision distance is recorded.
    /// </summary>
    /// <param name="ray">The ray to check.</param>
    /// <param name="tmin">The distance to intersection.</param>
    /// <param name="sp">The shading point information.</param>
    virtual bool Hit( const Ray& ray, real64& tmin, ShadePoint& sp ) const = 0;

    /// <summary>
    /// Sets the material for this piece of geometry.
    /// </summary>
    /// <param name="material">The material.</param>
    template<class T> void SetMaterial( const T& material );
};

REX_NS_END

#include "Geometry.inl"
#endif