# 11 - Projective Geometry
Greatly simplifies the basic operations in comparison to euclidean geometry and allows for projective transformations.

In 2D-projective geometry we use 3D vectors to represent all objects uniformly and operate on. We also use matrices to represent
transformations.

## 2D Objects
The two 2D Objects (Point and Line) are both represented by a 3D Vector originating from the origin and representing the 2D object as projection
on the 2D plane at height `z = 1`.

Any 3D Vector except `(0,0,0)` can represent any of the two geometric objects.

### Homogenization
2D point at `(x,y)` represented as `(x,y,1)` which is the same as any `λ(x,y,1)` with `λ` being non-zero.

### Normalization
To retrieve the projected 2D point one just divides by `z`: `(x,y,z) -> (x/z,y/z,1) -> (x/z,y/z)`

### Points at Infinity
When `z = 0` in `(x,y,z)` this means that we have a point at infinity in the direction `(x,y)`.

### Lines
A Line on the 2D plane is represented by a 3D Vector which is the normal of a plane going through the origin with its intersection at the 2D
projected plane being the line.

## Lines at Infinity
The one line `(0,0,1)` represents the line at infinity containing all the points at infinity.

All parallel lines meet at a point at infinity.

## Operations

### Is Point on Line
Point `p` is on line `l` **iff** vectors are orthogonal (dot product equals 0).

### Line through two Points
Line through points `p,q` has to be orthogonal to both vectors (cross product).

### Intersection of two Lines
Intersection point of lines `l,m` has to be on `l` and `m` (orthogonal to both => cross product).

### Construct Parallel through Point
Parallel to line `l` through point `p`. Get infinite point in direction of `l`: `q = l x (0,0,1)`. Then line through both points `p,q`. (cross product).

### Construct Perpendicular through Point
Perpendicular to line `l` through point `p`. Get infinite point in direction of `l`: `q = l x (0,0,1) = (x,y,0)`. 
Then get orthogonal to `q`: `q_o = (y,-x,0)`. Then line through both points `p,q` (cross product).

### Project Point onto Line
Project point `p` on line `l`. Get Perpendicular `m` to `l`. Then intersection of `m,l` (cross product).

### Area of Triangle
Triangle given by points `p,q,r`. Normalize `p,q,r`. Obtain matrix `M = (p q r)`. Area is `1/2 |det M| = 1/2 |p*(q x r)|`.

## Transformations

### Rotation
```
    (cos -sin 0)
M = (sin  cos 0)
    (  0    0 1)
```

### Translation
```
    (1 0 x)
M = (0 1 y)
    (0 0 1)
```

### Affine Transformation
Preserving parallelity.
```
    (a b c)
M = (d e f)
    (0 0 1)
```

### Projective Transformation
Preserving collinearity and point-on-line property.
Uniquely determined by four non-collinear points and their images.
```
    (a b c)
M = (d e f)
    (g h i)
```

### Find Projective Transformation
Find projective transformation matrix based on four non-collinear points `a,b,c,d` and their images `a',b',c',d'`.

Find two transformations `M1` and `M2`: 
- `M1` is transformation from points `(1,0,0),(0,1,0),(0,0,1),(1,1,1)` to `a',b',c',d'`
- `M2` is transformation from points `(1,0,0),(0,1,0),(0,0,1),(1,1,1)` to `a,b,c,d`

=> Transformation from `a,b,c,d` to `a',b',c',d'` will be `M1 * M2^(-1)`

Find `M1, M2` by solving system of linear equations and inverting 3x3 matrix.