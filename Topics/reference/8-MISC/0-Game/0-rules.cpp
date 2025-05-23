/*
nim game: 
there are n piles and each pile has a[i] stones, each player can take any number of stones from one pile, the player who takes the last stone wins.

if the xor of all piles is 0, the second player wins, otherwise the first player wins.

if the xor of all piles is 0, the next move will make the xor non-zero.
if the xor of all piles is non-zero, we can take stones from one pile to make the xor 0: let's it's value is x and msb of x is i, we can choice a pile p with bit[i]=1 and take stones from it so x ^ p ^ p' = 0, where p' is the new value of p, p' = p ^ x.
*/

/*
misere nim game:
there are n piles and each pile has a[i] stones, each player can take any number of stones from one pile, the player who takes the last stone loses.

not sure but we can use grundy numbers to solve this problem.
*/

/*
sprague-grundy theorem:
we can convert game to nim game by using grundy numbers. each position of the game has a grundy number, if the grundy number is 0, the position is losing position, otherwise it's winning position.

if the grundy number of the position is g, is MEX of the grundy numbers of the next positions.

if postion have several moves and each move transform to several positions, the grundy number of the position is MEX of the grundy numbers of the next transtions, and each transition has grundy number of xor of the grundy numbers of the next positions.
*/
