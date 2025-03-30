/*
Line Segments:

when have some line segments, we can use a sweep line algorithm to find the intersection of line segments.

1. sort all line segments by x coordinate of left end point.
2. make a set of active line segments, sorted by y coordinate of left end point.
3. for each line segment, check if it intersect with the line segments in the active set.
4. the line intersect with adjacent line segments in the active set.
*/