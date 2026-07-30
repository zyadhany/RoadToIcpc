// sin-low: a/sin(A) = b/sin(B) = c/sin(C)

/*
Area of triangle:

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

5. Two sides and included angle (SAS):
   Area = 1/2 * a * b * sin(C)

6. Using circumcircle radius (R):
   Area = (a * b * c) / (4 * R)

7. Using inradius (r):
   s = (a + b + c) / 2
   Area = r * s

8. From coordinates in 3D:
   Area = 1/2 * || (B−A) × (C−A) ||   (cross product norm)

9. One side and two angles (ASA / AAS):
   A = PI - (B + C)
   Area = (a^2 * sin(B) * sin(C)) / (2 * sin(A))

10. Three angles and circumradius (R):
    Area = 2 * R^2 * sin(A) * sin(B) * sin(C)

11. Exradii (r_a, r_b, r_c):
    Area = sqrt(r * r_a * r_b * r_c)
    Area = r_a * (s - a)

12. Pick's Theorem (grid/lattice points):
    Area = I + B/2 - 1   (I = interior points, B = boundary points)

13. Polar coordinates (two points (r1, theta1), (r2, theta2) from origin):
    Area = 1/2 * r1 * r2 * |sin(theta2 - theta1)|

14. Equilateral triangle:
    Area = (sqrt(3) / 4) * a^2
*/