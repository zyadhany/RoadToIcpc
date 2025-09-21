/*
Area of tringle:

Ways to compute the area of a triangle:

1. From coordinates (2D points):
   Area = 1/2 * | x1*(y2−y3) + x2*(y3−y1) + x3*(y1−y2) |

2. From vectors:
   Area = 1/2 * | AB × AC |   (cross product magnitude)

3. Heron’s formula (3 sides known):
   s = (a + b + c) / 2
   Area = sqrt( s * (s−a) * (s−b) * (s−c) )

4. Base and height:
   Area = 1/2 * base * height

5. Two sides and included angle:
   Area = 1/2 * a * b * sin(angle)

6. Using circumcircle radius (R):
   Area = (a * b * c) / (4 * R)

7. Using inradius (r):
   s = (a + b + c) / 2
   Area = r * s

8. From coordinates in 3D:
   Area = 1/2 * || (B−A) × (C−A) ||   (cross product norm)
*/