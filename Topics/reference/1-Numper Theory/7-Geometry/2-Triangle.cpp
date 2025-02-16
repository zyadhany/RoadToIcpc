
// knowing only points of triangle.
ld areaOfTriangle(pl a, pl b, pl c) {
    return 0.5 * abs(a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second));
}

ll dot_product(pl v1, pl v2) { 
    return v1.first * v2.first + v1.second * v2.second; 
} 

bool is_right_triangle(pl A, pl B, pl C) { 
    // Define vectors 
    pl AB = {B.first - A.first, B.second - A.second}; 
    pl BC = {C.first - B.first, C.second - B.second}; 
    pl CA = {A.first - C.first, A.second - C.second}; 
 
    // Check if any dot product is zero (indicating 90-degree angle) 
    return (dot_product(AB, BC) == 0 || dot_product(BC, CA) == 0 || dot_product(CA, AB) == 0); 
} 
