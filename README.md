TETRIS
work in progress

ISSUES/FUTURE ADDITIONS:
game over check overhaul
add highscore name input
for loop sizeof(array)/sizeof(array[0])integration

CHANGELOG
24/09 added the tileBag system to adjust randomness and repetitiveness of played tiles
25/09 changed tile::rotate to return bool, based upon success of rotation. if successful, the collision timer will be stopped
26/09 added a rotation check for spaces one spaces one down, to the right and the left if a collision is detected, thus allowing for T-spins and similar